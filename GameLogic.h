// Aiden D'Antuono

#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "Shape.h";

class gameLogic {
	public:
		gameLogic();
		shapeT getShape(int x, int y);
		void setShape(int x, int y, shapeT shape);
		bool compareShapes(shapeT firstShape, shapeT secondShape);
		void resetGame();
		void createShapes();
		ALLEGRO_BITMAP *createSquare(ALLEGRO_COLOR color);
		ALLEGRO_BITMAP *createCircle(ALLEGRO_COLOR color);
	private:
		shapeT gameShapes[12];
		shapeT shapeArray[5][5];
		int selectedArray[5][5] = { 0 };
		int matchedPairs;
};