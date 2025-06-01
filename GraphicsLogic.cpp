//Aiden D'Antuono

#include "GraphicsLogic.h"

graphicsLogic::graphicsLogic(int inWidth, int inHeight, gameLogic inGame, ALLEGRO_FONT *inFont) {
	width = inWidth;
	height = inHeight;
	game = inGame;
	font = inFont;
}

void graphicsLogic::mouseInput(int x, int y) {
	int gridx = x / (width / 5);
	int gridy = y / (height / 5);
	int index = gridx + (5 * gridy);

	if (game.alreadyMatched(index)) {
		return;
	}
	shapeT shape = game.getShape(index);
	drawShape(shape, gridx, gridy);
}

void graphicsLogic::drawShape(shapeT shape, int x, int y) {

	x = (width / 5) * x + ((width / 5) - 128) / 2;
	y = ((height / 5) * y) + ((height / 5) - 128) / 2;

	al_draw_bitmap(shape.sprite, x, y, 0);
}

void graphicsLogic::drawGrid() {
	al_clear_to_color(al_map_rgb(0, 0, 0));
	
	for (int i = 1; i < 5; i++) {
		al_draw_line((width / 5) * i, 0, (width / 5) * i, height, al_map_rgb(255, 255, 255), 2);
	}

	for (int i = 1; i < 5; i++) {
		al_draw_line(0, (height / 5) * i, width, (height / 5) * i, al_map_rgb(255, 255, 255), 2);
	}

}

void graphicsLogic::drawStatus() {
	clearGridSquare(4, 4);
	al_draw_textf(font, al_map_rgb(255, 255, 255), (width / 5) * 4 + 10, (height / 5) * 4 + 20, ALLEGRO_ALIGN_LEFT, "Matched: %i", game.getMatchedPairs());
	al_draw_textf(font, al_map_rgb(255, 255, 255), (width / 5) * 4 + 10, (height / 5) * 4 + 50, ALLEGRO_ALIGN_LEFT, "Remaining: %i", 12 - game.getMatchedPairs());
	al_flip_display();
}

void graphicsLogic::clearGridSquare(int x, int y) {
	al_draw_filled_rectangle((width / 5) * x + 5, (height / 5) * y + 5, (width / 5) * (x + 1) - 5, (height / 5) * (y + 1) - 5, al_map_rgb(0, 0, 0));
}

void graphicsLogic::handleMatching() {
	if (game.getNumSelected() != 2) {
		return;
	}
	else {
		int firstSelected = game.getFirstSelected();
		int secondSelected = game.getSecondSelected();
		bool match = game.compareShapes();
		time_t startTime, currentTime;

		if (!match) {
			//wait 5 seconds
			startTime = time(NULL);
			currentTime = time(NULL);

			while (currentTime - startTime < 2) {
				currentTime = time(NULL);
			}
			clearGridSquare(firstSelected % 5, firstSelected / 5);
			clearGridSquare(secondSelected % 5, secondSelected / 5);
		}
		else {
			//If the player has won the game
			if (game.getMatchedPairs() == 12) {
				drawStatus();
				startTime = time(NULL);
				currentTime = time(NULL);

				while (currentTime - startTime < 5) {
					currentTime = time(NULL);
				}
				al_clear_to_color(al_map_rgb(0, 0, 0));
				drawGrid();
				game.resetGame();
			}
		}
	}
}