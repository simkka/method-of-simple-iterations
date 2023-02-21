#include <iostream>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void iteration(double x0,double y0,double eps) {  // напишемо функцію метому простих ітерацій
double x,y,x1 = 0.0,y1 = 0.0;
    
int i=0;
    
cout <<"x0 = "<<x0<<"    y0 = "<<y0<<endl<<endl;
x=0.5-cos(y1-2);
y=sin(x1+2)-1.5;
cout <<"x = "<<x<<"    y = "<<y<<endl<<endl; // обчилюємо та виводимо значення функції в початковому наближені
    
double dx,dy; // задаємо дельта х та дельта у
dx=x-x0;
dy=y-y0;
cout <<"dx = "<<dx<<"    dy = "<<dy<<endl<<endl;

 
while (fabs(dx)>eps || fabs(dy)>eps) { // задаємо цикл, умова зупинки - модулі dx та dy <= eps
x1=x;
y1=y;
x=0.5-cos(y1-2);   // рахуємо х та у
y=sin(x1+2)-1.5;
dx=x-x1;   // рахуємо дельта х та дельта у
dy=y-y1;
cout <<"Ітерація №"<<i<<endl; // Виводимо інформацію
    cout <<"x = "<<x<<"    y = "<<y<<endl;
    cout <<"dx = "<<dx<<"    dy = "<<dy<<endl<<endl;
i++;}
    
cout <<"x = "<<x<<"    y = "<<y<<endl;  // виводимо остаточну відповідь

    double a=sin(x+2)-y-1.5;  // перевірка - підставимо отмані значення у систему функцій
    double b=x+cos(y-2)-0.5;
cout <<"Перевірка: F1 = "<<a<<"    F2 = "<<b<<endl;
}

int main(){
iteration(10000, 10000, 0.00001); }
