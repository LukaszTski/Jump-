#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"

int main(int argc, char **argv) {

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_BITMAP  *image = NULL;
	ALLEGRO_BITMAP  *image1 = NULL;
	ALLEGRO_BITMAP  *image2 = NULL;

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

	display = al_create_display(1024, 768);

	if (!display) {
		al_show_native_message_box(display, "Error", "Error", "Failed to initialize display!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return 0;
	}

	image = al_load_bitmap("titlee.png");
	image1 = al_load_bitmap("newgame.png");
	image2 = al_load_bitmap("exit.png");

	if (!image) {
		al_show_native_message_box(display, "Error", "Error", "Failed to load image!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		return 0;
	}

	al_draw_bitmap(image, 270, 0, 0);
	al_draw_bitmap(image1, 0, 300, 0);
	al_draw_bitmap(image2, 0, 400, 0);

	al_flip_display();
	al_rest(9);

	al_destroy_display(display);
	al_destroy_bitmap(image);
	al_destroy_bitmap(image1);
	al_destroy_bitmap(image2);

	return 0;
}
