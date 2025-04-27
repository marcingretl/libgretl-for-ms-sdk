@ECHO OFF

REM Note: please adjust path to VS installation

SET "STACK_PATH=..\stack"

cl.exe /EHsc .\gretlapi.cpp /Fe:gretlapi-cl-cpp.exe /Fo:gretlapi-cl-cpp.obj^
 /I%STACK_PATH%\include /I%STACK_PATH%\include\glib-2.0 /I%STACK_PATH%\lib\glib-2.0\include^
 /I"c:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\VC"^
 /link /LIBPATH:"%STACK_PATH%\lib"^
 gretl-1.0.lib xml2.lib fftw3.lib glib-2.0.lib intl.lib gobject-2.0.lib
 