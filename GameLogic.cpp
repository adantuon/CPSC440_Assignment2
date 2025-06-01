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

//Return number of matched pairs
int gameLogic::getMatchedPairs() {
	return matchedPairs;
}

//Return number of selected shapes
int gameLogic::getNumSelected() {
	return numSelected;
}

//Return index of first selected shape
int gameLogic::getFirstSelected() {
	int returnInt = firstSelected;
	return returnInt;
}

//Return index of secondSelected shape
int gameLogic::getSecondSelected() {
	int returnInt = secondSelected;
	return returnInt;
}

//Check if index is already matched with another shape or is the status square
bool gameLogic::alreadyMatched(int index) {
	if (index > 23) {
		return true;
	}
	else if (matchedArray[index] == 1) {
		return true;
	}
	else {
		return false;
	}
}

//Return the shape at the position on the board and set index for either first or second selection
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

//Compare selected shapes to see if they match
bool gameLogic::compareShapes() {
	shapeT firstShape = shapeArray[firstSelected];
	shapeT secondShape = shapeArray[secondSelected];

	//If shapes match update game to reflect, reset selections, and return true
	if (firstShape.sprite == secondShape.sprite) {
		matchedPairs++;
		matchedArray[firstSelected] = 1;
		matchedArray[secondSelected] = 1;

		numSelected = 0;
		firstSelected = -1;
		secondSelected = -1;
		return true;
	}
	//If don't match reset selections and return false
	else {
		numSelected = 0;
		firstSelected = -1;
		secondSelected = -1;
		return false;
	}
}

//Resets game to default state
void gameLogic::resetGame() {
	//Reset Variables
	matchedPairs = 0;
	numSelected = 0;
	firstSelected = -1;
	secondSelected = -1;

	for (int i = 0; i < 24; i++) {
		matchedArray[i] = 0;
	}

	int randIndex;
	shapeT tmpShapeT;
	srand(time(NULL));

	//Shuffle the board
	for (int i = 23; i >= 1; i--) {
		randIndex = rand() % (i + 1);
		tmpShapeT = shapeArray[i];
		shapeArray[i] = shapeArray[randIndex];
		shapeArray[randIndex] = tmpShapeT;
	}
}

//Create bitmaps for all the shapes
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

//Create a square bitmap of given color
ALLEGRO_BITMAP* gameLogic::createSquare(ALLEGRO_COLOR color) {
	ALLEGRO_BITMAP *bitmap = al_create_bitmap(128, 128);
	
	al_set_target_bitmap(bitmap);
	al_clear_to_color(al_map_rgb(0, 0, 0));
	
	al_draw_filled_rectangle(0, 0, 128, 128, color);

	return(bitmap);
}

//Create a circle bitmap of given color
ALLEGRO_BITMAP* gameLogic::createCircle(ALLEGRO_COLOR color) {
	ALLEGRO_BITMAP *bitmap = al_create_bitmap(128, 128);

	al_set_target_bitmap(bitmap);
	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_draw_filled_circle(64, 64, 64, color);

	return(bitmap);
}