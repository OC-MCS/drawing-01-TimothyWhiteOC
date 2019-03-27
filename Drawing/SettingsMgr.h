#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

enum ShapeEnum { CIRCLE, SQUARE };

// finish this code; add functions, data as needed

class SettingsMgr
{
private:
	Color color;
	ShapeEnum shape;
public:
	// Constructor
	SettingsMgr(Color startingColor, ShapeEnum startingShape)
	{
		color = startingColor;
		shape = startingShape;
	}

	// Color getCurColor(): Returns the current color.
	Color getCurColor()
	{
		return color;
	}

	// ShapeEnum getCurShape(): Returns the current shape.
	ShapeEnum getCurShape()
	{
		return shape;
	}

	// void setColor(): Sets the current color to the input value.
	void setColor(Color c) {
		color = c;
	}

	// void setShape(): Sets the current shape to the input value.
	void setShape(ShapeEnum s) {
		shape = s;
	}

	// void readFromFile(): Accepts an fstream of the file to read from. Reads the color and shape settings from the file.
	void readFromFile(fstream& file) {
		unsigned int colorSetting;
		file.read(reinterpret_cast<char*>(&colorSetting), sizeof(unsigned int));
		file.read(reinterpret_cast<char*>(&shape), sizeof(ShapeEnum));
		color = Color(colorSetting);
	}

	// void writeToFile(): Accepts an fstream of the file to write to. Writes the color and shape settings to the file.
	void writeToFile(fstream& file) {
		unsigned int colorSetting = color.toInteger();
		file.write(reinterpret_cast<char*>(&colorSetting), sizeof(unsigned int));
		file.write(reinterpret_cast<char*>(&shape), sizeof(ShapeEnum));
	}
};
