#include "raylib.h"
#include "vec2.h"
#include "random.h"
#include "particle.h"
#include <vector>

#define MAX_PARTICLE 100000

int main(int argc, char **argv)
{
	Random::Init();

	InitWindow(640,480, "particle using raylib");
	SetTargetFPS(60);
	//Particle par[MAX_PARTICLE];

	std::vector<Particle> par;
	par.resize(MAX_PARTICLE);

	for (int i=0; i<MAX_PARTICLE; ++i) {
		par[i].position = { Random::Float() * 640, Random::Float() * 480};
		par[i].velocity = { Random::Float() * 20 - 10, Random::Float() * 20 - 10};
		par[i].friction = Random::Float() * 0.009 + 0.99;
	}

	while(!WindowShouldClose()) {

		vec2f mouse = {(float)GetMouseX(), (float)GetMouseY()};
		for (int i=0; i<MAX_PARTICLE; ++i) {
			if ( IsMouseButtonDown( MOUSE_BUTTON_LEFT ) ) {
				vec2f temp = (par[i].position - mouse);

				float force = pow(temp.length()/24,2);
				temp = temp.normalized();
				temp.x *= force;
				temp.y *= force;

				par[i].external_force += -temp;
			}
			if ( IsMouseButtonDown( MOUSE_BUTTON_RIGHT ) ) {
				vec2f temp = (par[i].position - mouse);

				float force = pow(30/temp.length(),2);
				temp = temp.normalized();
				temp.x *= force;
				temp.y *= force;

				par[i].external_force += temp;
			}
			if ( IsMouseButtonDown( MOUSE_BUTTON_MIDDLE ) ) {
				vec2f temp = (par[i].position - mouse);

				float force = pow(temp.length()/40,1.4);
				temp = temp.normalized();
				temp.x *= force;
				temp.y *= force;

				par[i].external_force += temp;
			}

			par[i].update(GetFrameTime());
		}

		BeginDrawing();
		ClearBackground(RAYWHITE);

		for (int i=0; i<MAX_PARTICLE; ++i) {
			par[i].draw();
		}

		DrawFPS(10,10);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
