#ifndef STATISTIC_H_
#define STATISTIC_H_
struct Statistic;

//PreCondicion: -
//PosCondicion: Crea y devuelve un nuevo @Statistic vacio
Statistic* CreateStatistic();

//PreCondicion: @statistic es una struct valido y @data es un entero valido
//PosCondicion: actualiza los valores de @statistic comparandolos y/o sumando con data
void ControlStatistic(Statistic* statistic, int data);

//PreCondicion: @a y @b son enteros validos
//PosCondicion: devuelve el numero menor, si son iguales, devuelve @b
int IsLess(int a, int b);

//PreCondicion: @a y @b son enteros validos
//PosCondicion: devuelve el numero mayor, si son iguales, devuelve @b
int IsMajor(int a, int b);

//PreCondicion: @a y @b son enteros validos
//PosCondicion: devuelve la suma de los numeros
int Add(int a, int b);

//PreCondicion: @total y @count son enteros validos
//PosCondicion: devuelve el flotante resultante entre @total y @count
float Division(int total, int count);

//iterator

//PreCondicion: @statistic es una struct valido
//PosCondicion: devuelve el valor de @minimun
int GetMinimum(Statistic* statistic);

//PreCondicion: @statistic es una struct valido
//PosCondicion: devuelve el valor de @maximun
int GetMaximum(Statistic* statistic);

//PreCondicion: @statistic es una struct valido
//PosCondicion: devuelve el valor de @total
int GetTotal(Statistic* statistic);

//PreCondicion: @statistic es una struct valido
//PosCondicion: devuelve el valor de @mean
int GetMean(Statistic* statistic);

//PreCondicion: @statistic es una struct valido
//PosCondicion: devuelve el valor de @count
int GetCount(Statistic* statistic);

//PreCondicion: @statistic es una struct valido
//PosCondicion: Muestra todas las estadisticas
void ViewStatistic(Statistic* statistic);

#endif /* STATISTIC_H_ */
