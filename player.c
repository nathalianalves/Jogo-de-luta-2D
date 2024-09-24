#include "player.h"

// Cria o personagem "Ryuhaku Todoh" e retorna sua struct
player *create_ryuhaku_todoh(int face, float display_x, float display_y) {
  player *new_todoh;

  // Aloca memória para o personagem
  new_todoh = (player*) malloc(sizeof(player));
  if (!new_todoh)
    return NULL;
  
  new_todoh->ID = TODOH;
  new_todoh->face = face;
  new_todoh->life = 100;

  // Criação e tratamento de erros - foto do rosto
  new_todoh->profile = al_load_bitmap("Sprites/Ryuhaku Todoh/Todoh.png");
  if (!new_todoh->profile) {
    free(new_todoh);
    return NULL;
  }

  // Carrega elementos sobre a foto do rosto
  new_todoh->profile_width = al_get_bitmap_width(new_todoh->profile);
  new_todoh->profile_height = al_get_bitmap_height(new_todoh->profile);

  // Criação e tratamento de erros - animação neutra
  new_todoh->neutral = create_todoh_neutral();
  if (!new_todoh->neutral) {
    al_destroy_bitmap(new_todoh->profile);
    free(new_todoh);
    return NULL;
  }

  // Criação e tratamento de erros - animação andando
  new_todoh->walk = create_todoh_walk();  
  if (!new_todoh->walk) {
    al_destroy_bitmap(new_todoh->profile);
    destroy_animation(new_todoh->neutral, new_todoh->neutral->num_frames);
    free(new_todoh);
    return NULL;
  }
  
  // Criação e tratamento de erros - animação do pulo
  new_todoh->jump = create_todoh_jump();
  if (!new_todoh->jump) {
    al_destroy_bitmap(new_todoh->profile);
    destroy_animation(new_todoh->neutral, new_todoh->neutral->num_frames);
    destroy_animation(new_todoh->walk, new_todoh->walk->num_frames);
    free(new_todoh);
    return NULL;
  }

  // Criação e tratamento de erros - animação agachado
  new_todoh->crouch = create_todoh_crouch();
  if (!new_todoh->crouch) {
    al_destroy_bitmap(new_todoh->profile);
    destroy_animation(new_todoh->neutral, new_todoh->neutral->num_frames);
    destroy_animation(new_todoh->walk, new_todoh->walk->num_frames);
    destroy_animation(new_todoh->jump, new_todoh->jump->num_frames);
    free(new_todoh);
    return NULL;
  }

  // Criação e tratamento de erros - animação de ataque A
  new_todoh->attack_A = create_todoh_attack_A();
  if (!new_todoh->attack_A) {
    al_destroy_bitmap(new_todoh->profile);
    destroy_animation(new_todoh->neutral, new_todoh->neutral->num_frames);
    destroy_animation(new_todoh->walk, new_todoh->walk->num_frames);
    destroy_animation(new_todoh->jump, new_todoh->jump->num_frames);
    destroy_animation(new_todoh->crouch, new_todoh->crouch->num_frames);
    free(new_todoh);
    return NULL;
  }

  // Criação e tratamento de erros - animação de ataque B
  new_todoh->attack_B = create_todoh_attack_B();
  if (!new_todoh->attack_B) {
    al_destroy_bitmap(new_todoh->profile);
    destroy_animation(new_todoh->neutral, new_todoh->neutral->num_frames);
    destroy_animation(new_todoh->walk, new_todoh->walk->num_frames);
    destroy_animation(new_todoh->jump, new_todoh->jump->num_frames);
    destroy_animation(new_todoh->crouch, new_todoh->crouch->num_frames);
    destroy_animation(new_todoh->attack_A, new_todoh->attack_A->num_frames);
    free(new_todoh);
    return NULL;
  }

  // Criação e tratamento de erros - animação de ataque A no ar
  new_todoh->jump_attack_A = create_todoh_jump_attack_A();
  if (!new_todoh->jump_attack_A) {
    al_destroy_bitmap(new_todoh->profile);
    destroy_animation(new_todoh->neutral, new_todoh->neutral->num_frames);
    destroy_animation(new_todoh->walk, new_todoh->walk->num_frames);
    destroy_animation(new_todoh->jump, new_todoh->jump->num_frames);
    destroy_animation(new_todoh->crouch, new_todoh->crouch->num_frames);
    destroy_animation(new_todoh->attack_A, new_todoh->attack_A->num_frames);
    destroy_animation(new_todoh->attack_B, new_todoh->attack_B->num_frames);
    free(new_todoh);
    return NULL;
  }

  // Ataque B no ar é o mesmo que o ataque A no ar
  new_todoh->jump_attack_B = new_todoh->jump_attack_A;

  // Criação e tratamento de erros - animação de ataque A agachado
  new_todoh->crouch_attack_A = create_todoh_crouch_attack();
  if (!new_todoh->crouch_attack_A) {
    al_destroy_bitmap(new_todoh->profile);
    destroy_animation(new_todoh->neutral, new_todoh->neutral->num_frames);
    destroy_animation(new_todoh->walk, new_todoh->walk->num_frames);
    destroy_animation(new_todoh->jump, new_todoh->jump->num_frames);
    destroy_animation(new_todoh->crouch, new_todoh->crouch->num_frames);
    destroy_animation(new_todoh->attack_A, new_todoh->attack_A->num_frames);
    destroy_animation(new_todoh->attack_B, new_todoh->attack_B->num_frames);
    destroy_animation(new_todoh->jump_attack_A, new_todoh->jump_attack_A->num_frames);
    free(new_todoh);
    return NULL;
  }

  // Ataque B agachado é o mesmo que o ataque A agachado
  new_todoh->crouch_attack_B = new_todoh->crouch_attack_A;

  // Não tem ataque especial
  new_todoh->special_attack = NULL;

  // Criação e tratamento de erros - animação de morte
  new_todoh->death = create_todoh_death();
  if (!new_todoh->death) {
    al_destroy_bitmap(new_todoh->profile);
    destroy_animation(new_todoh->neutral, new_todoh->neutral->num_frames);
    destroy_animation(new_todoh->walk, new_todoh->walk->num_frames);
    destroy_animation(new_todoh->jump, new_todoh->jump->num_frames);
    destroy_animation(new_todoh->crouch, new_todoh->crouch->num_frames);
    destroy_animation(new_todoh->attack_A, new_todoh->attack_A->num_frames);
    destroy_animation(new_todoh->attack_B, new_todoh->attack_B->num_frames);
    destroy_animation(new_todoh->jump_attack_A, new_todoh->jump_attack_A->num_frames);
    destroy_animation(new_todoh->crouch_attack_A, new_todoh->crouch_attack_A->num_frames);
    free(new_todoh);
    return NULL;
  }

  // Criação e tratamento de erros - defesa em pé
  new_todoh->standing_defense = al_load_bitmap("Sprites/Ryuhaku Todoh/Stand Defense.png");
  if (!new_todoh->standing_defense) {
    al_destroy_bitmap(new_todoh->profile);
    destroy_animation(new_todoh->neutral, new_todoh->neutral->num_frames);
    destroy_animation(new_todoh->walk, new_todoh->walk->num_frames);
    destroy_animation(new_todoh->jump, new_todoh->jump->num_frames);
    destroy_animation(new_todoh->crouch, new_todoh->crouch->num_frames);
    destroy_animation(new_todoh->attack_A, new_todoh->attack_A->num_frames);
    destroy_animation(new_todoh->attack_B, new_todoh->attack_B->num_frames);
    destroy_animation(new_todoh->jump_attack_A, new_todoh->jump_attack_A->num_frames);
    destroy_animation(new_todoh->crouch_attack_A, new_todoh->crouch_attack_A->num_frames);
    destroy_animation(new_todoh->death, new_todoh->death->num_frames);
    free(new_todoh);
    return NULL;
  }

  // Criação e tratamento de erros - defesa agachado
  new_todoh->crouch_defense = al_load_bitmap("Sprites/Ryuhaku Todoh/Crouch Defense.png");
  if (!new_todoh->crouch_defense) {
    al_destroy_bitmap(new_todoh->profile);
    destroy_animation(new_todoh->neutral, new_todoh->neutral->num_frames);
    destroy_animation(new_todoh->walk, new_todoh->walk->num_frames);
    destroy_animation(new_todoh->jump, new_todoh->jump->num_frames);
    destroy_animation(new_todoh->crouch, new_todoh->crouch->num_frames);
    destroy_animation(new_todoh->attack_A, new_todoh->attack_A->num_frames);
    destroy_animation(new_todoh->attack_B, new_todoh->attack_B->num_frames);
    destroy_animation(new_todoh->jump_attack_A, new_todoh->jump_attack_A->num_frames);
    destroy_animation(new_todoh->crouch_attack_A, new_todoh->crouch_attack_A->num_frames);
    destroy_animation(new_todoh->death, new_todoh->death->num_frames);
    al_destroy_bitmap(new_todoh->standing_defense);
    free(new_todoh);
    return NULL;
  } 

  // Animação inicial: neutra
  new_todoh->current_animation = NEUTRAL; 
  new_todoh->current_width = al_get_bitmap_width(new_todoh->neutral->frames[new_todoh->neutral->current_frame]);
  new_todoh->current_height = al_get_bitmap_height(new_todoh->neutral->frames[new_todoh->neutral->current_frame]);

  /* Configura as variáveis frame_count (quantos frames se passaram sem atualização) 
     e frame_delay (quantos frames tem que se passar antes de atualizar)             */
  new_todoh->frame_count = 0;
  new_todoh->frame_delay = 15;

  // Configura as variáveis de posição do personagem
  if (new_todoh->face == 1)
    new_todoh->x = (float) 20.0;
  else if (new_todoh->face == -1)
    new_todoh->x = (float) display_x - 20.0;

  new_todoh->y = (float) display_y - new_todoh->current_height;
  new_todoh->speed = (float) 5.0;

  // Inicializa outras variáveis
  new_todoh->is_jumping = 0;
  new_todoh->jump_speed = (float) -20;

  new_todoh->is_A_attacking = 0;
  new_todoh->is_B_attacking = 0;

  new_todoh->is_special_attacking = 0;
  new_todoh->frames_special_attack = -1;

  new_todoh->is_taking_damage = 0;
  new_todoh->is_dying = 0;
  new_todoh->dead = 0;

  // Cria o joystick controlador do personagem
  new_todoh->control = create_joystick();
  if (!new_todoh->control) {
    al_destroy_bitmap(new_todoh->profile);
    destroy_animation(new_todoh->neutral, new_todoh->neutral->num_frames);
    destroy_animation(new_todoh->walk, new_todoh->walk->num_frames);
    destroy_animation(new_todoh->jump, new_todoh->jump->num_frames);
    destroy_animation(new_todoh->crouch, new_todoh->crouch->num_frames);
    destroy_animation(new_todoh->attack_A, new_todoh->attack_A->num_frames);
    destroy_animation(new_todoh->attack_B, new_todoh->attack_B->num_frames);
    destroy_animation(new_todoh->jump_attack_A, new_todoh->jump_attack_A->num_frames);
    destroy_animation(new_todoh->crouch_attack_A, new_todoh->crouch_attack_A->num_frames);
    destroy_animation(new_todoh->death, new_todoh->death->num_frames);
    al_destroy_bitmap(new_todoh->standing_defense);
    al_destroy_bitmap(new_todoh->crouch_defense);
    free(new_todoh);
    return NULL;
  }

  return new_todoh;
}

