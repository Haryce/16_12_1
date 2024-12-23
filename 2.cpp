#include <iostream>
#include <cmath>
using namespace std;
double f(double x) {
    return x * x - 2;
}
void poldel(double a, double b, double g) {
    if (f(a) * f(b) >= 0) {
        cout << "Невозможно применить метод половинного деления." << endl;
        return;
    }
    double c;
    int N = 0; 
    while ((b - a) >= g) {
        c = (a + b) / 2;
        if (f(c) == 0.0) {
            break;
        }
        if (f(c) * f(a) < 0) {
            b = c;
        }
        else {
            a = c;
        }
        N++;
    }
    cout << "Приближенный корень: " << c << endl;
    cout << "Количество последовательных приближений N(h): " << N << endl;
}
int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Введите начало интервала: ";
    double a; 
    double b; 
    double h;
    cin >> a;
    cout << "Введите конец интервала: ";
    cin >> b;
    cout << "Введите h: ";
    cin >> h;
    poldel(a, b, h);
    return 0;
}