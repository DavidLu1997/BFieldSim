#include <iostream>
#include <cmath>
#include <string>
#include "Vector.h"
#include "MagneticField.h"
using namespace std;

int scale = 1000; //Points per meter

double a = 0;
double r = 0;
double w = 0;
double l = 0;
int n = 0;
double lx, ly, lz;
double x, y, z;

#define mew 1.2566370614E-6
#define pi 3.14159265359

bool insidePlane(Vector p, Vector x, Vector y, Vector z);

int main()
{
	cout << "Enter scale (points per meter):";
	cin >> scale;

	cout << "Resolution in m (x, y, z):";
	cin >> lx >> ly >> lz;

	lx *= scale;
	ly *= scale;
	lz *= scale;

	MagneticField f((int)lx, (int)ly, (int)lz, (1.0/scale));

	//Coil 1
	//CENTERS ON X AXIS
	
	cout << "Enter i:";
	cin >> a;

	cout << "Enter r:";
	cin >> r;
	r *= scale;

	cout << "Enter w:";
	cin >> w;
	w *= scale;

	cout << "Enter N:";
	cin >> n;

	cout << "Enter x:";
	cin >> x;
	x *= scale;
	x += lx / 2;

	cout << "Enter y:";
	cin >> y;
	y *= scale;
	y += ly / 2;

	cout << "Enter z:";
	cin >> z;
	z *= scale;
	z += lz / 2;

	for (int c = 0; c < n; c++)
	{
		y += c*(w / n);

		for (int i = 0; i < f.field.size(); i++)
		{
			for (int k = 0; k < f.field[lx-1][ly-1].size(); k++)
			{
				if (sqrt(pow(i - x, 2) + pow(y - y, 2) + pow(k - z, 2)) >(r*0.9) && sqrt(pow(i - x, 2) + pow(y - y, 2) + pow(k - z, 2)) <(r*1.1))
				{
					for (int j = 0; j < f.field[lx-1].size(); j++)
					{
						for (int l = 0; l < f.field[lx-1][ly-1].size(); l++)
						{
							if (sqrt(pow(i - x, 2) + pow(y - y, 2) + pow(l - z, 2)) >= r)
							{
								f.field[x][j][l].i += (mew*a) / (4 * pi*pow((1.0 / scale) * abs(x - x), 2)) * (1.0/scale);
								f.field[x][j][l].j += (mew*a) / (4 * pi*pow((1.0 / scale) * abs(j - y), 2)) * (1.0 / scale);
								f.field[x][j][l].k += (mew*a) / (4 * pi*pow((1.0 / scale) * abs(l - z), 2)) * (1.0 / scale);
							}

							else
							{
								f.field[x][j][l].i += (mew*a) / (4 * pi) * (1.0 / scale) * (1 / abs(x - x)) * (1.0 / scale);
								f.field[x][j][l].j += (mew*a) / (4 * pi) * (1.0 / scale) * (1 / abs(j - y)) * (1.0 / scale);
								f.field[x][j][l].k += (mew*a) / (4 * pi) * (1.0 / scale) * (1 / abs(l - z)) * (1.0 / scale);
							}
						}
					}
				}
			}
		}

		cout << c << endl;
	}

	//Coil 2
	//CENTERS ON Y AXIS
	cout << "Enter i:";
	cin >> a;

	cout << "Enter r:";
	cin >> r;
	r *= scale;

	cout << "Enter w:";
	cin >> w;
	w *= scale;

	cout << "Enter N:";
	cin >> n;

	cout << "Enter x:";
	cin >> x;
	x *= scale;
	x += lx / 2;

	cout << "Enter y:";
	cin >> y;
	y *= scale;
	y += ly / 2;

	cout << "Enter z:";
	cin >> z;
	z *= scale;
	z += lz / 2;

	for (int c = 0; c < n; c++)
	{
		x += c*(w / n);

		for (int j = 0; j < f.field[lx-1].size(); j++)
		{
			for (int k = 0; k < f.field[lx-1][ly-1].size(); k++)
			{
				if (sqrt(pow(x - x, 2) + pow(j - y, 2) + pow(k - z, 2)) >(r*0.9) && sqrt(pow(x - x, 2) + pow(j - y, 2) + pow(k - z, 2)) <(r*1.1))
				{
					for (int i = 0; i < f.field.size(); i++)
					{
						for (int l = 0; l < f.field[lx-1][ly-1].size(); l++)
						{
							if (sqrt(pow(i - x, 2) + pow(y - y, 2) + pow(l - z, 2)) >= r)
							{
								f.field[i][y][l].i += (mew*a) / (4 * pi*pow((1.0 / scale) * abs(i - x), 2)) * (1.0 / scale);
								f.field[i][y][l].j += (mew*a) / (4 * pi*pow((1.0 / scale) * abs(y - y), 2)) * (1.0 / scale);
								f.field[i][y][l].k += (mew*a) / (4 * pi*pow((1.0 / scale) * abs(l - z), 2)) * (1.0 / scale);
							}

							else
							{
								f.field[i][y][l].i += (mew*a) / (4 * pi) * (1.0 / scale) * (1 / abs(i - x)) * (1.0 / scale);
								f.field[i][y][l].j += (mew*a) / (4 * pi) * (1.0 / scale) * (1 / abs(y - y)) * (1.0 / scale);
								f.field[i][y][l].k += (mew*a) / (4 * pi) * (1.0 / scale) * (1 / abs(l - z)) * (1.0 / scale);
							}
						}
					}
				}
			}
		}

		cout << c << endl;
	}

	string name;
	cout << "Filename (.csv):";
	cin >> name;

	f.fileWrite(name + ".csv");
}