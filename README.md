 <h1>README</h1>
  <h2>Requisitos</h2>
  <ul>
    <li><a href="https://www.tensorflow.org/install/lang_c">TensorFlow C API</a>: Se requiere instalar la biblioteca TensorFlow C API para compilar y ejecutar este programa.</li>
    <li>Compilador de C++: Se necesita un compilador de C++ compatible para compilar el código fuente.</li>
    <li>Archivo del modelo entrenado: Debe tener el archivo del modelo entrenado en formato ".pb" listo para usar. Asegúrese de colocarlo en la ruta "model/" relativa al directorio donde se encuentra el programa.</li>
  </ul>
  <h2>Configuración</h2>
  <p>Antes de ejecutar el programa, asegúrese de cumplir con los siguientes pasos de configuración:</p>
  <ol>
    <li>Descargue e instale la biblioteca TensorFlow C API siguiendo las instrucciones proporcionadas en la <a href="https://www.tensorflow.org/install/lang_c">documentación oficial de TensorFlow</a>.</li>
    <li>Compile el código fuente utilizando un compilador de C++ compatible. Asegúrese de vincular correctamente la biblioteca TensorFlow C API durante la compilación. Puede utilizar el siguiente comando de compilación como referencia:<br>
    <code>g++ -o programa programa.cpp -ltensorflow</code></li>
  </ol>
  <p>Asegúrese de ajustar el nombre del archivo fuente y el nombre del ejecutable según corresponda.</p>
  <h2>Uso</h2>
  <p>Antes de ejecutar el programa, asegúrese de realizar la siguiente configuración adicional en su entorno de desarrollo:</p>
  <ol>
    <li>Ejecute el siguiente comando en la terminal para configurar las variables de entorno necesarias:<br>
    <code>export LD_LIBRARY_PATH=/ruta/a/tensorflow/lib:$LD_LIBRARY_PATH</code></li>
  </ol>
  <p>Una vez que haya configurado correctamente el entorno, siga estos pasos para ejecutar el programa:</p>
  <ol>
    <li>Coloque el archivo del modelo entrenado ("saved_model.pb") en la ruta "model/" relativa al directorio donde se encuentra el programa.</li>
    <li>Ejecute el programa mediante el siguiente comando:<br>
    <code>./programa</code></li>
  </ol>
  <p>Tenga en cuenta que este programa puede presentar errores en la inicialización de los tensores o en la ejecución de la sesión.</p>
