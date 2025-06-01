//Aiden D'Antuono

#include "GameLogic.h"

gameLogic::gameLogic() {
	createShapes();

	//Put tiles in game
	for (int i = 0; i < 12; i++) {
		shapeArray[i] = gameShapes[i];
		shapeArray[i + 12] = gameShapes[i];
	}

	resetGame();
}

int gameLogic::getMatchedPairs() {
	return matchedPairs;
}

int gameLogic::getNumSelected() {
	return numSelected;
}

//Returns firstSelected;
int gameLogic::getFirstSelected() {
	int returnInt = firstSelected;
	return returnInt;
}

//Returns secondSelected and sets it to -1 for graphics to clear cards
int gameLogic::getSecondSelected() {
	int returnInt = secondSelected;
	return returnInt;
}

bool gameLogic::alreadyMatched(int index) {
	if (matchedArray[index] == 1) {
		return true;
	}
	else {
		return false;
	}
}

shapeT gameLogic::getShape(int index) {
	if (firstSelected == -1) {
		firstSelected = index;
	}
	else {
		secondSelected = index;
	}
	numSelected++;
	return shapeArray[index];
}

void gameLogic::setShape(int x, int y, shapeT shape) {

}

bool gameLogic::compareShapes() {
	shapeT firstShape = gameShapes[firstSelected];
	shapeT secondShape = gameShapes[secondSelected];

	

	if (firstShape.sprite == secondShape.sprite) {
		matchedPairs++;
		matchedArray[firstSelected] = 1;
		matchedArray[secondSelected] = 1;

		numSelected = 0;
		firstSelected = -1;
		secondSelected = -1;
		return true;
	}
	else {
		numSelected = 0;
		firstSelected = -1;
		secondSelected = -1;
		return false;
	}
}

void gameLogic::resetGame() {
	matchedPairs = 0;
	numSelected = 0;
	firstSelected = -1;
	secondSelected = -1;

	//Will need to clear the board AND clear matchedArray

	int randIndex;
	shapeT tmpShapeT;
	srand(time(NULL));

	//shuffle the board
	/*
	for (int i = 23; i >= 1; i--) {
		randIndex = rand() % (i + 1);
		tmpShapeT = shapeArray[i];
		shapeArray[i] = shapeArray[randIndex];
		shapeArray[randIndex] = tmpShapeT;
	}
	*/
}

void gameLogic::createShapes() {
	//Palette
	ALLEGRO_COLOR red = al_map_rgb(255, 0, 0);
	ALLEGRO_COLOR green = al_map_rgb(0, 255, 0);
	ALLEGRO_COLOR blue = al_map_rgb(0, 0, 255);
	ALLEGRO_COLOR yellow = al_map_rgb(255, 255, 0);
	ALLEGRO_COLOR magenta = al_map_rgb(255, 0, 255);
	ALLEGRO_COLOR cyan = al_map_rgb(0, 255, 255);

	gameShapes[0] = { createSquare(red) };
	gameShapes[1] = { createSquare(green) };
	gameShapes[2] = { createSquare(blue) };
	gameShapes[3] = { createSquare(yellow) };
	gameShapes[4] = { createSquare(magenta) };
	gameShapes[5] = { createSquare(cyan) };
	gameShapes[6] = { createCircle(red) };
	gameShapes[7] = { createCircle(green) };
	gameShapes[8] = { createCircle(blue) };
	gameShapes[9] = { createCircle(yellow) };
	gameShapes[10] = { createCircle(magenta) };
	gameShapes[11] = { createCircle(cyan) };

}

//SHOULD PROBABLY PUT THESE IN THE CLASS
ALLEGRO_BITMAP* gameLogic::createSquare(ALLEGRO_COLOR color) {
	ALLEGRO_BITMAP *bitmap = al_create_bitmap(128, 128);
	
	al_set_target_bitmap(bitmap);
	al_clear_to_color(al_map_rgb(0, 0, 0));
	
	al_draw_filled_rectangle(0, 0, 128, 128, color);

	return(bitmap);
}

ALLEGRO_BITMAP* gameLogic::createCircle(ALLEGRO_COLOR color) {
	ALLEGRO_BITMAP *bitmap = al_create_bitmap(128, 128);

	al_set_target_bitmap(bitmap);
	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_draw_filled_circle(64, 64, 64, color);

	return(bitmap);
}