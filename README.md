# gccJobTest


Algunos elementos se tuvieron que borrar debido a la gran cantidad de espacio que ocupan individualmente, pero hasta donde yo tenía el sistema no es necesario su uso principalmente con wxWidgets y boost.

## Desempaquetado de la app:

So

## Si es necesario compilar sus dependencias:

* wxWidgets:
  * en wxWidgets-3.0.4 ejecutar configure: $ ./configure --disable-shared --enable-unicode --enable-static
  * luejo ejecutar make: "$ make"
* sqlite3:
  * en el directorio sqlite3 ejecutar: $ ./configure  --enable-static
  * luejo ejecutar make: "$ make"
* zlib:
  * los mismos pasos que sqlite3 pero en el directorio zlib-1.2.11
  * ir a la carpeta zlib-1.2.11/contrib/minizip y ejecutar "$ make"
* boost:
  * ir a la carpeta boost_1_66_0 y ejecutar: "$ ./boostrap.sh && ./b2 link=static"

## Compilado:

* Lastimosamente no pude realizar el compilado estático de todo el sistema (es solo añadir la bandera "-static" a la compilación), sin embargo, puede tener 2 opciones:

  1. Descargar codeblocks y abrir directamente el proyecto que ya contiene las banderas, ó:
  2. ejecutar las siguientes sentencias en el directorio raíz del proyecto (si quiere intentar compilarlo estaticamente que no es mucho tiempo por favor añadir la bandera "-static" en la última sentencia de compilación):

