#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdio.h>
#include <time.h>
#include "menu.h"
#include "character_selection.h"
#include "game.h"

int main() {
  int background_id, menu_option, p1, p2, done;
  fight *game;

  // Variáveis Allegro
  ALLEGRO_DISPLAY *display;
  ALLEGRO_TIMER *timer;
  ALLEGRO_EVENT_QUEUE *event_queue;
  ALLEGRO_EVENT event;
  ALLEGRO_FONT *aof_font_24;

  srand(time(NULL));

  // Inicialização Allegro
  al_init();
  al_init_image_addon();
  al_init_primitives_addon();
  al_init_font_addon();
  al_init_ttf_addon();
  al_install_keyboard();

  // Criação e tratamento de erros - display
  display = al_create_display(DISPLAY_WIDTH, DISPLAY_HEIGHT);
  if (!display) {
    printf("Não foi possível criar display.\n");
    return -1;
  }

  // Criação e tratamento de erros - timer
  timer = al_create_timer(1.0 / FPS);
  if (!timer) {
    printf("Não foi possível criar timer.\n");
    al_destroy_display(display);
    return -1;
  }

  // Criação e tratamento de erros - fila de eventos
  event_queue = al_create_event_queue();
  if (!event_queue) {
    printf("Não foi possível criar fila de eventos.\n");
    al_destroy_display(display);
    al_destroy_timer(timer);
    return -1;
  }

  // Criação e tratamento de erros - fonte
  aof_font_24 = al_load_font("Fonts/art-of-fighting-2.ttf", 24, 0);
  if (!aof_font_24) {
    printf("Não foi possível carregar fonte.\n");
    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_event_queue(event_queue);
    return -1;
  }

  // Primeiro passo: menu (menu_option guarda a opção final)
  done = 0;
  menu_option = 0;
  if (!menu(&menu_option, &done, display)) {
    printf("Erro no menu.\n");
    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_event_queue(event_queue);
    al_destroy_font(aof_font_24);
    return -1;
  }

  if (menu_option == 1)
    done = 1;

  // Segundo passo: seleção de personagem (p1 e p2 guardam as opções finais)
  p1 = 0;
  p2 = 0;
  if (!done) {
    if(!character_selection(&p1, &p2, display, &done)) {
      printf("Erro na seleção de personagem.\n");
      al_destroy_display(display);
      al_destroy_timer(timer);
      al_destroy_event_queue(event_queue);
      al_destroy_font(aof_font_24);
      return -1;
    }
  }

  // Sorteia a paisagem da luta 
  background_id = rand() % 2;

  // Criação e tratamento de erros - atributos do jogo
  game = create_fight(background_id, p1, p2);
  if (!game) {
    printf("Não foi possível criar partida.\n");
    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_event_queue(event_queue);
    al_destroy_font(aof_font_24);
    return -1;
  }

  // Configura a fila de eventos
  al_register_event_source(event_queue, al_get_keyboard_event_source());
  al_register_event_source(event_queue, al_get_display_event_source(display));
  al_register_event_source(event_queue, al_get_timer_event_source(timer));

  // Loop principal
  al_start_timer(timer);
  while (!done) {
    al_wait_for_event(event_queue, &event);

    if (!game->is_paused) {
      if (!game->done) {
        if (event.type == ALLEGRO_EVENT_TIMER) {
          // Se o jogo está entre dois rounds, "segura" a tela com o vencedor da rodada
          if (game->end_of_round) { 
            if (al_get_time() - game->end_time >= 2.0) 
              game->end_of_round = 0;
          } else { // Se um round está acontecendo, atualiza e desenha o estado atual
            update_player(game->player1, game->player2, DISPLAY_WIDTH, DISPLAY_HEIGHT);
            draw_game(game, aof_font_24);
          }
        }

        // Organiza o controle do personagem
        if ((event.type == ALLEGRO_EVENT_KEY_DOWN) || (event.type == ALLEGRO_EVENT_KEY_UP)) {
          set_controls(&event, game->player1, game->player2);
        }
      } else {
        if (event.type == ALLEGRO_EVENT_TIMER) {
          al_clear_to_color(al_map_rgb(0, 0, 0));

          // Desenha resultados 
          if (game->winner == 0) // CASO 1: Empate
            al_draw_text(aof_font_24, al_map_rgb(255, 255, 255), DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2, ALLEGRO_ALIGN_CENTER, "TIE");  
          else if (game->winner == 1) { // CASO 2: Player1 vence
            al_draw_text(aof_font_24, al_map_rgb(255, 255, 255), DISPLAY_WIDTH / 2 - 200, DISPLAY_HEIGHT / 2 - 30, ALLEGRO_ALIGN_CENTER, "WINNER:");
            al_draw_text(aof_font_24, al_map_rgb(255, 255, 255), DISPLAY_WIDTH / 2 - 200, DISPLAY_HEIGHT / 2, ALLEGRO_ALIGN_CENTER, "PLAYER 1");
            al_draw_bitmap(game->player1->profile, DISPLAY_WIDTH / 2 - game->player1->profile_width / 2 - 200, DISPLAY_HEIGHT / 2 + 30, 0);
            al_draw_text(aof_font_24, al_map_rgb(255, 255, 255), DISPLAY_WIDTH / 2 + 200, DISPLAY_HEIGHT / 2 - 30, ALLEGRO_ALIGN_CENTER, "LOSER:");
            al_draw_text(aof_font_24, al_map_rgb(255, 255, 255), DISPLAY_WIDTH / 2 + 200, DISPLAY_HEIGHT / 2, ALLEGRO_ALIGN_CENTER, "PLAYER 2");
            al_draw_bitmap(game->player2->profile, DISPLAY_WIDTH / 2 - game->player1->profile_width / 2 + 200, DISPLAY_HEIGHT / 2 + 30, 0);
          } else { // CASO 3: Player2 vence
            al_draw_text(aof_font_24, al_map_rgb(255, 255, 255), DISPLAY_WIDTH / 2 + 200, DISPLAY_HEIGHT / 2 - 30, ALLEGRO_ALIGN_CENTER, "WINNER:");
            al_draw_text(aof_font_24, al_map_rgb(255, 255, 255), DISPLAY_WIDTH / 2 + 200, DISPLAY_HEIGHT / 2, ALLEGRO_ALIGN_CENTER, "PLAYER 2");
            al_draw_bitmap(game->player2->profile, DISPLAY_WIDTH / 2 - game->player2->profile_width / 2 + 200, DISPLAY_HEIGHT / 2 + 30, 0);
            al_draw_text(aof_font_24, al_map_rgb(255, 255, 255), DISPLAY_WIDTH / 2 - 200, DISPLAY_HEIGHT / 2 - 30, ALLEGRO_ALIGN_CENTER, "LOSER:");
            al_draw_text(aof_font_24, al_map_rgb(255, 255, 255), DISPLAY_WIDTH / 2 - 200, DISPLAY_HEIGHT / 2, ALLEGRO_ALIGN_CENTER, "PLAYER 1");
            al_draw_bitmap(game->player1->profile, DISPLAY_WIDTH / 2 - game->player2->profile_width / 2 - 200, DISPLAY_HEIGHT / 2 + 30, 0);
          }

          al_flip_display();
        }
      }
    } else {
      // Se está pausado, desenha na tela
      if (event.type == ALLEGRO_EVENT_TIMER) {
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_text(aof_font_24, al_map_rgb(255, 255, 255), DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2, ALLEGRO_ALIGN_CENTER, "PAUSED!");
        al_flip_display();
      }
    }

    // ESC: pausa/despausa
    if ((event.type == ALLEGRO_EVENT_KEY_DOWN) && (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE))
      game->is_paused = game->is_paused ^ 1;

    if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) 
      done = 1;
    
  }

  // Desaloca as variáveis
  al_destroy_display(display);
  al_destroy_timer(timer);
  al_destroy_event_queue(event_queue);
  al_destroy_font(aof_font_24);
  destroy_fight(game);

  return 0;
}