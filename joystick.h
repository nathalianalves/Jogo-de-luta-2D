/*  Biblioteca de funções relacionadas aos controladores de personagens
    Nathália Nogueira Alves - GRR20232349 - 2024*/

#ifndef _JOYSTICK_
#define _JOYSTICK_

#include <stdio.h>
#include <stdlib.h>

// Define a estrutura joystick. Cada sinal é 1 se o botão correspondente está pressionado e 0 caso contrário
typedef struct joystick joystick;
struct joystick {
  int up;
  int down;
  int left;
  int right;
  int attack_A;
  int attack_B;
  int special_attack;
  int defense;
};

// Cria um joystick e retorna um ponteiro para ele. Retorna NULL em caso de erro.
joystick *create_joystick();

// Inverte o sinal "up" no joystick passado como parâmetro
void joystick_up(joystick *control);

// Inverte o sinal "down" no joystick passado como parâmetro
void joystick_down(joystick *control);

// Inverte o sinal "left" no joystick passado como parâmetro
void joystick_left(joystick *control);

// Inverte o sinal "right" no joystick passado como parâmetro
void joystick_right(joystick *control);

// Inverte o sinal "attack_A" no joystick passado como parâmetro
void joystick_attack_A(joystick *control);

// Inverte o sinal "attack_B" no joystick passado como parâmetro
void joystick_attack_B(joystick *control);

// Inverte o sinal "special_attack" no joystick passado como parâmetro
void joystick_special_attack(joystick *control);

// Inverte o sinal "defense" no joystick passado como parâmetro
void joystick_defense(joystick *control);

// Desaloca memória usada para um joystick
void destroy_joystick(joystick *control);

#endif