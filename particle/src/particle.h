#ifndef __PARTICLE_H__ 
#define __PARTICLE_H__ 

#include "vec2.h"

struct Particle {
	vec2f position, velocity, external_force; 
	float friction;
	void update(const float &timestep);
	void draw() const;	
};

#endif
