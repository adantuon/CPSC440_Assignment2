//Aiden D'Antuono

#include "GraphicsLogic.h"

graphicsLogic::graphicsLogic(int inWidth, int inHeight, gameLogic inGame, ALLEGRO_FONT *inFont) {
	width = inWidth;
	height = inHeight;
	game = inGame;
	font = inFont;
}

//Handles mouse input
void graphicsLogic::mouseInput(int x, int y) {
	//Convert mouse x and y to grid position
	int gridx = x / (width / 5);
	int gridy = y / (height / 5);

	//Convert grid position to array index
	int index = gridx + (5 * gridy);

	//Determine if square is already matched or is the status square and stop if so
	if (game.alreadyMatched(index)) {
		return;
	}
	//get shape that should be in that position on the board
	shapeT shape = game.getShape(index);

	//Draw shape at that position
	drawShape(shape, gridx, gridy);
}

//Draws given shape in given square on grid
void graphicsLogic::drawShape(shapeT shape, int x, int y) {

	x = (width / 5) * x + ((width / 5) - 128) / 2;
	y = ((height / 5) * y) + ((height / 5) - 128) / 2;

	al_draw_bitmap(shape.sprite, x, y, 0);
}

//Draws grid on display
void graphicsLogic::drawGrid() {
	al_clear_to_color(al_map_rgb(0, 0, 0));
	
	for (int i = 1; i < 5; i++) {
		al_draw_line((width / 5) * i, 0, (width / 5) * i, height, al_map_rgb(255, 255, 255), 2);
	}

	for (int i = 1; i < 5; i++) {
		al_draw_line(0, (height / 5) * i, width, (height / 5) * i, al_map_rgb(255, 255, 255), 2);
	}

}

//Draw status of game in status square
void graphicsLogic::drawStatus() {
	clearGridSquare(4, 4);
	al_draw_textf(font, al_map_rgb(255, 255, 255), (width / 5) * 4 + 10, (height / 5) * 4 + 20, ALLEGRO_ALIGN_LEFT, "Matched: %i", game.getMatchedPairs());
	al_draw_textf(font, al_map_rgb(255, 255, 255), (width / 5) * 4 + 10, (height / 5) * 4 + 50, ALLEGRO_ALIGN_LEFT, "Remaining: %i", 12 - game.getMatchedPairs());
	al_flip_display();
}

//Clears a given position on the board
void graphicsLogic::clearGridSquare(int x, int y) {
	al_draw_filled_rectangle((width / 5) * x + 5, (height / 5) * y + 5, (width / 5) * (x + 1) - 5, (height / 5) * (y + 1) - 5, al_map_rgb(0, 0, 0));
}

//Handles the matching of shapes
void graphicsLogic::handleMatching() {
	//If don't have two shapes to see if match stop 
	if (game.getNumSelected() != 2) {
		return;
	}
	else {
		int firstSelected = game.getFirstSelected();
		int secondSelected = game.getSecondSelected();
		time_t startTime, currentTime;

		//See if shapes match
		bool match = game.compareShapes();
		

		//if they don't match
		if (!match) {
			startTime = time(NULL);
			currentTime = time(NULL);

			//Pause game
			while (currentTime - startTime < 2) {
				currentTime = time(NULL);
			}

			//Clear the selected shapes
			clearGridSquare(firstSelected % 5, firstSelected / 5);
			clearGridSquare(secondSelected % 5, secondSelected / 5);
		}
		else {
			//If the player has won the game
			if (game.getMatchedPairs() == 12) {
				//update status to show player has gotten all matches
				drawStatus();
				startTime = time(NULL);
				currentTime = time(NULL);

				//Pause game
				while (currentTime - startTime < 5) {
					currentTime = time(NULL);
				}

				//Remake board and reset the game
				al_clear_to_color(al_map_rgb(0, 0, 0));
				drawGrid();
				game.resetGame();
			}
		}
	}
}