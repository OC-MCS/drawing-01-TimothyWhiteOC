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
public:
	// Constructor
	SettingsUI(SettingsMgr *mgr)
	{
		settings = mgr;
	}

	// void handleMouseUp(): Called when the mouse button is released. Checks if the mouse is on any of the buttons and changes the settings appropriately.
	void handleMouseUp(Vector2f mouse)
	{
		if (mouse.x > 75 && mouse.x < 125) {
			if (mouse.y > 100 && mouse.y < 150) {
				settings->setColor(Color::Red);
			}
			else if (mouse.y > 175 && mouse.y < 225) {
				settings->setColor(Color::Green);
			}
			else if (mouse.y > 250 && mouse.y < 300) {
				settings->setColor(Color::Blue);
			}
			else if (mouse.y > 400 && mouse.y < 450) {
				settings->setShape(CIRCLE);
			}
			else if (mouse.y > 475 && mouse.y < 525) {
				settings->setShape(SQUARE);
			}
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

		CircleShape red(25), green(25), blue(25);
		red.setPosition(75, 100);
		green.setPosition(75, 175);
		blue.setPosition(75, 250);

		red.setOutlineColor(Color::Red);
		green.setOutlineColor(Color::Green);
		blue.setOutlineColor(Color::Blue);
		red.setOutlineThickness(5);
		green.setOutlineThickness(5);
		blue.setOutlineThickness(5);

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

		CircleShape circle(25);
		RectangleShape square(Vector2f(50, 50));
		circle.setPosition(75, 400);
		square.setPosition(75, 475);
		circle.setOutlineColor(Color::White);
		square.setOutlineColor(Color::White);
		circle.setOutlineThickness(5);
		square.setOutlineThickness(5);
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
