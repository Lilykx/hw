
#include <iostream>
#include <cmath>
#include <locale.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    double s,v,po,cl;
    cout << "Введите площадь крыла:";
    cin >> s;
    cout << "Введите скорость полета:";
    cin >> v;
    cout << "Введите плотность воздуха:";
    cin >> po;
    cout << "Введите коэффициент подьемной силы:";
    cin >> cl;

    cout << "Подьемная сила при заданных данных составит " << 0.5 * s * v * v * po * cl << endl;
    return 0;
}
