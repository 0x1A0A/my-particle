#ifndef __PARTICLE_H__ 
#define __PARTICLE_H__ 

#include "vec2.h"

struct Particle {
	vec2f position, velocity; 
	float mass;
	void update(const float &timestep);
	void apply_force(const vec2f &force);
	void draw() const;	
};

#endif
