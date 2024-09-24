#include "character_selection.h"

// Cria a struct de seleção de personagem (que contem as 16 opções de escolha possíveis)
characters *create_character_selection() {
  characters *new_character_selection;

  new_character_selection = (characters*) malloc(sizeof(characters));
  if (!new_character_selection)
    return NULL;
  
  new_character_selection->todoh_todoh = al_load_bitmap("Sprites/Character Selection/Todo x Todo.png");
  if (!new_character_selection->todoh_todoh) {
    free(new_character_selection);
    return NULL;
  }

  new_character_selection->todoh_ryo = al_load_bitmap("Sprites/Character Selection/Todo x Ryo.png");
  if (!new_character_selection->todoh_ryo) {
    al_destroy_bitmap(new_character_selection->todoh_todoh);
    free(new_character_selection);
    return NULL;
  } 

  new_character_selection->todoh_robert = al_load_bitmap("Sprites/Character Selection/Todo x Robert.png");
  if (!new_character_selection->todoh_robert) {
    al_destroy_bitmap(new_character_selection->todoh_ryo);
    al_destroy_bitmap(new_character_selection->todoh_todoh);
    free(new_character_selection);
    return NULL;
  }

  new_character_selection->todoh_jack = al_load_bitmap("Sprites/Character Selection/Todo x Jack.png");
  if (!new_character_selection->todoh_jack) {
    al_destroy_bitmap(new_character_selection->todoh_robert);
    al_destroy_bitmap(new_character_selection->todoh_ryo);
    al_destroy_bitmap(new_character_selection->todoh_todoh);
    free(new_character_selection);
    return NULL;
  }

  new_character_selection->ryo_todoh = al_load_bitmap("Sprites/Character Selection/Ryo x Todo.png");
  if (!new_character_selection->ryo_todoh) {
    al_destroy_bitmap(new_character_selection->todoh_jack);
    al_destroy_bitmap(new_character_selection->todoh_robert);
    al_destroy_bitmap(new_character_selection->todoh_ryo);
    al_destroy_bitmap(new_character_selection->todoh_todoh);
    free(new_character_selection);
    return NULL;
  }

  new_character_selection->ryo_ryo = al_load_bitmap("Sprites/Character Selection/Ryo x Ryo.png");
  if (!new_character_selection->ryo_ryo) {
    al_destroy_bitmap(new_character_selection->ryo_todoh);
    al_destroy_bitmap(new_character_selection->todoh_jack);
    al_destroy_bitmap(new_character_selection->todoh_robert);
    al_destroy_bitmap(new_character_selection->todoh_ryo);
    al_destroy_bitmap(new_character_selection->todoh_todoh);
    free(new_character_selection);
    return NULL;
  }

  new_character_selection->ryo_robert = al_load_bitmap("Sprites/Character Selection/Ryo x Robert.png");
  if (!new_character_selection->ryo_robert) {
    al_destroy_bitmap(new_character_selection->ryo_ryo);
    al_destroy_bitmap(new_character_selection->ryo_todoh);
    al_destroy_bitmap(new_character_selection->todoh_jack);
    al_destroy_bitmap(new_character_selection->todoh_robert);
    al_destroy_bitmap(new_character_selection->todoh_ryo);
    al_destroy_bitmap(new_character_selection->todoh_todoh);
    free(new_character_selection);
    return NULL;
  }

  new_character_selection->ryo_jack = al_load_bitmap("Sprites/Character Selection/Ryo x Jack.png");
  if (!new_character_selection->ryo_jack) {
    al_destroy_bitmap(new_character_selection->ryo_robert);
    al_destroy_bitmap(new_character_selection->ryo_ryo);
    al_destroy_bitmap(new_character_selection->ryo_todoh);
    al_destroy_bitmap(new_character_selection->todoh_jack);
    al_destroy_bitmap(new_character_selection->todoh_robert);
    al_destroy_bitmap(new_character_selection->todoh_ryo);
    al_destroy_bitmap(new_character_selection->todoh_todoh);
    free(new_character_selection);
    return NULL;
  }

  new_character_selection->robert_todoh = al_load_bitmap("Sprites/Character Selection/Robert x Todo.png");
  if (!new_character_selection->robert_todoh) {
    al_destroy_bitmap(new_character_selection->ryo_jack);
    al_destroy_bitmap(new_character_selection->ryo_robert);
    al_destroy_bitmap(new_character_selection->ryo_ryo);
    al_destroy_bitmap(new_character_selection->ryo_todoh);
    al_destroy_bitmap(new_character_selection->todoh_jack);
    al_destroy_bitmap(new_character_selection->todoh_robert);
    al_destroy_bitmap(new_character_selection->todoh_ryo);
    al_destroy_bitmap(new_character_selection->todoh_todoh);
    free(new_character_selection);
    return NULL;
  }

  new_character_selection->robert_ryo = al_load_bitmap("Sprites/Character Selection/Robert x Ryo.png");
  if (!new_character_selection->robert_ryo) {
    al_destroy_bitmap(new_character_selection->robert_todoh);
    al_destroy_bitmap(new_character_selection->ryo_jack);
    al_destroy_bitmap(new_character_selection->ryo_robert);
    al_destroy_bitmap(new_character_selection->ryo_ryo);
    al_destroy_bitmap(new_character_selection->ryo_todoh);
    al_destroy_bitmap(new_character_selection->todoh_jack);
    al_destroy_bitmap(new_character_selection->todoh_robert);
    al_destroy_bitmap(new_character_selection->todoh_ryo);
    al_destroy_bitmap(new_character_selection->todoh_todoh);
    free(new_character_selection);
    return NULL;
  }

  new_character_selection->robert_robert = al_load_bitmap("Sprites/Character Selection/Robert x Robert.png");
  if (!new_character_selection->robert_robert) {
    al_destroy_bitmap(new_character_selection->robert_ryo);
    al_destroy_bitmap(new_character_selection->robert_todoh);
    al_destroy_bitmap(new_character_selection->ryo_jack);
    al_destroy_bitmap(new_character_selection->ryo_robert);
    al_destroy_bitmap(new_character_selection->ryo_ryo);
    al_destroy_bitmap(new_character_selection->ryo_todoh);
    al_destroy_bitmap(new_character_selection->todoh_jack);
    al_destroy_bitmap(new_character_selection->todoh_robert);
    al_destroy_bitmap(new_character_selection->todoh_ryo);
    al_destroy_bitmap(new_character_selection->todoh_todoh);
    free(new_character_selection);
    return NULL;
  }

  new_character_selection->robert_jack = al_load_bitmap("Sprites/Character Selection/Robert x Jack.png");
  if (!new_character_selection->robert_jack) {
    al_destroy_bitmap(new_character_selection->robert_robert);
    al_destroy_bitmap(new_character_selection->robert_ryo);
    al_destroy_bitmap(new_character_selection->robert_todoh);
    al_destroy_bitmap(new_character_selection->ryo_jack);
    al_destroy_bitmap(new_character_selection->ryo_robert);
    al_destroy_bitmap(new_character_selection->ryo_ryo);
    al_destroy_bitmap(new_character_selection->ryo_todoh);
    al_destroy_bitmap(new_character_selection->todoh_jack);
    al_destroy_bitmap(new_character_selection->todoh_robert);
    al_destroy_bitmap(new_character_selection->todoh_ryo);
    al_destroy_bitmap(new_character_selection->todoh_todoh);
    free(new_character_selection);
    return NULL;
  }

  new_character_selection->jack_todoh = al_load_bitmap("Sprites/Character Selection/Jack x Todo.png");
  if (!new_character_selection->jack_todoh) {
    al_destroy_bitmap(new_character_selection->robert_jack);
    al_destroy_bitmap(new_character_selection->robert_robert);
    al_destroy_bitmap(new_character_selection->robert_ryo);
    al_destroy_bitmap(new_character_selection->robert_todoh);
    al_destroy_bitmap(new_character_selection->ryo_jack);
    al_destroy_bitmap(new_character_selection->ryo_robert);
    al_destroy_bitmap(new_character_selection->ryo_ryo);
    al_destroy_bitmap(new_character_selection->ryo_todoh);
    al_destroy_bitmap(new_character_selection->todoh_jack);
    al_destroy_bitmap(new_character_selection->todoh_robert);
    al_destroy_bitmap(new_character_selection->todoh_ryo);
    al_destroy_bitmap(new_character_selection->todoh_todoh);
    free(new_character_selection);
    return NULL;
  }

  new_character_selection->jack_ryo = al_load_bitmap("Sprites/Character Selection/Jack x Ryo.png");
  if (!new_character_selection->jack_ryo) {
    al_destroy_bitmap(new_character_selection->jack_todoh);
    al_destroy_bitmap(new_character_selection->robert_jack);
    al_destroy_bitmap(new_character_selection->robert_robert);
    al_destroy_bitmap(new_character_selection->robert_ryo);
    al_destroy_bitmap(new_character_selection->robert_todoh);
    al_destroy_bitmap(new_character_selection->ryo_jack);
    al_destroy_bitmap(new_character_selection->ryo_robert);
    al_destroy_bitmap(new_character_selection->ryo_ryo);
    al_destroy_bitmap(new_character_selection->ryo_todoh);
    al_destroy_bitmap(new_character_selection->todoh_jack);
    al_destroy_bitmap(new_character_selection->todoh_robert);
    al_destroy_bitmap(new_character_selection->todoh_ryo);
    al_destroy_bitmap(new_character_selection->todoh_todoh);
    free(new_character_selection);
    return NULL;
  }

  new_character_selection->jack_robert = al_load_bitmap("Sprites/Character Selection/Jack x Robert.png");
  if (!new_character_selection->jack_robert) {
    al_destroy_bitmap(new_character_selection->jack_ryo);
    al_destroy_bitmap(new_character_selection->jack_todoh);
    al_destroy_bitmap(new_character_selection->robert_jack);
    al_destroy_bitmap(new_character_selection->robert_robert);
    al_destroy_bitmap(new_character_selection->robert_ryo);
    al_destroy_bitmap(new_character_selection->robert_todoh);
    al_destroy_bitmap(new_character_selection->ryo_jack);
    al_destroy_bitmap(new_character_selection->ryo_robert);
    al_destroy_bitmap(new_character_selection->ryo_ryo);
    al_destroy_bitmap(new_character_selection->ryo_todoh);
    al_destroy_bitmap(new_character_selection->todoh_jack);
    al_destroy_bitmap(new_character_selection->todoh_robert);
    al_destroy_bitmap(new_character_selection->todoh_ryo);
    al_destroy_bitmap(new_character_selection->todoh_todoh);
    free(new_character_selection);
    return NULL;
  }

  new_character_selection->jack_jack = al_load_bitmap("Sprites/Character Selection/Jack x Jack.png");
  if (!new_character_selection->jack_jack) {
    al_destroy_bitmap(new_character_selection->jack_robert);
    al_destroy_bitmap(new_character_selection->jack_ryo);
    al_destroy_bitmap(new_character_selection->jack_todoh);
    al_destroy_bitmap(new_character_selection->robert_jack);
    al_destroy_bitmap(new_character_selection->robert_robert);
    al_destroy_bitmap(new_character_selection->robert_ryo);
    al_destroy_bitmap(new_character_selection->robert_todoh);
    al_destroy_bitmap(new_character_selection->ryo_jack);
    al_destroy_bitmap(new_character_selection->ryo_robert);
    al_destroy_bitmap(new_character_selection->ryo_ryo);
    al_destroy_bitmap(new_character_selection->ryo_todoh);
    al_destroy_bitmap(new_character_selection->todoh_jack);
    al_destroy_bitmap(new_character_selection->todoh_robert);
    al_destroy_bitmap(new_character_selection->todoh_ryo);
    al_destroy_bitmap(new_character_selection->todoh_todoh);
    free(new_character_selection);
    return NULL;
  }

  return new_character_selection;
}

