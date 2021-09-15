#ifndef TOOLS_H_
#define TOOLS_H_
#include <iostream>
//PreCondicion: @answer es un char valido
//PosCondicion:	devuelve un @answer ingresado por el usuario
char Continue(char answer);

//PreCondicion: -
//PosCondicion:	devuelve true si el usuario desea continuar, o false si no
bool Continue();

//PreCondicion: -
//PosCondicion:	Devuelve un char ingresado por el usuario agregando un salto de linea en pantalla
char EnterChar();

//PreCondicion: -
//PosCondicion:	Devuelve una cadena de caracteres ingresada por el usuario agregando un salto de linea en pantalla
std::string EnterString();

//PreCondicion: -
//PosCondicion:
int EnterNumber();

//PreCondicion: -
//PosCondicion:	Limpia la pantalla
void CleanScreen();

#endif /* TOOLS_H_ */
