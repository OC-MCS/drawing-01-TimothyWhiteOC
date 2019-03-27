#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Shape.h"

using namespace std;
using namespace sf;

// finish the ShapeMgr class.

class ShapeMgr
{
private:
	vector<DrawingShape*> shapes;
public:
	// Constructor
	ShapeMgr()
	{
		
	}

	// void addShape(): Adds either a Circle or a Square to the list of shapes, depending on the value of the ShapeEnum.
	void addShape(Vector2f pos, ShapeEnum whichShape, Color color)
	{
		switch (whichShape) {
			case CIRCLE:
				shapes.push_back(new Circle(pos, color));
				break;
			case SQUARE:
				shapes.push_back(new Square(pos, color));
				break;
		}
	}

	// const vector<DrawingShape*>& getShapes(): Returns the list of shapes.
	const vector<DrawingShape*>& getShapes() {
		return shapes;
	}

	// void readFromFile(): Accepts an fstream of the file to read from. Reads the list of shapes from the file.
	void readFromFile(fstream& file) {
		WriteableShape inshape;
		while (file.read(reinterpret_cast<char*>(&inshape), sizeof(inshape))) {
			addShape(Vector2f(inshape.x, inshape.y), inshape.shape, Color(inshape.color));
		}
	}

	// void writeToFile(): Accepts an fstream of the file to write to. Writes the list of shapes to the file.
	void writeToFile(fstream& file) {
		for (int i = 0; i < shapes.size(); i++) {
			file.write(reinterpret_cast<char*>(&shapes[i]->getFileRecord()), sizeof(WriteableShape));
		}
	}
};
