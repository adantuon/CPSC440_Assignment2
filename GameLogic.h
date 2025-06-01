// Aiden D'Antuono

#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdio.h>
#include "Shape.h"

class gameLogic {
	public:
		gameLogic();
		shapeT getShape(int index);
		void setShape(int x, int y, shapeT shape);
		bool compareShapes();
		void resetGame();
		void createShapes();
		ALLEGRO_BITMAP *createSquare(ALLEGRO_COLOR color);
		ALLEGRO_BITMAP *createCircle(ALLEGRO_COLOR color);
		int getNumSelected();
		int getFirstSelected();
		int getSecondSelected();
		int getMatchedPairs();
		bool alreadyMatched(int index);
	private:
		shapeT gameShapes[12];
		shapeT shapeArray[24];
		int matchedArray[24] = { 0 };
		int firstSelected;
		int secondSelected;
		int numSelected;
		int matchedPairs;
};