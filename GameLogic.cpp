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

shapeT gameLogic::getShape(int index) {
	selectedArray[index] = 1;
	return shapeArray[index];
}

void gameLogic::setShape(int x, int y, shapeT shape) {

}

bool gameLogic::compareShapes(shapeT firstShape, shapeT secondShape) {
	if (&firstShape == &secondShape) {
		return(true);
	}
	else {
		return(false);
	}
}
void gameLogic::resetGame() {
	matchedPairs = 0;

	//Will need to clear the board

	int randIndex;
	shapeT tmpShapeT;
	srand(time(NULL));

	//shuffle the board
	for (int i = 23; i >= 1; i--) {
		randIndex = rand() % (i + 1);
		tmpShapeT = shapeArray[i];
		shapeArray[i] = shapeArray[randIndex];
		shapeArray[randIndex] = tmpShapeT;
	}
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