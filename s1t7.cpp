#include <iostream>
#include <locale.h>

using namespace std;

//зачем в условии тяга и сопротивление, если отсчет идет a_y? или мне надо лечь спать?

double calcay(double m, double L, double g) {
    return (L - m * g) / m;
}
int main()
{
    setlocale(LC_ALL, "Russian");

    double g = 9.81;
    double m, L;

    cout << "Введите массу: ";
    cin >> m;
    cout << "Подьемную силу: ";
    cin >> L;
    double ay = calcay(m, L, g);
    if (ay < 0) {
        cout << "снижение" << endl;
    }
    else if (ay > 0.5) {
        cout << "набор высоты" << endl;
    }
    else {
        cout << "горизонтальный полет" << endl;
    }

    return 0;
}
