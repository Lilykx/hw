
#include <iostream>
#include <locale.h>

using namespace ::std;

double calca(double T, double D, double m) {
    return (T - D) / m;
}
double calcay(double L, double m, double g) {
    return (L - m * g) / m;
}
int main() {
    setlocale(LC_ALL, "Russian");
    double m, L, D, T;
    double g = 9.81;

    cout << "Введите массу:";
    cin >> m;
    cout << "Введите подьемную силу:";
    cin >> L;
    cout << "Введите сопротивление:";
    cin >>D;
    cout << "Введите тягу двигателя:";
    cin >> T;

    double a = calca(T, D, m);
    double ay = calcay(L, m, g);

    cout << "Ускорение по направлению движения:" << a << endl;
    cout << "Ускорение по вертикали:" << ay << endl;
}

