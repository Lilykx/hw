#include <iostream>
#include <clocale>
#include <vector>
#include <iomanip>

// \t великое изобретение человечества - прощай setw!!

using namespace std;

struct Point { double x, y, z; };
int main()
{
	setlocale(LC_ALL, "Russian");
	double vx = 30, vy = 20, vz = 40;
	double dt = 1;
	double t_max = 10;

	vector<Point> traj; 
	for (double t = 0; t <= t_max; t += dt) {
		Point p;
		p.x = vx * t;
		p.y = vy * t;
		p.z = vz * t;
		traj.push_back(p);
	}

	cout << fixed << setprecision(2);
	cout << "x\ty\tz\n";

	for (const auto& p : traj) {
		cout << p.x << "\t" << p.y << "\t" << p.z << "\n";
	}
}