#include "Particle.h"

Particle::Particle(long double x, long double y, long double z)
{
	mass = 9.10937281E-31;
	position = Vector(x, y, z);
	velocity = Vector();
	netForce = Vector();
}

Particle::Particle(long double M, long double x, long double y, long double z)
{
	mass = M;
	position = Vector(x, y, z);
	velocity = Vector();
	netForce = Vector();
}

void Particle::iterate(long double t)
{
	velocity.i += netForce.i / mass;
	velocity.j += netForce.j / mass;
	velocity.k += netForce.k / mass;

	position.i += velocity.i * t;
	position.j += velocity.j * t;
	position.k += velocity.k * t;
}