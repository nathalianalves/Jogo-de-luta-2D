/*  Biblioteca de funções relacionadas à jogadores (atualizações de movimento, de animações)
    Nathália Nogueira Alves - GRR20232349 - 2024*/

/*CONTROLES:
  - Player1: 
    movimentação: WASD
    ataque A: C
    ataque B: V
    defesa: B
    ataque especial (se houver): F
    
  - Player2:
    movimentação: flechas
    ataque A: P
    ataque B: O
    defesa: K
    ataque especial (se houver): L
*/

#ifndef _PLAYER_
#define _PLAYER_

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "joystick.h"
#include "character_animations.h"
#include "animation.h"

#define TODOH 0
#define RYO 1
#define ROBERT 2
#define JACK 3

#define NEUTRAL 0
#define WALK 1
#define JUMP 2
#define CROUCH 3
#define ATTACK_A 4
#define ATTACK_B 5
#define JUMP_ATTACK_A 6
#define JUMP_ATTACK_B 7
#define CROUCH_ATTACK_A 8
#define CROUCH_ATTACK_B 9
#define SPECIAL_ATTACK 10
#define DEATH 11
#define STANDING_DEFENSE 12
#define CROUCH_DEFENSE 13

/*Define a estrutura de dados de um personagem*/
typedef struct {
  int ID; // Número que identifica o personagem
  int face; // 1 - virado para a direita | -1 - virado para a esquerda
  int life; 

  ALLEGRO_BITMAP *profile;
  int profile_width;
  int profile_height;

  /*Animações*/
  animation *neutral; 
  animation *walk; 
  animation *jump; 
  animation *crouch; 
  animation *attack_A; 
  animation *attack_B; 
  animation *jump_attack_A; 
  animation *jump_attack_B;
  animation *crouch_attack_A;
  animation *crouch_attack_B;
  animation *special_attack;
  animation *death;
  ALLEGRO_BITMAP *standing_defense;
  ALLEGRO_BITMAP *crouch_defense;

  int previous_animation; // Se a animação mudou, usada para zerar o frame da animação anterior
  int current_animation; 
  int current_width;
  int current_height;
  
  int frame_count; // Contador: quantos frames se passaram sem atualizações na animação
  int frame_delay; // Quantos frames devem se passar sem atualizações na animação

  float x;
  float y;
  float speed;

  int is_jumping;
  float jump_speed;

  int is_A_attacking;
  int is_B_attacking;

  int is_special_attacking; // -1 se o personagem não tiver ataque especial, 0 se tiver e não estiver em uso, 1 se estiver atacando
  int frames_special_attack; // Quantos frames se passaram sem ataque especial. Se for 600, o jogador pode usar o ataque novamente

  int is_taking_damage; // Usado para definir se está levando dano. Se está, qualquer outra ação é bloqueada.
  int is_dying; // Usado para definir se a animação atual é a de morte
  int dead;

  joystick *control;
} player;

// Cria um personagem com as especificidades do Ryuhaku Todoh. Retorna NULL para erro.
player *create_ryuhaku_todoh(int face, float display_x, float display_y);

// Cria um personagem com as especificidades do Ryo Sakazaki. Retorna NULL para erro.
player *create_ryo_sakazaki(int face, float display_x, float display_y);

// Cria um personagem com as especificidades do Robert Garcia. Retorna NULL para erro.
player *create_robert_garcia(int face, float display_x, float display_y);

player *create_jack_turner(int face, float display_x, float display_y);

// Atualiza o joystick dos jogadores passados como parametro
void set_controls(ALLEGRO_EVENT *event, player *element1, player *element2);

// Retorna 1 se houve colisão entre os 2 personagens, e 0 caso contrário. 
int colision(player *element1, player *element2);

// Verifica se o jogador ultrapassou os limites do display. Se passou, corrige x ou y
void verify_display_limits(player *element, int display_x, int display_y);

// Atualiza medidas (width e height) do jogador passado como parametro
void update_measures(player *element);

// Se necessário, zera current_animation da última animação do personagem
void reset_animation(player *element);

// Atualiza posição, animação e medidas do personagem
void update_player(player *element1, player *element2, float display_x, float display_y);

// Atualiza o campo "face" dos dois jogadores passados como parâmetro. Os personagens sempre devem ficar de frente um para o outro
void update_faces(player *element1, player *element2);

// Imprime o frame atual da animação atual na tela
void draw_player(player *element);

// Desenha informações sobre os dois players: retângulo superior, rosto do personagem, valor da vida e, se houver, ataque especial
void draw_HUD(player *element1, player *element2, int display_x);

// Desaloca a memória usada para um personagem
void destroy_player(player *element);

#endif