/*  Biblioteca de funções relacionadas ao jogo
    Nathália Nogueira Alves - GRR20232349 - 2024*/

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include "player.h"

#define DISPLAY_WIDTH 651
#define DISPLAY_HEIGHT 435
#define FPS 60.0

/*Define a estrutura de dados usada para guardar atributos de uma luta*/
typedef struct fight {
  int rounds; 
  int current_round;
  ALLEGRO_BITMAP *background;

  player *player1;
  int player1_num_victories;

  player *player2;
  int player2_num_victories;

  int is_paused;
  int done;
  int winner;

  int end_of_round; // 1 se um round acabou (se está entre rounds), 0 caso contrário
  double end_time;  // Se end_of_round == 1, guarda o tempo em que acabou
} fight;

// Cria uma luta com os atributos que contem os IDS passados como parâmetro
fight *create_fight(int background_id, int player1_id, int player2_id);

// Começa o próximo round: incrementa current_round e o número de vitórias do ganhador (se houver um), atualiza vida e estados dos players
void reset_round(fight *game, int round_result);

// Desenha o estado atual do jogo: entre rounds ou em uma batalha
void draw_game(fight *game, ALLEGRO_FONT *font);

// Desaloca a memória utilizada para uma luta
void destroy_fight(fight *element);