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

class Alien : public Shape {
private:
	float _RectX1;
	float _RectX2;
	float _RectX3;

	float _RectY1;
	float _RectY2;

public:
	Alien();
	Alien(Point2D position,
		int Red, int Green, int Blue, int Alpha, float RectX1,
		float RectX2, float RectX3,  float RectY1,
		float RectY2) : Shape(position, Red, Green, Blue, Alpha),
		_RectX1(RectX1), _RectX2(RectX2), _RectX3(RectX3),
		_RectY1(RectY1), _RectY2(RectY2) {};

	float GetX1() {
		return(_RectX1);
	}
	float GetX2() {
		return(_RectX2);
	}
	float GetX3() {
		return(_RectX3);
	}
	
	float GetY1() {
		return(_RectY1);
	}
	float GetY2() {
		return(_RectY2);
	}

	void SetX1(float SetX1) {
		_RectX1 = SetX1;
	}
	void SetX2(float SetX2) {
		_RectX2 = SetX2;
	}
	void SetX3(float SetX3) {
		_RectX3 = SetX3;
	}

	void SetY1(float SetY1) {
		_RectY1 = SetY1;
	}
	void SetY2(float SetY2) {
		_RectY2 = SetY2;
	}

	virtual void render(SDL_Renderer* renderer) {
		SDL_SetRenderDrawColor(renderer, GetR(), GetG(), GetB(), GetAlpha());
		SDL_RenderDrawLine(renderer, GetX1(), GetY2(),GetX2(),GetY1());
		SDL_RenderDrawLine(renderer, GetX1(), GetY2(), GetX2(),_Point2D._y);
		SDL_RenderDrawLine(renderer, _Point2D._x,GetY2(),GetX3(),GetY1());
		SDL_RenderDrawLine(renderer, _Point2D._x, GetY2(), GetX3(),_Point2D._y);
		SDL_RenderDrawLine(renderer, GetX3(), GetY1(), GetX2(), _Point2D._y);
		SDL_RenderDrawLine(renderer, GetX2(), GetY1(), GetX3(), _Point2D._y);
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
