#include <iostream>
#include <fstream>
#include "MiEconomia.h"
#include "Tools.h"
#include "List.h"
#include "TxtParser.h"
#include "String.h"
#include "Statistic.h"
using namespace std;

char separator='=';

struct FileTxt{
	char* nameTxt;
	ofstream newTxt;
	ifstream loadTxt;
	List* txtParser;
	Statistic* statistic;
};

FileTxt* CreateEmtpy(){
	FileTxt* newTxt= new FileTxt;
	newTxt->nameTxt=NULL;
	newTxt->txtParser=NULL;
	newTxt->statistic=NULL;
	return newTxt;
}

FileTxt* Create(char* nameTxt){
	FileTxt* newTxt= CreateEmtpy();
	newTxt->nameTxt=nameTxt;
	newTxt->txtParser=CreateList();
	newTxt->statistic=CreateStatistic();
	return newTxt;
}

//.txt

void CreateTxt(char* nameTxt){
	ofstream newTxt;
	newTxt.open(nameTxt);
	newTxt.close();
}

void Enter(FileTxt* txt, Node* newData){
	if(newData!=NULL){
		txt->newTxt<<GetValues(newData);
		txt->newTxt<<"=";
		txt->newTxt<<GetCost(newData);
		txt->newTxt<<"\n";
	}
}

bool CheckExist(char* nameTxt){
	ifstream read;
	read.open(nameTxt);
	if(!read.fail()){
		read.close();
		return true;
	}
	else{
		return false;
	}
}

List* TxtParser(FileTxt* file){
	if(CheckExist(file->nameTxt)){
		string line="a";
		file->loadTxt.open(file->nameTxt);
		getline(file->loadTxt, line);
		while(line!=""){
			string values=CutWords(line,0,separator);
			int cost=ConvertToInt(CutWords(line,SearchChar(line,separator)+1));
			AddNode(file->txtParser,Create(values,cost));
			ControlStatistic(file->statistic,cost);
			getline(file->loadTxt, line);
		}
		file->loadTxt.close();
	}
	return file->txtParser;
}

void Write(FileTxt* file){
	bool answer=true;
	while(answer!=false){
		Node* iterator=EnterNode();
		file->newTxt<<GetValues(iterator);
		file->newTxt<<"=";
		file->newTxt<<GetCost(iterator);
		file->newTxt<<"\n";
		DestroyNode(iterator);
		answer=Continue();
	}
}

void Load(List* txt){
	bool answer=true;
	while(answer){
		AddNode(txt,EnterNode());
		answer=Continue();
	}
}

void LoadNew(List* txt){
	if(GetFirst(txt)==NULL){
		Load(txt);
	}
	else{
		cout<<"Ya existe un archivo. volviendo al menu anterior..."<<endl<<endl;
	}
}

void Read(List* txt){
	ViewList(txt);
}


bool Change(List* txt){
	cout<<"Escriba el dato que quiera modificar: ";
	string answer=EnterString();
	bool exists=Change(txt,answer);
	return exists;
}

bool CheckExist(FileTxt* txt){
	txt->loadTxt.open(txt->nameTxt);
	bool answer=txt->loadTxt.fail();
	txt->loadTxt.close();
	return !answer;
}

List* GetList(FileTxt* txt){
	return txt->txtParser;
}

Statistic* GetStatistic(FileTxt* txt){
	return txt->statistic;
}

void Save(FileTxt* file, List* txt){
	file->newTxt.open(file->nameTxt);
	Node* iterator=GetFirst(txt);
	while(iterator!=NULL){
		Enter(file,iterator);
		iterator=GetNext(iterator);
	}
	file->newTxt.close();
}

//BackUp

char* nameBackUp="BackUp.txt";
FileTxt* BackUp=Create(nameBackUp);

bool CompareTxt(FileTxt* txt, FileTxt* compare){
	if(CheckExist(txt->nameTxt) and CheckExist(compare->nameTxt)){
		string lineTxt,lineCompare;
		txt->loadTxt.open(txt->nameTxt);
		compare->loadTxt.open(compare->nameTxt);
		do{
			getline(txt->loadTxt,lineTxt);
			getline(compare->loadTxt,lineCompare);
			if(!CompareString(lineTxt,lineCompare)){
				return false;
			}
		}
		while(lineTxt!="" and lineCompare!="");
		return true;
	}
	else{
		return false;
	}
}

void SaveBackUp(FileTxt* txt){
	//FileTxt* txt=Create(nameTxt);
	List* txtParser=GetList(txt);
	if(txtParser!=NULL){
		CopyList(txtParser,GetList(BackUp));
		//Save(BackUp);
	}
}
