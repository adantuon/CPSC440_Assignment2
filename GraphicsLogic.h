// Aiden D'Antuono
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "Shape.h";

class graphicsLogic {
public:
	graphicsLogic();
	void mouseInput(int x, int y);
	void drawShape(int x, int y);
	void drawGrid(int width, int height);
	void drawStatus(ALLEGRO_FONT *font, int matchedPairs, int width, int height);
private:
	
};