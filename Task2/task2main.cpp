#define SDL_MAIN_HANDLED
#include "task2.h"



void testRendering(vector<Shape*> S, SDL_Renderer* renderer) {
	for (auto x : S) {
		x->render(renderer);//calls the specific shapes renderer
	}
}


int main(int argc, char* args[]) {
	vector<Shape*> S;//vector to contain shapes
	//srand(time(NULL));//uses computers time to randomize numbers

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("le formes",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		800, 600, SDL_WINDOW_OPENGL);
	if (window == nullptr)
	{
		SDL_Log("Could not create a window: %s", SDL_GetError());
		return -1;
	}
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr)
	{
		SDL_Log("Could not create a renderer: %s", SDL_GetError());
		return -1;
	}

	int xPos = 400;
	int yPos = 550;
	int BasePos = 350;
	int Base2Pos = 300;
	int HeightPos = 500;
	bool loop = true;
	while (loop == true)
	{
		SDL_Delay(20);
		SDL_Event event;
		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				break;
			}
		}
		switch (event.type) {
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_p: {
				PlayerShip player;
				player.SetBase(BasePos);
				player.SetHeight(HeightPos);
				Shape* Splayer = &player;
				Splayer->SetR(255);
				Splayer->SetG(255);
				Splayer->SetB(255);
				Splayer->SetAlpha(255);
				Splayer->_Point2D._x = xPos;
				Splayer->_Point2D._y = yPos;
				S.push_back(Splayer);
				break;
			}
			case SDLK_LEFT: {
				S.clear();
				PlayerShip player;
				if (BasePos < 200) {

				}
				else {
					BasePos--;
				}
				
				player.SetBase(BasePos);
				player.SetHeight(HeightPos);
				Shape* Splayer = &player;
				Splayer->SetR(255);
				Splayer->SetG(255);
				Splayer->SetB(255);
				Splayer->SetAlpha(255);
				if (xPos < 200) {

				}
				else {
					xPos--;
				}
				
				Splayer->_Point2D._x = xPos;
				Splayer->_Point2D._y = yPos;
				S.push_back(Splayer);
				break;
			}
			case SDLK_RIGHT: {
				S.clear();
				PlayerShip player;
				if (BasePos > 600) {

				}
				else {
					BasePos++;
				}
				
				player.SetBase(BasePos);
				player.SetHeight(HeightPos);
				Shape* Splayer = &player;
				Splayer->SetR(255);
				Splayer->SetG(255);
				Splayer->SetB(255);
				Splayer->SetAlpha(255);
				if (xPos > 600) {

				}
				else {
					xPos++;
				}
				
				Splayer->_Point2D._x = xPos;
				Splayer->_Point2D._y = yPos;
				S.push_back(Splayer);
				break;
			}


			case SDLK_q:
			{loop = false;
			break; }

			case SDLK_x:
			{S.clear();
			break; }
			}
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);
		testRendering(S, renderer);

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();


	return 0;
}