// Cria o personagem "Ryo Sakazaki" e retorna sua struct
player *create_ryo_sakazaki(int face, float display_x, float display_y) {
  player *new_ryo;

  // Aloca memória para o personagem
  new_ryo = (player*) malloc(sizeof(player));
  if (!new_ryo)
    return NULL;

  new_ryo->ID = RYO;
  new_ryo->face = face;
  new_ryo->life = 100;

  // Criação e tratamento de erros - foto do rosto
  new_ryo->profile = al_load_bitmap("Sprites/Ryo Sakazaki/Ryo.png");
  if (!new_ryo->profile) {
    free(new_ryo);
    return NULL;
  }

  // Carrega elementos sobre a foto do rosto
  new_ryo->profile_width = al_get_bitmap_width(new_ryo->profile);
  new_ryo->profile_height = al_get_bitmap_height(new_ryo->profile);

  // Criação e tratamento de erros - animação neutra
  new_ryo->neutral = create_ryo_neutral();
  if (!new_ryo->neutral) {
    al_destroy_bitmap(new_ryo->profile);
    free(new_ryo);
    return NULL;
  }

  // Criação e tratamento de erros - animação andando
  new_ryo->walk = create_ryo_walk();  
  if (!new_ryo->walk) {
    al_destroy_bitmap(new_ryo->profile);
    destroy_animation(new_ryo->neutral, new_ryo->neutral->num_frames);
    free(new_ryo);
    return NULL;
  }

  // Criação e tratamento de erros - animação do pulo
  new_ryo->jump = create_ryo_jump();
  if (!new_ryo->jump) {
    al_destroy_bitmap(new_ryo->profile);
    destroy_animation(new_ryo->neutral, new_ryo->neutral->num_frames);
    destroy_animation(new_ryo->walk, new_ryo->walk->num_frames);
    free(new_ryo);
    return NULL;
  }

  // Criação e tratamento de erros - animação agachado
  new_ryo->crouch = create_ryo_crouch();
  if (!new_ryo->crouch) {
    al_destroy_bitmap(new_ryo->profile);
    destroy_animation(new_ryo->neutral, new_ryo->neutral->num_frames);
    destroy_animation(new_ryo->walk, new_ryo->walk->num_frames);
    destroy_animation(new_ryo->jump, new_ryo->jump->num_frames);
    free(new_ryo);
    return NULL;
  }

  // Criação e tratamento de erros - ataque A
  new_ryo->attack_A = create_ryo_attack_A();
  if (!new_ryo->attack_A) {
    al_destroy_bitmap(new_ryo->profile);
    destroy_animation(new_ryo->neutral, new_ryo->neutral->num_frames);
    destroy_animation(new_ryo->walk, new_ryo->walk->num_frames);
    destroy_animation(new_ryo->jump, new_ryo->jump->num_frames);
    destroy_animation(new_ryo->crouch, new_ryo->crouch->num_frames);
    free(new_ryo);
    return NULL;
  }

  // Criação e tratamento de erros - ataque B
  new_ryo->attack_B = create_ryo_attack_B();
  if (!new_ryo->attack_B) {
    al_destroy_bitmap(new_ryo->profile);
    destroy_animation(new_ryo->neutral, new_ryo->neutral->num_frames);
    destroy_animation(new_ryo->walk, new_ryo->walk->num_frames);
    destroy_animation(new_ryo->jump, new_ryo->jump->num_frames);
    destroy_animation(new_ryo->crouch, new_ryo->crouch->num_frames);
    destroy_animation(new_ryo->attack_A, new_ryo->attack_A->num_frames);
    free(new_ryo);
    return NULL;
  }

  // Criação e tratamento de erros - ataque A no ar
  new_ryo->jump_attack_A = create_ryo_jump_attack_A();
  if (!new_ryo->jump_attack_A) {
    al_destroy_bitmap(new_ryo->profile);
    destroy_animation(new_ryo->neutral, new_ryo->neutral->num_frames);
    destroy_animation(new_ryo->walk, new_ryo->walk->num_frames);
    destroy_animation(new_ryo->jump, new_ryo->jump->num_frames);
    destroy_animation(new_ryo->crouch, new_ryo->crouch->num_frames);
    destroy_animation(new_ryo->attack_A, new_ryo->attack_A->num_frames);
    destroy_animation(new_ryo->attack_B, new_ryo->attack_B->num_frames);
    free(new_ryo);
    return NULL;
  }

  // Criação e tratamento de erros - ataque B no ar
  new_ryo->jump_attack_B = create_ryo_jump_attack_B();
  if (!new_ryo->jump_attack_B) {
    al_destroy_bitmap(new_ryo->profile);
    destroy_animation(new_ryo->neutral, new_ryo->neutral->num_frames);
    destroy_animation(new_ryo->walk, new_ryo->walk->num_frames);
    destroy_animation(new_ryo->jump, new_ryo->jump->num_frames);
    destroy_animation(new_ryo->crouch, new_ryo->crouch->num_frames);
    destroy_animation(new_ryo->attack_A, new_ryo->attack_A->num_frames);
    destroy_animation(new_ryo->attack_B, new_ryo->attack_B->num_frames);
    destroy_animation(new_ryo->jump_attack_A, new_ryo->jump_attack_A->num_frames);
    free(new_ryo);
    return NULL;
  }

  // Criação e tratamento de erros - ataque A agachado
  new_ryo->crouch_attack_A = create_ryo_crouch_attack_A();
  if (!new_ryo->crouch_attack_A) {
    al_destroy_bitmap(new_ryo->profile);
    destroy_animation(new_ryo->neutral, new_ryo->neutral->num_frames);
    destroy_animation(new_ryo->walk, new_ryo->walk->num_frames);
    destroy_animation(new_ryo->jump, new_ryo->jump->num_frames);
    destroy_animation(new_ryo->crouch, new_ryo->crouch->num_frames);
    destroy_animation(new_ryo->attack_A, new_ryo->attack_A->num_frames);
    destroy_animation(new_ryo->attack_B, new_ryo->attack_B->num_frames);
    destroy_animation(new_ryo->jump_attack_A, new_ryo->jump_attack_A->num_frames);
    destroy_animation(new_ryo->jump_attack_B, new_ryo->jump_attack_B->num_frames);
    free(new_ryo);
    return NULL;
  }

  // Criação e tratamento de erros - ataque B agachado
  new_ryo->crouch_attack_B = create_ryo_crouch_attack_B();
  if (!new_ryo->crouch_attack_B) {
    al_destroy_bitmap(new_ryo->profile);
    destroy_animation(new_ryo->neutral, new_ryo->neutral->num_frames);
    destroy_animation(new_ryo->walk, new_ryo->walk->num_frames);
    destroy_animation(new_ryo->jump, new_ryo->jump->num_frames);
    destroy_animation(new_ryo->crouch, new_ryo->crouch->num_frames);
    destroy_animation(new_ryo->attack_A, new_ryo->attack_A->num_frames);
    destroy_animation(new_ryo->attack_B, new_ryo->attack_B->num_frames);
    destroy_animation(new_ryo->jump_attack_A, new_ryo->jump_attack_A->num_frames);
    destroy_animation(new_ryo->jump_attack_B, new_ryo->jump_attack_B->num_frames);
    destroy_animation(new_ryo->crouch_attack_A, new_ryo->crouch_attack_A->num_frames);
    free(new_ryo);
    return NULL;
  }

  // Criação e tratamento de erros - ataque especial
  new_ryo->special_attack = create_ryo_special_attack();
  if (!new_ryo->special_attack) {
    al_destroy_bitmap(new_ryo->profile);
    destroy_animation(new_ryo->neutral, new_ryo->neutral->num_frames);
    destroy_animation(new_ryo->walk, new_ryo->walk->num_frames);
    destroy_animation(new_ryo->jump, new_ryo->jump->num_frames);
    destroy_animation(new_ryo->crouch, new_ryo->crouch->num_frames);
    destroy_animation(new_ryo->attack_A, new_ryo->attack_A->num_frames);
    destroy_animation(new_ryo->attack_B, new_ryo->attack_B->num_frames);
    destroy_animation(new_ryo->jump_attack_A, new_ryo->jump_attack_A->num_frames);
    destroy_animation(new_ryo->jump_attack_B, new_ryo->jump_attack_B->num_frames);
    destroy_animation(new_ryo->crouch_attack_A, new_ryo->crouch_attack_A->num_frames);
    destroy_animation(new_ryo->crouch_attack_B, new_ryo->crouch_attack_B->num_frames);
    free(new_ryo);
    return NULL;
  }

  // Criação e tratamento de erros - morte
  new_ryo->death = create_ryo_death();
  if (!new_ryo->death) {
    al_destroy_bitmap(new_ryo->profile);
    destroy_animation(new_ryo->neutral, new_ryo->neutral->num_frames);
    destroy_animation(new_ryo->walk, new_ryo->walk->num_frames);
    destroy_animation(new_ryo->jump, new_ryo->jump->num_frames);
    destroy_animation(new_ryo->crouch, new_ryo->crouch->num_frames);
    destroy_animation(new_ryo->attack_A, new_ryo->attack_A->num_frames);
    destroy_animation(new_ryo->attack_B, new_ryo->attack_B->num_frames);
    destroy_animation(new_ryo->jump_attack_A, new_ryo->jump_attack_A->num_frames);
    destroy_animation(new_ryo->jump_attack_B, new_ryo->jump_attack_B->num_frames);
    destroy_animation(new_ryo->crouch_attack_A, new_ryo->crouch_attack_A->num_frames);
    destroy_animation(new_ryo->crouch_attack_B, new_ryo->crouch_attack_B->num_frames);
    destroy_animation(new_ryo->special_attack, new_ryo->special_attack->num_frames);
    free(new_ryo);
    return NULL;
  }
  
  // Criação e tratamento de erros - defesa em pé
  new_ryo->standing_defense = al_load_bitmap("Sprites/Ryo Sakazaki/Stand Defense.png");
  if (!new_ryo->standing_defense) {
    al_destroy_bitmap(new_ryo->profile);
    destroy_animation(new_ryo->neutral, new_ryo->neutral->num_frames);
    destroy_animation(new_ryo->walk, new_ryo->walk->num_frames);
    destroy_animation(new_ryo->jump, new_ryo->jump->num_frames);
    destroy_animation(new_ryo->crouch, new_ryo->crouch->num_frames);
    destroy_animation(new_ryo->attack_A, new_ryo->attack_A->num_frames);
    destroy_animation(new_ryo->attack_B, new_ryo->attack_B->num_frames);
    destroy_animation(new_ryo->jump_attack_A, new_ryo->jump_attack_A->num_frames);
    destroy_animation(new_ryo->jump_attack_B, new_ryo->jump_attack_B->num_frames);
    destroy_animation(new_ryo->crouch_attack_A, new_ryo->crouch_attack_A->num_frames);
    destroy_animation(new_ryo->crouch_attack_B, new_ryo->crouch_attack_B->num_frames);
    destroy_animation(new_ryo->special_attack, new_ryo->special_attack->num_frames);
    destroy_animation(new_ryo->death, new_ryo->death->num_frames);
    free(new_ryo);
    return NULL;
  }

  // Criação e tratamento de erros - defesa agachado
  new_ryo->crouch_defense = al_load_bitmap("Sprites/Ryo Sakazaki/Crouch Defense.png");
  if (!new_ryo->crouch_defense) {
    al_destroy_bitmap(new_ryo->profile);
    destroy_animation(new_ryo->neutral, new_ryo->neutral->num_frames);
    destroy_animation(new_ryo->walk, new_ryo->walk->num_frames);
    destroy_animation(new_ryo->jump, new_ryo->jump->num_frames);
    destroy_animation(new_ryo->crouch, new_ryo->crouch->num_frames);
    destroy_animation(new_ryo->attack_A, new_ryo->attack_A->num_frames);
    destroy_animation(new_ryo->attack_B, new_ryo->attack_B->num_frames);
    destroy_animation(new_ryo->jump_attack_A, new_ryo->jump_attack_A->num_frames);
    destroy_animation(new_ryo->jump_attack_B, new_ryo->jump_attack_B->num_frames);
    destroy_animation(new_ryo->crouch_attack_A, new_ryo->crouch_attack_A->num_frames);
    destroy_animation(new_ryo->crouch_attack_B, new_ryo->crouch_attack_B->num_frames);
    destroy_animation(new_ryo->special_attack, new_ryo->special_attack->num_frames);
    destroy_animation(new_ryo->death, new_ryo->death->num_frames);
    al_destroy_bitmap(new_ryo->standing_defense);
    free(new_ryo);
    return NULL;
  }

  // Animação inicial: neutra
  new_ryo->current_animation = NEUTRAL; 
  new_ryo->current_width = al_get_bitmap_width(new_ryo->neutral->frames[new_ryo->neutral->current_frame]);
  new_ryo->current_height = al_get_bitmap_height(new_ryo->neutral->frames[new_ryo->neutral->current_frame]);

  /* Configura as variáveis frame_count (quantos frames se passaram sem atualização) 
     e frame_delay (quantos frames tem que se passar antes de atualizar)             */
  new_ryo->frame_count = 0;
  new_ryo->frame_delay = 15;

  // Configura as variáveis de posição do personagem
  if (new_ryo->face == 1)
    new_ryo->x = (float) 20.0;
  else if (new_ryo->face == -1)
    new_ryo->x = (float) display_x - 20.0;

  new_ryo->y = (float) display_y - new_ryo->current_height;
  new_ryo->speed = (float) 5.0;

  // Configura outras variaveis
  new_ryo->is_jumping = 0;
  new_ryo->jump_speed = (float) -20;

  new_ryo->is_A_attacking = 0;
  new_ryo->is_B_attacking = 0;

  new_ryo->is_special_attacking = 0;
  new_ryo->frames_special_attack = 600;

  new_ryo->is_taking_damage = 0;
  new_ryo->is_dying = 0;
  new_ryo->dead = 0;

  // Cria o joystick controlador do personagem
  new_ryo->control = create_joystick();
  if (!new_ryo->control) {
    al_destroy_bitmap(new_ryo->profile);
    destroy_animation(new_ryo->neutral, new_ryo->neutral->num_frames);
    destroy_animation(new_ryo->walk, new_ryo->walk->num_frames);
    destroy_animation(new_ryo->jump, new_ryo->jump->num_frames);
    destroy_animation(new_ryo->crouch, new_ryo->crouch->num_frames);
    destroy_animation(new_ryo->attack_A, new_ryo->attack_A->num_frames);
    destroy_animation(new_ryo->attack_B, new_ryo->attack_B->num_frames);
    destroy_animation(new_ryo->jump_attack_A, new_ryo->jump_attack_A->num_frames);
    destroy_animation(new_ryo->jump_attack_B, new_ryo->jump_attack_B->num_frames);
    destroy_animation(new_ryo->crouch_attack_A, new_ryo->crouch_attack_A->num_frames);
    destroy_animation(new_ryo->crouch_attack_B, new_ryo->crouch_attack_B->num_frames);
    destroy_animation(new_ryo->special_attack, new_ryo->special_attack->num_frames);
    destroy_animation(new_ryo->death, new_ryo->death->num_frames);
    al_destroy_bitmap(new_ryo->standing_defense);
    al_destroy_bitmap(new_ryo->crouch_defense);
    free(new_ryo);
    return NULL;
  }

  return new_ryo;
}

