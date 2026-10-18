#include <iostream>
#include <vector>
#include <clocale>
#include <iomanip>
#include <algorithm>
//Задачи 1 и 2 объединены в один файл
// setw в прошлом, ведь есть \t
//Обработки граничных случаев для v0 нет, так как v0 это константа
//Шагов 10, потому что мне жалко памяти
//Задачи 6 и 7 сюда же (сикс севен!!)
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	double v0 = 50;
	double g = 9.8;
	double dt = 1;

	vector<double> times;
	vector<double> heights;

	for (double t = 0; t <= 15; t += dt)
	{
		times.push_back(t);
		double h = v0 * t - 0.5 * g * t * t;
		heights.push_back(h);
		if (h < 0)
		{
			break;
		}
	}

	cout << fixed << setprecision(2);
	cout << "Время (с)\tВысота (м)" << endl;
	cout << "-------------------------" << endl;
	cout << "0.00\t\t" << heights[0] << endl; //первое значение все равно 0, вывожу для красоты

	for (size_t i = 1; i < times.size(); ++i)
	{
		cout << times[i] << "\t\t" << heights[i] << endl;
	}

	if (heights.empty() || heights[0] < 0) {
		cout << "Данных нет" << endl;
		return 1;
	}
	else {
		size_t idx_max = 0;
		for (size_t i = 1; i < heights.size(); ++i)
		{
			if (heights[i] > heights[idx_max])
			{
				idx_max = i;
			}
		}
		cout << "Максимальная высота " << heights[idx_max] << " в момент времени " << times[idx_max] << endl;
	
	}
	//Задача 7 
	auto it = find_if(next(heights.begin()), heights.end(), //иначе он радостно выдает 0 из-за первого элемента и больше ничего не ищет
		[](double h) { return h <= 0.0; });

	if (it != heights.end())
	{
		size_t idx = static_cast<size_t>(distance(heights.begin(), it));
		cout << "Время падения: " << times[idx]
			<< " с, высота: " << heights[idx] << " м" << endl;
	}
	else
	{
		cout << "не упала" << endl;
	}

	// Задача 6
	auto new_end = remove_if(heights.begin(), heights.end(), [](double h) { return h < 10; });
	heights.erase(new_end, heights.end());
	cout << fixed << setprecision(2);
	cout << "Высота (м)" << endl;
	cout << heights[0] << endl;
	for (size_t i = 1; i < heights.size(); ++i)
	{
		cout << heights[i] << endl;
	}
	return 0;
}
