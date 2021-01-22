#pragma once
#include <iostream>
#include <vector>
#include <SDL.h>
#include <time.h>
#include <cstdlib>

using namespace std;

class Point2D {//stores x and y coordinates
public:
	Point2D();
	Point2D(float x, float y);
	float _x;
	float _y;
};


class Shape {//abstract base class for shapes
private:
	int _RGB[4];//colours and alpha

public:
	Shape();
	Shape(Point2D position, int Red, int Green, int Blue, int Alpha);
	Point2D _Point2D;
	int GetR() {
		return(_RGB[0]);
	}
	int GetG() {
		return(_RGB[1]);
	}
	int GetB() {
		return(_RGB[2]);
	}
	int GetAlpha() {
		return(_RGB[3]);
	}
	void SetR(int SetRed) {
		if (SetRed < 0 || SetRed > 255) {
			_RGB[0] = _RGB[0];
		}
		else {
			_RGB[0] = SetRed;
		}
	}
	void SetG(int SetGreen) {
		if (SetGreen < 0 || SetGreen > 255) {
			_RGB[1] = _RGB[1];
		}
		else {
			_RGB[1] = SetGreen;
		}
	}
	void SetB(int SetBlue) {
		if (SetBlue < 0 || SetBlue > 255) {
			_RGB[2] = _RGB[2];
		}
		else {
			_RGB[2] = SetBlue;
		}
	}
	void SetAlpha(int SetAlpha) {
		if (SetAlpha < 0 || SetAlpha > 255) {
			_RGB[3] = _RGB[3];
		}
		else {
			_RGB[3] = SetAlpha;
		}
	}

	virtual void render(SDL_Renderer* renderer) {

	}

};

class Projectile : public Shape {//inherits shape
private:
	float _Width;
	float _Height;

public:
	Projectile();
	Projectile(Point2D position,
		int Red, int Green, int Blue, int Alpha, float Width, float Height) :
		Shape(position, Red, Green, Blue, Alpha), _Width(Width), _Height(Height) {};
	//initialiser list


	float GetWidth() {
		return(_Width);
	}
	float GetHeight() {
		return(_Height);
	}

	void SetWidth(float SetW) {
		_Width = SetW;
	}
	void SetHeight(float SetH) {
		_Height = SetH;
	}

	virtual void render(SDL_Renderer* renderer) {
		Shape::render(renderer);
		/*cout << "Projectile " << "x: " << _Point2D._x <<
			"y: " << _Point2D._y << " " << GetWidth() << " " << GetHeight();*/

		SDL_SetRenderDrawColor(renderer, GetR(), GetG(), GetB(), GetAlpha());
		SDL_RenderDrawLine(renderer, _Point2D._x, _Point2D._y, _Point2D._x, GetHeight());
		SDL_RenderDrawLine(renderer, _Point2D._x, GetHeight(), GetWidth(), GetHeight());
		SDL_RenderDrawLine(renderer, GetWidth(), GetHeight(), GetWidth(), _Point2D._y);
		SDL_RenderDrawLine(renderer, GetWidth(), _Point2D._y, _Point2D._x, _Point2D._y);
		//draws a Projectile

	}
};

class PlayerShip : public Shape {// inherits shape
private:
	float _Base;
	float _Height;
	float _Base2;

public:
	PlayerShip();
	PlayerShip(Point2D position,
		int Red, int Green, int Blue, int Alpha, float Base, float Height, float Base2) :
		Shape(position, Red, Green, Blue, Alpha), _Base(Base), _Height(Height) , _Base2(Base2){};
	//initialiser list

	float GetBase() {
		return(_Base);
	}
	float GetHeight() {
		return(_Height);
	}
	float GetBase2() {
		return(_Base2);
	}

	void SetBase(float SetB) {
		_Base = SetB;
	}
	void SetHeight(float SetH) {
		_Height = SetH;
	}
	void SetBase2(float SetB2) {
		_Base2 = SetB2;
	}

	virtual void render(SDL_Renderer* renderer) {
		Shape::render(renderer);
		
		SDL_SetRenderDrawColor(renderer, GetR(), GetG(), GetB(), GetAlpha());
		SDL_RenderDrawLine(renderer, _Point2D._x, _Point2D._y, GetBase(), GetHeight());
		SDL_RenderDrawLine(renderer, GetBase(), _Point2D._y, GetBase2(), _Point2D._y);
		SDL_RenderDrawLine(renderer, _Point2D._x, _Point2D._y, GetBase(), _Point2D._y);
		SDL_RenderDrawLine(renderer, GetBase2(), _Point2D._y, GetBase(), GetHeight());
		//draws a PlayerShip

	}
};

class Circle : public Shape {// inherits shape
private:
	float _Radius;

public:
	Circle();
	Circle(Point2D position,
		int Red, int Green, int Blue, int Alpha, float Radius) :
		Shape(position, Red, Green, Blue, Alpha), _Radius(Radius) {};
	//initialiser list

	float GetRadius() {
		return(_Radius);
	}

	void SetRadius(float SetR) {
		_Radius = SetR;
	}

	virtual void render(SDL_Renderer* renderer) {
		Shape::render(renderer);
		/*cout << "Circle " << "x: " << _Point2D._x <<
			"y: " << _Point2D._y << " " << GetRadius();*/

		int h = 120;
		int k = 100;
		int step = 15;
		int PrevX = _Point2D._x;
		int PrevY = _Point2D._y;

		SDL_SetRenderDrawColor(renderer, GetR(), GetG(), GetB(), GetAlpha());
		for (int theta = 0; theta <= 360; theta += step) {
			_Point2D._x = h + GetRadius() * cos((theta * 3.14159) / 180);
			_Point2D._y = k + GetRadius() * sin((theta * 3.14159) / 180);
			SDL_RenderDrawLine(renderer, PrevX, PrevY, _Point2D._x, _Point2D._y);
			PrevX = _Point2D._x;
			PrevY = _Point2D._y;

		}
		//draws a circle


	}

};
