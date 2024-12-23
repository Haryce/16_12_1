#include <iostream>
#include <cmath>
using namespace std;
double f(double x) {
    return x * x - 2;
}
double poldel(double a, double b, double g) { //функция половинного деления
    double c;
    while (b - a > g) {
        c = (a + b) / 2;
        if (f(c) == 0) {
            return c;
        }
        else if (f(c) * f(a) < 0) {
            b = c;
        }
        else {
            a = c;
        }
    }
    return c;
}
int main() {
    setlocale(LC_ALL, "Russian");
    double a, b, g;
    cout << "Введите начало интервала: ";
    cin >> a;
    cout << "Введите конец интервала: ";
    cin >> b;
    cout << "Введите погрешность: ";
    cin >> g;

    double s = poldel(a, b, g);

    cout << "Корень уравнения: " << s << endl;
    return 0;
}