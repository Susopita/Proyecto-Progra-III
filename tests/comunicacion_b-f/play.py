import subprocess
import multiprocessing
import platform
import os

"""
Este script ejecuta automaticamente el backend y el frontend de la aplicación.

Si quieres visualizar la ejecucacion en tiempo real, puedes ejecutar los scripts de forma manual en dos terminales individuales en el siguiente orden:

-> Terminal 1: (Backend)

    - Navegar al directorio raíz del proyecto
    - Compilar el Backend en caso de que no lo hayas hecho
    - Ejecutar el siguiente comando para compilar:

        g++ -std=c++20 -Ibackend/include -Ibackend/SoapComm tests/comunicacion_b-f/test_backend.cpp backend/src/protoserver.cpp backend/SoapComm/sopasockets.cpp backend/src/mensajes.pb.cc backend/src/search_algorithm.cpp -L/usr/local/lib -lprotobuf -labsl_base -labsl_strings -labsl_time -labsl_log_internal_check_op -labsl_log_internal_conditions -labsl_log_internal_fnmatch -labsl_log_internal_format -labsl_log_internal_globals -labsl_log_internal_log_sink_set -labsl_log_internal_message -labsl_log_internal_nullguard -labsl_log_internal_proto -pthread -o tests/comunicacion_b-f/backend

    - Ejecutar el backend con el siguiente comando:
    
            ./tests/comunicacion_b-f/backend

-> Terminal 2: (Frontend)

    - Navegar al directorio raíz del proyecto
    - Primero ejecutar el backend
    - Ejecutar el siguiente comando para ejecutar el frontend:

            python tests/comunicacion_b-f/test_frontend.py
"""

def ejecutar_comando(comando, nombre_proceso="comando"):
    proceso = subprocess.Popen(comando, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    stdout, stderr = proceso.communicate()
    print('-'*20)
    print(f"Salida de {nombre_proceso}:\n{stdout}")
    print(f"Errores de {nombre_proceso}:\n{stderr}")
    print('-'*20)

    if proceso.returncode == 0:
        return True
    else: 
        return False

def main():
    ruta_actual = os.path.abspath(os.path.join(__file__, '..', '..', '..'))
    sistema = platform.system()
    backend_ejecutable = 'backend.exe' if sistema == 'Windows' else 'backend'
    if not os.path.exists(f'{ruta_actual}/tests/comunicacion_b-f/{backend_ejecutable}'):
        
        comandoCompilacionBackend = f'cd {ruta_actual} && g++ -std=c++20 -Ibackend/include -Ibackend/SoapComm tests/comunicacion_b-f/test_backend.cpp backend/src/protoserver.cpp backend/SoapComm/sopasockets.cpp backend/src/mensajes.pb.cc backend/src/search_algorithm.cpp -L/usr/local/lib -lprotobuf -labsl_base -labsl_strings -labsl_time -labsl_log_internal_check_op -labsl_log_internal_conditions -labsl_log_internal_fnmatch -labsl_log_internal_format -labsl_log_internal_globals -labsl_log_internal_log_sink_set -labsl_log_internal_message -labsl_log_internal_nullguard -labsl_log_internal_proto -pthread -o tests/comunicacion_b-f/backend'

        sinError = ejecutar_comando(comandoCompilacionBackend, "compilacion backend")
    
        if not sinError:
            print("Error al compilar el backend")
            return
        
    # Comandos que quieres ejecutar
    comandoBackend = f'{ruta_actual}/tests/comunicacion_b-f/{backend_ejecutable}'
    comandoFronted = f'python {ruta_actual}/tests/comunicacion_b-f/test_frontend.py'

    # Crear procesos para ejecutar los comandos simultáneamente
    proceso1 = multiprocessing.Process(target=ejecutar_comando, args=(comandoBackend, "Backend"))
    proceso2 = multiprocessing.Process(target=ejecutar_comando, args=(comandoFronted, "Frontend"))

    # Iniciar los procesos
    proceso1.start()
    proceso2.start()

    # Esperar a que ambos procesos terminen
    proceso2.join()
    proceso1.join()

if __name__ == '__main__':
    main()
