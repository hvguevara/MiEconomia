#include "Statistic.h"
#include "List.h"

struct Statistic{
	int minimum;
	int maximum;
	int total;
	float mean;
	int count;
};

Statistic* CreateStatistic(){
	Statistic* newStatistic= new Statistic;
	newStatistic->minimum=NULL;
	newStatistic->maximum=NULL;
	newStatistic->total=0;
	newStatistic->count=0;
	newStatistic->mean=NULL;
	return newStatistic;
}

void ControlStatistic(Statistic* statistic, int data){
	if(statistic->count!=0){
		statistic->minimum=IsLess(statistic->minimum,data);
		statistic->maximum=IsMajor(statistic->maximum,data);
		statistic->total=Add(statistic->total,data);
		statistic->count++;
		statistic->mean=Division(statistic->total,statistic->count);
	}
	else{
		statistic->minimum=statistic->maximum=statistic->total=statistic->mean=data;
		statistic->count=1;
	}
}

int IsLess(int a, int b){
	return a<b ? a : b;
}

int IsMajor(int a, int b){
	return a>b ? a : b;
}

int Add(int a, int b){
	return a+b;
}

float Division(int total, int count){
	return (total*1.0)/count;
}



//iterator

int GetMinimum(Statistic* statistic){
	return statistic->minimum;
}

int GetMaximum(Statistic* statistic){
	return statistic->maximum;
}

int GetTotal(Statistic* statistic){
	return statistic->total;
}

int GetMean(Statistic* statistic){
	return statistic->mean;
}

int GetCount(Statistic* statistic){
	return statistic->count;
}

void ViewStatistic(Statistic* statistic){
	cout<<"***ESTADISTICAS***"<<endl;
	cout<<"\tCosto menor= $"<<GetMinimum(statistic)<<endl;
	cout<<"\tCosto mayor= $"<<GetMaximum(statistic)<<endl;
	cout<<"\tCosto total= $"<<GetTotal(statistic)<<endl;
	cout<<"\tCosto promedio= $"<<GetMean(statistic)<<endl;
	cout<<"\tCantidad de movimientos = "<<GetCount(statistic)<<endl<<endl;
}

