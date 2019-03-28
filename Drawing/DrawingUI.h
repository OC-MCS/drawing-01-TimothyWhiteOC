#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "ShapeMgr.h"

// finish this code; add functions, data as needed

class DrawingUI
{
private:
	RectangleShape canvas;
public:
	// Constructor
	DrawingUI(Vector2f p)
	{
		canvas.setPosition(p);
		canvas.setOutlineColor(Color::White);
		canvas.setOutlineThickness(1);
		canvas.setSize(Vector2f(550, 500));
	}

	// void draw(): Draws a box representing the canvas and all shapes in the ShapeMgr.
	void draw(RenderWindow& win, ShapeMgr *mgr)
	{
		win.draw(canvas);

		vector<DrawingShape*> shapes = mgr->getShapes();
		for (int i = 0; i < shapes.size(); i++) {
			shapes[i]->draw(win);
		}
	}
	
	// bool isMouseInCanvas(): Returns a bool whether or not the mouse is in the canvas.
	bool isMouseInCanvas(Vector2f mousePos)
	{
		return canvas.getGlobalBounds().contains(mousePos) && canvas.getGlobalBounds().contains(Vector2f(mousePos.x + 10, mousePos.y + 10));
	}
};

