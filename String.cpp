#include <iostream>
using namespace std;

char* Create(int size){
	char* newWords= new char[size];
	return newWords;
}

void Destroy(char* words){
	delete[] words;
}

int SearchChar(string txt, char character){
	int answer=-1;
	for(int index=0;txt[index]!='\0';index++){
		if (txt[index]==character){
			answer=index;
		}
	}
	return answer;
}

string CutWords(string txt, int inicialPosition, char separator){
	string newWords="";
	int size=txt.size();
	while(txt[inicialPosition]!=separator and inicialPosition<size){
		newWords+=txt[inicialPosition];
		inicialPosition++;
	}
	return newWords;
}

bool CompareString(string words, string compare){
	int size=words.size();
	if(size==compare.size()){
		int index=0;
		while(index<size){
			if(words[index]!=compare[index]){
				return false;
			}
			index++;
		}
		return true;
	}
	else{
		return false;
	}
}

char* Copy(string origin){
	int size=origin.size();
	char* copy=Create(size);
	for(int index=0;index<size;index++){
		copy[index]=origin[index];
	}
	return copy;
}

char* Copy(string origin, char* destiny){
	int size=origin.size();
	for(int index=0;index<size;index++){
		destiny[index]=origin[index];
	}
	return destiny;
}

int ConvertToInt(char number){
	if(number=='0'){
		return 0;
	}
	else if(number=='1'){
		return 1;
	}
	else if(number=='2'){
		return 2;
	}
	else if(number=='3'){
		return 3;
	}
	else if(number=='4'){
		return 4;
	}
	else if(number=='5'){
		return 5;
	}
	else if(number=='6'){
		return 6;
	}
	else if(number=='7'){
		return 7;
	}
	else if(number=='8'){
		return 8;
	}
	else if(number=='9'){
		return 9;
	}
	else{
		return -1;
	}
}

int ConvertToInt(string words){
	int numer=0;
	int convert;
	for(int index=0; index<words.size(); index++){
		convert=ConvertToInt(words[index]);
		if(convert>-1){
			numer=(numer*10)+convert;
		}

		else{
			return numer;
		}
	}
	return numer;
}



