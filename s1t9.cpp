#include <iostream>
#include <locale.h>
#include <vector>
#include <cmath>

using namespace std;

struct Aircraft {
	double m;
	double s;
	double T;
	double cl;
	double cd;
};

double calcL(double po, double v, double s, double cl) {
	return 0.5 * po * v * v * s * cl;
}
double calcD(double po, double v, double s, double cd) {
	return 0.5 * po * v * v * s * cd;
}
double calca(double T, double D, double m) {
	return (T - D) / m;
}
int main()
{
	setlocale(LC_ALL, "Russian");

	int N;
	cout << "Введите количество самолётов: ";
	cin >> N;

	vector<Aircraft> planes(N);

	double po, v;

	cout << "Введите плотность воздуха:";
	cin >> po;
	cout << "Введите скорость полёта:";
	cin >> v;

	for (int i = 0; i < N; i++) {
		cout << "Самолет " << i + 1 << endl;
		cout << "масса: ";
		cin >> planes[i].m;
		cout << "площадь крыла: ";
		cin >> planes[i].s;
		cout << "тяга: ";
		cin >> planes[i].T;
		cout << "cl: ";
		cin >> planes[i].cl;
		cout << "cd: ";
		cin >> planes[i].cd;
	}
	vector<double> a(N);

	for (int i = 0; i < N; i++) {
		double D = calcD(planes[i].s, v, po, planes[i].cd);
		double L = calcL(planes[i].s, v, po, planes[i].cl);
		a[i] = calca(planes[i].T, D, planes[i].m);
		cout << "Самолет " << i + 1
			<< ": L = " << L
			<< ", D = " << D
			<< ", a = " << a[i] << "\n";
	}
	int best = 0;

	for (int i = 0; i < N; i++) {
		if (a[i] > a[best]) best = i;
	}
	cout << "Быстрее всех: самолет " << best + 1 << endl;
	return 0;
}