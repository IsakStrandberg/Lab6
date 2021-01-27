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

Alien::Alien() {
	_Point2D._x = 0.0;
	_Point2D._y = 0.0;
	SetR(0);
	SetG(0);
	SetB(0);
	SetAlpha(0);
	SetX1(0);
	SetX2(0);
	SetX3(0);
	SetY1(0);
	SetY2(0);
}
