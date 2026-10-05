
#include <iostream>
#include <locale.h>

using namespace std;

double calcD(double s,double v, double po, double cd) {
    return 0, 5 * s * v * v * s * cd;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    double s, v, po, cd;
    cout << "Введите площадь крыла:";
    cin >> s;
    cout << "Введите скорость полета:";
    cin >> v;
    cout << "Введите плотность воздуха:";
    cin >> po;
    cout << "Введите коэффициент сопротивления:";
    cin >> cd;
    double D = calcD(s, v, po, cd);
    cout << "Аэродинамическое сопротивление при заданных данных составит " << D << endl;
    return 0;
}
