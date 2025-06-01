// Aiden D'Antuono
#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdio.h>
#include "Shape.h";
#include "GameLogic.h"

class graphicsLogic {
public:
	graphicsLogic(int inWidth, int inHeight, gameLogic inGame);
	void mouseInput(int x, int y);
	void drawShape(shapeT shape, int x, int y);
	void drawGrid();
	void drawStatus(ALLEGRO_FONT *font);
	void clearGridSquare(int x, int y);
	void handleMatching();
private:
	int height;
	int width;
	gameLogic game;
	
};