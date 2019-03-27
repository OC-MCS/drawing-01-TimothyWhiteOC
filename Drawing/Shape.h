#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

// finish this code; add functions, classes, data as needed
struct WriteableShape {
	ShapeEnum shape;
	float x, y;
	unsigned int color;
};


// DrawingShape should be an abstract base class 
// for Circle and Square
class DrawingShape 
{
public:
	virtual void draw(RenderWindow& win) = 0;
	virtual WriteableShape getFileRecord() = 0;
};

// add Circle, Square classes below. These are derived from DrawingShape

class Circle : public DrawingShape {
private:
	CircleShape c;
public:
	// Constructor
	Circle(Vector2f pos, Color color) {
		c.setPosition(pos);
		c.setFillColor(color);
		c.setRadius(5);
	}

	// void draw(): Draws the contained CircleShape.
	void draw(RenderWindow& win) {
		win.draw(c);
	}

	// WriteableShape getFileRecord(): Returns a WriteableShape representing the object to be written to file.
	WriteableShape getFileRecord() {
		return { CIRCLE, c.getPosition().x, c.getPosition().y, c.getFillColor().toInteger() };
	}
};

class Square : public DrawingShape {
private:
	RectangleShape r;
public:
	// Constructor
	Square(Vector2f pos, Color color) {
		r.setPosition(pos);
		r.setFillColor(color);
		r.setSize(Vector2f(10, 10));
	}

	// void draw(): Draws the contained RectangleShape.
	void draw(RenderWindow& win) {
		win.draw(r);
	}

	// WriteableShape getFileRecord(): Returns a WriteableShape representing the object to be written to file.
	WriteableShape getFileRecord() {
		return { SQUARE, r.getPosition().x, r.getPosition().y, r.getFillColor().toInteger() };
	}
};
