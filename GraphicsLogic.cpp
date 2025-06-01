//Aiden D'Antuono

#include "GraphicsLogic.h"

graphicsLogic::graphicsLogic() {

}

void graphicsLogic::mouseInput(int x, int y) {
	/*
	Interpret coords into position in the array
	pass the position to getShape from GameLogic
	pass shape from getShape to drawShape
	*/

}

void graphicsLogic::drawShape(shapeT shape, int x, int y) {
	al_draw_bitmap(shape.sprite, x, y, 0);
}

void graphicsLogic::drawGrid(int width, int height) {
	al_clear_to_color(al_map_rgb(0, 0, 0));
	
	for (int i = 1; i < 5; i++) {
		al_draw_line((width / 5) * i, 0, (width / 5) * i, height, al_map_rgb(255, 255, 255), 2);
	}

	for (int i = 1; i < 5; i++) {
		al_draw_line(0, (height / 5) * i, width, (height / 5) * i, al_map_rgb(255, 255, 255), 2);
	}

}

void graphicsLogic::drawStatus(ALLEGRO_FONT *font,int matchedPairs, int width, int height) {
	clearGridSquare(4, 4, width, height);
	al_draw_textf(font, al_map_rgb(255, 255, 255), (width / 5) * 4 + 10, (height / 5) * 4 + 20, ALLEGRO_ALIGN_LEFT, "Matched: %i", matchedPairs);
	al_draw_textf(font, al_map_rgb(255, 255, 255), (width / 5) * 4 + 10, (height / 5) * 4 + 50, ALLEGRO_ALIGN_LEFT, "Remaining: %i", 12 - matchedPairs);

}

void graphicsLogic::clearGridSquare(int x, int y, int width, int height) {
	al_draw_filled_rectangle((width / 5) * x + 5, (height / 5) * y + 5, (width / 5) * (x + 1) - 5, (height / 5) * (y + 1) - 5, al_map_rgb(0, 0, 0));
}