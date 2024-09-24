/*  Biblioteca de funções relacionadas ao menu do jogo
    Nathália Nogueira Alves - GRR20232349 - 2024*/

#ifndef _MENU_
#define _MENU_

#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

// Desenha o menu e retorna em *option a opção decidida
int menu(int *option, int *game_done, ALLEGRO_DISPLAY *display);

#endif