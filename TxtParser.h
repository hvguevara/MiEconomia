#ifndef TXTPARSER_H_
#define TXTPARSER_H_
#include "List.h"
#include "Statistic.h"
//El Archivo txt se generar en la carpeta del proyecto

struct FileTxt;

//PreCondicion: -
//PosCondicion: crea y devuelve una estructura FileTxt vacia
FileTxt* CreateEmtpy();

//PreCondicion: @nameTxt es una cadena de caracteres valida, corresponde al nombre de un archivo .txt
//PosCondicion: crea y devuelve una estructura FileTxt con el elemento @nameTxt completado
FileTxt* Create(char* nameTxt);

//.txt

//PreCondicion: @nameTxt es una cadena de caracteres valida, corresponde al nombre de un archivo .txt
//PosCondicion: Crea una archivo .txt vacio donde se aloja el proyecto con el nombre dentro de @nameTxt
void CreateTxt(char* nameTxt);

//PreCondicion: @txt es un struct valido y @newData es una node valido
//PosCondicion: guarda el contenido de @newData dentro de @txt dentro de archivo .txt, si @newData esta vacio, no hace nada
void Enter(FileTxt* txt, Node* newData);

//PreCondicion: @nameTxt es una cadena de caracteres valida, corresponde al nombre de un archivo .txt
//PosCondicion: Devuelve true si existe un archivo .txt llamado @nameTxt dentro de la carpeta del proyecto, de lo contrario devuelve false
bool CheckExist(char* nameTxt);

//PreCondicion: @file es un struc valido
//PosCondicion: si existe, parsea el archivo .txt alojado en la carpeta del proyecto llamado @nameTxt devolviendo un struc List*, si no existe, devuelve una lista vacia
List* TxtParser(FileTxt* file);

//PreCondicion: @file es un struc valido
//PosCondicion: se permite que el usuario ingrese la cantidad de datos nuevos en @txt de forma manual que desee
void Write(FileTxt* file);

//PreCondicion: @txt es una struct lista valida
//PosCondicion: permite cargar en @txt tantos datos como el usuario desee
void Load(List* txt);

//PreCondicion: @txt es una struct lista valida
//PosCondicion: si @txt esta vaciaa, permite cargar en @txt tantos datos como el usuario desee, sino mostrara un mensaje en pantalla y no hara nada mas
void LoadNew(List* txt);

//PreCondicion: @txt es una struct lista valida
//PosCondicion: Lee y muestra por pantalla el archivo .txt llamado @nameTxt
void Read(List* txt);

//PreCondicion: @txt es una struct lista valida
//PosCondicion: si existe, Permite modificar un dato que el usuario desee dentro de @txt , si no existe, mostrara un mensaje y no hará nada mas
bool Change(List* txt);

//PreCondicion: @txt es una struct lista valida
//PosCondicion: si existe un archivo .txt llamado dentro de @txt, true, sino false
bool CheckExist(FileTxt* txt);

//PreCondicion: @file es un struc valido No Vacio, @txt es una struct lista valida
//PosCondicion: Guarda el contenido de @txt dentro del archivo .txt alojado en la carpeta del proyecto representado por @file
void Save(FileTxt* file, List* txt);

//iterator

//PreCondicion: @file es un struc valido
//PosCondicion: devuelve la List* contenida en @file
List* GetList(FileTxt* file);

//PreCondicion:
//PosCondicion:
Statistic* GetStatistic(FileTxt* txt);

//BackUp

//PreCondicion: -
//PosCondicion: -
bool CompareTxt(FileTxt* txt, FileTxt* compare);

//PreCondicion: -
//PosCondicion: -
void SaveBackUp(FileTxt* txt);


#endif /* TXTPARSER_H_ */
