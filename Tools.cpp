#include <iostream>
#include "Tools.h"

using namespace std;

char Continue(char answer){
	cout<<"desea cargar mas?(s para si, n para salir): ";
	answer=EnterChar();
	return answer;
}

bool Continue(){
	cout<<"desea cargar mas?(cualquier tecla para continuar, 'n' para salir): ";
	char answer=EnterChar();
	return answer=='n' ? false : true;
}

char EnterChar(){
	char newChar;
	cin>>newChar;
	cin.clear();
	cin.ignore(1024, '\n');
	cout<<endl;
	return newChar;
}

string EnterString(){
	string words;
	cin>>words;
	cin.clear();
	cin.ignore(1024, '\n');
	return words;
}

int EnterNumber(){
	int number;
	cin>>number;
	cin.clear();
	cin.ignore(1024, '\n');
	cout<<endl;
	return number;
}

void CleanScreen(){

}

