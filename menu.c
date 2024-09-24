#include "menu.h"

// Desenha o menu e retorna em *option a opção decidida
int menu(int *option, int *game_done, ALLEGRO_DISPLAY *display) {
  int menu_done;
  ALLEGRO_FONT *aof_font_10;
  ALLEGRO_BITMAP *menu;
  ALLEGRO_TIMER *timer;
  ALLEGRO_EVENT_QUEUE *event_queue;
  ALLEGRO_EVENT event;

  timer = al_create_timer(1 / 60.0);
  if (!timer) {
    printf("Falha ao criar timer - menu.\n");
    return 0;
  }

  event_queue = al_create_event_queue();
  if (!event_queue) {
    printf("Falha ao criar fila de eventos - menu.\n");
    al_destroy_timer(timer);
    return 0;
  }

  aof_font_10 = al_load_font("Fonts/nugo-sans-light.ttf", 15, 0);
  if (!aof_font_10) {
    printf("Falha ao carregar fonte - menu.\n");
    al_destroy_timer(timer);
    al_destroy_event_queue(event_queue);
    return 0;
  }

  menu = al_load_bitmap("Sprites/Menu/Menu.png");
  if (!menu) {
    printf("Falha ao carregar foto - menu.\n");
    al_destroy_timer(timer);
    al_destroy_event_queue(event_queue);
    al_destroy_font(aof_font_10);
    return 0;
  }

  al_register_event_source(event_queue, al_get_keyboard_event_source());
  al_register_event_source(event_queue, al_get_display_event_source(display));
  al_register_event_source(event_queue, al_get_timer_event_source(timer));

  menu_done = 0;
  al_start_timer(timer);
  while ((!menu_done) && (!(*game_done))) {
    al_wait_for_event(event_queue, &event);

    // Desenha o menu com a opção atual em branco
    if (event.type == ALLEGRO_EVENT_TIMER) {
      al_clear_to_color(al_map_rgb(0, 0, 0));
      
      al_draw_bitmap(menu, 0, 0, 0);
      
      if ((*option) == 0) {
        al_draw_text(aof_font_10, al_map_rgb(255, 255, 255), 651 / 2, 435 / 2 + 50, ALLEGRO_ALIGN_CENTER, "1P VS 2P MODE");
        al_draw_text(aof_font_10, al_map_rgb(80, 80, 80), 651 / 2, 435 / 2 + 80, ALLEGRO_ALIGN_CENTER, "EXIT");
      } else if ((*option) == 1) {
        al_draw_text(aof_font_10, al_map_rgb(80, 80, 80), 651 / 2, 435 / 2 + 50, ALLEGRO_ALIGN_CENTER, "1P VS 2P MODE");
        al_draw_text(aof_font_10, al_map_rgb(255, 255, 255), 651 / 2, 435 / 2 + 80, ALLEGRO_ALIGN_CENTER, "EXIT");
      }

      al_flip_display();
    }

    if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
      if (event.keyboard.keycode == ALLEGRO_KEY_UP) {
        (*option)--;
        if ((*option) < 0)
          *option = 0;
      }

      if (event.keyboard.keycode == ALLEGRO_KEY_DOWN) {
        (*option)++;
        if ((*option) > 1)
          *option = 1;
      }

      if (event.keyboard.keycode == ALLEGRO_KEY_ENTER)
        menu_done = 1;
    }

    if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
      (*game_done) = 1;
    }
  }

  al_destroy_event_queue(event_queue);
  al_destroy_timer(timer);
  al_destroy_bitmap(menu);
  al_destroy_font(aof_font_10);

  return 1;
}