// Cria o personagem "Robert Garcia" e retorna sua struct
player *create_robert_garcia(int face, float display_x, float display_y) {
  player *new_robert;

  // Aloca memória para o personagem
  new_robert = (player*) malloc(sizeof(player));
  if (!new_robert)
    return NULL;

  new_robert->ID = ROBERT;
  new_robert->face = face;
  new_robert->life = 100;
  
  // Criação e tratamento de erros - foto do rosto
  new_robert->profile = al_load_bitmap("Sprites/Robert Garcia/Robert.png");
  if (!new_robert->profile) {
    free(new_robert);
    return NULL;
  }

  // Carrega informações sobre foto do rosto
  new_robert->profile_width = al_get_bitmap_width(new_robert->profile);
  new_robert->profile_height = al_get_bitmap_height(new_robert->profile);

  // Criação e tratamento de erros - animação neutra
  new_robert->neutral = create_robert_neutral();
  if (!new_robert->neutral) {
    al_destroy_bitmap(new_robert->profile);
    free(new_robert);
    return NULL;
  }

  // Criação e tratamento de erros - animação andando
  new_robert->walk = create_robert_walk();  
  if (!new_robert->walk) {
    al_destroy_bitmap(new_robert->profile);
    destroy_animation(new_robert->neutral, new_robert->neutral->num_frames);
    free(new_robert);
    return NULL;
  }

  // Criação e tratamento de erros - animação do pulo
  new_robert->jump = create_robert_jump();
  if (!new_robert->jump) {
    al_destroy_bitmap(new_robert->profile);
    destroy_animation(new_robert->neutral, new_robert->neutral->num_frames);
    destroy_animation(new_robert->walk, new_robert->walk->num_frames);
    free(new_robert);
    return NULL;
  }

  // Criação e tratamento de erros - animação agachado
  new_robert->crouch = create_robert_crouch();
  if (!new_robert->crouch) {
    al_destroy_bitmap(new_robert->profile);
    destroy_animation(new_robert->neutral, new_robert->neutral->num_frames);
    destroy_animation(new_robert->walk, new_robert->walk->num_frames);
    destroy_animation(new_robert->jump, new_robert->jump->num_frames);
    free(new_robert);
    return NULL;
  }

  // Criação e tratamento de erros - ataque A
  new_robert->attack_A = create_robert_attack_A();
  if (!new_robert->attack_A) {
    al_destroy_bitmap(new_robert->profile);
    destroy_animation(new_robert->neutral, new_robert->neutral->num_frames);
    destroy_animation(new_robert->walk, new_robert->walk->num_frames);
    destroy_animation(new_robert->jump, new_robert->jump->num_frames);
    destroy_animation(new_robert->crouch, new_robert->crouch->num_frames);
    free(new_robert);
    return NULL;
  }

  // Criação e tratamento de erros - ataque B
  new_robert->attack_B = create_robert_attack_B();
  if (!new_robert->attack_B) {
    al_destroy_bitmap(new_robert->profile);
    destroy_animation(new_robert->neutral, new_robert->neutral->num_frames);
    destroy_animation(new_robert->walk, new_robert->walk->num_frames);
    destroy_animation(new_robert->jump, new_robert->jump->num_frames);
    destroy_animation(new_robert->crouch, new_robert->crouch->num_frames);
    destroy_animation(new_robert->attack_A, new_robert->attack_A->num_frames);
    free(new_robert);
    return NULL;
  }

  // Criação e tratamento de erros - ataque A no ar
  new_robert->jump_attack_A = create_robert_jump_attack_A();
  if (!new_robert->jump_attack_A) {
    al_destroy_bitmap(new_robert->profile);
    destroy_animation(new_robert->neutral, new_robert->neutral->num_frames);
    destroy_animation(new_robert->walk, new_robert->walk->num_frames);
    destroy_animation(new_robert->jump, new_robert->jump->num_frames);
    destroy_animation(new_robert->crouch, new_robert->crouch->num_frames);
    destroy_animation(new_robert->attack_A, new_robert->attack_A->num_frames);
    destroy_animation(new_robert->attack_B, new_robert->attack_B->num_frames);
    free(new_robert);
    return NULL;
  }

  // Criação e tratamento de erros - ataque B no ar
  new_robert->jump_attack_B = create_robert_jump_attack_B();
  if (!new_robert->jump_attack_B) {
    al_destroy_bitmap(new_robert->profile);
    destroy_animation(new_robert->neutral, new_robert->neutral->num_frames);
    destroy_animation(new_robert->walk, new_robert->walk->num_frames);
    destroy_animation(new_robert->jump, new_robert->jump->num_frames);
    destroy_animation(new_robert->crouch, new_robert->crouch->num_frames);
    destroy_animation(new_robert->attack_A, new_robert->attack_A->num_frames);
    destroy_animation(new_robert->attack_B, new_robert->attack_B->num_frames);
    destroy_animation(new_robert->jump_attack_A, new_robert->jump_attack_A->num_frames);
    free(new_robert);
    return NULL;
  }

  // Criação e tratamento de erros - ataque A agachado
  new_robert->crouch_attack_A = create_robert_crouch_attack_A();
  if (!new_robert->crouch_attack_A) {
    al_destroy_bitmap(new_robert->profile);
    destroy_animation(new_robert->neutral, new_robert->neutral->num_frames);
    destroy_animation(new_robert->walk, new_robert->walk->num_frames);
    destroy_animation(new_robert->jump, new_robert->jump->num_frames);
    destroy_animation(new_robert->crouch, new_robert->crouch->num_frames);
    destroy_animation(new_robert->attack_A, new_robert->attack_A->num_frames);
    destroy_animation(new_robert->attack_B, new_robert->attack_B->num_frames);
    destroy_animation(new_robert->jump_attack_A, new_robert->jump_attack_A->num_frames);
    destroy_animation(new_robert->jump_attack_B, new_robert->jump_attack_B->num_frames);
    free(new_robert);
    return NULL;
  }

  // Criação e tratamento de erros - ataque B agachado
  new_robert->crouch_attack_B = create_robert_crouch_attack_B();
  if (!new_robert->crouch_attack_B) {
    al_destroy_bitmap(new_robert->profile);
    destroy_animation(new_robert->neutral, new_robert->neutral->num_frames);
    destroy_animation(new_robert->walk, new_robert->walk->num_frames);
    destroy_animation(new_robert->jump, new_robert->jump->num_frames);
    destroy_animation(new_robert->crouch, new_robert->crouch->num_frames);
    destroy_animation(new_robert->attack_A, new_robert->attack_A->num_frames);
    destroy_animation(new_robert->attack_B, new_robert->attack_B->num_frames);
    destroy_animation(new_robert->jump_attack_A, new_robert->jump_attack_A->num_frames);
    destroy_animation(new_robert->jump_attack_B, new_robert->jump_attack_B->num_frames);
    destroy_animation(new_robert->crouch_attack_A, new_robert->crouch_attack_A->num_frames);
    free(new_robert);
    return NULL;
  }

  // Criação e tratamento de erros - ataque especial
  new_robert->special_attack = create_robert_special_attack();
  if (!new_robert->special_attack) {
    al_destroy_bitmap(new_robert->profile);
    destroy_animation(new_robert->neutral, new_robert->neutral->num_frames);
    destroy_animation(new_robert->walk, new_robert->walk->num_frames);
    destroy_animation(new_robert->jump, new_robert->jump->num_frames);
    destroy_animation(new_robert->crouch, new_robert->crouch->num_frames);
    destroy_animation(new_robert->attack_A, new_robert->attack_A->num_frames);
    destroy_animation(new_robert->attack_B, new_robert->attack_B->num_frames);
    destroy_animation(new_robert->jump_attack_A, new_robert->jump_attack_A->num_frames);
    destroy_animation(new_robert->jump_attack_B, new_robert->jump_attack_B->num_frames);
    destroy_animation(new_robert->crouch_attack_A, new_robert->crouch_attack_A->num_frames);
    destroy_animation(new_robert->crouch_attack_B, new_robert->crouch_attack_B->num_frames);
    free(new_robert);
    return NULL;
  }

  // Criação e tratamento de erros - morte
  new_robert->death = create_robert_death();
  if (!new_robert->death) {
    al_destroy_bitmap(new_robert->profile);
    destroy_animation(new_robert->neutral, new_robert->neutral->num_frames);
    destroy_animation(new_robert->walk, new_robert->walk->num_frames);
    destroy_animation(new_robert->jump, new_robert->jump->num_frames);
    destroy_animation(new_robert->crouch, new_robert->crouch->num_frames);
    destroy_animation(new_robert->attack_A, new_robert->attack_A->num_frames);
    destroy_animation(new_robert->attack_B, new_robert->attack_B->num_frames);
    destroy_animation(new_robert->jump_attack_A, new_robert->jump_attack_A->num_frames);
    destroy_animation(new_robert->jump_attack_B, new_robert->jump_attack_B->num_frames);
    destroy_animation(new_robert->crouch_attack_A, new_robert->crouch_attack_A->num_frames);
    destroy_animation(new_robert->crouch_attack_B, new_robert->crouch_attack_B->num_frames);
    destroy_animation(new_robert->special_attack, new_robert->special_attack->num_frames);
    free(new_robert);
    return NULL;
  }
  
  // Criação e tratamento de erros - defesa em pé
  new_robert->standing_defense = al_load_bitmap("Sprites/Robert Garcia/Stand Defense.png");
  if (!new_robert->standing_defense) {
    al_destroy_bitmap(new_robert->profile);
    destroy_animation(new_robert->neutral, new_robert->neutral->num_frames);
    destroy_animation(new_robert->walk, new_robert->walk->num_frames);
    destroy_animation(new_robert->jump, new_robert->jump->num_frames);
    destroy_animation(new_robert->crouch, new_robert->crouch->num_frames);
    destroy_animation(new_robert->attack_A, new_robert->attack_A->num_frames);
    destroy_animation(new_robert->attack_B, new_robert->attack_B->num_frames);
    destroy_animation(new_robert->jump_attack_A, new_robert->jump_attack_A->num_frames);
    destroy_animation(new_robert->jump_attack_B, new_robert->jump_attack_B->num_frames);
    destroy_animation(new_robert->crouch_attack_A, new_robert->crouch_attack_A->num_frames);
    destroy_animation(new_robert->crouch_attack_B, new_robert->crouch_attack_B->num_frames);
    destroy_animation(new_robert->special_attack, new_robert->special_attack->num_frames);
    destroy_animation(new_robert->death, new_robert->death->num_frames);
    free(new_robert);
    return NULL;
  }

  // Criação e tratamento de erros - defesa agachado
  new_robert->crouch_defense = al_load_bitmap("Sprites/Robert Garcia/Crouch Defense.png");
  if (!new_robert->crouch_defense) {
    al_destroy_bitmap(new_robert->profile);
    destroy_animation(new_robert->neutral, new_robert->neutral->num_frames);
    destroy_animation(new_robert->walk, new_robert->walk->num_frames);
    destroy_animation(new_robert->jump, new_robert->jump->num_frames);
    destroy_animation(new_robert->crouch, new_robert->crouch->num_frames);
    destroy_animation(new_robert->attack_A, new_robert->attack_A->num_frames);
    destroy_animation(new_robert->attack_B, new_robert->attack_B->num_frames);
    destroy_animation(new_robert->jump_attack_A, new_robert->jump_attack_A->num_frames);
    destroy_animation(new_robert->jump_attack_B, new_robert->jump_attack_B->num_frames);
    destroy_animation(new_robert->crouch_attack_A, new_robert->crouch_attack_A->num_frames);
    destroy_animation(new_robert->crouch_attack_B, new_robert->crouch_attack_B->num_frames);
    destroy_animation(new_robert->special_attack, new_robert->special_attack->num_frames);
    destroy_animation(new_robert->death, new_robert->death->num_frames);
    al_destroy_bitmap(new_robert->standing_defense);
    free(new_robert);
    return NULL;
  }

  // Animação inicial: neutra
  new_robert->current_animation = NEUTRAL; 
  new_robert->current_width = al_get_bitmap_width(new_robert->neutral->frames[new_robert->neutral->current_frame]);
  new_robert->current_height = al_get_bitmap_height(new_robert->neutral->frames[new_robert->neutral->current_frame]);

  /* Configura as variáveis frame_count (quantos frames se passaram sem atualização) 
     e frame_delay (quantos frames tem que se passar antes de atualizar)             */
  new_robert->frame_count = 0;
  new_robert->frame_delay = 15;

  // Configura as variáveis de posição do personagem
  if (new_robert->face == 1)
    new_robert->x = (float) 20.0;
  else if (new_robert->face == -1)
    new_robert->x = (float) display_x - 20.0;

  new_robert->y = (float) display_y - new_robert->current_height;
  new_robert->speed = (float) 5.0;

  // Inicialização de outras variaveis
  new_robert->is_jumping = 0;
  new_robert->jump_speed = (float) -20;

  new_robert->is_A_attacking = 0;
  new_robert->is_B_attacking = 0;

  new_robert->is_special_attacking = 0;
  new_robert->frames_special_attack = 600;

  new_robert->is_taking_damage = 0;
  new_robert->is_dying = 0;
  new_robert->dead = 0;

  // Cria o joystick controlador do personagem
  new_robert->control = create_joystick();
  if (!new_robert->control) {
    destroy_animation(new_robert->neutral, new_robert->neutral->num_frames);
    destroy_animation(new_robert->walk, new_robert->walk->num_frames);
    destroy_animation(new_robert->jump, new_robert->jump->num_frames);
    destroy_animation(new_robert->crouch, new_robert->crouch->num_frames);
    destroy_animation(new_robert->attack_A, new_robert->attack_A->num_frames);
    destroy_animation(new_robert->attack_B, new_robert->attack_B->num_frames);
    destroy_animation(new_robert->jump_attack_A, new_robert->jump_attack_A->num_frames);
    destroy_animation(new_robert->jump_attack_B, new_robert->jump_attack_B->num_frames);
    destroy_animation(new_robert->crouch_attack_A, new_robert->crouch_attack_A->num_frames);
    destroy_animation(new_robert->crouch_attack_B, new_robert->crouch_attack_B->num_frames);
    destroy_animation(new_robert->special_attack, new_robert->special_attack->num_frames);
    destroy_animation(new_robert->death, new_robert->death->num_frames);
    al_destroy_bitmap(new_robert->standing_defense);
    al_destroy_bitmap(new_robert->crouch_defense);
    free(new_robert);
    return NULL;
  }

  return new_robert;
}

