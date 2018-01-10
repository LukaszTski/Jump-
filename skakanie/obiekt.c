#include <stdio.h>
#include <allegro5/allegro.h>

const float FPS = 60;
const int SCREEN_W = 1024;
const int SCREEN_H = 768;
const int OBJECT_SIZE = 16;
enum MYKEYS {
	KEY_UP
};

int main() {
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *object = NULL;
	float object_x = SCREEN_W / 2.0 - OBJECT_SIZE / 2.0;
	float object_y = SCREEN_H / 2.0 - OBJECT_SIZE / 2.0;
	float object_dy = 0;
	float gravity = 0.7;
	float lift = -6.0;

	bool key[4] = { false };
	bool redraw = true;

	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
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

	object = al_create_bitmap(OBJECT_SIZE, OBJECT_SIZE);
	if (!object) {
		fprintf(stderr, "failed to create object bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	al_set_target_bitmap(object);

	al_clear_to_color(al_map_rgb(255, 100, 100));

	al_set_target_bitmap(al_get_backbuffer(display));

	event_queue = al_create_event_queue();
	if (!event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");
		al_destroy_bitmap(object);
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	al_start_timer(timer);

	while (1)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			if (object_y < 0 || object_y > SCREEN_H - OBJECT_SIZE) {
				object_y = SCREEN_H - OBJECT_SIZE;
				object_dy = -1;
			}

			object_dy += gravity;
			object_y += object_dy;

			if (key[KEY_UP] && object_y >= 0) {
				object_dy += lift;
			}


			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = true;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = false;
				break;
			}
		}

		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			al_clear_to_color(al_map_rgb(0, 0, 0));

			al_draw_bitmap(object, object_x, object_y, 0);

			al_flip_display();
		}
	}

	al_destroy_bitmap(object);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}
