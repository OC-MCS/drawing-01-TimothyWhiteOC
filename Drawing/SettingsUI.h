#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "SettingsMgr.h"

// finish this code; add functions, data as needed
void die(string msg) {
	cout << msg << endl;
	exit(-1);
}

class SettingsUI
{
private:
	SettingsMgr *settings;
	CircleShape red, green, blue;
	CircleShape circle;
	RectangleShape square;
public:
	// Constructor
	SettingsUI(SettingsMgr *mgr)
	{
		settings = mgr;
		red.setRadius(25);
		red.setPosition(75, 100);
		red.setOutlineColor(Color::Red);
		red.setOutlineThickness(5);
		green.setRadius(25);
		green.setPosition(75, 175);
		green.setOutlineColor(Color::Green);
		green.setOutlineThickness(5);
		blue.setRadius(25);
		blue.setPosition(75, 250);
		blue.setOutlineColor(Color::Blue);
		blue.setOutlineThickness(5);
		circle.setRadius(25);
		circle.setPosition(75, 400);
		circle.setOutlineColor(Color::White);
		circle.setOutlineThickness(5);
		square.setSize(Vector2f(50, 50));
		square.setPosition(75, 475);
		square.setOutlineColor(Color::White);
		square.setOutlineThickness(5);
	}

	// void handleMouseUp(): Called when the mouse button is released. Checks if the mouse is on any of the buttons and changes the settings appropriately.
	void handleMouseUp(Vector2f mouse)
	{
		if (red.getGlobalBounds().contains(mouse)) {
			settings->setColor(Color::Red);
		}
		else if (green.getGlobalBounds().contains(mouse)) {
			settings->setColor(Color::Green);
		}
		else if (blue.getGlobalBounds().contains(mouse)) {
			settings->setColor(Color::Blue);
		}
		else if (circle.getGlobalBounds().contains(mouse)) {
			settings->setShape(CIRCLE);
		}
		else if (square.getGlobalBounds().contains(mouse)) {
			settings->setShape(SQUARE);
		}
	}

	// void draw(): Draws the settings buttons and text to the screen.
	void draw(RenderWindow& win)
	{
		Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf")) {
			die("couldn't load font");
		}

		Text colorLabel;
		colorLabel.setString("Select Color:");
		colorLabel.setPosition(15, 50);
		colorLabel.setFont(font);
		win.draw(colorLabel);

		red.setFillColor(Color::Transparent);
		green.setFillColor(Color::Transparent);
		blue.setFillColor(Color::Transparent);
		Color c = settings->getCurColor();
		if (c == Color::Red) {
			red.setFillColor(Color::Red);
		}
		else if (c == Color::Green) {
			green.setFillColor(Color::Green);
		}
		else if (c == Color::Blue) {
			blue.setFillColor(Color::Blue);
		}
		win.draw(red);
		win.draw(green);
		win.draw(blue);

		Text shapeLabel;
		shapeLabel.setString("Select Shape:");
		shapeLabel.setPosition(5, 350);
		shapeLabel.setFont(font);
		win.draw(shapeLabel);

		circle.setFillColor(Color::Transparent);
		square.setFillColor(Color::Transparent);
		ShapeEnum s = settings->getCurShape();
		if (s == CIRCLE) {
			circle.setFillColor(Color::White);
		}
		else if (s == SQUARE) {
			square.setFillColor(Color::White);
		}
		win.draw(circle);
		win.draw(square);
	}

};