// Cria o personagem "Jack Turner" e retorna sua struct
player *create_jack_turner(int face, float display_x, float display_y) {
  player *new_jack;

  // Aloca memória para o personagem
  new_jack = (player*) malloc(sizeof(player));
  if (!new_jack)
    return NULL;
  
  new_jack->ID = JACK;
  new_jack->face = face;
  new_jack->life = 100;

  // Criação e tratamento de erros - foto do rosto
  new_jack->profile = al_load_bitmap("Sprites/Jack Turner/Jack.png");
  if (!new_jack->profile) {
    free(new_jack);
    return NULL;
  }

  // Carrega informações sobre a foto do rosto
  new_jack->profile_width = al_get_bitmap_width(new_jack->profile);
  new_jack->profile_height = al_get_bitmap_height(new_jack->profile);

  // Criação e tratamento de erros - animação neutra
  new_jack->neutral = create_jack_neutral();
  if (!new_jack->neutral) {
    al_destroy_bitmap(new_jack->profile);
    free(new_jack);
    return NULL;
  }

  // Criação e tratamento de erros - animação andando
  new_jack->walk = create_jack_walk();  
  if (!new_jack->walk) {
    al_destroy_bitmap(new_jack->profile);
    destroy_animation(new_jack->neutral, new_jack->neutral->num_frames);
    free(new_jack);
    return NULL;
  }
  
  // Criação e tratamento de erros - animação do pulo
  new_jack->jump = create_jack_jump();
  if (!new_jack->jump) {
    al_destroy_bitmap(new_jack->profile);
    destroy_animation(new_jack->neutral, new_jack->neutral->num_frames);
    destroy_animation(new_jack->walk, new_jack->walk->num_frames);
    free(new_jack);
    return NULL;
  }

  // Criação e tratamento de erros - animação agachado
  new_jack->crouch = create_jack_crouch();
  if (!new_jack->crouch) {
    al_destroy_bitmap(new_jack->profile);
    destroy_animation(new_jack->neutral, new_jack->neutral->num_frames);
    destroy_animation(new_jack->walk, new_jack->walk->num_frames);
    destroy_animation(new_jack->jump, new_jack->jump->num_frames);
    free(new_jack);
    return NULL;
  }

  // Criação e tratamento de erros - ataque A
  new_jack->attack_A = create_jack_attack_A();
  if (!new_jack->attack_A) {
    al_destroy_bitmap(new_jack->profile);
    destroy_animation(new_jack->neutral, new_jack->neutral->num_frames);
    destroy_animation(new_jack->walk, new_jack->walk->num_frames);
    destroy_animation(new_jack->jump, new_jack->jump->num_frames);
    destroy_animation(new_jack->crouch, new_jack->crouch->num_frames);
    free(new_jack);
    return NULL;
  }

  // Criação e tratamento de erros - ataque B
  new_jack->attack_B = create_jack_attack_B();
  if (!new_jack->attack_B) {
    al_destroy_bitmap(new_jack->profile);
    destroy_animation(new_jack->neutral, new_jack->neutral->num_frames);
    destroy_animation(new_jack->walk, new_jack->walk->num_frames);
    destroy_animation(new_jack->jump, new_jack->jump->num_frames);
    destroy_animation(new_jack->crouch, new_jack->crouch->num_frames);
    destroy_animation(new_jack->attack_A, new_jack->attack_A->num_frames);
    free(new_jack);
    return NULL;
  }

  // Criação e tratamento de erros - ataque A no ar
  new_jack->jump_attack_A = create_jack_jump_attack_A();
  if (!new_jack->jump_attack_A) {
    al_destroy_bitmap(new_jack->profile);
    destroy_animation(new_jack->neutral, new_jack->neutral->num_frames);
    destroy_animation(new_jack->walk, new_jack->walk->num_frames);
    destroy_animation(new_jack->jump, new_jack->jump->num_frames);
    destroy_animation(new_jack->crouch, new_jack->crouch->num_frames);
    destroy_animation(new_jack->attack_A, new_jack->attack_A->num_frames);
    destroy_animation(new_jack->attack_B, new_jack->attack_B->num_frames);
    free(new_jack);
    return NULL;
  }

  // Ataque B no ar é o mesmo que o ataque A
  new_jack->jump_attack_B = new_jack->jump_attack_A;

  // Não tem ataques agachados nem ataque especial
  new_jack->crouch_attack_A = NULL;
  new_jack->crouch_attack_B = NULL;
  new_jack->special_attack = NULL;

  // Criação e tratamento de erros - morte
  new_jack->death = create_jack_death();
  if (!new_jack->death) {
    al_destroy_bitmap(new_jack->profile);
    destroy_animation(new_jack->neutral, new_jack->neutral->num_frames);
    destroy_animation(new_jack->walk, new_jack->walk->num_frames);
    destroy_animation(new_jack->jump, new_jack->jump->num_frames);
    destroy_animation(new_jack->crouch, new_jack->crouch->num_frames);
    destroy_animation(new_jack->attack_A, new_jack->attack_A->num_frames);
    destroy_animation(new_jack->attack_B, new_jack->attack_B->num_frames);
    destroy_animation(new_jack->jump_attack_A, new_jack->jump_attack_A->num_frames);
    free(new_jack);
    return NULL;
  }

  // Criação e tratamento de erros - defesa em pé
  new_jack->standing_defense = al_load_bitmap("Sprites/Jack Turner/Stand Defense.png");
  if (!new_jack->standing_defense) {
    al_destroy_bitmap(new_jack->profile);
    destroy_animation(new_jack->neutral, new_jack->neutral->num_frames);
    destroy_animation(new_jack->walk, new_jack->walk->num_frames);
    destroy_animation(new_jack->jump, new_jack->jump->num_frames);
    destroy_animation(new_jack->crouch, new_jack->crouch->num_frames);
    destroy_animation(new_jack->attack_A, new_jack->attack_A->num_frames);
    destroy_animation(new_jack->attack_B, new_jack->attack_B->num_frames);
    destroy_animation(new_jack->jump_attack_A, new_jack->jump_attack_A->num_frames);
    destroy_animation(new_jack->death, new_jack->death->num_frames);
    free(new_jack);
    return NULL;
  }

  // Criação e tratamento de erros - defesa agachado
  new_jack->crouch_defense = al_load_bitmap("Sprites/Jack Turner/Crouch Defense.png");
  if (!new_jack->crouch_defense) {
    al_destroy_bitmap(new_jack->profile);
    destroy_animation(new_jack->neutral, new_jack->neutral->num_frames);
    destroy_animation(new_jack->walk, new_jack->walk->num_frames);
    destroy_animation(new_jack->jump, new_jack->jump->num_frames);
    destroy_animation(new_jack->crouch, new_jack->crouch->num_frames);
    destroy_animation(new_jack->attack_A, new_jack->attack_A->num_frames);
    destroy_animation(new_jack->attack_B, new_jack->attack_B->num_frames);
    destroy_animation(new_jack->jump_attack_A, new_jack->jump_attack_A->num_frames);
    destroy_animation(new_jack->death, new_jack->death->num_frames);
    al_destroy_bitmap(new_jack->standing_defense);
    free(new_jack);
    return NULL;
  }

  // Animação inicial: neutra
  new_jack->current_animation = NEUTRAL; 
  new_jack->current_width = al_get_bitmap_width(new_jack->neutral->frames[new_jack->neutral->current_frame]);
  new_jack->current_height = al_get_bitmap_height(new_jack->neutral->frames[new_jack->neutral->current_frame]);

  /* Configura as variáveis frame_count (quantos frames se passaram sem atualização) 
     e frame_delay (quantos frames tem que se passar antes de atualizar)             */
  new_jack->frame_count = 0;
  new_jack->frame_delay = 15;

  // Configura as variáveis de posição do personagem
  if (new_jack->face == 1)
    new_jack->x = (float) 20.0;
  else if (new_jack->face == -1)
    new_jack->x = (float) display_x - 20.0;

  new_jack->y = (float) display_y - new_jack->current_height;
  new_jack->speed = (float) 5.0;

  // Inicialização de outras variaveis
  new_jack->is_jumping = 0;
  new_jack->jump_speed = (float) -20;

  new_jack->is_A_attacking = 0;
  new_jack->is_B_attacking = 0;

  new_jack->is_special_attacking = 0;
  new_jack->frames_special_attack = -1;

  new_jack->is_taking_damage = 0;
  new_jack->is_dying = 0;
  new_jack->dead = 0;

  // Cria o joystick controlador do personagem
  new_jack->control = create_joystick();
  if (!new_jack->control) {
    destroy_animation(new_jack->neutral, new_jack->neutral->num_frames);
    destroy_animation(new_jack->walk, new_jack->walk->num_frames);
    destroy_animation(new_jack->jump, new_jack->jump->num_frames);
    destroy_animation(new_jack->crouch, new_jack->crouch->num_frames);
    destroy_animation(new_jack->attack_A, new_jack->attack_A->num_frames);
    destroy_animation(new_jack->attack_B, new_jack->attack_B->num_frames);
    destroy_animation(new_jack->jump_attack_A, new_jack->jump_attack_A->num_frames);
    destroy_animation(new_jack->death, new_jack->death->num_frames);
    al_destroy_bitmap(new_jack->standing_defense);
    al_destroy_bitmap(new_jack->crouch_defense);
    free(new_jack);
    return NULL;
  }

  return new_jack;
}

