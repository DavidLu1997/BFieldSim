#ifndef PARTICLE_H
#define PARTICLE_H

#include "Vector.h"

class Particle
{
public:

	Particle(long double x, long double y, long double z);

	Particle(long double M, long double x, long double y, long double z);

	void iterate(long double t);

	long double mass;
	Vector position;
	Vector velocity;
	Vector netForce;
};

#endif