```
g++ -Wall -std=c++11 -fexceptions -O2 -std=c++11 -I/home/jjalvarezl/Proyectos/jobTestCodeBlocks/wxWidgets-3.0.4/lib/wx/include/gtk2-unicode-static-3.0 -I/home/jjalvarezl/Proyectos/jobTestCodeBlocks/wxWidgets-3.0.4/include -D_FILE_OFFSET_BITS=64 -D__WXGTK__ -pthread -std=c++11 -IwxWidgets-3.0.4/include -lwxWidgets-3.0.4/lib -IwxWidgets-3.0.4/lib/wx/include/gtk2-unicode-3.0 -Izlib-1.2.11/ -Izlib-1.2.11/contrib/minizip/ -Iboost_1_66_0 -lsqlite3 -Iinclude -c /home/jjalvarezl/Proyectos/jobTestCodeBlocks/Main.cpp -o obj/Release/Main.o

g++ -Wall -std=c++11 -fexceptions -O2 -std=c++11 -I/home/jjalvarezl/Proyectos/jobTestCodeBlocks/wxWidgets-3.0.4/lib/wx/include/gtk2-unicode-static-3.0 -I/home/jjalvarezl/Proyectos/jobTestCodeBlocks/wxWidgets-3.0.4/include -D_FILE_OFFSET_BITS=64 -D__WXGTK__ -pthread -std=c++11 -IwxWidgets-3.0.4/include -lwxWidgets-3.0.4/lib -IwxWidgets-3.0.4/lib/wx/include/gtk2-unicode-3.0 -Izlib-1.2.11/ -Izlib-1.2.11/contrib/minizip/ -Iboost_1_66_0 -lsqlite3 -Iinclude -c /home/jjalvarezl/Proyectos/jobTestCodeBlocks/src/FileMetadata.cpp -o obj/Release/src/FileMetadata.o

g++ -Wall -std=c++11 -fexceptions -O2 -std=c++11 -I/home/jjalvarezl/Proyectos/jobTestCodeBlocks/wxWidgets-3.0.4/lib/wx/include/gtk2-unicode-static-3.0 -I/home/jjalvarezl/Proyectos/jobTestCodeBlocks/wxWidgets-3.0.4/include -D_FILE_OFFSET_BITS=64 -D__WXGTK__ -pthread -std=c++11 -IwxWidgets-3.0.4/include -lwxWidgets-3.0.4/lib -IwxWidgets-3.0.4/lib/wx/include/gtk2-unicode-3.0 -Izlib-1.2.11/ -Izlib-1.2.11/contrib/minizip/ -Iboost_1_66_0 -lsqlite3 -Iinclude -c /home/jjalvarezl/Proyectos/jobTestCodeBlocks/src/LogLineMetadata.cpp -o obj/Release/src/LogLineMetadata.o

g++ -Wall -std=c++11 -fexceptions -O2 -std=c++11 -I/home/jjalvarezl/Proyectos/jobTestCodeBlocks/wxWidgets-3.0.4/lib/wx/include/gtk2-unicode-static-3.0 -I/home/jjalvarezl/Proyectos/jobTestCodeBlocks/wxWidgets-3.0.4/include -D_FILE_OFFSET_BITS=64 -D__WXGTK__ -pthread -std=c++11 -IwxWidgets-3.0.4/include -lwxWidgets-3.0.4/lib -IwxWidgets-3.0.4/lib/wx/include/gtk2-unicode-3.0 -Izlib-1.2.11/ -Izlib-1.2.11/contrib/minizip/ -Iboost_1_66_0 -lsqlite3 -Iinclude -c /home/jjalvarezl/Proyectos/jobTestCodeBlocks/src/LogMetadata.cpp -o obj/Release/src/LogMetadata.o

g++ -Wall -std=c++11 -fexceptions -O2 -std=c++11 -I/home/jjalvarezl/Proyectos/jobTestCodeBlocks/wxWidgets-3.0.4/lib/wx/include/gtk2-unicode-static-3.0 -I/home/jjalvarezl/Proyectos/jobTestCodeBlocks/wxWidgets-3.0.4/include -D_FILE_OFFSET_BITS=64 -D__WXGTK__ -pthread -std=c++11 -IwxWidgets-3.0.4/include -lwxWidgets-3.0.4/lib -IwxWidgets-3.0.4/lib/wx/include/gtk2-unicode-3.0 -Izlib-1.2.11/ -Izlib-1.2.11/contrib/minizip/ -Iboost_1_66_0 -lsqlite3 -Iinclude -c /home/jjalvarezl/Proyectos/jobTestCodeBlocks/src/MainView.cpp -o obj/Release/src/MainView.o
g++ -Wall -std=c++11 -fexceptions -O2 -std=c++11 -I/home/jjalvarezl/Proyectos/jobTestCodeBlocks/wxWidgets-3.0.4/lib/wx/include/gtk2-unicode-static-3.0 -I/home/jjalvarezl/Proyectos/jobTestCodeBlocks/wxWidgets-3.0.4/include -D_FILE_OFFSET_BITS=64 -D__WXGTK__ -pthread -std=c++11 -IwxWidgets-3.0.4/include -lwxWidgets-3.0.4/lib -IwxWidgets-3.0.4/lib/wx/include/gtk2-unicode-3.0 -Izlib-1.2.11/ -Izlib-1.2.11/contrib/minizip/ -Iboost_1_66_0 -lsqlite3 -Iinclude -c /home/jjalvarezl/Proyectos/jobTestCodeBlocks/src/SqliteManagement.cpp -o obj/Release/src/SqliteManagement.o

g++ -Wall -std=c++11 -fexceptions -O2 -std=c++11 -I/home/jjalvarezl/Proyectos/jobTestCodeBlocks/wxWidgets-3.0.4/lib/wx/include/gtk2-unicode-static-3.0 -I/home/jjalvarezl/Proyectos/jobTestCodeBlocks/wxWidgets-3.0.4/include -D_FILE_OFFSET_BITS=64 -D__WXGTK__ -pthread -std=c++11 -IwxWidgets-3.0.4/include -lwxWidgets-3.0.4/lib -IwxWidgets-3.0.4/lib/wx/include/gtk2-unicode-3.0 -Izlib-1.2.11/ -Izlib-1.2.11/contrib/minizip/ -Iboost_1_66_0 -lsqlite3 -Iinclude -c /home/jjalvarezl/Proyectos/jobTestCodeBlocks/src/ZlibManagement.cpp -o obj/Release/src/ZlibManagement.o

g++  -o bin/Release/jobTestCodeBlocks obj/Release/Main.o obj/Release/src/FileMetadata.o obj/Release/src/LogLineMetadata.o obj/Release/src/LogMetadata.o obj/Release/src/MainView.o obj/Release/src/SqliteManagement.o obj/Release/src/ZlibManagement.o  -s -L/home/jjalvarezl/Proyectos/jobTestCodeBlocks/wxWidgets-3.0.4/lib -pthread   /home/jjalvarezl/Proyectos/jobTestCodeBlocks/wxWidgets-3.0.4/lib/libwx_gtk2u_xrc-3.0.a /home/jjalvarezl/Proyectos/jobTestCodeBlocks/wxWidgets-3.0.4/lib/libwx_gtk2u_qa-3.0.a /home/jjalvarezl/Proyectos/jobTestCodeBlocks/wxWidgets-3.0.4/lib/libwx_baseu_net-3.0.a /home/jjalvarezl/Proyectos/jobTestCodeBlocks/wxWidgets-3.0.4/lib/libwx_gtk2u_html-3.0.a /home/jjalvarezl/Proyectos/jobTestCodeBlocks/wxWidgets-3.0.4/lib/libwx_gtk2u_adv-3.0.a /home/jjalvarezl/Proyectos/jobTestCodeBlocks/wxWidgets-3.0.4/lib/libwx_gtk2u_core-3.0.a /home/jjalvarezl/Proyectos/jobTestCodeBlocks/wxWidgets-3.0.4/lib/libwx_baseu_xml-3.0.a /home/jjalvarezl/Proyectos/jobTestCodeBlocks/wxWidgets-3.0.4/lib/libwx_baseu-3.0.a -lgthread-2.0 -pthread -lX11 -lXxf86vm -lSM -lgtk-x11-2.0 -lgdk-x11-2.0 -lpangocairo-1.0 -latk-1.0 -lcairo -lgdk_pixbuf-2.0 -lgio-2.0 -lpangoft2-1.0 -lpango-1.0 -lgobject-2.0 -lglib-2.0 -lfontconfig -lfreetype -lpng -ljpeg -lexpat -lwxregexu-3.0 -lwxtiff-3.0 -lz -ldl -lm  -lz -lboost_filesystem -lboost_system -ldl  zlib-1.2.11/libz.a zlib-1.2.11/contrib/minizip/ioapi.o zlib-1.2.11/contrib/minizip/unzip.o zlib-1.2.11/contrib/minizip/zip.o sqlite3/.libs/libsqlite3.a
```

