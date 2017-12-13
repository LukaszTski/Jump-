#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"

int main(int argc, char **argv) {

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_BITMAP *image9 = NULL;
	ALLEGRO_BITMAP *image10 = NULL;
	ALLEGRO_BITMAP *image11 = NULL;

	if (!al_init()) {
		al_show_native_message_box(display, "Error", "Error", "Failed to initialize allegro!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return 0;
	}

	if (!al_init_image_addon()) {
		al_show_native_message_box(display, "Error", "Error", "Failed to initialize al_init_image_addon!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return 0;
	}

	display = al_create_display(800, 600);

	if (!display) {
		al_show_native_message_box(display, "Error", "Error", "Failed to initialize display!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return 0;
	}

	image9 = al_load_bitmap("doyou.png");
	image10 = al_load_bitmap("yes.png");
	image11 = al_load_bitmap("no.png");

	if (!image9) {
		al_show_native_message_box(display, "Error", "Error", "Failed to load image!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		return 0;
	}

	al_draw_bitmap(image9, 150, 150, 0);
	al_draw_bitmap(image10, 300, 300, 0);
	al_draw_bitmap(image11, 300, 380, 0);
	

	al_flip_display();
	al_rest(9);

	al_destroy_display(display);
	al_destroy_bitmap(image9);
	al_destroy_bitmap(image10);
	al_destroy_bitmap(image11);
	

	return 0;
}