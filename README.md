# Docker exercise 1

This exercise tries to imitate some situation that you may experience when building through the source code with Docker.

## Build

Prebuild: 
You will need: git and build-essentials
 - On Debian based systems (Ubuntu, centos...):
> $ sudo apt-get -yqq update && sudo apt-get -yqq git build-essential

Building:
> $ git clone https://github.com/Naikelin/docker-exercise1  \
> $ cd docker-exercise1  \
> $ make

Run:

> On folder directory where you did make  \
> $ ./check 'someword'

If you built a docker:

> $ docker run -it 'name of container' /bin/sh

#Español:

Ejercicio: 
Usted deberá construir esta aplicación ejecutando el comando 'make' (make construye un ejecutable para un archivo c). Este ejecutable recibe un argumento como una palabra. La idea es que construya esto en un docker y construya una imagen de docker funcional. Recuerde que para construir una imagen en docker deberá ejecutar en la carpeta donde tenga el Dockerfile (utilizando ubuntu como base):

> docker build -t exercise .

Una vez se haya construido la imagen, deberá ejecutar el siguiente comando:
> docker run -it exercise /bin/sh -c "cd /docker-exercise1 && ./check $(echo "ZG9ja2VyIC12Cg==" | base64 -d | sh | tr -s ' ' | cut -d ' ' -f 1)"

La ruta donde usted haga el *cd /docker-exercise1*  dependerá directamente de dónde usted haya generado el ejecutable del make. En este caso, se realizó el make en */docker-exercise1* con respecto a la raíz.

Usted al ejecutar lo enterior, le dará como output un string. ¡Si usted ingresa ese string correctamente a canvas, tendrá la pregunta buena!
