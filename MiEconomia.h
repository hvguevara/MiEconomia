#ifndef MIECONOMIA_H_
#define MIECONOMIA_H_
#include "List.h"
#include "TxtParser.h"

//PreCondicion:-
//PosCondicion: Programa principal
void MiEconomia();

//PreCondicion: @answer es un cadena de caracteres valida
//PosCondicion:	devuelve @answer con una valor ingresado por el usuario, pero solo numero de 1 al 4 inclusive o s
char Options(char answer);

//PreCondicion: @txt es una estructura List valida
//PosCondicion: -
void NewTxt(List* txt);

//PreCondicion: @txt es una estructura List valida
//PosCondicion: Agrega tantos elementos nuevos a @txt como quiera el usuario
void LoadTxt(List* txt);

//PreCondicion: @txt es una estructura List valida
//PosCondicion: Busca dentro de @txt el elemento que ingrese el usuario por teclado y modifica por completo, de no existir, mostrara un mensaje y no hara ninguna modificacion en @txt
void ChangeTxt(List* txt);

//PreCondicion: @txt es una estructura List valida
//PosCondicion: cargar y muestra el contenido de @txt, si esta vacio, no muestra nada
void ReadTxt(List* txt);

//PreCondicion: @txt es una estructura List valida
//PosCondicion: Muestra por pantalla todas las estadisticas
void StatisticTxt(List* txt);

//PreCondicion: @file es una estructura valida no vacia y @txt es una estructura List valida
//PosCondicion: Guarda todos el contenido de @txt dentro de una archivo .txt llamado con el contenido de @nameTxt
void SaveTxt(FileTxt* file,List* txt);

//PreCondicion: @txt es una estructura List valida
//PosCondicion:	vacia y libera todos los recursos utilizados por @txt pero no elimina
void DestroyTxt(List* txt);

#endif /* MIECONOMIA_H_ */
