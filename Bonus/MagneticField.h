#ifndef MAGNETICFIELD_H
#define MAGNETICFIELD_H

#include <vector>
#include <string>
#include "Vector.h"

//This is a surface
class MagneticField
{
private:
	int x, y, z;
	double scale;
public:
	MagneticField(int X, int Y, int Z, double Scale);

	std::vector< std::vector< std::vector<Vector> > > field;

	void print();
	void fileWrite(std::string name);
};

#endif