Dependencias adicionales que necesita el compilado estatico de wxWidgets (instalandolo desde apt):

-lgthread-2.0
-pthread
-lX11
-lXxf86vm
-lSM
-lgtk-x11-2.0
-lgdk-x11-2.0
-lpangocairo-1.0
-latk-1.0
-lcairo
-lgdk_pixbuf-2.0
-lgio-2.0
-lpangoft2-1.0
-lpango-1.0
-lgobject-2.0
-lglib-2.0
-lfontconfig
-lfreetype
-lpng
-ljpeg
-lexpat
-lwxregexu-3.0
-lwxtiff-3.0

## Banderas usadas en la compilación:

### Linkeo de directorios usados:

```
-IwxWidgets-3.0.4/include
-lwxWidgets-3.0.4/lib
-IwxWidgets-3.0.4/lib/wx/include/gtk2-unicode-3.0
-Izlib-1.2.11/
-Izlib-1.2.11/contrib/minizip/
-Iboost_1_66_0
-lsqlite3
```
### Opciones de ejecución:

```
-lz
-lboost_filesystem
-lboost_system
-ldl
```

### Linkeo de rutas de las librerías .a usadas:
```
zlib-1.2.11/libz.a
zlib-1.2.11/contrib/minizip/ioapi.o
zlib-1.2.11/contrib/minizip/unzip.o
zlib-1.2.11/contrib/minizip/zip.o
sqlite3/.libs/libsqlite3.a
```

### Obtención de las librerías con wx-config:
```
`./wxWidgets-3.0.4/wx-config --libs`
`./wxWidgets-3.0.4/wx-config --cxxflags`
```


## Restricciones:

* Los logs deben tener la extension .log o la extension .log.x donde x puede ser cualquier cadena *sin puntos*.
* Al no poderse impŕimir en wxWidgets, por cada archivo de log se imprime el numero de coincidencias en un archivo con el mismo nombre del archivo log en la carpeta ./logAnalisys.
* Dado a que hay dos archivos .dat para diferentes propositos dentro de la prueba, se ha dejado con nombre a Agent9.3.2.dat como nombre fijo de archivo para para procesamiento con sqlite y a smbios.dat como nombre fijo de archivo para SMBios.
* Debido a que la compilación de las librerías es estática es necesario que se ubique el proyecto en "/home/jjalvarezl/Proyectos/jobTestCodeBlocks/"
