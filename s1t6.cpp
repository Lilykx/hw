#include <iostream>
#include <vector>
#include <iomanip>
#include <locale.h>

using namespace::std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int N;
    cout << "Введите число шагов (высот): ";
    cin >> N;
    double S, CL;
    cout << "Площадь крыла: ";
    cin >> S;
    cout << "CL: ";
    cin >> CL;

    vector<double> V(N);
    vector<double> po(N);

    for (int i = 0; i < N; i++) {
        cout << "Шаг " << i + 1 << endl;
        cout << "Скорость: ";
        cin >> V[i];
        cout << "Плотность: ";
        cin >> po[i];
    }

    cout << setw(10) << "Шаг"
        << setw(10) << "Скорость"
        << setw(15) << "Плотность"
        << setw(20) << "Подьемная сила"<<endl;

    for (int i = 0; i < N; i++) {
        double L = 0.5 * po[i] * V[i] * V[i] * S * CL;
        cout << setw(10) << i + 1 
            << setw(10) << V[i]
            << setw(15) << po[i]
            << setw(20) << L << endl;
    }

    return 0;
}