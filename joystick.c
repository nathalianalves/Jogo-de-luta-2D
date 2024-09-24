#include "joystick.h"

// Cria um joystick e retorna um ponteiro para ele. Retorna NULL em caso de erro.
joystick *create_joystick() {
  joystick *new_joystick;

  new_joystick = (joystick*) malloc(sizeof(joystick));
  if (!new_joystick)
    return NULL;
  
  new_joystick->up = 0;
  new_joystick->down = 0;
  new_joystick->left = 0;
  new_joystick->right = 0;
  new_joystick->attack_A = 0;
  new_joystick->attack_B = 0;
  new_joystick->special_attack = 0;
  new_joystick->defense = 0;

  return new_joystick;
}

// Inverte o sinal "up" no joystick passado como parâmetro
void joystick_up(joystick *control) {
  control->up = control->up ^ 1;
}

// Inverte o sinal "down" no joystick passado como parâmetro
void joystick_down(joystick *control) {
  control->down = control->down ^ 1;
}

// Inverte o sinal "left" no joystick passado como parâmetro
void joystick_left(joystick *control) {
  control->left = control->left ^ 1;
}

// Inverte o sinal "right" no joystick passado como parâmetro
void joystick_right(joystick *control) {
  control->right = control->right ^ 1;
}

// Inverte o sinal "attack_A" no joystick passado como parâmetro
void joystick_attack_A(joystick *control) {
  control->attack_A = control->attack_A ^ 1;
}

// Inverte o sinal "attack_B" no joystick passado como parâmetro
void joystick_attack_B(joystick *control) {
  control->attack_B = control->attack_B ^ 1;
}

// Inverte o sinal "special_attack" no joystick passado como parâmetro
void joystick_special_attack(joystick *control) {
  control->special_attack = control->special_attack ^ 1;
}

// Inverte o sinal "defense" no joystick passado como parâmetro
void joystick_defense(joystick *control) {
  control->defense = control->defense ^ 1;
}

// Desaloca memória usada para um joystick
void destroy_joystick(joystick *control) {
  free(control);
}