// Atualiza o joystick dos jogadores passados como parametro
void set_controls(ALLEGRO_EVENT *event, player *element1, player *element2) {
  /*Player 1: joga com WASD, com ataques em C e V*/
  if (event->keyboard.keycode == ALLEGRO_KEY_W)
    joystick_up(element1->control);
  
  if (event->keyboard.keycode == ALLEGRO_KEY_S)
    joystick_down(element1->control);

  if (event->keyboard.keycode == ALLEGRO_KEY_A)
    joystick_left(element1->control);
  
  if (event->keyboard.keycode == ALLEGRO_KEY_D)
    joystick_right(element1->control);
  
  if (event->keyboard.keycode == ALLEGRO_KEY_C)
    joystick_attack_A(element1->control);
  
  if (event->keyboard.keycode == ALLEGRO_KEY_V)
    joystick_attack_B(element1->control);
  
  if (event->keyboard.keycode == ALLEGRO_KEY_B)
    joystick_defense(element1->control);

  if ((event->keyboard.keycode == ALLEGRO_KEY_F) && ((element1->ID == RYO) || (element1->ID == ROBERT)))
    joystick_special_attack(element1->control);
    
  /* Player 2: joga nas setinhas, com ataques em P e O*/
  if (event->keyboard.keycode == ALLEGRO_KEY_UP) 
    joystick_up(element2->control);

  if (event->keyboard.keycode == ALLEGRO_KEY_DOWN) 
    joystick_down(element2->control);
      
  if (event->keyboard.keycode == ALLEGRO_KEY_LEFT)
    joystick_left(element2->control);
      
  if (event->keyboard.keycode == ALLEGRO_KEY_RIGHT)
    joystick_right(element2->control);
    
  if (event->keyboard.keycode == ALLEGRO_KEY_P)
    joystick_attack_A(element2->control);

  if (event->keyboard.keycode == ALLEGRO_KEY_O)
    joystick_attack_B(element2->control);
  
  if (event->keyboard.keycode == ALLEGRO_KEY_K)
    joystick_defense(element2->control);

  if ((event->keyboard.keycode == ALLEGRO_KEY_L) && ((element2->ID == RYO) || (element2->ID == ROBERT)))
    joystick_special_attack(element2->control);
}

// Retorna 1 se houve colisão entre os 2 personagens, e 0 caso contrário. 
int colision(player *element1, player *element2) {
    int x1_start, x1_end, y1_start, y1_end, x2_start, x2_end, y2_start, y2_end;

    if (element1->face == 1)
      x1_start = element1->x;
    else
      x1_start = element1->x - element1->current_width;

    x1_end = x1_start + element1->current_width;

    y1_start = element1->y;
    y1_end = y1_start + element1->current_height;

    if (element2->face == 1)
      x2_start = element2->x;
    else
      x2_start = element2->x - element2->current_width;

    x2_end = x2_start + element2->current_width;

    y2_start = element2->y;
    y2_end = y2_start + element2->current_height;
    
    // Verifica interseção no eixo x
    int x_colision = (x1_start < x2_end) && (x1_end > x2_start);

    // Verifica interseção no eixo y
    int y_colision = (y1_start < y2_end) && (y1_end > y2_start);

    // Se há interseção em ambos os eixos, há colisão
    return (x_colision && y_colision);
}

// Retorna 1 se element1 deu dano em element2 e 0 caso contrário
int damage(player *element1, player *element2) {
  if ((!element2->control->defense) && ((element1->is_A_attacking) || (element1->is_B_attacking) || (element1->is_special_attacking)) && (colision(element1, element2))) {
    if ((element1->face == 1) && (element2->face == -1)) {
      if ((element1->x + element1->current_width) >= (element2->current_width))
        return 1;
    } else if ((element1->face == -1) && (element2->face == 1)) 
      if ((element1->x - element1->current_width) <= (element2->x + element2->current_width))
        return 1;
  }

  return 0;
}

// Verifica se o jogador ultrapassou os limites do display. Se passou, corrige x ou y
void verify_display_limits(player *element, int display_x, int display_y) {
  if (element->face == 1) { // se element->face for 1, o personagem está virado para a direita
    if (element->x > display_x - element->current_width)
      element->x = (float) display_x - element->current_width;
  
    if (element->x < 0)
      element->x = (float) 0;

  } else if (element->face == -1) { // se element->face for -1, o personagem está virado para a esquerda
    if (element->x > display_x)
      element->x = (float) display_x;
    
    if (element->x < element->current_width)
      element->x = (float) element->current_width;
  }

  if (element->y > display_y - element->current_height)
    element->y = (float) display_y - element->current_height;
  
  if (element->y < 0)
    element->y = (float) 0;  
}

// Retorna 1 se os dois jogadores estão vivos e 0 caso contrário.
int players_are_alive(player *element1, player *element2) {
  if ((element1->is_dying) || (element2->is_dying) || (element1->dead) || (element2->dead)) 
    return 0;

  return 1;
}

// Atualiza medidas (width e height) do jogador passado como parametro
void update_measures(player *element) {
  // Animação 0 - neutra
  if (element->current_animation == NEUTRAL) { 
    element->current_width = al_get_bitmap_width(element->neutral->frames[element->neutral->current_frame]);
    element->current_height = al_get_bitmap_height(element->neutral->frames[element->neutral->current_frame]);
    return;
  }

  // Animação 1 - andar
  if (element->current_animation == WALK) {
    element->current_width = al_get_bitmap_width(element->walk->frames[element->walk->current_frame]);
    element->current_height = al_get_bitmap_height(element->walk->frames[element->walk->current_frame]);
    return;
  }

  // Animação 2 - pular
  if (element->current_animation == JUMP) {
    element->current_width = al_get_bitmap_width(element->jump->frames[element->jump->current_frame]);
    element->current_height = al_get_bitmap_height(element->jump->frames[element->jump->current_frame]);
    return;
  }

  // Animação 3 - agachar
  if (element->current_animation == CROUCH) {
    element->current_width = al_get_bitmap_width(element->crouch->frames[element->crouch->current_frame]);
    element->current_height = al_get_bitmap_height(element->crouch->frames[element->crouch->current_frame]);
    return;
  }

  // Animação 4 - ataque em pé com membros superiores
  if (element->current_animation == ATTACK_A) {
    element->current_width = al_get_bitmap_width(element->attack_A->frames[element->attack_A->current_frame]);
    element->current_height = al_get_bitmap_height(element->attack_A->frames[element->attack_A->current_frame]);
    return;
  }

  // Animação 5 - ataque em pé com membros inferiores
  if (element->current_animation == ATTACK_B) {
    element->current_width = al_get_bitmap_width(element->attack_B->frames[element->attack_B->current_frame]);
    element->current_height = al_get_bitmap_height(element->attack_B->frames[element->attack_B->current_frame]);
    return;
  }

  // Animação 6 - ataque no ar com membros superiores
  if (element->current_animation == JUMP_ATTACK_A) {
    element->current_width = al_get_bitmap_width(element->jump_attack_A->frames[element->jump_attack_A->current_frame]);
    element->current_height = al_get_bitmap_height(element->jump_attack_A->frames[element->jump_attack_A->current_frame]);
    return;
  }

  // Animação 7 - ataque no ar com membros inferiores
  if (element->current_animation == JUMP_ATTACK_B) {
    element->current_width = al_get_bitmap_width(element->jump_attack_B->frames[element->jump_attack_B->current_frame]);
    element->current_height = al_get_bitmap_height(element->jump_attack_B->frames[element->jump_attack_B->current_frame]);
  }

  // Animação 8 - ataque agachado com membros superiores
  if (element->current_animation == CROUCH_ATTACK_A) {
    element->current_width = al_get_bitmap_width(element->crouch_attack_A->frames[element->crouch_attack_A->current_frame]);
    element->current_height = al_get_bitmap_height(element->crouch_attack_A->frames[element->crouch_attack_A->current_frame]);
  }

  // Animação 9 - ataque agachado com membros inferiores
  if (element->current_animation == CROUCH_ATTACK_B) {
    element->current_width = al_get_bitmap_width(element->crouch_attack_B->frames[element->crouch_attack_B->current_frame]);
    element->current_height = al_get_bitmap_height(element->crouch_attack_B->frames[element->crouch_attack_B->current_frame]);
  }

  // Animação 10 - ataque especial
  if (element->current_animation == SPECIAL_ATTACK) {
    element->current_width = al_get_bitmap_width(element->special_attack->frames[element->special_attack->current_frame]);
    element->current_height = al_get_bitmap_height(element->special_attack->frames[element->special_attack->current_frame]);
  }

  // Animação 11 - morrendo
  if (element->current_animation == DEATH) {
    element->current_width = al_get_bitmap_width(element->death->frames[element->death->current_frame]);
    element->current_height = al_get_bitmap_height(element->death->frames[element->death->current_frame]);
  }

  // Animação 12 - defesa em pé
  if (element->current_animation == STANDING_DEFENSE) {
    element->current_width = al_get_bitmap_width(element->standing_defense);
    element->current_height = al_get_bitmap_height(element->standing_defense);
  }

  // Animação 12 - defesa agachado
  if (element->current_animation == CROUCH_DEFENSE) {
    element->current_width = al_get_bitmap_width(element->crouch_defense);
    element->current_height = al_get_bitmap_height(element->crouch_defense);
  }
}

