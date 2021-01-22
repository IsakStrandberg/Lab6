#include "task2.h"

Point2D::Point2D(float x, float y) {
	_x = x;
	_y = y;
}
Point2D::Point2D() {
	_x = 0.0;
	_y = 0.0;
}


Shape::Shape(Point2D position, int Red, int Green, int Blue, int Alpha) {
	_Point2D = position;//
	SetR(Red);
	SetG(Green);
	SetB(Blue);
	SetAlpha(Alpha);
}
Shape::Shape() {
	_Point2D = Point2D();
	SetR(0);
	SetG(0);
	SetB(0);
	SetAlpha(0);
}

//Projectile::Projectile(Point2D position,
//	int Red, int Green, int Blue, int Alpha, float Width, float Height) {
//	_Point2D = position;
//	SetR(Red);
//	SetG(Green);
//	SetB(Blue);
//	SetAlpha(Alpha);
//	_Width = Width;
//	_Height = Height;
//}
Projectile::Projectile() {
	_Point2D._x = 0.0;
	_Point2D._y = 0.0;
	SetR(0);
	SetG(0);
	SetB(0);
	SetAlpha(0);
	_Width = 0.0;
	_Height = 0.0;
}

//PlayerShip::PlayerShip(Point2D position,
//	int Red, int Green, int Blue, int Alpha,float Base, float Height) {
//	_Point2D = position;
//	SetR(Red);
//	SetG(Green);
//	SetB(Blue);
//	SetAlpha(Alpha);
//	_Base = Base;
//	_Height = Height;
//}
PlayerShip::PlayerShip() {
	_Point2D._x = 0.0;
	_Point2D._y = 0.0;
	SetR(0);
	SetG(0);
	SetB(0);
	SetAlpha(0);
	_Base = 0.0;
	_Height = 0.0;
	_Base2 = 0.0;
}

//Circle::Circle(Point2D position,
//	int Red, int Green, int Blue, int Alpha, float Radius) {
//	_Point2D = position;
//	_Radius = Radius;
//}
Circle::Circle() {
	_Point2D._x = 0.0;
	_Point2D._y = 0.0;
	_Radius = 0.0;
}



//int main(int argc, char* argv[]) {
//	vector<Shape*> S;
//
//	Projectile first;
//	first.SetHeight(2.1);
//	first.SetWidth(3.3);
//	Shape* Sfirst = &first;//polymorphism i think
//	Sfirst->SetR(125);//before: first.SetR(125)
//	Sfirst->SetG(50);
//	Sfirst->SetB(200);
//	Sfirst->SetAlpha(100);
//	Sfirst->_Point2D._x = 2.3;
//	Sfirst->_Point2D._y = 5.1;
//	
//
//	PlayerShip second;
//	second.SetBase(2.0);
//	second.SetHeight(6.2);
//	Shape* Ssecond = &second;
//	Ssecond->SetR(20);
//	Ssecond->SetG(200);
//	Ssecond->SetB(50);
//	Ssecond->SetAlpha(110);
//	Ssecond->_Point2D._x = 1.2;
//	Ssecond->_Point2D._y = 2.1;
//	
//
//	Circle third;
//	third.SetRadius(2.7);
//	Shape* Sthird = &third;
//	Sthird->SetR(70);
//	Sthird->SetG(35);
//	Sthird->SetB(35);
//	Sthird->SetAlpha(70);
//	Sthird->_Point2D._x = 5.4;
//	Sthird->_Point2D._y = 6.6;
//	
//
//	S.push_back(Sfirst);
//	S.push_back(Ssecond);
//	S.push_back(Sthird);
//
//	//testRendering(S);
//
//	SDL_Init(SDL_INIT_EVERYTHING);
//	SDL_Window *window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400,SDL_WINDOW_SHOWN);
//	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
//
//	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
//
//	SDL_RenderClear(renderer);
//
//	SDL_RenderPresent(renderer);
//
//	SDL_Delay(3000);
//
//	system("pause");
//	return 0;
//}