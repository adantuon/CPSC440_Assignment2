// Aiden D'Antuono
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "GraphicsLogic.h"
#include <stdio.h>

int main() {
	int width = 960;
	int height = 720;
	bool exit = false;

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *eventQueue = NULL;

	if (!al_init()) {
		return(-1);
	}

	display = al_create_display(width, height);

	if (!display) {
		return(-1);
	}

	al_install_mouse();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();

	ALLEGRO_FONT *font = al_load_font("PressStart2P.ttf", 12, 0);
	if (font == NULL) {
		printf("Font is NULL\n");
		return(-1);
	}

	eventQueue = al_create_event_queue();
	al_register_event_source(eventQueue, al_get_display_event_source(display));
	al_register_event_source(eventQueue, al_get_mouse_event_source());

	graphicsLogic graphics_logic = graphicsLogic::graphicsLogic();


	graphics_logic.drawGrid(width, height);
	graphics_logic.drawStatus(font, 0, width, height);
	al_flip_display();

	while (!exit) {
		ALLEGRO_EVENT event;
		al_wait_for_event(eventQueue, &event);

		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			exit = true;
		}

		graphics_logic.drawStatus(font, 1, width, height);
		al_flip_display();

	}

	al_destroy_event_queue(eventQueue);
	al_destroy_display(display);
}