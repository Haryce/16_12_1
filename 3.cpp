#include <iostream>
#include <cmath>
using namespace std;
double f(double x) {
    return sqrt(2); 
}
double Prostit(double (*g)(double), double x0, double h, int maxIt) {
    double x_n = x0;
    for (int n = 0; n < maxIt; ++n) {
        double x = g(x_n);
        cout << "Iteration " << n + 1 << ": x = " << x << endl;
        if (fabs(x - x_n) < h) {
            return x;
        }
        x_n = x;
    }
    cout << "Maximum iterations reached." << endl;
    return x_n;
}
int main() {
    setlocale(LC_ALL, "Russian");
    double x0; //начальное приближение
    double h; //точность
    int maxIt; //макс количество итераций
    cout << "Введите начальное приближение (x0): ";
    cin >> x0;
    cout << "Введите (h): ";
    cin >> h;
    cout << "Введите максимальную итерацию: ";
    cin >> maxIt;
    double root = Prostit(f, x0, h, maxIt);
    cout << "Предполагаемый корень: " << root << endl;
    return 0;
}