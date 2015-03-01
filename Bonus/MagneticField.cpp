#include "MagneticField.h"
#include <iostream>
#include <fstream>

MagneticField::MagneticField(int X, int Y, int Z, double Scale)
{
	x = X;
	y = Y;
	z = Z;

	scale = Scale;

	std::vector<Vector> tempj;
	std::vector< std::vector<Vector> > tempi;
	Vector temp(0, 0, 0);

	for (int i = 0; i < x; i++)
	{
		field.push_back(tempi);
		for (int j = 0; j < y; j++)
		{
			field[i].push_back(tempj);
			for (int k = 0; k < z; k++)
			{
				field[i][j].push_back(temp);
			}
		}
	}
}

void MagneticField::print()
{
	for (int i = 0; i < field.size(); i++)
	{
		for (int j = 0; j < field[i].size(); j++)
		{
			for (int k = 0; k < field[i][j].size(); k++)
			{
				std::cout << "(" << field[i][j][k].i << "," << field[i][j][k].j << "," << field[i][j][k].k << ") ";
			}

			std::cout << std::endl;
		}

		std::cout << std::endl;
	}
}

void MagneticField::fileWrite(std::string name)
{
	std::ofstream file(name);

	for (int i = 0; i < field.size(); i++)
	{
		for (int j = 0; j < field[i].size(); j++)
		{
			for (int k = 0; k < field[i][j].size(); k++)
			{
				file << (i - (x / 2)) * scale << "," << (j - (y / 2)) * scale << "," << (k - (z / 2)) * scale << "," << field[i][j][k].i << "," << field[i][j][k].j << "," << field[i][j][k].k << std::endl;
			}
		}
	}
}