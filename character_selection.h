/*  Biblioteca de funções relacionadas à seleção de personagens
    Nathália Nogueira Alves - GRR20232349 - 2024*/

#ifndef _CHARACTER_SELECTION_
#define _CHARACTER_SELECTION_

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  ALLEGRO_BITMAP *todoh_todoh;
  ALLEGRO_BITMAP *todoh_ryo; 
  ALLEGRO_BITMAP *todoh_robert;
  ALLEGRO_BITMAP *todoh_jack;
  ALLEGRO_BITMAP *ryo_todoh;
  ALLEGRO_BITMAP *ryo_ryo;
  ALLEGRO_BITMAP *ryo_robert;
  ALLEGRO_BITMAP *ryo_jack;
  ALLEGRO_BITMAP *robert_todoh;
  ALLEGRO_BITMAP *robert_ryo;
  ALLEGRO_BITMAP *robert_robert;
  ALLEGRO_BITMAP *robert_jack;
  ALLEGRO_BITMAP *jack_todoh;
  ALLEGRO_BITMAP *jack_ryo;
  ALLEGRO_BITMAP *jack_robert;
  ALLEGRO_BITMAP *jack_jack;
} characters;

// Cria a struct de seleção de personagem (que contem as 16 opções de escolha possíveis)
characters *create_character_selection();

// Lida com a seleção do personagem
int character_selection(int *p1_option, int *p2_option, ALLEGRO_DISPLAY *display, int *game_done);

// Destrói todas as fotos de seleção de personagem
void destroy_character_selection(characters *character_selection);

#endif