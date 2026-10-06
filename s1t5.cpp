#include <iostream>
#include <locale.h>
#include <cmath>
using namespace ::std;

struct Plane {
    double m;
    double s;
    double cl;
    double cd;
    double T;
};

double calcD(double s, double v, double po, double cd) {
    return 0.5 * po * v * v * s * cd;
}

double calcL(double s, double v, double po, double cl) {
    return 0.5 * po * v * v * s * cl;
}

double calca(double T, double D, double m) {
    return (T - D) / m;
}
double calcay(double L, double m, double g) {
    return (L - m * g) / m;
}
double calct(double h, double ay) {
    return sqrt(h / (2 * ay));
}
int main() {
    setlocale(LC_ALL, "Russian");
    Plane planes[3];

    double po,v,h;
    double g = 9.81;

    cout << "Введите плотность воздуха:";
    cin >> po;
    cout << "Введите скорость полёта:";
    cin >> v;
    cout << "Введите высоту:";
    cin >> h;

    for (int i = 0; i < 3; i++) {
        cout << "Самолет " << i + 1 << endl;
        cout << "Масса:";
        cin >> planes[i].m;
        cout << "Площадь крыла:";
        cin >> planes[i].s;
        cout << "CL:";
        cin >> planes[i].cl;
        cout << "CD:";
        cin >> planes[i].cd;
        cout << "Тяга:";
        cin >> planes[i].T;
    }
    double t[3];
    
    for (int i = 0; i < 3; i++) {
        double D=calcD(planes[i].s, v, po, planes[i].cd);
        double L=calcL(planes[i].s, v, po, planes[i].cl);
        double a = calca(planes[i].T, D, planes[i].m);
        double ay = calcay(L, planes[i].m, g);
        t[i] = calct(h, ay);

        cout << "Самолет " << i + 1 << endl;
        cout << "Подъёмная сила" << L << endl;
        cout << "Сопротивление" << D << endl;
        cout << "Горизонтальное ускорение" << a<< endl;
        cout << "Вертикальное ускорение" << ay << endl;
    }

    int best = 0;

    for (int i = 0; i < 3; i++) {
        if (t[i] < t[best]) best = i;
    }
    cout << "Быстрее всех: самолет " << best + 1 << endl;
    return 0;
    }
