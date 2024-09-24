/*  Biblioteca de funções relacionadas à struct de animação
    Nathália Nogueira Alves - GRR20232349 - 2024*/
    
#ifndef _ANIMATIONS_
#define _ANIMATIONS_

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

// Define a estrutura de animações
typedef struct {
  int num_frames;
  ALLEGRO_BITMAP **frames;
  int current_frame;
} animation;

// Cria uma animação com o número de frames passados como parâmetro
animation *create_animation(int num_frames);

// Desaloca a memoria utilizada para uma struct de animação
void destroy_animation(animation *element, int num_valid);

#endif