// Lida com a seleção do personagem
int character_selection(int *p1_option, int *p2_option, ALLEGRO_DISPLAY *display, int *game_done) {
  int selected_p1, selected_p2, done;
  characters *frames;
  ALLEGRO_TIMER *timer;
  ALLEGRO_EVENT_QUEUE *event_queue;
  ALLEGRO_EVENT event;

  selected_p1 = 0;
  selected_p2 = 0;

  frames = create_character_selection();
  if (!frames) {
    printf("Falha em criar tela de seleção do personagem.\n");
    return 0;
  }

  timer = al_create_timer(1 / 30.0);
  if (!timer) {
    printf("Falha ao criar timer - character_selection.\n");
    destroy_character_selection(frames);
    return 0;
  }

  event_queue = al_create_event_queue();
  if (!event_queue) {
    printf("Falha ao criar fila de eventos - character_selection.\n");
    destroy_character_selection(frames);
    al_destroy_timer(timer);
    return 0;
  }

  al_register_event_source(event_queue, al_get_keyboard_event_source());
  al_register_event_source(event_queue, al_get_display_event_source(display));
  al_register_event_source(event_queue, al_get_timer_event_source(timer));

  done = 0;
  al_start_timer(timer);
  while ((!done) && (!(*game_done))) {
    al_wait_for_event(event_queue, &event);

    if (event.type == ALLEGRO_EVENT_TIMER) {
      al_clear_to_color(al_map_rgb(0, 0, 0));

      // Define, a partir das opções dos 2 players, qual foto desenhar
      if ((*p1_option == 0) && (*p2_option == 0))
        al_draw_bitmap(frames->todoh_todoh, 0, 0, 0);
      else if ((*p1_option == 0) && (*p2_option == 1))
        al_draw_bitmap(frames->todoh_ryo, 0, 0, 0);
      else if ((*p1_option == 0) && (*p2_option == 2))
        al_draw_bitmap(frames->todoh_robert, 0, 0, 0);
      else if ((*p1_option == 0) && (*p2_option == 3))
        al_draw_bitmap(frames->todoh_jack, 0, 0, 0);
      else if ((*p1_option == 1) && (*p2_option == 0))
        al_draw_bitmap(frames->ryo_todoh, 0, 0, 0);
      else if ((*p1_option == 1) && (*p2_option == 1))
        al_draw_bitmap(frames->ryo_ryo, 0, 0, 0);
      else if ((*p1_option == 1) && (*p2_option == 2))
        al_draw_bitmap(frames->ryo_robert, 0, 0, 0);
      else if ((*p1_option == 1) && (*p2_option == 3))
        al_draw_bitmap(frames->ryo_jack, 0, 0, 0);
      else if ((*p1_option == 2) && (*p2_option == 0))
        al_draw_bitmap(frames->robert_todoh, 0, 0, 0);
      else if ((*p1_option == 2) && (*p2_option == 1))
        al_draw_bitmap(frames->robert_ryo, 0, 0, 0);
      else if ((*p1_option == 2) && (*p2_option == 2))
        al_draw_bitmap(frames->robert_robert, 0, 0, 0);
      else if ((*p1_option == 2) && (*p2_option == 3))
        al_draw_bitmap(frames->robert_jack, 0, 0, 0);
      else if ((*p1_option == 3) && (*p2_option == 0))
        al_draw_bitmap(frames->jack_todoh, 0, 0, 0);
      else if ((*p1_option == 3) && (*p2_option == 1))
        al_draw_bitmap(frames->jack_ryo, 0, 0, 0);
      else if ((*p1_option == 3) && (*p2_option == 2))
        al_draw_bitmap(frames->jack_robert, 0, 0, 0);
      else if ((*p1_option == 3) && (*p2_option == 3))
        al_draw_bitmap(frames->jack_jack, 0, 0, 0);

      al_flip_display();
    }

    if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
      if ((event.keyboard.keycode == ALLEGRO_KEY_A) && (!selected_p1)) {
        (*p1_option)--;
        if ((*p1_option) < 0)
          (*p1_option) = 0;
      }

      if ((event.keyboard.keycode == ALLEGRO_KEY_D) && (!selected_p1)) {
        (*p1_option)++;
        if ((*p1_option) > 3)
          (*p1_option) = 3;
      }
      
      if ((event.keyboard.keycode == ALLEGRO_KEY_LEFT) && (!selected_p2)) {
        (*p2_option)--;
        if ((*p2_option) < 0)
          (*p2_option) = 0;
      }

      if ((event.keyboard.keycode == ALLEGRO_KEY_RIGHT) && (!selected_p2)) {
        (*p2_option)++;
        if ((*p2_option) > 3)
          (*p2_option) = 3;
      }

      if (event.keyboard.keycode == ALLEGRO_KEY_ENTER)
        selected_p2 = 1;
      
      if (event.keyboard.keycode == ALLEGRO_KEY_SPACE)
        selected_p1 = 1;
    }

    if ((selected_p1) && (selected_p2))
      done = 1;
    
    if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
      *game_done = 1;
  }

  destroy_character_selection(frames);
  al_destroy_timer(timer);
  al_destroy_event_queue(event_queue);

  return 1;
}

// Destrói todas as fotos de seleção de personagem
void destroy_character_selection(characters *character_selection) {
  al_destroy_bitmap(character_selection->todoh_todoh);
  al_destroy_bitmap(character_selection->todoh_ryo);
  al_destroy_bitmap(character_selection->todoh_robert);
  al_destroy_bitmap(character_selection->todoh_jack);
  al_destroy_bitmap(character_selection->ryo_todoh);
  al_destroy_bitmap(character_selection->ryo_ryo);
  al_destroy_bitmap(character_selection->ryo_robert);
  al_destroy_bitmap(character_selection->ryo_jack);
  al_destroy_bitmap(character_selection->robert_todoh);
  al_destroy_bitmap(character_selection->robert_ryo);
  al_destroy_bitmap(character_selection->robert_robert);
  al_destroy_bitmap(character_selection->robert_jack);
  al_destroy_bitmap(character_selection->jack_todoh);
  al_destroy_bitmap(character_selection->jack_ryo);
  al_destroy_bitmap(character_selection->jack_robert);
  al_destroy_bitmap(character_selection->jack_jack);
  
  free(character_selection);
}