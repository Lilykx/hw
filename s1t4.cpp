#include <iostream>
#include <locale.h>
#include <cmath>
using namespace ::std;

double calct(double h, double ay) {
    return sqrt(h / (2 * ay));
}

int main() {
    setlocale(LC_ALL, "Russian");
    double h,ay;

    cout << "Введите высоту:";
    cin >> h;
    cout << "Введите ускорение:";
    cin >> ay;
    if (h > 0 && ay > 0) {
        double t = calct(h, ay);
        cout << "Время:" << t << endl;
        return 0;
 }
    else {
        cout << "Ошибка" << endl;
        return 1;
    }

}