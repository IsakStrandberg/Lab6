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

	int AlienY1 = 20;
	int AlienY2 = 30;
	int Alien2Dy = 50;
	int AlienX1 = 360;
	int AlienX2 = 380;
	int AlienX3 = 420;
	int Alien2Dx = 440;
	bool AlienTurn = false;

	float Accel = 2;
	bool StopAccelLeft = false;
	bool StopAccelRight = false;
	int xPos = 400;
	int yPos = 550;
	int BasePos = 350;
	int Base2Pos = 300;
	int HeightPos = 500;

	float HeightProj = HeightPos;
	int OriginXPos;
	bool ProjExist = false;

	bool loop = true;
	bool Start = false;
	//Should dealocate memory for things when they disapear
	//and check if i can make things move by changing their values
	//instead of deleting them and recreating them
	while (loop == true)
	{
		if (Start == true) {
			if (AlienX1 - 100 <= 0) {
				AlienY1 = AlienY1 + 20;
				AlienY2 = AlienY2 + 20;
				Alien2Dy = Alien2Dy + 20;
				AlienTurn = true;
			}
			if (Alien2Dx  + 100 >= 800) {
				AlienY1 = AlienY1 + 20;
				AlienY2 = AlienY2 + 20;
				Alien2Dy = Alien2Dy + 20;
				AlienTurn = false;
			}
			if (AlienTurn == false) {
				AlienX1 = AlienX1 - 2;
				AlienX2 = AlienX2 - 2;
				AlienX3 = AlienX3 - 2;
				Alien2Dx = Alien2Dx - 2;
			}
			else {
				AlienX1 = AlienX1 + 2;
				AlienX2 = AlienX2 + 2;
				AlienX3 = AlienX3 + 2;
				Alien2Dx = Alien2Dx + 2;
			}

			int A1R = S.at(1)->GetR();
			int A1G = S.at(1)->GetG();
			int A1B = S.at(1)->GetB();
			int A1A = S.at(1)->GetAlpha();
			S.erase(S.begin() + 1);

			Alien alien;
			alien.SetX1(AlienX1);
			alien.SetX2(AlienX2);
			alien.SetX3(AlienX3);
			alien.SetY1(AlienY1);
			alien.SetY2(AlienY2);
			Shape* Salien = &alien;
			Salien->SetR(A1R);
			Salien->SetG(A1G);
			Salien->SetB(A1B);
			Salien->SetAlpha(A1A);
			Salien->_Point2D._x = Alien2Dx;
			Salien->_Point2D._y = Alien2Dy;
			S.insert(S.begin() + 1, Salien);

			int A2R = S.at(2)->GetR();
			int A2G = S.at(2)->GetG();
			int A2B = S.at(2)->GetB();
			int A2A = S.at(2)->GetAlpha();
			S.erase(S.begin() + 2);

			Alien alien2;
			alien2.SetX1(AlienX1 + 100);
			alien2.SetX2(AlienX2 + 100);
			alien2.SetX3(AlienX3 + 100);
			alien2.SetY1(AlienY1);
			alien2.SetY2(AlienY2);
			Shape* Salien2 = &alien2;
			Salien2->SetR(A2R);
			Salien2->SetG(A2G);
			Salien2->SetB(A2B);
			Salien2->SetAlpha(A2A);
			Salien2->_Point2D._x = Alien2Dx + 100;
			Salien2->_Point2D._y = Alien2Dy;
			S.insert(S.begin() + 2, Salien2);

			int A3R = S.at(3)->GetR();
			int A3G = S.at(3)->GetG();
			int A3B = S.at(3)->GetB();
			int A3A = S.at(3)->GetAlpha();
			S.erase(S.begin() + 3);

			Alien alien3;
			alien3.SetX1(AlienX1 - 100);
			alien3.SetX2(AlienX2 - 100);
			alien3.SetX3(AlienX3 - 100);
			alien3.SetY1(AlienY1);
			alien3.SetY2(AlienY2);
			Shape* Salien3 = &alien3;
			Salien3->SetR(A3R);
			Salien3->SetG(A3G);
			Salien3->SetB(A3B);
			Salien3->SetAlpha(A3A);
			Salien3->_Point2D._x = Alien2Dx - 100;
			Salien3->_Point2D._y = Alien2Dy;
			S.insert(S.begin() + 3, Salien3);

		}
		if (ProjExist == true) {

			if (HeightProj <= 0) {
				S.erase(S.begin() + 4);
				ProjExist = false;
				HeightProj = HeightPos;
			}
			else {

				HeightProj = HeightProj - 3;
				S.erase(S.begin() + 4);

				Projectile projectile;
				projectile.SetHeight(HeightProj);
				projectile.SetWidth(OriginXPos - 5);
				Shape* Sprojectile = &projectile;
				Sprojectile->SetR(255);
				Sprojectile->SetG(255);
				Sprojectile->SetB(255);
				Sprojectile->SetAlpha(255);
				Sprojectile->_Point2D._x = OriginXPos + 5;
				Sprojectile->_Point2D._y = HeightProj - 50;
				S.insert(S.begin() + 4, Sprojectile);
			}
		}
		SDL_Delay(20);
		HeightProj = HeightProj - 0.01;
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
				Start = true;
				PlayerShip player;
				player.SetBase(BasePos);
				player.SetHeight(HeightPos);
				player.SetBase2(Base2Pos);
				
				Shape* Splayer = &player;
				Splayer->SetR(255);
				Splayer->SetG(255);
				Splayer->SetB(255);
				Splayer->SetAlpha(255);
				Splayer->_Point2D._x = xPos;
				Splayer->_Point2D._y = yPos;
				S.insert(S.begin(),Splayer);
				
				///

				Alien alien;
				alien.SetX1(AlienX1);
				alien.SetX2(AlienX2);
				alien.SetX3(AlienX3);
				alien.SetY1(AlienY1);
				alien.SetY2(AlienY2);
				Shape* Salien = &alien;
				Salien->SetR(rand() % 255);
				Salien->SetG(rand() % 255);
				Salien->SetB(rand() % 255);
				Salien->SetAlpha(rand() % 255);
				Salien->_Point2D._x = Alien2Dx;
				Salien->_Point2D._y = Alien2Dy;
				S.insert(S.begin() + 1, Salien);

				Alien alien2;
				alien2.SetX1(AlienX1 + 100);
				alien2.SetX2(AlienX2 + 100);
				alien2.SetX3(AlienX3 + 100);
				alien2.SetY1(AlienY1);
				alien2.SetY2(AlienY2);
				Shape* Salien2 = &alien2;
				Salien2->SetR(rand() % 255);
				Salien2->SetG(rand() % 255);
				Salien2->SetB(rand() % 255);
				Salien2->SetAlpha(rand() % 255);
				Salien2->_Point2D._x = Alien2Dx + 100;
				Salien2->_Point2D._y = Alien2Dy;
				S.insert(S.begin() + 2, Salien2);

				Alien alien3;
				alien3.SetX1(AlienX1 - 100);
				alien3.SetX2(AlienX2 - 100);
				alien3.SetX3(AlienX3 - 100);
				alien3.SetY1(AlienY1);
				alien3.SetY2(AlienY2);
				Shape* Salien3 = &alien3;
				Salien3->SetR(rand() % 255);
				Salien3->SetG(rand() % 255);
				Salien3->SetB(rand() % 255);
				Salien3->SetAlpha(rand() % 255);
				Salien3->_Point2D._x = Alien2Dx - 100;
				Salien3->_Point2D._y = Alien2Dy;
				S.insert(S.begin() + 3, Salien3);
				break;
			}
			case SDLK_LEFT: {
				S.erase(S.begin());
				if (StopAccelRight == false) {
					Accel = 2;
				}
				StopAccelRight = true;
				StopAccelLeft = false;
				Accel = Accel + 0.01f;
				if (Accel == 4) {
					Accel--;
				}
				PlayerShip player;
				if (BasePos < 50) {
					BasePos = 50;
					Accel = 2;
				}
				else {
					BasePos = int(BasePos - Accel);
				}
				
				player.SetBase(BasePos);
				if (Base2Pos < 0) {
					Base2Pos = 0;
					Accel = 2;
				}
				else {
					Base2Pos = int(Base2Pos - Accel);
				}
				player.SetBase2(Base2Pos);
				player.SetHeight(HeightPos);
				Shape* Splayer = &player;
				Splayer->SetR(255);
				Splayer->SetG(255);
				Splayer->SetB(255);
				Splayer->SetAlpha(255);
				if (xPos < 100) {
					xPos = 100;
					Accel = 2;
				}
				else {
					xPos = int(xPos - Accel);
				}
				
				Splayer->_Point2D._x = xPos;
				Splayer->_Point2D._y = yPos;
				S.insert(S.begin(), Splayer);
				break;
			}///////////////////////////////////////////////////////////
			case SDLK_RIGHT: {
				S.erase(S.begin());
				if (StopAccelLeft == false) {
					Accel = 2;
				}
				StopAccelLeft = true;
				StopAccelRight = false;
				Accel = Accel + 0.01f;
				if (Accel == 4) {
					Accel--;
				}
				PlayerShip player;
				if (BasePos > 750) {
					BasePos = 750;
					Accel = 2;
				}
				else {
					BasePos = int(BasePos + Accel);
				}
				
				player.SetBase(BasePos);
				if (Base2Pos > 700) {
					Base2Pos = 700;
					Accel = 2;
				}
				else {
					Base2Pos = int(Base2Pos + Accel);
				}
				player.SetBase2(Base2Pos);
				player.SetHeight(HeightPos);
				Shape* Splayer = &player;
				Splayer->SetR(255);
				Splayer->SetG(255);
				Splayer->SetB(255);
				Splayer->SetAlpha(255);
				if (xPos > 800) {
					xPos = 800;
					Accel = 2;
				}
				else {
					xPos = int(xPos + Accel);
				}
				
				Splayer->_Point2D._x = xPos;
				Splayer->_Point2D._y = yPos;
				S.insert(S.begin(), Splayer);
				break;
			}

			case SDLK_UP:
			{
				if (ProjExist == true) {

				}
				else {
					ProjExist = true;
					OriginXPos = BasePos;
					Projectile projectile;
					projectile.SetHeight(HeightPos);
					projectile.SetWidth(OriginXPos - 5);
					Shape* Sprojectile = &projectile;
					Sprojectile->SetR(255);
					Sprojectile->SetG(255);
					Sprojectile->SetB(255);
					Sprojectile->SetAlpha(255);
					Sprojectile->_Point2D._x = OriginXPos + 5;
					Sprojectile->_Point2D._y = HeightPos - 50;
					S.insert(S.begin() + 4, Sprojectile);
				}
				break;
			}


			case SDLK_q:
			{loop = false;
			Start = false;
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