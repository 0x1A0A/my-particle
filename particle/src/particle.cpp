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
	position += {(velocity.x) * timestep,(velocity.y) * timestep};
}

// force should multiply by timestep
void Particle::apply_force(const vec2f &force)
{
	velocity += force/mass;
}

void Particle::draw() const
{
	float len = velocity.length();
	vec2f vec = len > 0 ? vec2f{0,0} : velocity.normalized();
	Color cc;
	float energy = len*len/2*mass;
	float sqen = sqrt(energy);
	float si = ((int)sqen % 255 )/255.f;
	float sk = ((int)(energy/4) % 255 )/255.f;
	float sj = ((int)(pow(energy/4,2)) % 255 )/255.f;

	cc.a = 255;
	cc.r = sj * 38;
	cc.g = si * 217;
	cc.b = sk * 80;

	DrawPixel( position.x, position.y, mixColor(RAYWHITE, cc, sqen > 1 ? 1 : sqrt(sqen)));
}