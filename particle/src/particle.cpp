#include "particle.h"
#include "raylib.h"

static Color mixColor(Color A, Color B, float amount)
{
	float r = (float)A.r * (1-amount) + (float)B.r * amount;
	float g = (float)A.g * (1-amount) + (float)B.g * amount; 
	float b = (float)A.b * (1-amount) + (float)B.b * amount; 

	return {(unsigned char)r,(unsigned char)g,(unsigned char)b,255};
}

void Particle::update(const float &timestep)
{
	position += {(velocity.x + external_force.x) * timestep,(velocity.y + external_force.y) * timestep};
	velocity.x *= friction;
	velocity.y *= friction;
	external_force.x *= friction-0.02f;
	external_force.y *= friction-0.02f;
}

void Particle::draw() const
{
	int ef = (int)external_force.length();
	float a = (ef%255)/255.f;
	Color cc;

	cc.a = 255;

	cc.r = 
	sqrt((a/2)*(a/2)) * 38;
	cc.g = 
	a * 217;
	cc.b = 
	sqrt(a/2) * 80;

	DrawPixel( position.x, position.y, cc);
}