// Se necessário, zera current_frame da última animação do personagem
void reset_animation(player *element) {
  // Se previous_animation e current_animation são iguais, a animação não foi alterada - então não há necessidade de zerar a anterior
  if ((element->previous_animation == element->current_animation) || (element->previous_animation == STANDING_DEFENSE) || (element->previous_animation == CROUCH_DEFENSE))
    return;

  // Se a animação foi alterada, zera a animação anterior
  if (element->previous_animation == NEUTRAL) // Animação 0 - neutra
    element->neutral->current_frame = 0;
  else if (element->previous_animation == WALK) // Animação 1 - andar
    element->walk->current_frame = 0;
  else if (element->previous_animation == JUMP) // Animação 2 - pular
    element->jump->current_frame = 0;
  else if (element->previous_animation == CROUCH) // Animação 3 - agachar
    element->crouch->current_frame = 0;
  else if (element->previous_animation == ATTACK_A) // Animação 4 - ataque em pé com membros superiores
    element->attack_A->current_frame = 0;
  else if (element->previous_animation == ATTACK_B) // Animação 5 - ataque em pé com membros inferiores
    element->attack_B->current_frame = 0;
  else if (element->previous_animation == JUMP_ATTACK_A) // Animação 6 - ataque no ar com membros superiores
    element->jump_attack_A->current_frame = 0;
  else if (element->previous_animation == JUMP_ATTACK_B) // Animação 7 - ataque no ar com membros inferiores
    element->jump_attack_B->current_frame = 0;
  else if (element->previous_animation == CROUCH_ATTACK_A) // Animação 8 - ataque agachado com membros superiores
    element->crouch_attack_A->current_frame = 0;
  else if (element->previous_animation == CROUCH_ATTACK_B) // Animação 9 - ataque agachado com membros inferiores
    element->crouch_attack_B->current_frame = 0;
  else if (element->previous_animation == SPECIAL_ATTACK) // Animação 10 - ataque especial
    element->special_attack->current_frame = 0;
  else if (element->previous_animation == DEATH) // Animação 11 - morte
    element->death->current_frame = 0;
}

