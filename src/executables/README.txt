In diesen Ordner k�nnen Executables eingef�gt werden.
Dazu muss im Ordner des Executables eine CMakeLists.txt Datei mit dem folgendem Inhalt erstellt werden:

cmake_minimum_required(VERSION 2.8)
include(${CMAKE_MODULE_PATH}/DefaultExecutable.cmake)

Diese kann auch aus einem der anderen Executable-Ordner kopiert werden