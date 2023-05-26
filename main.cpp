#include <stdio.h>
#include <tensorflow/c/c_api.h>
#include <iostream>
#include <fstream>

//Función para leer el modelo
TF_Buffer* read_file(const char* filename) {
    std::ifstream input_file(filename, std::ios::binary);
    if (!input_file.is_open()) {
        throw std::runtime_error("Failed to open file");
    }
    std::string file_contents((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
    input_file.close();
    return TF_NewBufferFromString(file_contents.c_str(), file_contents.size());
}

//https://github.com/AmirulOm/tensorflow_capi_sample

int main() {
    TF_Graph* Graph = TF_NewGraph();
    TF_Status* Status = TF_NewStatus();

    TF_SessionOptions* SessionOpts = TF_NewSessionOptions();
    const char* filename = "model/saved_model.pb";
    TF_Buffer* buffer = read_file(filename); //Se llama a la función para guardar el modelo entrenado en el buffer.
    TF_ImportGraphDefOptions* import_options = TF_NewImportGraphDefOptions();
    TF_GraphImportGraphDef(Graph, buffer, import_options, Status); //Se importa el modelo
    TF_Session* session = TF_NewSession(Graph, SessionOpts, Status);  

    //Se libera memoria
    TF_DeleteImportGraphDefOptions(import_options);
    TF_DeleteBuffer(buffer);
    TF_DeleteSessionOptions(SessionOpts);
    TF_DeleteStatus(Status);

    //Se verifica si el modelo se importó correctamente.
    if(TF_GetCode(Status) == TF_OK)
    {
        printf("TF_LoadSessionFromSavedModel OK\n");
    }
    else
    {
        printf("%s",TF_Message(Status));
    }

    // Define los tensores de entrada y salida
    const int64_t input_dim[] = {1, 2, 2};  // [batch, height, width]
    float input_values[] = {1, 2, 3, 4};  // valores de ejemplo para la matriz de entrada
    const int input_num = 1;
    const int output_num = 1;
    TF_Output* input = new TF_Output[input_num];
    TF_Tensor** input_tensor = new TF_Tensor*[input_num];
    TF_Output* output = new TF_Output[output_num];
    TF_Tensor** output_values = new TF_Tensor*[output_num];
    
    // Define el tensor de entrada
    input[0].oper = TF_GraphOperationByName(Graph, "serving_default_dense_3_input");
    input[0].index = 0;
    input_tensor[0] = TF_NewTensor(TF_FLOAT, input_dim, 3, input_values, 4 * sizeof(float), NULL, NULL);

    // Ejecuta la sesión
    TF_SessionRun(session, NULL, input, input_tensor, input_num, output, output_values, output_num, NULL, 0, NULL, Status);

    // Recupera los resultados
    float* output_data = static_cast<float*>(TF_TensorData(output_values[0]));
    std::cout << "Output tensor values: [" << output_data[0] << ", " << output_data[1] << ", " << output_data[2] << ", " << output_data[3] << "]" << std::endl;

    // Libera la memoria
    delete[] input;
    delete[] input_tensor;
    delete[] output;
    delete[] output_values;
    return 0;
}
