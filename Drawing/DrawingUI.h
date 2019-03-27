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
	Vector2f pos;
public:
	// Constructor
	DrawingUI(Vector2f p)
	{
		pos = p;
	}

	// void draw(): Draws a box representing the canvas and all shapes in the ShapeMgr.
	void draw(RenderWindow& win, ShapeMgr *mgr)
	{
		RectangleShape box;
		box.setPosition(pos);
		box.setOutlineColor(Color::White);
		box.setOutlineThickness(1);
		box.setSize(Vector2f(550, 500));
		win.draw(box);

		vector<DrawingShape*> shapes = mgr->getShapes();
		for (int i = 0; i < shapes.size(); i++) {
			shapes[i]->draw(win);
		}
	}
	
	// bool isMouseInCanvas(): Returns a bool whether or not the mouse is in the canvas.
	bool isMouseInCanvas(Vector2f mousePos)
	{
		return mousePos.x > pos.x &&
			   mousePos.x < pos.x + 540 &&
			   mousePos.y > pos.y &&
			   mousePos.y < pos.y + 490;
	}
};

