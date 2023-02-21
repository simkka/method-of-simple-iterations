#include <iostream>
#include <math.h>
using namespace std;
 
double function1(double x,double y){return sin(x+y)-1.2*x-0.1;} // задаємо наші функції
double function2(double x, double y){return x*x+y*y-1;}
double func11(double x, double y){return cos(x+y)-1.2;}// задаємо похідні (матрицю Якобі)
double func12(double x, double y){return cos(x+y);}
double func21(double x, double y){    return 2*x;}
double func22(double x, double y){    return 2*y;}
 
void ober_matr(double W[2][2])   // функція оберненої матриці
{
    double A, B;
    A = W[0][0]*W[1][1] - W[0][1]*W[1][0];
    B = W[0][0];
    W[0][0] = W[1][1]/A;
    W[1][1] = B/A;
    B = W[0][1];
    W[0][1] = -W[0][1]/A;
    W[1][0] = -W[1][0]/A;
}
 
void nuton(double x, double y)  // функція методу Ньютона
{
    int i = 0;
    double eps=0.00001;
    double W[2][2], dx = 0.0, dy = 0.0;
    cout <<"x = "<<x<<"    y = "<<y<<endl;
    do{
        W[0][0] = func11(x, y); // записуємо похідні у матрицю
        W[0][1] = func12(x, y);
        W[1][0] = func21(x, y);
        W[1][1] = func22(x, y);
        ober_matr(W);  // викликаємо функцію оберненої матриці
        dx = -W[0][0]*function1(x, y) + -W[0][1]*function2(x, y); // рахуємо dx dy
        dy = -W[1][0]*function1(x, y) + -W[1][1]*function2(x, y);
        cout <<"Ітерація №"<<i<<endl; // Виводимо інформацію
            cout <<"x = "<<x<<"    y = "<<y<<endl;
            cout <<"dx = "<<dx<<"    dy = "<<dy<<endl<<endl;
        x = x + dx;
        y = y + dy;
        i++;
        
    }while (fabs(dx)>eps || fabs(dy)>eps);
    
    cout <<"x = "<<x<<"    y = "<<y<<endl;  // виводимо остаточну відповідь
    cout << endl;
    double a=function1(x, y);  // перевірка - підставимо отмані значення у систему функцій
    double b=function2(x, y);
cout <<"Перевірка: F1 = "<<a<<"    F2 = "<<b<<endl;
}


int main()
{nuton(100, 100);}
