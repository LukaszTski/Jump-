#include <stdio.h>
#include <allegro5/allegro.h>
#include "allegro5/allegro_native_dialog.h"
#include "allegro5/allegro_image.h"

const float FPS = 60;
const int SCREEN_W = 1024;
const int SCREEN_H = 768;
const int CHARACTER_SIZE = 25;


enum MYKEYS {
	KEY_SPACE, KEY_DOWN, KEY_UP
};

int main(int argc, char **argv) {
	//images
	ALLEGRO_BITMAP *image = NULL;
	ALLEGRO_BITMAP *image1 = NULL;
	ALLEGRO_BITMAP *image2 = NULL;
	ALLEGRO_BITMAP *image3 = NULL;
	ALLEGRO_BITMAP *image4 = NULL;
	/*ALLEGRO_BITMAP *image5 = NULL;
	ALLEGRO_BITMAP *image6 = NULL;
	ALLEGRO_BITMAP *image7 = NULL;*/
	ALLEGRO_BITMAP *image8 = NULL;
	ALLEGRO_BITMAP *image9 = NULL;
	ALLEGRO_BITMAP *image10 = NULL;
	ALLEGRO_BITMAP *image11 = NULL;
	ALLEGRO_BITMAP *image12 = NULL;
	//traps
	//spikes
	ALLEGRO_BITMAP *trap1k = NULL;
	ALLEGRO_BITMAP *trap2k = NULL;
	ALLEGRO_BITMAP *trap3k = NULL;
	ALLEGRO_BITMAP *trap4k = NULL;
	ALLEGRO_BITMAP *trap5k = NULL;
	ALLEGRO_BITMAP *trap6k = NULL;
	ALLEGRO_BITMAP *trap7k = NULL;
	ALLEGRO_BITMAP *trap8k = NULL;
	//bombs
	ALLEGRO_BITMAP *trap1b = NULL;
	ALLEGRO_BITMAP *trap2b = NULL;
	ALLEGRO_BITMAP *trap3b = NULL;
	ALLEGRO_BITMAP *trap4b = NULL;
	//platforms
	ALLEGRO_BITMAP *platform1 = NULL;
	ALLEGRO_BITMAP *platform2 = NULL;
	ALLEGRO_BITMAP *platform3 = NULL;
	ALLEGRO_BITMAP *platform4 = NULL;
	ALLEGRO_BITMAP *platform5 = NULL;
	ALLEGRO_BITMAP *platform6 = NULL;
	ALLEGRO_BITMAP *platform7 = NULL;
	ALLEGRO_BITMAP *platform8 = NULL;
	ALLEGRO_BITMAP *platform9 = NULL;
	ALLEGRO_BITMAP *platform10 = NULL;
	//other
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *character = NULL;
	ALLEGRO_BITMAP *highlight = NULL;
	ALLEGRO_BITMAP *highlight2 = NULL;

	//images
	float image3_x = 0;
	float image3_y = SCREEN_H - 70;
	float image4_x = 1024;
	float image4_y = SCREEN_H - 70;
	float image3f = -5;
	/*float image5_x = 0;
	float image5_y = 0;
	float image6_x = 2048;
	float image6_y = 0;
	float image7_x = 1024;
	float image7_y = -384;
	float images5678f = -2;*/
	float image8_x = 0;
	float image8_y = 0;
	float image9_x = 4800;
	float image9_y = 0;
	float image9_dx = -5;
	//traps
	//spikes
	  //111
	float trap1k_x = 1400;
	float trap1k_y = SCREEN_H - 70 - CHARACTER_SIZE;
	float trap1k_dx = -5;
	float trap4k_x = 1550;
	float trap4k_y = SCREEN_H - 70 - CHARACTER_SIZE;
	float trap4k_dx = -5;
	float trap5k_x = 1700;
	float trap5k_y = SCREEN_H - 70 - CHARACTER_SIZE;
	float trap5k_dx = -5;
	float trap6k_x = 2200;
	float trap6k_y = SCREEN_H - 70 - CHARACTER_SIZE;
	float trap6k_dx = -5;
	  //1
	float trap2k_x = 800;
	float trap2k_y = SCREEN_H - 70 - CHARACTER_SIZE;
	float trap2k_dx = -5;
	float trap3k_x = 1100;
	float trap3k_y = SCREEN_H - 70 - CHARACTER_SIZE;
	float trap3k_dx = -5;
	float trap7k_x = 2370;
	float trap7k_y = SCREEN_H - 70 - CHARACTER_SIZE;
	float trap7k_dx = -5;
	float trap8k_x = 2750;
	float trap8k_y = SCREEN_H - 70 - CHARACTER_SIZE;
	float trap8k_dx = -5;
	//bombs
	float trap1b_x = 2600;
	float trap1b_y = SCREEN_H - 220;
	float trap1b_dx = -5;
	float trap2b_x = 2880;
	float trap2b_y = SCREEN_H - 170;
	float trap2b_dx = -5;
	float trap3b_x = 3080;
	float trap3b_y = SCREEN_H - 170;
	float trap3b_dx = -5;
	float trap4b_x = 3280;
	float trap4b_y = SCREEN_H - 170;
	float trap4b_dx = -5;
	//platforms
	  //111
	float platform8_x = 3300;
	float platform8_y = SCREEN_H - 350;
	float platform8_dx = -5;
	float platform9_x = 3850;
	float platform9_y = SCREEN_H - 410;
	float platform9_dx = -5;
	float platform10_x = 4450;
	float platform10_y = SCREEN_H - 100;
	float platform10_dx = -5;
	  //11
	float platform1_x = 2400;
	float platform1_y = SCREEN_H - 100;
	float platform1_dx = -5;
	float platform5_x = 2750;
	float platform5_y = SCREEN_H - 130;
	float platform5_dx = -5;
	float platform6_x = 2950;
	float platform6_y = SCREEN_H - 160;
	float platform6_dx = -5;
	float platform7_x = 3150;
	float platform7_y = SCREEN_H - 190;
	float platform7_dx = -5;
	  //1
	float platform2_x = 1480;
	float platform2_y = SCREEN_H - 170;
	float platform2_dx = -5;
	float platform3_x = 1630;
	float platform3_y = SCREEN_H - 200;
	float platform3_dx = -5;
	float platform4_x = 1780;
	float platform4_y = SCREEN_H - 230;
	float platform4_dx = -5;
	//other
	float highlight_x = 400;
	float highlight_y = 326;
	float highlight2_x = 400;
	float highlight2_y = 326;
	float character_x = SCREEN_W / 3.0;
	float character_y = SCREEN_H - 70;
	float character_dy = 0;
	float gravity = 1.4;
	float lift = -23.0;

	bool key[3] = { false };
	bool redraw = true;
	bool doexit = false;

	int x = 1;
	int y = 0;

	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}

	if (!al_init_image_addon()) {
		al_show_native_message_box(display, "Error", "Error", "Failed to initialize al_init_image_addon!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return 0;
	}

	if (!al_install_keyboard()) {
		fprintf(stderr, "failed to initialize the keyboard!\n");
		return -1;
	}

	timer = al_create_timer(1.0 / FPS);
	if (!timer) {
		fprintf(stderr, "failed to create timer!\n");
		return -1;
	}

	display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display) {
		fprintf(stderr, "failed to create display!\n");
		al_destroy_timer(timer);
		return -1;
	}


	//spikes
	trap1k = al_load_bitmap("spikes.png");
	if (!trap1k) {
		fprintf(stderr, "failed to create object bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	trap2k = al_load_bitmap("spikes2.png");
	if (!trap2k) {
		fprintf(stderr, "failed to create object bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	trap3k = al_load_bitmap("spikes2.png");
	if (!trap3k) {
		fprintf(stderr, "failed to create object bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	trap4k = al_load_bitmap("spikes.png");
	if (!trap4k) {
		fprintf(stderr, "failed to create object bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}
	trap5k = al_load_bitmap("spikes.png");
	if (!trap5k) {
		fprintf(stderr, "failed to create object bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	trap6k = al_load_bitmap("spikes.png");
	if (!trap6k) {
		fprintf(stderr, "failed to create object bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}
	trap7k = al_load_bitmap("spikes2.png");
	if (!trap7k) {
		fprintf(stderr, "failed to create object bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}
	trap8k = al_load_bitmap("spikes2.png");
	if (!trap8k) {
		fprintf(stderr, "failed to create object bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	//bombs
	trap1b = al_load_bitmap("bomb.png");
	if (!trap1b) {
		fprintf(stderr, "failed to create object bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}
	trap2b = al_load_bitmap("bomb.png");
	if (!trap2b) {
		fprintf(stderr, "failed to create object bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}
	trap3b = al_load_bitmap("bomb.png");
	if (!trap3b) {
		fprintf(stderr, "failed to create object bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}
	trap4b = al_load_bitmap("bomb.png");
	if (!trap4b) {
		fprintf(stderr, "failed to create object bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	//platforms
	platform1 = al_load_bitmap("platform1.png");
	if (!platform1) {
		fprintf(stderr, "failed to create object bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	platform2 = al_load_bitmap("platform2.png");
	if (!platform2) {
		fprintf(stderr, "failed to create object bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	platform3 = al_load_bitmap("platform2.png");
	if (!platform3) {
		fprintf(stderr, "failed to create object bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	platform4 = al_load_bitmap("platform2.png");
	if (!platform4) {
		fprintf(stderr, "failed to create object bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	platform5 = al_load_bitmap("platform1.png");
	if (!platform5) {
		fprintf(stderr, "failed to create object bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	platform6 = al_load_bitmap("platform1.png");
	if (!platform6) {
		fprintf(stderr, "failed to create object bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	platform7 = al_load_bitmap("platform1.png");
	if (!platform7) {
		fprintf(stderr, "failed to create object bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	platform8 = al_load_bitmap("platform3.png");
	if (!platform8) {
		fprintf(stderr, "failed to create object bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	platform9 = al_load_bitmap("platform3.png");
	if (!platform9) {
		fprintf(stderr, "failed to create object bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	platform10 = al_load_bitmap("platform3.png");
	if (!platform10) {
		fprintf(stderr, "failed to create object bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	highlight = al_create_bitmap(15, 15);
	if (!highlight) {
		fprintf(stderr, "failed to create object bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	image = al_load_bitmap("titlee.png");
	if (!image) {
		al_show_native_message_box(display, "Error", "Error", "Failed to load image!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		return -1;
	}

	character = al_create_bitmap(CHARACTER_SIZE, CHARACTER_SIZE);
	if (!character) {
		fprintf(stderr, "failed to create object bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	image1 = al_load_bitmap("newgame.png");
	if (!image1) {
		al_show_native_message_box(display, "Error", "Error", "Failed to load image!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		return -1;
	}

	image2 = al_load_bitmap("exit.png");
	if (!image2) {
		al_show_native_message_box(display, "Error", "Error", "Failed to load image!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		return -1;
	}

	image3 = al_load_bitmap("bottom.png");
	if (!image3) {
		al_show_native_message_box(display, "Error", "Error", "Failed to load image!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		return -1;
	}

	image4 = al_load_bitmap("bottom.png");
	if (!image4) {
		al_show_native_message_box(display, "Error", "Error", "Failed to load image!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		return -1;
	}

	/*image5 = al_load_bitmap("tlo.png");
	if (!image5) {
		al_show_native_message_box(display, "Error", "Error", "Failed to load image!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		return -1;
	}
	image6 = al_load_bitmap("tlo2.png")
	if (!image6) {
		al_show_native_message_box(display, "Error", "Error", "Failed to load image!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		return -1;
	}
	image7 = al_load_bitmap("tlo3.png");
	if (!image7) {
		al_show_native_message_box(display, "Error", "Error", "Failed to load image!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		return -1;
	}*/

	image8 = al_load_bitmap("tlo3.png");
	if (!image8) {
		al_show_native_message_box(display, "Error", "Error", "Failed to load image!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		return -1;
	}
	image9 = al_load_bitmap("finish.png");
	if (!image9) {
		al_show_native_message_box(display, "Error", "Error", "Failed to load image!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		return -1;
	}
	image10 = al_load_bitmap("complete3.png");
	if (!image10) {
		al_show_native_message_box(display, "Error", "Error", "Failed to load image!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		return -1;
	}
	image11 = al_load_bitmap("loser.png");
	if (!image11) {
		al_show_native_message_box(display, "Error", "Error", "Failed to load image!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		return -1;
	}
	image12 = al_load_bitmap("exit.png");
	if (!image12) {
		al_show_native_message_box(display, "Error", "Error", "Failed to load image!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		return -1;
	}

	al_set_target_bitmap(highlight);
	al_clear_to_color(al_map_rgb(100, 100, 100));
	//ddd
	al_set_target_bitmap(character);
	al_clear_to_color(al_map_rgb(250, 220, 35));
	al_set_target_bitmap(al_get_backbuffer(display));
	

	event_queue = al_create_event_queue();
	if (!event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");
		al_destroy_bitmap(highlight);
		al_destroy_bitmap(display);
		al_destroy_timer(timer);
		return -1;
	}

	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_clear_to_color(al_map_rgb(255, 100, 100));
	al_flip_display();

	al_start_timer(timer);
	
	while (!doexit)

	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {

			if (x == 1) {
				if (key[KEY_DOWN]) {
					if (y == 0) {
						highlight_y = 426;
						highlight_x = 451;
						y = 1;
					}
				}
				if (key[KEY_UP]) {
					if (y == 1) {
						highlight_y = 326;
						highlight_x = 400;
						y = 0;
					}
				}
			}

			if (x == 0) {

				image9_x += image3f;
				if (image9_x <= SCREEN_W / 3.0 + 25) {
					platform9_dx *= 0;
					platform10_dx *= 0;
					image3f *= 0;
					x = 2;
				}
				/*image5_x += images5678f;
				image6_x += images5678f;
				image7_x += images5678f;

				if (image5_x <= -2048) {
					image5_x = 0;
				}

				if (image7_x <= -1024) {
					image7_x = 1024;
				}

				if (image8_x <= -1024) {
					image8_x = 1024;
				}

				if (image6_x <= 0) {
					image6_x = 2048;
				}*/

				character_dy += gravity;
				character_y += character_dy;

				if (character_y > SCREEN_H - 70 - CHARACTER_SIZE) {
					character_dy *= 0;
					character_y = SCREEN_H - 70 - CHARACTER_SIZE;
				}

				if (character_y < CHARACTER_SIZE) {
					character_dy *= 0;
					character_y = CHARACTER_SIZE;
				}

				if (key[KEY_SPACE] && character_dy == 0) {
					character_dy += lift;
				}

				image3_x += image3f;
				image4_x += image3f;

				if (image3_x <= -1024) {
					image3_x = 0;
				}

				if (image4_x <= 0) {
					image4_x = 1024;
				}

				//collision

				//spikes on the ground
				trap1k_x += trap1k_dx;

				if (trap1k_x <= SCREEN_W / 3.0 + 25) {
					if (trap1k_x + 70 <= SCREEN_W / 3.0) {
						trap1k_dx = -5;
					}
					else if (character_y >= SCREEN_H - 70 - CHARACTER_SIZE) {
						trap1k_dx *= 0;
						x = 3;
					}
				}

				trap2k_x += trap2k_dx;

				if (trap2k_x <= SCREEN_W / 3.0 + 25) {
					if (trap2k_x + 30 <= SCREEN_W / 3.0) {
						trap2k_dx = -5;
					}
					else if (character_y >= SCREEN_H - 70 - CHARACTER_SIZE) {
						trap2k_dx *= 0;
						x = 3;
					}
				}

				trap3k_x += trap3k_dx;

				if (trap3k_x <= SCREEN_W / 3.0 + 25) {
					if (trap3k_x + 30 <= SCREEN_W / 3.0) {
						trap2k_dx = -5;
					}
					else if (character_y >= SCREEN_H - 70 - CHARACTER_SIZE) {
						trap3k_dx *= 0;
						x = 3;
					}
				}

				trap4k_x += trap4k_dx;

				if (trap4k_x <= SCREEN_W / 3.0 + 25) {
					if (trap4k_x + 70 <= SCREEN_W / 3.0) {
						trap4k_dx = -5;
					}
					else if (character_y >= SCREEN_H - 70 - CHARACTER_SIZE) {
						trap4k_dx *= 0;
						x = 3;
					}
				}

				trap5k_x += trap5k_dx;

				if (trap5k_x <= SCREEN_W / 3.0 + 25) {
					if (trap5k_x + 70 <= SCREEN_W / 3.0) {
						trap5k_dx = -5;
					}
					else if (character_y >= SCREEN_H - 70 - CHARACTER_SIZE) {
						trap5k_dx *= 0;
						x = 3;
					}
				}

				trap6k_x += trap6k_dx;

				if (trap6k_x <= SCREEN_W / 3.0 + 25) {
					if (trap6k_x + 70 <= SCREEN_W / 3.0) {
						trap6k_dx = -5;
					}
					else if (character_y >= SCREEN_H - 70 - CHARACTER_SIZE) {
						trap6k_dx *= 0;
						x = 3;
					}
				}

				trap7k_x += trap7k_dx;

				if (trap7k_x <= SCREEN_W / 3.0 + 25) {
					if (trap7k_x + 30 <= SCREEN_W / 3.0) {
						trap7k_dx = -5;
					}
					else if (character_y >= SCREEN_H - 70 - CHARACTER_SIZE) {
						trap7k_dx *= 0;
						x = 3;
					}
				}

				trap8k_x += trap8k_dx;

				if (trap8k_x <= SCREEN_W / 3.0 + 25) {
					if (trap8k_x + 30 <= SCREEN_W / 3.0) {
						trap8k_dx = -5;
					}
					else if (character_y >= SCREEN_H - 70 - CHARACTER_SIZE) {
						trap8k_dx *= 0;
						x = 3;
					}
				}

				//bombs
				trap1b_x += trap1b_dx;

				if (trap1b_x <= SCREEN_W / 3.0 + 25) {//below
					if (trap1b_x + 50 <= SCREEN_W / 3.0) {
						trap1b_dx = -5;
					}//over
					else if (character_y < SCREEN_H - 220) {
						trap1b_dx = -5;
					}//side/bottom
					else if (character_y >= SCREEN_H - 220) {
						if (character_y <= SCREEN_H - 170) {
							trap1b_dx *= 0;
							gravity *= 0;
							character_dy *= 0;
							x = 3;
						}
					}
				}
				trap2b_x += trap2b_dx;

				if (trap2b_x <= SCREEN_W / 3.0 + 25) {//below
					if (trap2b_x + 50 <= SCREEN_W / 3.0) {
						trap2b_dx = -5;
					}//over
					else if (character_y < SCREEN_H - 170) {
						trap2b_dx = -5;
					}//side/bottom
					else if (character_y >= SCREEN_H - 170) {
						if (character_y <= SCREEN_H - 120) {
							trap2b_dx *= 0;
							gravity *= 0;
							character_dy *= 0;
							x = 3;
						}
					}
				}
				trap3b_x += trap3b_dx;

				if (trap3b_x <= SCREEN_W / 3.0 + 25) {//below
					if (trap3b_x + 50 <= SCREEN_W / 3.0) {
						trap3b_dx = -5;
					}//over
					else if (character_y < SCREEN_H - 170) {
						trap3b_dx = -5;
					}//side/bottom
					else if (character_y >= SCREEN_H - 170) {
						if (character_y <= SCREEN_H - 120) {
							trap3b_dx *= 0;
							gravity *= 0;
							character_dy *= 0;
							x = 3;
						}
					}
				}
				trap4b_x += trap4b_dx;

				if (trap4b_x <= SCREEN_W / 3.0 + 25) {//below
					if (trap4b_x + 50 <= SCREEN_W / 3.0) {
						trap4b_dx = -5;
					}//over
					else if (character_y < SCREEN_H - 170) {
						trap4b_dx = -5;
					}//side/bottom
					else if (character_y >= SCREEN_H - 170) {
						if (character_y <= SCREEN_H - 120) {
							trap4b_dx *= 0;
							gravity *= 0;
							character_dy *= 0;
							x = 3;
						}
					}
				}

				//platforms
				platform1_x += platform1_dx;

				if (platform1_x <= SCREEN_W / 3.0 + 25) {
					if (platform1_x + 100 <= SCREEN_W / 3.0) {
						platform1_dx = -5;
					}
					else if (character_y >= SCREEN_H - 100 + 30) {
						platform1_dx = -5;
					}
					else if (character_y >= SCREEN_H - 100 - 25) {
						character_dy = 0;
						character_y = SCREEN_H - 100 - 25;
					}
				}

				platform2_x += platform2_dx;

				if (platform2_x <= SCREEN_W / 3.0 + 25) {
					if (platform2_x + 34 <= SCREEN_W / 3.0) {
						platform2_dx = -5;
					}
					else if (character_y >= SCREEN_H - 170 + 30) {
						platform2_dx = -5;
					}
					else if (character_y >= SCREEN_H - 170 - 25) {
						character_dy = 0;
						character_y = SCREEN_H - 170 - 25;
					}
				}

				platform3_x += platform3_dx;

				if (platform3_x <= SCREEN_W / 3.0 + 25) {
					if (platform3_x + 34 <= SCREEN_W / 3.0) {
						platform3_dx = -5;
					}
					else if (character_y >= SCREEN_H - 200 + 30) {
						platform3_dx = -5;
					}
					else if (character_y >= SCREEN_H - 200 - 25) {
						character_dy = 0;
						character_y = SCREEN_H - 200 - 25;
					}
				}

				platform4_x += platform4_dx;

				if (platform4_x <= SCREEN_W / 3.0 + 25) {
					if (platform4_x + 34 <= SCREEN_W / 3.0) {
						platform4_dx = -5;
					}
					else if (character_y >= SCREEN_H - 230 + 30) {
						platform4_dx = -5;
					}
					else if (character_y >= SCREEN_H - 230 - 25) {
						character_dy = 0;
						character_y = SCREEN_H - 230 - 25;
					}
				}

				platform5_x += platform5_dx;

				if (platform5_x <= SCREEN_W / 3.0 + 25) {
					if (platform5_x + 100 <= SCREEN_W / 3.0) {
						platform5_dx = -5;
					}
					else if (character_y >= SCREEN_H - 130 + 30) {
						platform5_dx = -5;
					}
					else if (character_y >= SCREEN_H - 130 - 25) {
						character_dy = 0;
						character_y = SCREEN_H - 130 - 25;
					}
				}

				platform6_x += platform6_dx;

				if (platform6_x <= SCREEN_W / 3.0 + 25) {
					if (platform6_x + 100 <= SCREEN_W / 3.0) {
						platform6_dx = -5;
					}
					else if (character_y >= SCREEN_H - 160 + 30) {
						platform6_dx = -5;
					}
					else if (character_y >= SCREEN_H - 160 - 25) {
						character_dy = 0;
						character_y = SCREEN_H - 160 - 25;
					}
				}

				platform7_x += platform7_dx;

				if (platform7_x <= SCREEN_W / 3.0 + 25) {
					if (platform7_x + 100 <= SCREEN_W / 3.0) {
						platform7_dx = -5;
					}
					else if (character_y >= SCREEN_H - 190 + 30) {
						platform7_dx = -5;
					}
					else if (character_y >= SCREEN_H - 190 - 25) {
						character_dy = 0;
						character_y = SCREEN_H - 190 - 25;
					}
				}

				platform8_x += platform8_dx;

				if (platform8_x <= SCREEN_W / 3.0 + 25) {
					if (platform8_x + 400 <= SCREEN_W / 3.0) {
						platform8_dx = -5;
					}
					else if (character_y >= SCREEN_H - 350 + 30) {
						platform8_dx = -5;
					}
					else if (character_y >= SCREEN_H - 350 - 25) {
						character_dy = 0;
						character_y = SCREEN_H - 350 - 25;
					}
				}

				platform9_x += platform9_dx;

				if (platform9_x <= SCREEN_W / 3.0 + 25) {
					if (platform9_x + 400 <= SCREEN_W / 3.0) {
						platform9_dx = -5;
					}
					else if (character_y >= SCREEN_H - 410 + 30) {
						platform9_dx = -5;
					}
					else if (character_y >= SCREEN_H - 410 - 25) {
						character_dy = 0;
						character_y = SCREEN_H - 410 - 25;
					}
				}

				platform10_x += platform10_dx;

				if (platform10_x <= SCREEN_W / 3.0 + 25) {
					if (platform10_x + 400 <= SCREEN_W / 3.0) {
						platform10_dx = -5;
					}
					else if (character_y >= SCREEN_H - 100 + 30) {
						platform10_dx = -5;
					}
					else if (character_y >= SCREEN_H - 100 - 25) {
						character_dy = 0;
						character_y = SCREEN_H - 100 - 25;
					}
				}

				if (key[KEY_SPACE] && character_dy == 0) {
					character_dy += lift;
				}
			}

			if (x == 2) {
					if (y == 0) {
						highlight_y = 326;
						highlight_x = 400;
						y = 1;
					}
			}

			if (x == 3) {
					if (y == 0) {
						highlight_y = 326;
						highlight_x = 400;
						y = 1;
					}
			}


			redraw = true;

		}
	
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_SPACE:
				key[KEY_SPACE] = true;
				break;
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = true;
				break;
			case ALLEGRO_KEY_DOWN:
				key[KEY_DOWN] = true;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_SPACE:
				key[KEY_SPACE] = false;
				break;
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = false;
				break;
			case ALLEGRO_KEY_DOWN:
				key[KEY_DOWN] = false;
				break;
			case ALLEGRO_KEY_ENTER:
				if (y == 1)
					doexit = true;
				else
				{
					x = 0;
					doexit = false;
				}
				break;
			}
		}

		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;
			if (x == 1) {


				al_clear_to_color(al_map_rgb(255, 100, 100));

				al_draw_bitmap(image, 270, 0, 0);
				al_draw_bitmap(image1, 412, 300, 0);
				al_draw_bitmap(image2, 412, 400, 0);
				al_draw_bitmap(highlight, highlight_x, highlight_y, 0);
				al_flip_display();

			}
			else if (x == 2) {

				al_clear_to_color(al_map_rgb(255, 100, 100));

				al_draw_bitmap(image10, 270, 100, 0);
				al_draw_bitmap(image12, 412, 300, 0);
				al_draw_bitmap(highlight, highlight2_x, highlight2_y, 0);
				al_flip_display();
			}
			else if (x == 3) {
				al_clear_to_color(al_map_rgb(255, 100, 100));

				al_draw_bitmap(image11, 270, 100, 0);
				al_draw_bitmap(image12, 412, 300, 0);
				al_draw_bitmap(highlight, highlight2_x, highlight2_y, 0);
				al_flip_display();

			}
			else
			{
				al_clear_to_color(al_map_rgb(0, 0, 0));
				/*al_draw_bitmap(image5, image5_x, image5_y, 0);
				al_draw_bitmap(image6, image6_x, image6_y, 0);
				al_draw_bitmap(image7, image7_x, image7_y, 0);*/
				al_draw_bitmap(image8, image8_x, image8_y, 0);
				al_draw_bitmap(image9, image9_x, image9_y, 0);
				al_draw_bitmap(image3, image3_x, image3_y, 0);
				al_draw_bitmap(image4, image4_x, image4_y, 0);
				al_draw_bitmap(character, character_x, character_y, 0);
				//traps
				//spikes
				al_draw_bitmap(trap1k, trap1k_x, trap1k_y, 0);
				al_draw_bitmap(trap2k, trap2k_x, trap2k_y, 0);
				al_draw_bitmap(trap3k, trap3k_x, trap3k_y, 0);
				al_draw_bitmap(trap4k, trap4k_x, trap4k_y, 0);
				al_draw_bitmap(trap5k, trap5k_x, trap5k_y, 0);
				al_draw_bitmap(trap6k, trap6k_x, trap6k_y, 0);
				al_draw_bitmap(trap7k, trap7k_x, trap7k_y, 0);
				al_draw_bitmap(trap8k, trap8k_x, trap8k_y, 0);
				//bombs
				al_draw_bitmap(trap1b, trap1b_x, trap1b_y, 0);
				al_draw_bitmap(trap2b, trap2b_x, trap2b_y, 0);
				al_draw_bitmap(trap3b, trap3b_x, trap3b_y, 0);
				al_draw_bitmap(trap4b, trap4b_x, trap4b_y, 0);
				//platforms
				al_draw_bitmap(platform1, platform1_x, platform1_y, 0);
				al_draw_bitmap(platform2, platform2_x, platform2_y, 0);
				al_draw_bitmap(platform3, platform3_x, platform3_y, 0);
				al_draw_bitmap(platform4, platform4_x, platform4_y, 0);
				al_draw_bitmap(platform5, platform5_x, platform5_y, 0);
				al_draw_bitmap(platform6, platform6_x, platform6_y, 0);
				al_draw_bitmap(platform7, platform7_x, platform7_y, 0);
				al_draw_bitmap(platform8, platform8_x, platform8_y, 0);
				al_draw_bitmap(platform9, platform9_x, platform9_y, 0);
				al_draw_bitmap(platform10, platform10_x, platform10_y, 0);
				al_flip_display();
			}
		}
	}

	al_destroy_bitmap(image);
	al_destroy_bitmap(image1);
	al_destroy_bitmap(image2);
	al_destroy_bitmap(highlight);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}