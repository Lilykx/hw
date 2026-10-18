#include <iostream>
#include <vector>
#include <iomanip>
#include <numeric> //оказывается, что для accumulate надо подключать numeric. А че не сказали то? Мне лень даже гуглить

//Задачи 3 4 обьединены в один файл (опять)
//вводные данные взяла с первого задания
//опционально=не надо :)

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	double v0 = 50;
	double g = 9.8;
	double dt = 1;
	double t_max = 10;

	vector<double> times;
	vector<double> velocities;

	for (double t = 0; t <= t_max; t += dt)
	{
		times.push_back(t);
		double v = v0 - g * t;
		velocities.push_back(v);
	}
	cout << fixed << setprecision(2);
	cout << "Время (s)\tСкорость (m/s)" << endl;
	cout << "-----------------------------" << endl;
	for (size_t i = 0; i < times.size(); ++i)
	{
		cout << setw(10) << times[i] << "\t" << velocities[i] << endl;
	}
	if (velocities.empty())
	{
		cout << "пусто" << endl;
	}
	else
	{
		double sum = accumulate(velocities.begin(), velocities.end(), 0.0);
		double avg = sum / velocities.size();
		cout << "avg " << avg << endl;
	}

}
