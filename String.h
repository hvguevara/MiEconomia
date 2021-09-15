#ifndef STRING_H_
#define STRING_H_

//PreCondicion: -
//PosCondicion: -
char* Create(int size);

//PreCondicion: -
//PosCondicion: -
void Destroy(char* words);

//PreCondicion: @txt es una cadena de caracteres valida
//PosCondicion: devuelve la posicion donde se encuenta @separator, de no existir, devuelve -1
int SearchChar(string txt, char character);

//PreCondicion: @txt es una cadena de caracteres valida, @inicialPosition es un posicion valida en @txt y @separator es un caracter valido
//PosCondicion: devuelve una copia de @txt desde @ inicialPosition hasta @separador o hasta que encuentre '\0'
string CutWords(string txt, int inicialPosition, char separator='\0');

//PreCondicion: -
//PosCondicion: -
bool CompareString(string words, string compare);

//PreCondicion: -
//PosCondicion: -
char* Copy(string origin);

//PreCondicion: -
//PosCondicion: -
char* Copy(string origin, char* destiny);

//PreCondicion: @words es una cadena de caracteres valida, correpondiente a un numero
//PosCondicion: el numero equivalente a words, de tener alguna caracter distinto a un numero, devolvera el numero generado hasta que se corte
int ConvertToInt(string words);

#endif /* STRING_H_ */
