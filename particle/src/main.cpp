#include "raylib.h"
#include "vec2.h"
#include "random.h"
#include "particle.h"
#include <vector>

#define MAX_PARTICLE 70000

int main(int argc, char **argv)
{
	Random::Init();

	InitWindow(640,480, "particle using raylib");
	SetTargetFPS(60);

	std::vector<Particle> par;
	par.resize(MAX_PARTICLE);

	for (int i=0; i<MAX_PARTICLE; ++i) {
		par[i].position = { Random::Float() * 640, Random::Float() * 480};
		par[i].velocity = { Random::Float() * 20 - 10, Random::Float() * 20 - 10};
		par[i].mass = Random::Float() * 6 + 7;
	}

	while(!WindowShouldClose()) {
		float timestep = GetFrameTime();
		vec2f mouse = {(float)GetMouseX(), (float)GetMouseY()};
		for (int i=0; i<MAX_PARTICLE; ++i) {
			vec2f total = {0,0};

			int button = 
				IsMouseButtonDown(MOUSE_BUTTON_LEFT) |
				IsMouseButtonDown(MOUSE_BUTTON_RIGHT) << 1 |
				IsMouseButtonDown(MOUSE_BUTTON_MIDDLE) << 2;

			if ( button ) {
				if ( IsMouseButtonDown( MOUSE_BUTTON_LEFT ) ) {
					vec2f temp = (par[i].position - mouse);

					float force = pow(temp.length()/par[i].mass,2);
					temp = temp.normalized();
					temp.x *= force;
					temp.y *= force;

					total+=-temp*timestep;
				}
				if ( IsMouseButtonDown( MOUSE_BUTTON_RIGHT ) ) {
					vec2f temp = (par[i].position - mouse);

					float force = pow(500/temp.length(),2);
					temp = temp.normalized();
					temp.x *= force;
					temp.y *= force;

					total+=temp*timestep;
				}
				if ( IsMouseButtonDown( MOUSE_BUTTON_MIDDLE ) ) {
					vec2f temp = (par[i].position - mouse);

					float force = pow(temp.length(),1.4);
					temp = temp.normalized();
					temp.x *= force;
					temp.y *= force;

					total+=temp*timestep;
				}
				par[i].apply_force(total);
			} else {
				par[i].apply_force(-par[i].velocity*sqrt(par[i].mass)*timestep);
			}

			// TraceLog(LOG_INFO,"before %f %f", par[i].velocity.x, par[i].velocity.y);
			// TraceLog(LOG_INFO,"after %f %f", par[i].velocity.x, par[i].velocity.y);

			par[i].update(timestep);
		}

		BeginDrawing();
		ClearBackground(BLACK);

		for (int i=0; i<MAX_PARTICLE; ++i) {
			par[i].draw();
		}

		char buff[5];
		sprintf(buff, "%d", GetFPS());
		DrawText( buff, 10, 10, 10, WHITE );

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
