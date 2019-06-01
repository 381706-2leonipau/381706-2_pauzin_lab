cmake_minimum_required(VERSION 2.8) #Проверка версии CMake.

set(PROJECT_NAME 381706-2_pauzin_lab) #Создаем обычную локальную переменную с именем проекта
project(${PROJECT_NAME}) # Название проекта




set(datlink datlink)
set(datlistlib datlistlib)
set(liststacklib liststacklib)
set(arrlistlib arrlistlib)
set(exeptionlib exeptionlib)

set(texttree texttree)
set(texttreelib texttreelib)
set(texttreetest texttreetest)
set(plexlib plexlib)
set(plex plex)
set(plextest plextest)
set(tablelib tablelib)
set(tabletest tabletest)
set(sorttablelib sorttablelib)
set(sorttable sorttable)
set(sorttabletest sorttabletest)
set(treetablelib treetablelib)
set(treetable treetable)
set(treetabletest treetabletest)
set(hashtablelib hashtablelib)
set(hashtable hashtable)
set(hashtabletest hashtabletest)

set(scantablelib scantablelib)
set(scantable scantable)



set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) #Создается переменная CMAKE_CONFIGURATION_TYPES со значением "Debug;Release" и меткой/разделом Configs, переменная сохраниется в специальном файле доступном из всех файлов,
if(NOT CMAKE_BUILD_TYPE) # проверка имеющихся у компилятора вариантов сборки
  set(CMAKE_BUILD_TYPE Release) #Если нет то устанавливаем Release
endif()

include_directories(  ${CMAKE_CURRENT_SOURCE_DIR}/scantablelib ${CMAKE_CURRENT_SOURCE_DIR}/arrlistlib  ${CMAKE_CURRENT_SOURCE_DIR}/liststacklib ${CMAKE_CURRENT_SOURCE_DIR}/hashtablelib ${CMAKE_CURRENT_SOURCE_DIR}/treetablelib ${CMAKE_CURRENT_SOURCE_DIR}/sorttablelib ${CMAKE_CURRENT_SOURCE_DIR}/tablelib ${CMAKE_CURRENT_SOURCE_DIR}/plexlib ${CMAKE_CURRENT_SOURCE_DIR}/texttreelib  ${CMAKE_CURRENT_SOURCE_DIR}/datlistlib ${CMAKE_CURRENT_SOURCE_DIR}/datlink ${CMAKE_CURRENT_SOURCE_DIR}/exeptionlib ${CMAKE_CURRENT_SOURCE_DIR}/gtest)


add_subdirectory(gtest)


add_subdirectory (scantablelib)
add_subdirectory (scantable) 


add_subdirectory(exeptionlib)
add_subdirectory(datlistlib)
add_subdirectory(datlink)
add_subdirectory(liststacklib)
add_subdirectory(arrlistlib)

add_subdirectory(texttreelib)
add_subdirectory(texttreetest)
add_subdirectory(texttree)
add_subdirectory(plexlib)
add_subdirectory(plextest)
add_subdirectory(plex)
add_subdirectory(tablelib)
add_subdirectory(tabletest)
#add_subdirectory(table)
add_subdirectory(sorttablelib)
add_subdirectory(sorttabletest)
add_subdirectory(sorttable)
add_subdirectory(treetablelib)
add_subdirectory(treetabletest)
add_subdirectory(treetable)
add_subdirectory(hashtablelib)
add_subdirectory(hashtabletest)
add_subdirectory(hashtable)


#file(GLOB hdrs "*.h*") #Добавляем в переменную hdrs все файлы с расширением .h
#file(GLOB srcs "*.cpp") #Добавляем в переменную srcs все файлы с расширением .h


#add_executable(${PROJECT_NAME} ${srcs} ${hdrs}) #Создаем проект с именем из переменной ${PROJECT_NAME}, в него добавляются файлы из переменных ${srcs} и ${hdrs}

#add_subdirectory(lib1) #Собираем проект в поддиректории lib1
#target_link_libraries(${PROJECT_NAME} ${MyLib1}) #Подключаем к проекту с именем ${PROJECT_NAME} библиотеку с именем ${MyLib1}