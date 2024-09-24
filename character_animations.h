/*  Biblioteca de funções relacionadas à criação de animações de personagens
    Nathália Nogueira Alves - GRR20232349 - 2024*/

#ifndef _CHARACTER_ANIMATIONS_
#define _CHARACTER_ANIMATIONS_

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "animation.h"

/*FUNÇÕES RELACIONADAS AO PERSONAGEM RYUHAKU TODOH*/
animation *create_todoh_neutral();

animation *create_todoh_walk();

animation *create_todoh_jump();

animation *create_todoh_crouch();

animation *create_todoh_attack_A();

animation *create_todoh_attack_B();

animation *create_todoh_jump_attack_A();

animation *create_todoh_crouch_attack();

animation *create_todoh_death();

/*FUNÇÕES RELACIONADAS AO PERSONAGEM RYO SAKAZAKI*/
animation *create_ryo_neutral();

animation *create_ryo_walk();

animation *create_ryo_jump();

animation *create_ryo_crouch();

animation *create_ryo_attack_A();

animation *create_ryo_attack_B();

animation *create_ryo_jump_attack_A();

animation *create_ryo_jump_attack_B();

animation *create_ryo_crouch_attack_A();

animation *create_ryo_crouch_attack_B();

animation *create_ryo_special_attack();

animation *create_ryo_death();

/* FUNÇÕES RELACIONADAS AO PERSONAGEM ROBERT GARCIA*/
animation *create_robert_neutral();

animation *create_robert_walk();

animation *create_robert_jump();

animation *create_robert_crouch();

animation *create_robert_attack_A();

animation *create_robert_attack_B();

animation *create_robert_jump_attack_A();

animation *create_robert_jump_attack_B();

animation *create_robert_crouch_attack_A();

animation *create_robert_crouch_attack_B();

animation *create_robert_special_attack();

animation *create_robert_death();

/*FUNÇÕES RELACIONADAS AO PERSONAGEM JACK TURNER*/
animation *create_jack_neutral();

animation *create_jack_walk();

animation *create_jack_jump();

animation *create_jack_crouch();

animation *create_jack_attack_A();

animation *create_jack_attack_B();

animation *create_jack_jump_attack_A();

animation *create_jack_death();

#endif