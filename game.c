#include "game.h"

// Cria uma luta com os atributos que contem os IDS passados como parâmetro
fight *create_fight(int background_id, int player1_id, int player2_id) {
  fight *new_fight;

  new_fight = (fight*) malloc(sizeof(fight));
  if (!new_fight)
    return NULL;
  
  new_fight->rounds = 3;
  new_fight->current_round = 0;
  // Carrega o fundo com base em background_id
  if (background_id == 0)
    new_fight->background = al_load_bitmap("Sprites/Backgrounds/Down Town.png");
  else if (background_id == 1)
    new_fight->background = al_load_bitmap("Sprites/Backgrounds/Karuta.jpg");
  if (!new_fight->background) {
    printf("Não foi possível carregar background.\n");
    return NULL;
  }

  // Cria o player1 com base em player1_id
  if (player1_id == 0)
    new_fight->player1 = create_ryuhaku_todoh(1, DISPLAY_WIDTH, DISPLAY_HEIGHT);
  else if (player1_id == 1)
    new_fight->player1 = create_ryo_sakazaki(1, DISPLAY_WIDTH, DISPLAY_HEIGHT);
  else if (player1_id == 2)
    new_fight->player1 = create_robert_garcia(1, DISPLAY_WIDTH, DISPLAY_HEIGHT);
  else if (player1_id == 3)
    new_fight->player1 = create_jack_turner(1, DISPLAY_WIDTH, DISPLAY_HEIGHT);
  
  if (!new_fight->player1) {
    printf("Não foi possível criar jogador 1.\n");
    al_destroy_bitmap(new_fight->background);
    return NULL;
  }

  new_fight->player1_num_victories = 0;

  // Cria o player2 com base em player2_id
  if (player2_id == 0)
    new_fight->player2 = create_ryuhaku_todoh(-1, DISPLAY_WIDTH, DISPLAY_HEIGHT);
  else if (player2_id == 1)
    new_fight->player2 = create_ryo_sakazaki(-1, DISPLAY_WIDTH, DISPLAY_HEIGHT);
  else if (player2_id == 2)
    new_fight->player2 = create_robert_garcia(-1, DISPLAY_WIDTH, DISPLAY_HEIGHT);
  else if (player2_id == 3)
    new_fight->player2 = create_jack_turner(-1, DISPLAY_WIDTH, DISPLAY_HEIGHT);

  if (!new_fight->player2) {
    printf("Não foi possível criar jogador 2.\n");
    al_destroy_bitmap(new_fight->background);
    destroy_player(new_fight->player1);
    return NULL;
  }
  new_fight->player2_num_victories = 0;

  new_fight->is_paused = 0;
  new_fight->done = 0;
  new_fight->winner = 0;

  new_fight->end_of_round = 0;
  new_fight->end_time = 0;

  return new_fight;
}

// Começa o próximo round: incrementa current_round e o número de vitórias do ganhador (se houver um), atualiza vida e estados dos players
void reset_round(fight *game, int round_result) {
  game->current_round++;

  // Reinicia atributos - player1
  game->player1->life = 100;
  game->player1->is_taking_damage = 0;
  game->player1->is_dying = 0;
  game->player1->dead = 0;
  game->player1->face = 1;
  game->player1->x = (float) 20;
  if ((game->player1->ID == RYO) || (game->player1->ID == ROBERT))
    game->player1->frames_special_attack = 600;

  // Reinicia atributos - player2
  game->player2->life = 100;
  game->player2->is_taking_damage = 0;
  game->player2->is_dying = 0;
  game->player2->dead = 0;
  game->player2->face = -1;
  game->player2->x = (float) DISPLAY_WIDTH - 20;
  if ((game->player2->ID == RYO) || (game->player2->ID == ROBERT))
    game->player2->frames_special_attack = 600;

  // round_result guarda o número do player vencedor. Se for 0, houve empate.
  if (round_result == 1)
    game->player1_num_victories++;
  else if (round_result == 2)
    game->player2_num_victories++;

  if (game->player1_num_victories >= 2) {
    game->done = 1;
    game->winner = 1;
  } else if (game->player2_num_victories >= 2) {
    game->done = 1;
    game->winner = 2;
  } else if (game->current_round >= game->rounds) {
    game->done = 1;
    if (game->player1_num_victories > game->player2_num_victories)
      game->winner = 1;
    else if (game->player2_num_victories > game->player1_num_victories)
      game->winner = 2;
  }
}

// Desenha o estado atual do jogo: entre rounds ou em uma batalha
void draw_game(fight *game, ALLEGRO_FONT *font) {
  // Se os dois players estão mortos, houve empate
  if ((game->player1->dead) && (game->player2->dead)) {
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_textf(font, al_map_rgb(255, 255, 255), DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2, ALLEGRO_ALIGN_CENTER, "ROUND %d", game->current_round + 1);
    al_draw_text(font, al_map_rgb(255, 255, 255), DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2 + 30, ALLEGRO_ALIGN_CENTER, "TIE");
    al_flip_display();
    game->end_of_round = 1;
    game->end_time = al_get_time();

    reset_round(game, 0);
  } else if (game->player1->dead) { // Se o player1 está morto, vitória do player2
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_textf(font, al_map_rgb(255, 255, 255), DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2, ALLEGRO_ALIGN_CENTER, "ROUND %d", game->current_round + 1);
    al_draw_text(font, al_map_rgb(255, 255, 255), DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2 + 30, ALLEGRO_ALIGN_CENTER, "WINNER: PLAYER 2");
    al_flip_display();
    game->end_of_round = 1;
    game->end_time = al_get_time();

    reset_round(game, 2);
  } else if (game->player2->dead) { // Se o player2 está morto, vitória do player1
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_textf(font, al_map_rgb(255, 255, 255), DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2, ALLEGRO_ALIGN_CENTER, "ROUND %d", game->current_round + 1);
    al_draw_text(font, al_map_rgb(255, 255, 255), DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2 + 30, ALLEGRO_ALIGN_CENTER, "WINNER: PLAYER 1");
    al_flip_display();
    game->end_of_round = 1;
    game->end_time = al_get_time();

    reset_round(game, 1);
  } else { // Se nenhum dos dois players está morto, a batalha ainda está acontecendo
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_bitmap(game->background, 0, 0, 0);

    if (game->player1->is_taking_damage) {
      draw_player(game->player1);
      draw_player(game->player2);
    } else {
      draw_player(game->player2);
      draw_player(game->player1);
    }

    draw_HUD(game->player1, game->player2, DISPLAY_WIDTH);
    al_flip_display();
  }
}

// Desaloca a memória utilizada para uma luta
void destroy_fight(fight *element) {
  al_destroy_bitmap(element->background);
  destroy_player(element->player1);
  destroy_player(element->player2);
  free(element);
}