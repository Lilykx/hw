#include <iostream>
#include <locale.h>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
//тут мне тяга зачем... почему... условие не совпадает с целью задачи...
//количество ЛА не указано - какое ТЗ, такой результат, я использую векторы

struct Aircraft {
    double m;
    double s;
    double cl;
};

double calcL(double po, double v, double s, double cl) {
    return 0.5 * po * v * v * s * cl;
}
double calcay(double L, double m, double g) {
    return (L - m * g) / m;
}
double calct(double h, double ay) {
    return sqrt((0.5 * h) / ay);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    double g = 9.81;
    double po, v, h;
    int N;
    cout << "Введите количество самолётов: ";
    cin >> N;

    vector<Aircraft> planes(N);

    cout << "Введите сопротивление воздуха, скорость и высоту: ";
    cin >> po >> v >> h;

    for (int i = 0; i < N; i++) {
        cout << "Самолет " << i + 1 << ":\n";
        cout << "масса: ";         
        cin >> planes[i].m;
        cout << "площадь крыла: "; 
        cin >> planes[i].s;
        cout << "cl: ";            
        cin >> planes[i].cl;
    }

    vector<double> times(N);
    vector<int> id(N);

    for (int i = 0; i < N; i++) {
        double L = calcL(po, v, planes[i].s, planes[i].cl);
        double ay = calcay(L, planes[i].m, g);
        times[i] = calct(h, ay);
        id[i] = i;
    }

    sort(id.begin(), id.end(),
        [&](int a, int b) { return times[a] < times[b]; });

    for (int k = 0; k < id.size(); k++) {
        int i = id[k];
        cout << "Самолет " << i + 1 << "время - " << times[i] << endl;
    }
}