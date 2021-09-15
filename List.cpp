#include <iostream>
#include "List.h"
#include "String.h"
#include "Tools.h"
#include "Statistic.h"
using namespace std;

struct Node{
	int cost;
	string values;
	Node* next;
};

struct List{
	Node* first;
	Node* last;
	int total;
	int length;
	Statistic* statistic;
};

List* CreateList(){
	List* newList=new List;
	newList->first=NULL;
	newList->last=NULL;
	newList->total=0;
	newList->length=0;
	return newList;
}

Node* Create(){
	Node* newNode=new Node;
	newNode->cost=NULL;
	newNode->values="";
	newNode->next=NULL;
	return newNode;
}

Node* Create(string values, int cost){
	Node* newNode=Create();
	newNode->values=values;
	newNode->cost=cost;
	return newNode;
}

Node* EnterNode(){
	Node* newNode=Create();
	cout<<"tipo de gasto: ";
	newNode->values=EnterString();
	cout<<"costo: $";
	newNode->cost=EnterNumber();
	return newNode;
}

void Change(Node* modify){
	cout<<"Ingrese el nuevo tipo de dato: ";
	string newValues=EnterString();
	cout<<"ingrese el nuevo costo: ";
	int newCost=EnterNumber();
	modify->values=newValues;
	modify->cost=newCost;
}

void AddNode(List* list,Node* newNode){
	if(list->first==NULL){
		list->first=newNode;
		list->last=list->first;
	}
	else{
		list->last->next=newNode;
		list->last=newNode;
	}
	list->length++;
	list->total+=list->last->cost;
}

Node* SearchKey(List* list,string key){
	Node* search=list->first;
	while(search!=NULL){
		if (CompareString(search->values,key)==true){
			return search;
		}
		search=GetNext(search);
	}
	return NULL;
}

void EnterList(List* list){
	char answer='1';
	while(answer!='n'){
		AddNode(list, EnterNode());
		ViewList(list);
		answer=Continue(answer);
	}
	cout<<"Bye"<<endl;
}

void ViewList(List* list){
	if(list->length>0){
		Node* iterator=list->first;
		while(iterator!=NULL){
			cout<<iterator->values<<": $"<<iterator->cost<<endl;
			iterator=iterator->next;
		}
	}
}

void CopyList(List* origin, List* Destiny){
	List* aux=Destiny;
	Destiny=origin;
	DestroyList(aux);
}

//iterator

Node* GetFirst(List* list){
	return list->first;
}

Node* GetLast(List* list){
	return list->last;
}

Node* GetNext(Node* iterator){
	return iterator!=NULL ?  iterator->next :  NULL;
}

string GetValues(Node* iterator){
	return iterator->values;
}

int GetCost(Node* iterator){
	return iterator->cost;
}

Node* Search(List* list,string key){
	return SearchKey(list,key);
}

bool Change(List* list, string key){
	Node* modify=Search(list, key);
	if(modify!=NULL){
		Change(modify);
		return true;
	}
	return false;
}

void DestroyNode(Node* node){
	delete node;
}

void DestroyList(List* list){
	Node* iterator=list->first;
	Node* destroy=iterator;
	while(iterator!=NULL){
		iterator=iterator->next;
		delete destroy;
		destroy=iterator;
	}
	delete list;
}
