#include <iostream>
#include <locale.h>
#include <vector>

using namespace std;

double calcay(double T, double po, double s, double cl, double cd,
    double m, double g) {
    double L = T * cl / cd;
    return (L - m * g) / m;
}
double calct(double h, double ay) {
    return sqrt(2 * h / ay);
}

int main()
{
	setlocale(LC_ALL, "Russian");

    double g = 9.81;
    double m, s, cl, cd;
    double po, h;
    double Tmin, Tmax, dT;

    cout << "Масса: ";         
    cin >> m;
    cout << "Площадь крыла: "; 
    cin >> s;
    cout << "CL: ";              
    cin >> cl;
    cout << "CD: ";              
    cin >> cd;
    cout << "Плотность воздуха: ";    
    cin >> po;
    cout << "Высота: ";        
    cin >> h;

    cout << "Tmin: ";  
    cin >> Tmin;
    cout << "Tmax: ";  
    cin >> Tmax;
    cout << "dT: ";    
    cin >> dT;

    double bestT = Tmin;
    double bestTime = calct(h, calcay(Tmin, po, s, cl, cd, m, g));
    
    for (int k = 0; ; k++) {
        double T = Tmin + k * dT;
        if (T > Tmax) break;
        
        double ay = calcay(T, po, s, cl, cd, m, g);
        double t = calct(h, ay);
        cout << "Тяга "<< T << ", ускорение " << ay << ", время " << t << endl;

        if (t < bestTime) {
            bestTime = t;
            bestT = T;
        }
    }

    cout << "Оптимальная тяга: " << bestT
        << " Время: " << bestTime << endl;

    return 0;
}