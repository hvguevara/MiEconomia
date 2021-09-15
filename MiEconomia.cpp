#include <iostream>
#include "MiEconomia.h"
#include "TxtParser.h"
#include "Tools.h"
#include "List.h"
#include "Statistic.h"
using namespace std;
char* nameTxt="MiEconomia.txt";

void Init(char* nameTxt);

void MiEconomia(){
	//InitBackUp();
	Init(nameTxt);
	FileTxt* file=Create(nameTxt);
	FileTxt* backUp=Create("BackUp.txt");
	List* txt=TxtParser(file);
	char answer=Options(answer);
	while(answer!='s'){
		if(answer=='1'){
			NewTxt(txt);
		}
		else if(answer=='2'){
			LoadTxt(txt);
		}
		else if(answer=='3'){
			ChangeTxt(txt);
		}
		else if(answer=='4'){
			ReadTxt(txt);
		}
		else if(answer=='5'){
			StatisticTxt(txt);
		}
		else{
			DestroyTxt(txt);
			txt=CreateList();
		}
		system("PAUSE");
		answer=Options(answer);
	}
	SaveTxt(file, txt);
	SaveTxt(backUp, txt);
}

void Init(char* nameTxt){
	if(!CheckExist(nameTxt)){
		CreateTxt(nameTxt);
	}
}

bool ExistsTxt(char* nameTxt){
	return 0;
}

char Options(char answer){
	cout<<"Ingrese el numero de la opcion deseada.."<<endl;
	cout<<"\t(1)-> Ingresar un nuevo archivo .txt"<<endl;
	cout<<"\t(2)-> Ingresar nuevos datos al archivo existente"<<endl;
	cout<<"\t(3)-> modificar datos del archivo existente"<<endl;
	cout<<"\t(4)-> mostrar todos los datos del archivo existente"<<endl;
	cout<<"\t(5)-> Mostrar estadisticas"<<endl;
	cout<<"\t(6)-> borrar todo"<<endl;
	cout<<"\t(s)-> Para salir"<<endl<<endl;
	cout<<"ingrese la opcion deseada: ";
	answer=EnterChar();
	if(answer!='1' and answer!='2' and answer!='3' and answer!='4' and answer!='5' and answer!='6' and answer!='s'){
		cout<<"La opcion ingresada no es valida"<<endl;
		answer=Options(answer);
	}
	return answer;
}

void NewTxt(List* txt){
	LoadNew(txt);
}

void ReadTxt(List* txt){
	Read(txt);
}

void LoadTxt(List* txt){
	Load(txt);
}

void ChangeTxt(List* txt){
	bool change=Change(txt);
	if(change==true){
		cout<<"modificacion exitosa"<<endl<<endl;
	}
	else{
		cout<<"no existe ese dato"<<endl<<endl;
	}
}

void StatisticTxt(List* txt){
	//ViewStatistic(GetStatistic(TxtParser(nameTxt)));
}

void SaveTxt(FileTxt* file,List* txt){
	Save(file,txt);
}

void DestroyTxt(List* txt){
	DestroyList(txt);
}

//BackUp
