//Aiden D'Antuono

#include "GameLogic.h"

gameLogic::gameLogic() {
	createShapes();
	resetGame();
}

shapeT gameLogic::getShape(int x, int y) {
	shapeT deleteLater;

	return deleteLater;

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

}

void gameLogic::createShapes() {
	//Palette
	ALLEGRO_COLOR red = al_map_rgb(255, 0, 0);
	ALLEGRO_COLOR green = al_map_rgb(0, 255, 0);
	ALLEGRO_COLOR blue = al_map_rgb(0, 0, 255);
	ALLEGRO_COLOR yellow = al_map_rgb(255, 255, 0);
	ALLEGRO_COLOR magenta = al_map_rgb(255, 0, 255);
	ALLEGRO_COLOR cyan = al_map_rgb(0, 255, 255);

	gameShapes[0] = { "Red Square", createSquare(red) };
	gameShapes[1] = { "Green Square", createSquare(green) };
	gameShapes[2] = { "Blue Square", createSquare(blue) };
	gameShapes[3] = { "Yellow Square", createSquare(yellow) };
	gameShapes[4] = { "Magenta Square", createSquare(magenta) };
	gameShapes[5] = { "Cyan Square", createSquare(cyan) };
	gameShapes[6] = { "Red Circle", createCircle(red) };
	gameShapes[7] = { "Green Circle", createCircle(green) };
	gameShapes[8] = { "Blue Circle", createCircle(blue) };
	gameShapes[9] = { "Yellow Circle", createCircle(yellow) };
	gameShapes[10] = { "Magenta Circle", createCircle(magenta) };
	gameShapes[11] = { "Cyan Circle", createCircle(cyan) };

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