// Atualiza o estado atual do jogador: posição, vida, dano, animação, altura, largura, etc.
void update_player(player *element1, player *element2, float display_x, float display_y) {
  // Configuração do pulo - player1
  if ((element1->control->up) && (!element1->is_jumping) && (!element1->control->down) && (!element1->is_special_attacking) && (!element1->is_taking_damage) && (players_are_alive(element1, element2))) 
    element1->is_jumping = 1;

  // Configuração do pulo - player2
  if ((element2->control->up) && (!element2->is_jumping) && (!element2->control->down) && (!element2->is_special_attacking) && (!element2->is_taking_damage) && (players_are_alive(element1, element2))) 
    element2->is_jumping = 1;

  // Configuração do ataque A - player1
  if ((element1->control->attack_A) && (!element1->is_A_attacking) && (!element1->is_B_attacking) && (!element1->is_special_attacking) && (!element1->is_taking_damage) && (players_are_alive(element1, element2))) 
    element1->is_A_attacking = 1;
  
  // Configuração do ataque A - player2
  if ((element2->control->attack_A) && (!element2->is_A_attacking) && (!element2->is_B_attacking) && (!element2->is_special_attacking) && (!element2->is_taking_damage) && (players_are_alive(element1, element2))) 
    element2->is_A_attacking = 1;

  // Configuração do ataque B - player1
  if ((element1->control->attack_B) && (!element1->is_B_attacking) && (!element1->is_A_attacking) && (!element1->is_special_attacking) && (!element1->is_taking_damage) && (players_are_alive(element1, element2))) 
    element1->is_B_attacking = 1;
  
  // Configuração do ataque B - player2
  if ((element2->control->attack_B) && (!element2->is_B_attacking) && (!element2->is_A_attacking) && (!element2->is_special_attacking) && (!element2->is_taking_damage) && (players_are_alive(element1, element2))) 
    element2->is_B_attacking = 1;

  // Configuração do ataque especial - player1
  if ((element1->control->special_attack) && (!element1->is_special_attacking) && (!element1->is_A_attacking) && (!element1->is_B_attacking) && (!element1->control->down) && (!element1->is_jumping) && (!element1->is_taking_damage)  && (!element1->control->defense) && (element1->frames_special_attack == 600) && (players_are_alive(element1, element2)))
    element1->is_special_attacking = 1;

  // Configuração do ataque especial - player2
  if ((element2->control->special_attack) && (!element2->is_special_attacking) && (!element2->is_A_attacking) && (!element2->is_B_attacking) && (!element2->control->down) && (!element2->is_jumping) && (!element2->is_taking_damage) &&  (!element2->control->defense) && (element2->frames_special_attack == 600) && (players_are_alive(element1, element2)))
    element2->is_special_attacking = 1;

  // Configura previous_animation - player1
  element1->previous_animation = element1->current_animation;

  // Configura previous_animation - player2
  element2->previous_animation = element2->current_animation;

  // Estado neutro - player1
  if ((!element1->control->right) && (!element1->control->left) && (!element1->is_jumping) && (!element1->control->down) && (!element1->is_A_attacking) && (!element1->is_B_attacking) && (!element1->control->defense) && (players_are_alive(element1, element2))) {
    element1->current_animation = NEUTRAL;
    element1->frame_count++;
    if (element1->frame_count >= element1->frame_delay) {
      element1->neutral->current_frame++;
      if (element1->neutral->current_frame >= element1->neutral->num_frames)
        element1->neutral->current_frame = 0;
      element1->frame_count = 0;
    }
    update_measures(element1);
  }
  
  // Estado neutro - player2
  if ((!element2->control->right) && (!element2->control->left) && (!element2->is_jumping) && (!element2->control->down) && (!element2->is_A_attacking) && (!element2->is_B_attacking) && (!element2->control->defense) && (players_are_alive(element1, element2))) {
    element2->current_animation = NEUTRAL;
    element2->frame_count++;
    if (element2->frame_count >= element2->frame_delay) {
      element2->neutral->current_frame++;
      if (element2->neutral->current_frame >= element2->neutral->num_frames)
        element2->neutral->current_frame = 0;
      element2->frame_count = 0;
    }
    update_measures(element2);
  }

  // Estado movimentando para a direita - player1
  if ((element1->control->right) && (!element1->control->down) && (!element1->is_A_attacking) && (!element1->is_B_attacking) && (!element1->is_special_attacking) && (!element1->is_taking_damage) && (!element1->control->defense) && (players_are_alive(element1, element2))) {
    element1->x += element1->speed;
    if (!element1->is_jumping) {
      element1->current_animation = WALK;
      element1->frame_count++;
      if (element1->frame_count >= element1->frame_delay) {
        element1->walk->current_frame++;
        if (element1->walk->current_frame >= element1->walk->num_frames)
          element1->walk->current_frame = 0;
        element1->frame_count = 0;
      }
    }
  
    update_measures(element1);
    update_faces(element1, element2);
    if ((colision(element1, element2)) && (!element1->is_jumping) && (!element2->is_jumping) && (element1->face == 1) && (element2->face == -1)) 
      element1->x = element2->x - element2->current_width - element1->current_width - 2;
  } 
  
  // Estado movimentando para a direita - player2
  if ((element2->control->right) && (!element2->control->down) && (!element2->is_A_attacking) && (!element2->is_B_attacking) && (!element2->is_special_attacking) && (!element2->is_taking_damage) && (!element2->control->defense) && (players_are_alive(element1, element2))) {
    element2->x += element2->speed;
    if (!element2->is_jumping) {
      element2->current_animation = WALK;
      element2->frame_count++;
      if (element2->frame_count >= element2->frame_delay) {
        element2->walk->current_frame++;
        if (element2->walk->current_frame >= element2->walk->num_frames)
          element2->walk->current_frame = 0;
        element2->frame_count = 0;
      }
    }

    update_measures(element2);
    update_faces(element1, element2);
    if ((colision(element1, element2)) && (!element1->is_jumping) && (!element2->is_jumping) && (element1->face == -1) && (element2->face == 1)) 
      element2->x = element1->x - element1->current_width - element2->current_width - 2;

  }

  // Estado movimentando para a esquerda - player1
  if ((element1->control->left) && (!element1->control->down) && (!element1->is_A_attacking) && (!element1->is_B_attacking) && (!element1->is_special_attacking) && (!element1->is_taking_damage) && (!element1->control->defense) && (players_are_alive(element1, element2))) {
    element1->x -= element1->speed;
    if (!element1->is_jumping) {
      element1->current_animation = WALK;
      element1->frame_count++;
      if (element1->frame_count >= element1->frame_delay) {
        element1->walk->current_frame++;
        if (element1->walk->current_frame >= element1->walk->num_frames)
          element1->walk->current_frame = 0;
        element1->frame_count = 0;
      }
    }

    update_measures(element1);
    update_faces(element1, element2);
    if ((colision(element1, element2)) && (!element1->is_jumping) && (!element2->is_jumping) && (element1->face == -1) && (element2->face == 1)) 
      element1->x = element2->x + element2->current_width + element1->current_width + 2;
    
  }
  
  // Estado movimentando para a esquerda - player2
  if ((element2->control->left) && (!element2->control->down) && (!element2->is_A_attacking) && (!element2->is_B_attacking) && (!element2->is_special_attacking) && (!element2->is_taking_damage) && (!element2->control->defense) && (players_are_alive(element1, element2))) {
    element2->x -= element2->speed;
    if (!element2->is_jumping) {
      element2->current_animation = WALK;
      element2->frame_count++;
      if (element2->frame_count >= element2->frame_delay) {
        element2->walk->current_frame++;
        if (element2->walk->current_frame >= element2->walk->num_frames)
          element2->walk->current_frame = 0;
        element2->frame_count = 0;
      }
    }

    update_measures(element2);
    update_faces(element1, element2);
    if ((colision(element1, element2)) && (!element1->is_jumping) && (!element2->is_jumping) && (element1->face == 1) && (element2->face == -1)) 
      element2->x = element1->x + element1->current_width + element2->current_width + 2;
    
  }

  // Estado pulo - player1
  if (element1->is_jumping) {
    element1->y += element1->jump_speed;
    update_measures(element1);

    if ((colision(element1, element2)) && (element1->jump_speed >= 0)) {
      element1->y = element2->y - element1->current_height;
      element1->current_animation = NEUTRAL;
    } else {
      element1->current_animation = JUMP;
      element1->frame_count++;
      if (element1->frame_count >= element1->frame_delay) {
        element1->jump->current_frame++;
        if (element1->jump->current_frame >= element1->jump->num_frames)
          element1->jump->current_frame = 0;
        element1->frame_count = 0;
      }

      element1->jump_speed++;
      if (element1->y >= display_y - element1->current_height) {
        element1->y = (float) display_y - element1->current_height;
        element1->is_jumping = 0;
        element1->jump_speed = (float) -20;
      }
    }
  }
  
  // Estado pulo - player2
  if (element2->is_jumping) {
    element2->y += element2->jump_speed;
    update_measures(element2);

    if ((colision(element1, element2)) && (element2->jump_speed >= 0)) {
      element2->y = element1->y - element2->current_height;
      element2->current_animation = NEUTRAL;
    } else {
      element2->current_animation = JUMP;
      element2->frame_count++;
      if (element2->frame_count >= element2->frame_delay) {
        element2->jump->current_frame++;
        if (element2->jump->current_frame >= element2->jump->num_frames)
          element2->jump->current_frame = 0;
        element2->frame_count = 0;
      }

      element2->jump_speed++;
      if (element2->y >= display_y - element2->current_height) {
        element2->y = (float) display_y - element2->current_height;
        element2->is_jumping = 0;
        element2->jump_speed = (float) -20;
      }
    }
  }

  // Estado agachado - player1
  if ((element1->control->down) && (!element1->is_jumping) && (!element1->is_A_attacking) && (!element1->is_B_attacking) && (!element1->is_taking_damage) && (!element1->control->defense) && (players_are_alive(element1, element2))) {
    element1->current_animation = CROUCH;
    element1->frame_count++;
    if (element1->frame_count >= element1->frame_delay) {
      element1->crouch->current_frame++;
      if (element1->crouch->current_frame >= element1->crouch->num_frames)
        element1->crouch->current_frame = 0;
      element1->frame_count = 0;
    }

    update_measures(element1);
  }
  
  // Estado agachado - player2
  if ((element2->control->down) && (!element2->is_jumping) && (!element2->is_A_attacking) && (!element2->is_B_attacking) && (!element2->is_taking_damage) && (!element2->control->defense) && (players_are_alive(element1, element2))) {
    element2->current_animation = CROUCH;
    element2->frame_count++;
    if (element2->frame_count >= element2->frame_delay) {
      element2->crouch->current_frame++;
      if (element2->crouch->current_frame >= element2->crouch->num_frames)
        element2->crouch->current_frame = 0;
      element2->frame_count = 0;
    }

    update_measures(element2);
  }

  // Estado ataque superior - player1
  if ((element1->is_A_attacking) && (!element1->control->right) && (!element1->control->left) && (!element1->is_jumping) && (!element1->control->down) && (!element1->control->defense) && (!element1->is_B_attacking)) {
    element1->current_animation = ATTACK_A;
    element1->frame_count += 3;
    if (element1->frame_count >= element1->frame_delay) {
      element1->attack_A->current_frame++;
      if (element1->attack_A->current_frame >= element1->attack_A->num_frames) {
        element1->attack_A->current_frame = 0;
        element1->is_A_attacking = 0;
        if (element2->is_taking_damage)
          element2->is_taking_damage = 0;
      }
      element1->frame_count = 0;
    }

    update_measures(element1);
  }
  
  // Estado ataque superior - player2
  if ((element2->is_A_attacking) && (!element2->control->right) && (!element2->control->left) && (!element2->is_jumping) && (!element2->control->down) && (!element2->control->defense)) {
    element2->current_animation = ATTACK_A;
    element2->frame_count += 3;
    if (element2->frame_count >= element2->frame_delay) {
      element2->attack_A->current_frame++;
      if (element2->attack_A->current_frame >= element2->attack_A->num_frames) {
        element2->attack_A->current_frame = 0;
        element2->is_A_attacking = 0;
        if (element1->is_taking_damage)
          element1->is_taking_damage = 0;
      }
      element2->frame_count = 0;
    }

    update_measures(element2);
  }

  // Estado ataque inferior - player1
  if ((element1->is_B_attacking) && (!element1->control->right) && (!element1->control->left) && (!element1->is_jumping) && (!element1->control->down) && (!element1->control->defense)) {
    element1->current_animation = ATTACK_B;
    element1->frame_count += 3;
    if (element1->frame_count >= element1->frame_delay) {
      element1->attack_B->current_frame++;
      if (element1->attack_B->current_frame >= element1->attack_B->num_frames) {
        element1->attack_B->current_frame = 0;
        element1->is_B_attacking = 0;
        if (element2->is_taking_damage)
          element2->is_taking_damage = 0;
      }
      element1->frame_count = 0;
    }

    update_measures(element1);
  }
  
  // Estado ataque inferior - player2
  if ((element2->is_B_attacking) && (!element2->control->right) && (!element2->control->left) && (!element2->is_jumping) && (!element2->control->down) && (!element2->control->defense)) {
    element2->current_animation = ATTACK_B;
    element2->frame_count += 3;
    if (element2->frame_count >= element2->frame_delay) {
      element2->attack_B->current_frame++;
      if (element2->attack_B->current_frame >= element2->attack_B->num_frames) {
        element2->attack_B->current_frame = 0;
        element2->is_B_attacking = 0;
        if (element1->is_taking_damage)
          element1->is_taking_damage = 0;
      }
      element2->frame_count = 0;
    }

    update_measures(element2);
  }

  // Estado ataque superior no ar - player1
  if ((element1->is_A_attacking) && (element1->is_jumping) && (!element1->control->down) && (!element1->control->defense)) {
    element1->current_animation = JUMP_ATTACK_A;
    element1->frame_count += 3;
    if (element1->frame_count >= element1->frame_delay) {
      element1->jump_attack_A->current_frame++;
      if (element1->jump_attack_A->current_frame >= element1->jump_attack_A->num_frames) {
        element1->jump_attack_A->current_frame = 0;
        element1->is_A_attacking = 0;
        if (element2->is_taking_damage)
          element2->is_taking_damage = 0;
      }
      element1->frame_count = 0;
    }

    update_measures(element1);
  }

  // Estado ataque superior no ar - player2
  if ((element2->is_A_attacking) && (element2->is_jumping) && (!element2->control->down) && (!element2->control->defense)) {
    element2->current_animation = JUMP_ATTACK_A;
    element2->frame_count += 3;
    if (element2->frame_count >= element2->frame_delay) {
      element2->jump_attack_A->current_frame++;
      if (element2->jump_attack_A->current_frame >= element2->jump_attack_A->num_frames) {
        element2->jump_attack_A->current_frame = 0;
        element2->is_A_attacking = 0;
        if (element1->is_taking_damage)
          element1->is_taking_damage = 0;
      }
      element2->frame_count = 0;
    }

    update_measures(element2);
  }

  // Estado ataque inferior no ar - player1
  if ((element1->is_B_attacking) && (element1->is_jumping) && (!element1->control->down) && (!element1->control->defense)) {
    element1->current_animation = JUMP_ATTACK_B;
    element1->frame_count += 3;
    if (element1->frame_count >= element1->frame_delay) {
      element1->jump_attack_B->current_frame++;
      if (element1->jump_attack_B->current_frame >= element1->jump_attack_B->num_frames) {
        element1->jump_attack_B->current_frame = 0;
        element1->is_B_attacking = 0;
        if (element2->is_taking_damage)
          element2->is_taking_damage = 0;
      }
      element1->frame_count = 0;
    }

    update_measures(element1);
  }

  // Estado ataque inferior no ar - player2
  if ((element2->is_B_attacking) && (element2->is_jumping) && (!element2->control->down) && (!element2->control->defense)) {
    element2->current_animation = JUMP_ATTACK_B;
    element2->frame_count += 3;
    if (element2->frame_count >= element2->frame_delay) {
      element2->jump_attack_B->current_frame++;
      if (element2->jump_attack_B->current_frame >= element2->jump_attack_B->num_frames) {
        element2->jump_attack_B->current_frame = 0;
        element2->is_B_attacking = 0;
        if (element1->is_taking_damage)
          element1->is_taking_damage = 0;
      }
      element2->frame_count = 0;
    }

    update_measures(element2);
  }  

  // Estado ataque superior agachado - player1
  if ((element1->is_A_attacking) && (!element1->control->right) && (!element1->control->left) && (!element1->is_jumping) && (element1->control->down) && (!element1->is_B_attacking) && (!element1->is_special_attacking) && (element1->ID != JACK)) {
    element1->current_animation = CROUCH_ATTACK_A;
    element1->frame_count++;
    if (element1->frame_count >= element1->frame_delay) {
      element1->crouch_attack_A->current_frame++;
      if (element1->crouch_attack_A->current_frame >= element1->crouch_attack_A->num_frames) {
        element1->crouch_attack_A->current_frame = 0;
        element1->is_A_attacking = 0;
        if (element2->is_taking_damage)
          element2->is_taking_damage = 0;
      }
      element1->frame_count = 0;
    }

    update_measures(element1);
  }
  
  // Estado ataque superior agachado - player2
  if ((element2->is_A_attacking) && (!element2->control->right) && (!element2->control->left) && (!element2->is_jumping) && (element2->control->down) && (!element2->is_B_attacking) && (!element2->is_special_attacking) && (element2->ID != JACK)) {
    element2->current_animation = CROUCH_ATTACK_A;
    element2->frame_count++;
    if (element2->frame_count >= element2->frame_delay) {
      element2->crouch_attack_A->current_frame++;
      if (element2->crouch_attack_A->current_frame >= element2->crouch_attack_A->num_frames) {
        element2->crouch_attack_A->current_frame = 0;
        element2->is_A_attacking = 0;
        if (element1->is_taking_damage)
          element1->is_taking_damage = 0;
      }
      element2->frame_count = 0;
    }

    update_measures(element2);
  }

  // Estado ataque inferior agachado - player1
  if ((element1->is_B_attacking) && (!element1->control->right) && (!element1->control->left) && (!element1->is_jumping) && (element1->control->down) && (!element1->is_A_attacking) && (!element1->is_special_attacking) && (element1->ID != JACK)) {
    element1->current_animation = CROUCH_ATTACK_B;
    element1->frame_count++;
    if (element1->frame_count >= element1->frame_delay) {
      element1->crouch_attack_B->current_frame++;
      if (element1->crouch_attack_B->current_frame >= element1->crouch_attack_B->num_frames) {
        element1->crouch_attack_B->current_frame = 0;
        element1->is_B_attacking = 0;
        if (element2->is_taking_damage)
          element2->is_taking_damage = 0;
      }
      element1->frame_count = 0;
    }

    update_measures(element1);
  }
  
  // Estado ataque inferior agachado - player2
  if ((element2->is_B_attacking) && (!element2->control->right) && (!element2->control->left) && (!element2->is_jumping) && (element2->control->down) && (!element2->is_A_attacking) && (!element2->is_special_attacking) && (element2->ID != JACK)) {
    element2->current_animation = CROUCH_ATTACK_B;
    element2->frame_count++;
    if (element2->frame_count >= element2->frame_delay) {
      element2->crouch_attack_B->current_frame++;
      if (element2->crouch_attack_B->current_frame >= element2->crouch_attack_B->num_frames) {
        element2->crouch_attack_B->current_frame = 0;
        element2->is_B_attacking = 0;
        if (element1->is_taking_damage)
          element1->is_taking_damage = 0;
      }
      element2->frame_count = 0;
    }

    update_measures(element2);
  }


  // Estado ataque especial - player1
  if (element1->is_special_attacking) {
    element1->current_animation = SPECIAL_ATTACK;
    element1->frame_count++;
    if (element1->frame_count >= element1->frame_delay) {
      element1->special_attack->current_frame++;
      if (element1->special_attack->current_frame >= element1->special_attack->num_frames) {
        element1->special_attack->current_frame = 0;
        element1->frames_special_attack = 0;
        element1->is_special_attacking = 0;
        if (element2->is_taking_damage)
          element2->is_taking_damage = 0;
      }
      element1->frame_count = 0;
    }

    update_measures(element1);
  } else if (element1->frames_special_attack < 600)
    element1->frames_special_attack++;

  // Estado ataque especial - player2
  if (element2->is_special_attacking) {
    element2->current_animation = SPECIAL_ATTACK;
    element2->frame_count++;
    if (element2->frame_count >= element2->frame_delay) {
      element2->special_attack->current_frame++;
      if (element2->special_attack->current_frame >= element2->special_attack->num_frames) {
        element2->special_attack->current_frame = 0;
        element2->frames_special_attack = 0;
        element2->is_special_attacking = 0;
        if (element1->is_taking_damage)
          element1->is_taking_damage = 0;
      }
      element2->frame_count = 0;
    }

    update_measures(element2);
  } else if (element2->frames_special_attack < 600)
    element2->frames_special_attack++;

  // Estado de defesa em pé - player1
  if ((element1->control->defense) && (!element1->control->down) && (!element1->control->right) && (!element1->control->left) && (!element1->is_A_attacking) && (!element1->is_B_attacking) && (!element1->is_special_attacking)) {
    element1->current_animation = STANDING_DEFENSE;
    update_measures(element1);
  }

  // Estado de defesa em pé - player2
  if ((element2->control->defense) && (!element2->control->down) && (!element2->control->right) && (!element2->control->left) && (!element2->is_A_attacking) && (!element2->is_B_attacking) && (!element2->is_special_attacking)) {
    element2->current_animation = STANDING_DEFENSE;
    update_measures(element2);
  }

  // Estado de defesa agachado - player1
  if ((element1->control->defense) && (element1->control->down) && (!element1->control->right) && (!element1->control->left) && (!element1->is_A_attacking) && (!element1->is_B_attacking) && (!element1->is_special_attacking)) {
    element1->current_animation = CROUCH_DEFENSE;
    update_measures(element1);
  }

  // Estado de defesa agachado - player2
  if ((element2->control->defense) && (element2->control->down) && (!element2->control->right) && (!element2->control->left) && (!element2->is_A_attacking) && (!element2->is_B_attacking) && (!element2->is_special_attacking)) {
    element2->current_animation = CROUCH_DEFENSE;
    update_measures(element2);
  }

  // Configura o dano do player1
  if (damage(element2, element1) && (!element1->is_taking_damage)) {
    element1->is_taking_damage = 1;
    if (element2->is_special_attacking)
      element1->life -= 25;
    else
      element1->life -= 10;
  }

  // Configura o dano do player2
  if (damage(element1, element2) && (!element2->is_taking_damage)) {
    element2->is_taking_damage = 1;
    if (element1->is_special_attacking)
      element2->life -= 25;
    else
      element2->life -= 10;
  }

  // Se necessário, configura o início da animação de morte do player1 - e trava todos os seus outros movimentos
  if (element1->life <= 0) {
    element1->life = 0;
    element1->is_dying = 1;
  }
  
  // Se necessário, configura o início da animação de morte do player2 - e trava todos os seus outros movimentos
  if (element2->life <= 0) {
    element2->life = 0;
    element2->is_dying = 1;
  }

  // Estado morrendo - player1
  if ((element1->is_dying) && (!element1->dead)) {
    element1->current_animation = DEATH;
    if (element1->face == 1)
      element1->x -= 2.0;
    else
      element1->x += 2.0;
    element1->frame_count++;
    if (element1->frame_count >= element1->frame_delay) {
      element1->death->current_frame++;
      // Se a animação de morte acabou, ativa "dead" (indicando que player está morto) e trava a animação no último frame
      if (element1->death->current_frame >= element1->death->num_frames) {
        element1->dead = 1;
        element1->is_dying = 0;
        element1->death->current_frame = element1->death->num_frames - 1;
      }
      element1->frame_count = 0;
    }

    update_measures(element1);
  }

  // Estado morrendo - player2
  if ((element2->is_dying) && (!element2->dead)) {
    element2->current_animation = DEATH;
    if (element2->face == 1)
      element2->x -= 2.0;
    else
      element2->x += 2.0;
    element2->frame_count++;
    if (element2->frame_count >= element2->frame_delay) {
      element2->death->current_frame++;
      // Se a animação de morte acabou, ativa "dead" (indicando que player está morto) e trava a animação no último frame
      if (element2->death->current_frame >= element2->death->num_frames) {
        element2->dead = 1;
        element2->is_dying = 0;
        element2->death->current_frame = element2->death->num_frames - 1;
      }
      element2->frame_count = 0;
    }

    update_measures(element2);
  }

  // Zera o frame da animação anterior
  reset_animation(element1);
  reset_animation(element2);

  // Se o jogador não está pulando, a altura sempre é a altura do display - altura do frame
  if (!element1->is_jumping) 
    element1->y = (float) display_y - element1->current_height;
  
  if (!element2->is_jumping)
    element2->y = (float) display_y - element2->current_height;

  // Não deixa o jogador ultrapassar as laterais do display
  verify_display_limits(element1, display_x, display_y);
  verify_display_limits(element2, display_x, display_y);
}

