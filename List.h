#ifndef LIST_H_
#define LIST_H_
#include <iostream>
using namespace std;

struct Node;

//PreCondicion: -
//PosCondicion:	Crea y devuelve una @Node vacio
Node* Create();

//PreCondicion: -
//PosCondicion:	Crea y devuelve un @Node con los valores pasados por parametros
Node* Create(string values, int cost);

//PreCondicion: -
//PosCondicion:	Crea y devuelve un @Node con datos ingresados por el usuario
Node* EnterNode();

//PreCondicion:
//PosCondicion:
void Change(Node* modify);

//PreCondicion: @node es un Node valido
//PosCondicion:	libera los recursos de memoria utilizados por @node
void DestroyNode(Node* node);


struct List;

//PreCondicion: -
//PosCondicion:	Crea y devuelve @List vacia
List* CreateList();

//PreCondicion: @list es una List valida y @newNode es un Node valido no vacio
//PosCondicion:	Agrega @newNode en @list
void AddNode(List* list,Node* newNode);

//PreCondicion: @list es una lista valida, @key es una cadena de caracteres valida
//PosCondicion:	devuelve el primer que contenga la @key como values
Node* SearchKey(List* list,string key);

//PreCondicion: @list es una List valida
//PosCondicion:	permite ingresar datos nuevos en @list por el usuario
void EnterList(List* list);

//PreCondicion: @list es una List valida
//PosCondicion:	muestra todo el contenido de @list
void ViewList(List* list);

//PreCondicion: -
//PosCondicion: -
void CopyList(List* origin, List* Destiny);

//PreCondicion: @list es una List valida
//PosCondicion:	libera los recursos de memoria utilizados por @list
void DestroyList(List* list);


//iterator//

//PreCondicion: @Node es una nodo valido
//PosCondicion:	devuelve el siguiente nodo, si @iterator es NULL, devuelve NULL
Node* GetNext(Node* iterator);

//PreCondicion: @list es una List valida
//PosCondicion:	devuelve el primer elemento de @list
Node* GetFirst(List* list);

//PreCondicion: @list es una List valida
//PosCondicion:	devuelve el ultimo elemento de @list
Node* GetLast(List* list);

//PreCondicion: @iterator es una Node valido
//PosCondicion:	devuelve el values de @iterator
string GetValues(Node* iterator);

//PreCondicion: @iterator es una Node valido
//PosCondicion:	devuelve el cost de @iterator
int GetCost(Node* iterator);

//PreCondicion: @list es una lista valida, @key es una cadena de caracteres valida
//PosCondicion:	devuelve el primer que contenga la @key como values
Node* Search(List* list,string key);

//PreCondicion:
//PosCondicion:
bool Change(List* list, string key);

#endif /* LIST_H_ */