// Atualiza o campo "face" dos dois jogadores passados como parâmetro. Os personagens sempre devem ficar de frente um para o outro
void update_faces(player *element1, player *element2) {
  if ((element1->face == -1) && (element2->face == -1)) { 
    if (element1->x <= element2->x) {
      element1->face = 1;
      element1->x -= element1->current_width;
    } else {
      element2->face = 1;
      element2->x -= element2->current_width;
    }
  } else if ((element1->face == 1) && (element2->face == 1)) {
    if (element1->x >= element2->x) {
      element1->face = -1;
      element1->x += element1->current_width;
    } else {
      element2->face = -1;
      element2->x += element2->current_width;
    }
  } else if ((element1->face == -1) && (element2->face == 1)) {
    if (element1->x <= element2->x) {
      element1->face = 1;
      element1->x -= element1->current_width;
    }
  } else if ((element1->face == 1) && (element2->face == -1)) {
    if (element2->x <= element1->x + element1->current_width) {
      element2->face = 1;
      element2->x -= element2->current_width;
    }
  }
}

// Imprime o frame atual da animação atual na tela
void draw_player(player *element) {
  if (element->current_animation == NEUTRAL) // Animação 0 - neutra
    al_draw_scaled_bitmap(element->neutral->frames[element->neutral->current_frame], 0, 0, element->current_width, element->current_height, element->x, element->y, element->face * element->current_width, element->current_height, 0);
  else if (element->current_animation == WALK) // Animação 1 - andar
    al_draw_scaled_bitmap(element->walk->frames[element->walk->current_frame], 0, 0, element->current_width, element->current_height, element->x, element->y, element->face * element->current_width, element->current_height, 0);
  else if (element->current_animation == JUMP) // Animação 2 - pular
    al_draw_scaled_bitmap(element->jump->frames[element->jump->current_frame], 0, 0, element->current_width, element->current_height, element->x, element->y, element->face * element->current_width, element->current_height, 0);
  else if (element->current_animation == CROUCH) // Animação 3 - agachar
    al_draw_scaled_bitmap(element->crouch->frames[element->crouch->current_frame], 0, 0, element->current_width, element->current_height, element->x, element->y, element->face * element->current_width, element->current_height, 0);
  else if (element->current_animation == ATTACK_A) // Animação 4 - ataque de pé com membros superiores 
    al_draw_scaled_bitmap(element->attack_A->frames[element->attack_A->current_frame], 0, 0, element->current_width, element->current_height, element->x, element->y, element->face * element->current_width, element->current_height, 0);
  else if (element->current_animation == ATTACK_B) // Animação 5 - ataque de pé com membros inferiores
    al_draw_scaled_bitmap(element->attack_B->frames[element->attack_B->current_frame], 0, 0, element->current_width, element->current_height, element->x, element->y, element->face * element->current_width, element->current_height, 0);
  else if (element->current_animation == JUMP_ATTACK_A) // Animação 6 - ataque no ar com membros superiores
    al_draw_scaled_bitmap(element->jump_attack_A->frames[element->jump_attack_A->current_frame], 0, 0, element->current_width, element->current_height, element->x, element->y, element->face * element->current_width, element->current_height, 0);
  else if (element->current_animation == JUMP_ATTACK_B) // Animação 7 - ataque no ar com membros inferiores
    al_draw_scaled_bitmap(element->jump_attack_B->frames[element->jump_attack_B->current_frame], 0, 0, element->current_width, element->current_height, element->x, element->y, element->face * element->current_width, element->current_height, 0);
  else if (element->current_animation == CROUCH_ATTACK_A) // Animação 8 - ataque agachado com membros superiores
    al_draw_scaled_bitmap(element->crouch_attack_A->frames[element->crouch_attack_A->current_frame], 0, 0, element->current_width, element->current_height, element->x, element->y, element->face * element->current_width, element->current_height, 0);
  else if (element->current_animation == CROUCH_ATTACK_B) // Animação 9 - ataque agachado com membros inferiores 
    al_draw_scaled_bitmap(element->crouch_attack_B->frames[element->crouch_attack_B->current_frame], 0, 0, element->current_width, element->current_height, element->x, element->y, element->face * element->current_width, element->current_height, 0);
  else if (element->current_animation == SPECIAL_ATTACK) // Animação 10 - ataque especial
    al_draw_scaled_bitmap(element->special_attack->frames[element->special_attack->current_frame], 0, 0, element->current_width, element->current_height, element->x, element->y, element->face * element->current_width, element->current_height, 0);   
  else if (element->current_animation == DEATH) // Animação 11 - morte
    al_draw_scaled_bitmap(element->death->frames[element->death->current_frame], 0, 0, element->current_width, element->current_height, element->x, element->y, element->face * element->current_width, element->current_height, 0);   
  else if (element->current_animation == STANDING_DEFENSE)
    al_draw_scaled_bitmap(element->standing_defense, 0, 0, element->current_width, element->current_height, element->x, element->y, element->face * element->current_width, element->current_height, 0);
  else if (element->current_animation == CROUCH_DEFENSE)
    al_draw_scaled_bitmap(element->crouch_defense, 0, 0, element->current_width, element->current_height, element->x, element->y, element->face * element->current_width, element->current_height, 0);
}    

// Desenha informações sobre os dois players: retângulo superior, rosto do personagem, valor da vida e, se houver, ataque especial
void draw_HUD(player *element1, player *element2, int display_x) {
  al_draw_filled_rectangle(0, 0, display_x, element1->profile_height - 1, al_map_rgb(0, 0, 0));

  // Desenha o hud do player1 (na esquerda)
  al_draw_bitmap(element1->profile, 0, 0, 0);
  al_draw_filled_rectangle(element1->profile_width, element1->profile_height - 20, element1->profile_width + 2 * element1->life, element1->profile_height - 1, al_map_rgb(58, 181, 75));
  al_draw_rectangle(element1->profile_width, element1->profile_height - 20, element1->profile_width + 200, element1->profile_height - 1, al_map_rgb(255, 255, 255), 2);
  
  if ((element1->ID == RYO) || (element1->ID == ROBERT)) {
    al_draw_filled_rectangle(element1->profile_width, element1->profile_height - 40, element1->profile_width + element1->frames_special_attack / 3, element1->profile_height - 21, al_map_rgb(255, 0, 0));
    al_draw_rectangle(element1->profile_width, element1->profile_height - 40, element1->profile_width + 200, element1->profile_height - 21, al_map_rgb(255, 255, 255), 2);   
  }
  
  // Desenha o hud do player2 (na direita)
  al_draw_bitmap(element2->profile, display_x - element2->profile_width, 0, 0);
  al_draw_filled_rectangle(display_x - element2->profile_width, element2->profile_height - 20, display_x - element2->profile_width - 2 * element2->life, element2->profile_height - 1, al_map_rgb(58, 181, 75));
  al_draw_rectangle(display_x - element2->profile_width - 200, element2->profile_height - 20, display_x - element2->profile_width, element2->profile_height - 1, al_map_rgb(255, 255, 255), 2);
  
  if ((element2->ID == RYO) || (element2->ID == ROBERT)) {
    al_draw_filled_rectangle(display_x - element2->profile_width, element2->profile_height - 40, display_x - element2->profile_width - element2->frames_special_attack / 3, element2->profile_height - 21, al_map_rgb(255, 0, 0));
    al_draw_rectangle(display_x - element2->profile_width - 200, element2->profile_height - 40, display_x - element2->profile_width, element2->profile_height - 1, al_map_rgb(255, 255, 255), 2);
  }
}

// Desaloca a memória usada para um personagem
void destroy_player(player *element) {
  al_destroy_bitmap(element->profile);

  destroy_animation(element->neutral, element->neutral->num_frames);
  destroy_animation(element->walk, element->walk->num_frames);
  destroy_animation(element->jump, element->jump->num_frames);
  destroy_animation(element->crouch, element->crouch->num_frames);
  destroy_animation(element->attack_A, element->attack_A->num_frames);
  destroy_animation(element->attack_B, element->attack_B->num_frames);

  if (element->jump_attack_A != element->jump_attack_B) {
    destroy_animation(element->jump_attack_A, element->jump_attack_A->num_frames);
    destroy_animation(element->jump_attack_B, element->jump_attack_B->num_frames);
  } else 
    destroy_animation(element->jump_attack_A, element->jump_attack_A->num_frames);

  if (element->ID != JACK) {
    if (element->crouch_attack_A != element->crouch_attack_B) {
      destroy_animation(element->crouch_attack_A, element->crouch_attack_A->num_frames);
      destroy_animation(element->crouch_attack_B, element->crouch_attack_B->num_frames);
    } else
      destroy_animation(element->crouch_attack_A, element->crouch_attack_A->num_frames);
  }

  if ((element->ID == RYO) || (element->ID == ROBERT))
    destroy_animation(element->special_attack, element->special_attack->num_frames);

  destroy_animation(element->death, element->death->num_frames);
  
  al_destroy_bitmap(element->standing_defense);
  al_destroy_bitmap(element->crouch_defense);

  destroy_joystick(element->control);
  free(element);
}