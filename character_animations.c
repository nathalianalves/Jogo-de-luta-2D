#include "character_animations.h"

/*-------------------------------- PRIMEIRO PERSONAGEM: RYUHAKU TODOH --------------------------------*/
animation *create_todoh_neutral() {
  animation *new_neutral;

  new_neutral = create_animation(4);
  if (!new_neutral) 
    return NULL; 

  new_neutral->frames[0] = al_load_bitmap("Sprites/Ryuhaku Todoh/Neutral 1.png");
  if (!new_neutral->frames[0]) {
    printf("Falha ao carregar foto.\n");
    destroy_animation(new_neutral, 0);
    return NULL;
  }

  new_neutral->frames[1] = al_load_bitmap("Sprites/Ryuhaku Todoh/Neutral 2.png");
  if (!new_neutral->frames[1]) {
    printf("Falha ao carregar foto.\n");
    destroy_animation(new_neutral, 1);
    return NULL;
  }

  new_neutral->frames[2] = al_load_bitmap("Sprites/Ryuhaku Todoh/Neutral 3.png");
  if (!new_neutral->frames[2]) {
    printf("Falha ao carregar foto.\n");
    destroy_animation(new_neutral, 2);
    return NULL;
  }

  new_neutral->frames[3] = al_load_bitmap("Sprites/Ryuhaku Todoh/Neutral 4.png");
  if (!new_neutral->frames[3]) {
    printf("Falha ao carregar foto.\n");
    destroy_animation(new_neutral, 3);
    return NULL;
  }

  return new_neutral;
}

animation *create_todoh_walk() {
  animation *new_walk;

  // Aloca espaço para o vetor da animação "andar" do Mr Karate
  new_walk = create_animation(4); 
  if (!new_walk)  
    return NULL;
  
  // Criação e tratamento de erros - frame 1 animação "andar"
  new_walk->frames[0] = al_load_bitmap("Sprites/Ryuhaku Todoh/Walk 1.png");
  if (!new_walk->frames[0]){
    printf("Falha ao carregar foto.\n");
    destroy_animation(new_walk, 0);
    return NULL;
  }

  // Criação e tratamento de erros - frame 2 animação "andar"
  new_walk->frames[1] = al_load_bitmap("Sprites/Ryuhaku Todoh/Walk 2.png");
  if (!new_walk->frames[1]){
    printf("Falha ao carregar foto.\n");
    destroy_animation(new_walk, 1);
    return NULL;
  }

  // Criação e tratamento de erros - frame 3 animação "andar"
  new_walk->frames[2] = al_load_bitmap("Sprites/Ryuhaku Todoh/Walk 3.png");
  if (!new_walk->frames[2]){
    printf("Falha ao carregar foto.\n");
    destroy_animation(new_walk, 2);
    return NULL;
  }

  // Criação e tratamento de erros - frame 4 animação "andar"
  new_walk->frames[3] = al_load_bitmap("Sprites/Ryuhaku Todoh/Walk 4.png");
  if (!new_walk->frames[3]){
    printf("Falha ao carregar foto.\n");
    destroy_animation(new_walk, 3);
    return NULL;
  }
  
  return new_walk;
}

animation *create_todoh_jump() {
  animation *new_jump;

  // Aloca espaço para o vetor de animação "pulo" do Mr Karate
  new_jump = create_animation(5);
  if (!new_jump) 
    return NULL;

  // Criação e tratamento de erros - frame 1 animação "pulo"
  new_jump->frames[0] = al_load_bitmap("Sprites/Ryuhaku Todoh/Jump 1.png");
  if (!new_jump->frames[0]) {
    printf("Falha ao carregar foto.\n");
    destroy_animation(new_jump, 0);
    return NULL;
  }

  // Criação e tratamento de erros - frame 2 animação "pulo"
  new_jump->frames[1] = al_load_bitmap("Sprites/Ryuhaku Todoh/Jump 2.png");
  if (!new_jump->frames[1]) {
    printf("Falha ao carregar foto.\n");
    destroy_animation(new_jump, 1);
    return NULL;
  }

  // Criação e tratamento de erros - frame 3 animação "pulo"
  new_jump->frames[2] = al_load_bitmap("Sprites/Ryuhaku Todoh/Jump 3.png");
  if (!new_jump->frames[2]) {
    printf("Falha ao carregar foto.\n");
    destroy_animation(new_jump, 2);
    return NULL;
  }

  // Criação e tratamento de erros - frame 4 animação "pulo"
  new_jump->frames[3] = al_load_bitmap("Sprites/Ryuhaku Todoh/Jump 4.png");
  if (!new_jump->frames[3]) {
    printf("Falha ao carregar foto.\n");
    destroy_animation(new_jump, 3);
    return NULL;
  }

  // Criação e tratamento de erros - frame 5 animação "pulo"
  new_jump->frames[4] = al_load_bitmap("Sprites/Ryuhaku Todoh/Jump 5.png");
  if (!new_jump->frames[4]) {
    printf("Falha ao carregar foto.\n");
    destroy_animation(new_jump, 4);
    return NULL;
  }

  return new_jump;
}

animation *create_todoh_crouch() {
  animation *new_crouch;

  new_crouch = create_animation(1);
  if (!new_crouch)
    return NULL;
  
  new_crouch->frames[0] = al_load_bitmap("Sprites/Ryuhaku Todoh/Crouch.png");
  if (!new_crouch->frames[0]) {
    printf("Falha ao carregar foto.\n");
    destroy_animation(new_crouch, 0);
    return NULL;
  }

  return new_crouch;
}

animation *create_todoh_attack_A() {
  animation *new_attack_A;

  new_attack_A = create_animation(4);
  if (!new_attack_A) 
    return NULL;

  new_attack_A->frames[0] = al_load_bitmap("Sprites/Ryuhaku Todoh/Attack A 1.png");
  if (!new_attack_A->frames[0]) {
    printf("Falha ao carregar foto.\n");
    destroy_animation(new_attack_A, 0);
    return NULL;
  }

  new_attack_A->frames[1] = al_load_bitmap("Sprites/Ryuhaku Todoh/Attack A 2.png");
  if (!new_attack_A->frames[1]) {
    printf("Falha ao carregar foto.\n");
    destroy_animation(new_attack_A, 1);
    return NULL;
  }

  new_attack_A->frames[2] = al_load_bitmap("Sprites/Ryuhaku Todoh/Attack A 3.png");
  if (!new_attack_A->frames[2]) {
    printf("Falha ao carregar foto.\n");
    destroy_animation(new_attack_A, 2);
    return NULL;
  }

  new_attack_A->frames[3] = al_load_bitmap("Sprites/Ryuhaku Todoh/Attack A 4.png");
  if (!new_attack_A->frames[3]) {
    printf("Falha ao carregar foto.\n");
    destroy_animation(new_attack_A, 3);
    return NULL;
  }

  return new_attack_A;
}

animation *create_todoh_attack_B() {
  animation *new_attack_B;

  new_attack_B = create_animation(5);
  if (!new_attack_B) 
    return NULL;
  

  new_attack_B->frames[0] = al_load_bitmap("Sprites/Ryuhaku Todoh/Attack B 1.png");
  if (!new_attack_B->frames[0]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack_B, 0);
    return NULL;
  }

  new_attack_B->frames[1] = al_load_bitmap("Sprites/Ryuhaku Todoh/Attack B 2.png");
  if (!new_attack_B->frames[1]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack_B, 1);
    return NULL;
  }

  new_attack_B->frames[2] = al_load_bitmap("Sprites/Ryuhaku Todoh/Attack B 3.png");
  if (!new_attack_B->frames[2]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack_B, 2);
    return NULL;
  }

  new_attack_B->frames[3] = al_load_bitmap("Sprites/Ryuhaku Todoh/Attack B 4.png");
  if (!new_attack_B->frames[3]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack_B, 3);
    return NULL;
  }

  new_attack_B->frames[4] = al_load_bitmap("Sprites/Ryuhaku Todoh/Attack B 5.png");
  if (!new_attack_B->frames[4]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack_B, 4);
    return NULL;
  }

  return new_attack_B;
}

animation *create_todoh_jump_attack_A() {
  animation *new_jump_attack;

  new_jump_attack = create_animation(2);
  if (!new_jump_attack) 
    return NULL;

  new_jump_attack->frames[0] = al_load_bitmap("Sprites/Ryuhaku Todoh/Jump Attack 1.png");
  if (!new_jump_attack->frames[0]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_jump_attack, 0);
    return NULL;
  }

  new_jump_attack->frames[1] = al_load_bitmap("Sprites/Ryuhaku Todoh/Jump Attack 2.png");
  if (!new_jump_attack->frames[1]) {
    printf("Não foi possível carregar.\n");
    destroy_animation(new_jump_attack, 1);
    return NULL;
  }

  return new_jump_attack;
}

animation *create_todoh_crouch_attack() {
  animation *new_attack;

  new_attack = create_animation(3);
  if (!new_attack)
    return NULL;

  new_attack->frames[0] = al_load_bitmap("Sprites/Ryuhaku Todoh/Crouch Attack 1.png");
  if (!new_attack->frames[0]) {
    printf("Não foi possível carregar foto - crouch attack Todoh.\n");
    destroy_animation(new_attack, 0);
    return NULL;
  }

  new_attack->frames[1] = al_load_bitmap("Sprites/Ryuhaku Todoh/Crouch Attack 2.png");
  if (!new_attack->frames[1]) {
    printf("Não foi possível carregar foto - crouch attack Todoh.\n");
    destroy_animation(new_attack, 1);
    return NULL;
  }

  new_attack->frames[2] = al_load_bitmap("Sprites/Ryuhaku Todoh/Crouch Attack 3.png");
  if (!new_attack->frames[2]) {
    printf("Não foi possível carregar foto - crouch attack Todoh.\n");
    destroy_animation(new_attack, 2);
    return NULL;
  }

  return new_attack;
}

animation *create_todoh_death() {
  animation *new_death;

  new_death = create_animation(5);
  if (!new_death)
    return NULL;
    
  new_death->frames[0] = al_load_bitmap("Sprites/Ryuhaku Todoh/Death 1.png");
  if (!new_death->frames[0]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_death, 0);
    return NULL;
  }

  new_death->frames[1] = al_load_bitmap("Sprites/Ryuhaku Todoh/Death 2.png");
  if (!new_death->frames[1]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_death, 1);
    return NULL;
  }

  new_death->frames[2] = al_load_bitmap("Sprites/Ryuhaku Todoh/Death 3.png");
  if (!new_death->frames[2]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_death, 2);
    return NULL;
  }

  new_death->frames[3] = al_load_bitmap("Sprites/Ryuhaku Todoh/Death 4.png");
  if (!new_death->frames[3]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_death, 3);
    return NULL;
  }

  new_death->frames[4] = al_load_bitmap("Sprites/Ryuhaku Todoh/Death 5.png");
  if (!new_death->frames[4]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_death, 4);
    return NULL;
  }

  return new_death;
}

/*-------------------------------- SEGUNDO PERSONAGEM: RYO SAKAZAKI --------------------------------*/
animation *create_ryo_neutral() {
  animation *new_neutral;

  new_neutral = create_animation(4);
  if (!new_neutral)
    return NULL;
  
  new_neutral->frames[0] = al_load_bitmap("Sprites/Ryo Sakazaki/Neutral 1.png");
  if (!new_neutral->frames[0]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_neutral, 0);
    return NULL;
  }

  new_neutral->frames[1] = al_load_bitmap("Sprites/Ryo Sakazaki/Neutral 2.png");
  if (!new_neutral->frames[1]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_neutral, 1);
    return NULL;
  }

  new_neutral->frames[2] = al_load_bitmap("Sprites/Ryo Sakazaki/Neutral 3.png");
  if (!new_neutral->frames[2]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_neutral, 2);
    return NULL;
  }

  new_neutral->frames[3] = al_load_bitmap("Sprites/Ryo Sakazaki/Neutral 4.png");
  if (!new_neutral->frames[3]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_neutral, 3);
    return NULL;
  }

  return new_neutral;
}

animation *create_ryo_walk() {
  animation *new_walk;

  new_walk = create_animation(4);
  if (!new_walk)
    return NULL;

  new_walk->frames[0] = al_load_bitmap("Sprites/Ryo Sakazaki/Walk 1.png");
  if (!new_walk->frames[0]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_walk, 0);
    return NULL;
  }

  new_walk->frames[1] = al_load_bitmap("Sprites/Ryo Sakazaki/Walk 2.png");
  if (!new_walk->frames[1]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_walk, 1);
    return NULL;
  }

  new_walk->frames[2] = al_load_bitmap("Sprites/Ryo Sakazaki/Walk 3.png");
  if (!new_walk->frames[2]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_walk, 2);
    return NULL;
  }

  new_walk->frames[3] = al_load_bitmap("Sprites/Ryo Sakazaki/Walk 4.png");
  if (!new_walk->frames[3]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_walk, 3);
    return NULL;
  }

  return new_walk;
}

animation *create_ryo_jump() {
  animation *new_jump;

  new_jump = create_animation(5);
  if (!new_jump)
    return NULL;
  
  new_jump->frames[0] = al_load_bitmap("Sprites/Ryo Sakazaki/Jump 1.png");
  if (!new_jump->frames[0]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_jump, 0);
    return NULL;
  }

  new_jump->frames[1] = al_load_bitmap("Sprites/Ryo Sakazaki/Jump 2.png");
  if (!new_jump->frames[1]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_jump, 1);
    return NULL;
  }

  new_jump->frames[2] = al_load_bitmap("Sprites/Ryo Sakazaki/Jump 3.png");
  if (!new_jump->frames[2]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_jump, 2);
    return NULL;
  }

  new_jump->frames[3] = al_load_bitmap("Sprites/Ryo Sakazaki/Jump 4.png");
  if (!new_jump->frames[3]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_jump, 3);
    return NULL;
  }

  new_jump->frames[4] = al_load_bitmap("Sprites/Ryo Sakazaki/Jump 5.png");
  if (!new_jump->frames[4]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_jump, 4);
    return NULL;
  }

  return new_jump;
}

animation *create_ryo_crouch() {
  animation *new_crouch;

  new_crouch = create_animation(3);
  if (!new_crouch)
    return NULL;
  
  new_crouch->frames[0] = al_load_bitmap("Sprites/Ryo Sakazaki/Crouch 1.png");
  if (!new_crouch->frames[0]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_crouch, 0);
    return NULL;
  }

  new_crouch->frames[1] = al_load_bitmap("Sprites/Ryo Sakazaki/Crouch 2.png");
  if (!new_crouch->frames[1]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_crouch, 1);
    return NULL;
  }

  new_crouch->frames[2] = al_load_bitmap("Sprites/Ryo Sakazaki/Crouch 3.png");
  if (!new_crouch->frames[2]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_crouch, 2);
    return NULL;
  }

  return new_crouch;
}

animation *create_ryo_attack_A() {
  animation *new_attack_A;

  new_attack_A = create_animation(3);
  if (!new_attack_A)
    return NULL;
  
  new_attack_A->frames[0] = al_load_bitmap("Sprites/Ryo Sakazaki/Attack A 1.png");
  if (!new_attack_A->frames[0]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack_A, 0);
    return NULL;
  }

  new_attack_A->frames[1] = al_load_bitmap("Sprites/Ryo Sakazaki/Attack A 2.png");
  if (!new_attack_A->frames[1]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack_A, 1);
    return NULL;
  }

  new_attack_A->frames[2] = al_load_bitmap("Sprites/Ryo Sakazaki/Attack A 3.png");
  if (!new_attack_A->frames[2]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack_A, 2);
    return NULL;
  }
  
  return new_attack_A;
}

animation *create_ryo_attack_B() {
  animation *new_attack_B;

  new_attack_B = create_animation(4);
  if (!new_attack_B)
    return NULL;
  
  new_attack_B->frames[0] = al_load_bitmap("Sprites/Ryo Sakazaki/Attack B 1.png");
  if (!new_attack_B->frames[0]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack_B, 0);
    return NULL;
  }

  new_attack_B->frames[1] = al_load_bitmap("Sprites/Ryo Sakazaki/Attack B 2.png");
  if (!new_attack_B->frames[1]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack_B, 1);
    return NULL;
  }

  new_attack_B->frames[2] = al_load_bitmap("Sprites/Ryo Sakazaki/Attack B 3.png");
  if (!new_attack_B->frames[2]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack_B, 2);
    return NULL;
  }

  new_attack_B->frames[3] = al_load_bitmap("Sprites/Ryo Sakazaki/Attack B 4.png");
  if (!new_attack_B->frames[3]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack_B, 3);
    return NULL;
  }

  return new_attack_B;
}

animation *create_ryo_jump_attack_A() {
  animation *new_jump_attack;

  new_jump_attack = create_animation(3);
  if (!new_jump_attack)
    return NULL;
  
  new_jump_attack->frames[0] = al_load_bitmap("Sprites/Ryo Sakazaki/Jump Attack A 1.png");
  if (!new_jump_attack->frames[0]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_jump_attack, 0);
    return NULL;
  }

  new_jump_attack->frames[1] = al_load_bitmap("Sprites/Ryo Sakazaki/Jump Attack A 2.png");
  if (!new_jump_attack->frames[1]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_jump_attack, 1);
    return NULL;
  }

  new_jump_attack->frames[2] = al_load_bitmap("Sprites/Ryo Sakazaki/Jump Attack A 3.png");
  if (!new_jump_attack->frames[2]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_jump_attack, 2);
    return NULL;
  }
  
  return new_jump_attack;
}

animation *create_ryo_jump_attack_B() {
  animation *new_jump_attack;

  new_jump_attack = create_animation(3);
  if (!new_jump_attack)
    return NULL;
  
  new_jump_attack->frames[0] = al_load_bitmap("Sprites/Ryo Sakazaki/Jump Attack B 1.png");
  if (!new_jump_attack->frames[0]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_jump_attack, 0);
    return NULL;
  }

  new_jump_attack->frames[1] = al_load_bitmap("Sprites/Ryo Sakazaki/Jump Attack B 2.png");
  if (!new_jump_attack->frames[1]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_jump_attack, 1);
    return NULL;
  }

  new_jump_attack->frames[2] = al_load_bitmap("Sprites/Ryo Sakazaki/Jump Attack B 3.png");
  if (!new_jump_attack->frames[2]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_jump_attack, 2);
    return NULL;
  }
  
  return new_jump_attack;
}

animation *create_ryo_crouch_attack_A() {
  animation *new_attack;

  new_attack = create_animation(3);
  if (!new_attack)
    return NULL;
  
  new_attack->frames[0] = al_load_bitmap("Sprites/Ryo Sakazaki/Crouch Attack A 1.png");
  if (!new_attack->frames[0]) {
    printf("Não foi possível carregar foto - crouch attack A Ryo.\n");
    destroy_animation(new_attack, 0);
    return NULL;
  }

  new_attack->frames[1] = al_load_bitmap("Sprites/Ryo Sakazaki/Crouch Attack A 2.png");
  if (!new_attack->frames[1]) {
    printf("Não foi possível carregar foto - crouch attack A Ryo.\n");
    destroy_animation(new_attack, 1);
    return NULL;
  }

  new_attack->frames[2] = al_load_bitmap("Sprites/Ryo Sakazaki/Crouch Attack A 3.png");
  if (!new_attack->frames[2]) {
    printf("Não foi possível carregar foto - crouch attack A Ryo.\n");
    destroy_animation(new_attack, 2);
    return NULL;
  }

  return new_attack;
}

animation *create_ryo_crouch_attack_B() {
  animation *new_attack;

  new_attack = create_animation(3);
  if (!new_attack)
    return NULL;

  new_attack->frames[0] = al_load_bitmap("Sprites/Ryo Sakazaki/Crouch Attack B 1.png");
  if (!new_attack->frames[0]) {
    printf("Não foi possível carregar foto - crouch attack A Ryo.\n");
    destroy_animation(new_attack, 0);
    return NULL;
  }

  new_attack->frames[1] = al_load_bitmap("Sprites/Ryo Sakazaki/Crouch Attack B 2.png");
  if (!new_attack->frames[1]) {
    printf("Não foi possível carregar foto - crouch attack A Ryo.\n");
    destroy_animation(new_attack, 1);
    return NULL;
  }

  new_attack->frames[2] = al_load_bitmap("Sprites/Ryo Sakazaki/Crouch Attack B 3.png");
  if (!new_attack->frames[2]) {
    printf("Não foi possível carregar foto - crouch attack A Ryo.\n");
    destroy_animation(new_attack, 2);
    return NULL;
  }

  return new_attack;   
}

animation *create_ryo_special_attack() {
  animation *new_attack;

  new_attack = create_animation(20);
  if (!new_attack)
    return NULL;

  new_attack->frames[0] = al_load_bitmap("Sprites/Ryo Sakazaki/Special Attack 1.png");
  if (!new_attack->frames[0]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack, 0);
    return NULL;
  }

  new_attack->frames[1] = al_load_bitmap("Sprites/Ryo Sakazaki/Special Attack 2.png");
  if (!new_attack->frames[1]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack, 1);
    return NULL;
  }

  new_attack->frames[2] = al_load_bitmap("Sprites/Ryo Sakazaki/Special Attack 3.png");
  if (!new_attack->frames[2]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack, 2);
    return NULL;
  }
  new_attack->frames[3] = al_load_bitmap("Sprites/Ryo Sakazaki/Special Attack 4.png");
  if (!new_attack->frames[3]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack, 3);
    return NULL;
  }

  new_attack->frames[4] = al_load_bitmap("Sprites/Ryo Sakazaki/Special Attack 5.png");
  if (!new_attack->frames[4]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack, 4);
    return NULL;
  }

  new_attack->frames[5] = al_load_bitmap("Sprites/Ryo Sakazaki/Special Attack 6.png");
  if (!new_attack->frames[5]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack, 5);
    return NULL;
  }

  new_attack->frames[6] = al_load_bitmap("Sprites/Ryo Sakazaki/Special Attack 7.png");
  if (!new_attack->frames[6]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack, 6);
    return NULL;
  }

  new_attack->frames[7] = al_load_bitmap("Sprites/Ryo Sakazaki/Special Attack 8.png");
  if (!new_attack->frames[7]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack, 7);
    return NULL;
  }

  new_attack->frames[8] = al_load_bitmap("Sprites/Ryo Sakazaki/Special Attack 9.png");
  if (!new_attack->frames[8]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack, 8);
    return NULL;
  }

  new_attack->frames[9] = al_load_bitmap("Sprites/Ryo Sakazaki/Special Attack 10.png");
  if (!new_attack->frames[9]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack, 9);
    return NULL;
  }

  new_attack->frames[10] = al_load_bitmap("Sprites/Ryo Sakazaki/Special Attack 11.png");
  if (!new_attack->frames[10]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack, 10);
    return NULL;
  }

  new_attack->frames[11] = al_load_bitmap("Sprites/Ryo Sakazaki/Special Attack 12.png");
  if (!new_attack->frames[11]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack, 11);
    return NULL;
  }

  new_attack->frames[12] = al_load_bitmap("Sprites/Ryo Sakazaki/Special Attack 13.png");
  if (!new_attack->frames[12]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack, 12);
    return NULL;
  }

  new_attack->frames[13] = al_load_bitmap("Sprites/Ryo Sakazaki/Special Attack 14.png");
  if (!new_attack->frames[13]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack, 13);
    return NULL;
  }

  new_attack->frames[14] = al_load_bitmap("Sprites/Ryo Sakazaki/Special Attack 15.png");
  if (!new_attack->frames[14]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack, 14);
    return NULL;
  }

  new_attack->frames[15] = al_load_bitmap("Sprites/Ryo Sakazaki/Special Attack 16.png");
  if (!new_attack->frames[15]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack, 15);
    return NULL;
  }

  new_attack->frames[16] = al_load_bitmap("Sprites/Ryo Sakazaki/Special Attack 17.png");
  if (!new_attack->frames[16]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack, 16);
    return NULL;
  }

  new_attack->frames[17] = al_load_bitmap("Sprites/Ryo Sakazaki/Special Attack 18.png");
  if (!new_attack->frames[17]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack, 17);
    return NULL;
  }

  new_attack->frames[18] = al_load_bitmap("Sprites/Ryo Sakazaki/Special Attack 19.png");
  if (!new_attack->frames[18]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack, 18);
    return NULL;
  }

  new_attack->frames[19] = al_load_bitmap("Sprites/Ryo Sakazaki/Special Attack 20.png");
  if (!new_attack->frames[19]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack, 19);
    return NULL;
  }

  return new_attack;
}

animation *create_ryo_death() {
  animation *new_death;

  new_death = create_animation(6);
  if (!new_death)
    return NULL;
    
  new_death->frames[0] = al_load_bitmap("Sprites/Ryo Sakazaki/Death 1.png");
  if (!new_death->frames[0]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_death, 0);
    return NULL;
  }

  new_death->frames[1] = al_load_bitmap("Sprites/Ryo Sakazaki/Death 2.png");
  if (!new_death->frames[1]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_death, 1);
    return NULL;
  }

  new_death->frames[2] = al_load_bitmap("Sprites/Ryo Sakazaki/Death 3.png");
  if (!new_death->frames[2]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_death, 2);
    return NULL;
  }

  new_death->frames[3] = al_load_bitmap("Sprites/Ryo Sakazaki/Death 4.png");
  if (!new_death->frames[3]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_death, 3);
    return NULL;
  }

  new_death->frames[4] = al_load_bitmap("Sprites/Ryo Sakazaki/Death 5.png");
  if (!new_death->frames[4]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_death, 4);
    return NULL;
  }

  new_death->frames[5] = al_load_bitmap("Sprites/Ryo Sakazaki/Death 6.png");
  if (!new_death->frames[5]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_death, 5);
    return NULL;
  }

  return new_death;
}

/*-------------------------------- TERCEIRO PERSONAGEM: ROBERT GARCIA --------------------------------*/
animation *create_robert_neutral() {
  animation *new_neutral;

  new_neutral = create_animation(6);
  if (!new_neutral)
    return NULL;
  
  new_neutral->frames[0] = al_load_bitmap("Sprites/Robert Garcia/Neutral 1.png");
  if (!new_neutral->frames[0]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_neutral, 0);
    return NULL;
  }

  new_neutral->frames[1] = al_load_bitmap("Sprites/Robert Garcia/Neutral 2.png");
  if (!new_neutral->frames[1]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_neutral, 1);
    return NULL;
  }

  new_neutral->frames[2] = al_load_bitmap("Sprites/Robert Garcia/Neutral 3.png");
  if (!new_neutral->frames[2]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_neutral, 2);
    return NULL;
  }

  new_neutral->frames[3] = al_load_bitmap("Sprites/Robert Garcia/Neutral 4.png");
  if (!new_neutral->frames[3]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_neutral, 3);
    return NULL;
  }

  new_neutral->frames[4] = al_load_bitmap("Sprites/Robert Garcia/Neutral 5.png");
  if (!new_neutral->frames[4]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_neutral, 4);
    return NULL;
  }

  new_neutral->frames[5] = al_load_bitmap("Sprites/Robert Garcia/Neutral 6.png");
  if (!new_neutral->frames[5]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_neutral, 5);
    return NULL;
  }

  return new_neutral;
}

animation *create_robert_walk() {
  animation *new_walk;

  new_walk = create_animation(4);
  if (!new_walk)
    return NULL;
  
  new_walk->frames[0] = al_load_bitmap("Sprites/Robert Garcia/Walk 1.png");
  if (!new_walk->frames[0]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_walk, 0);
    return NULL;
  }

  new_walk->frames[1] = al_load_bitmap("Sprites/Robert Garcia/Walk 2.png");
  if (!new_walk->frames[1]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_walk, 1);
    return NULL;
  }

  new_walk->frames[2] = al_load_bitmap("Sprites/Robert Garcia/Walk 3.png");
  if (!new_walk->frames[2]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_walk, 2);
    return NULL;
  }

  new_walk->frames[3] = al_load_bitmap("Sprites/Robert Garcia/Walk 4.png");
  if (!new_walk->frames[3]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_walk, 3);
    return NULL;
  }

  return new_walk;
}

animation *create_robert_jump() {
  animation *new_jump;

  new_jump = create_animation(6);
  if (!new_jump)
    return NULL;
  
  new_jump->frames[0] = al_load_bitmap("Sprites/Robert Garcia/Jump 1.png");
  if (!new_jump->frames[0]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_jump, 0);
    return NULL;
  }

  new_jump->frames[1] = al_load_bitmap("Sprites/Robert Garcia/Jump 2.png");
  if (!new_jump->frames[1]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_jump, 1);
    return NULL;
  }

  new_jump->frames[2] = al_load_bitmap("Sprites/Robert Garcia/Jump 3.png");
  if (!new_jump->frames[2]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_jump, 2);
    return NULL;
  }

  new_jump->frames[3] = al_load_bitmap("Sprites/Robert Garcia/Jump 4.png");
  if (!new_jump->frames[3]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_jump, 3);
    return NULL;
  }

  new_jump->frames[4] = al_load_bitmap("Sprites/Robert Garcia/Jump 5.png");
  if (!new_jump->frames[4]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_jump, 4);
    return NULL;
  }

  new_jump->frames[5] = al_load_bitmap("Sprites/Robert Garcia/Jump 6.png");
  if (!new_jump->frames[5]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_jump, 5);
    return NULL;
  }

  return new_jump;
}

animation *create_robert_crouch() {
  animation *new_crouch;

  new_crouch = create_animation(1);
  if (!new_crouch)
    return NULL;
  
  new_crouch->frames[0] = al_load_bitmap("Sprites/Robert Garcia/Crouch.png");
  if (!new_crouch->frames[0]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_crouch, 0);
    return NULL;
  }

  return new_crouch;
}

animation *create_robert_attack_A() {
  animation *new_attack_A;

  new_attack_A = create_animation(3);
  if (!new_attack_A)
    return NULL;
  
  new_attack_A->frames[0] = al_load_bitmap("Sprites/Robert Garcia/Attack A 1.png");
  if (!new_attack_A->frames[0]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack_A, 0);
    return NULL;
  }

  new_attack_A->frames[1] = al_load_bitmap("Sprites/Robert Garcia/Attack A 2.png");
  if (!new_attack_A->frames[1]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack_A, 1);
    return NULL;
  }

  new_attack_A->frames[2] = al_load_bitmap("Sprites/Robert Garcia/Attack A 3.png");
  if (!new_attack_A->frames[2]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack_A, 2);
    return NULL;
  }
  
  return new_attack_A;
}

animation *create_robert_attack_B() {
  animation *new_attack_B;

  new_attack_B = create_animation(3);
  if (!new_attack_B)
    return NULL;
  
  new_attack_B->frames[0] = al_load_bitmap("Sprites/Robert Garcia/Attack B 1.png");
  if (!new_attack_B->frames[0]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack_B, 0);
    return NULL;
  }

  new_attack_B->frames[1] = al_load_bitmap("Sprites/Robert Garcia/Attack B 2.png");
  if (!new_attack_B->frames[1]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack_B, 1);
    return NULL;
  }

  new_attack_B->frames[2] = al_load_bitmap("Sprites/Robert Garcia/Attack B 3.png");
  if (!new_attack_B->frames[2]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack_B, 2);
    return NULL;
  }
  
  return new_attack_B;
}

animation *create_robert_jump_attack_A() {
  animation *new_jump_attack;

  new_jump_attack = create_animation(3);
  if (!new_jump_attack)
    return NULL;
  
  new_jump_attack->frames[0] = al_load_bitmap("Sprites/Robert Garcia/Jump Attack A 1.png");
  if (!new_jump_attack->frames[0]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_jump_attack, 0);
    return NULL;
  }

  new_jump_attack->frames[1] = al_load_bitmap("Sprites/Robert Garcia/Jump Attack A 2.png");
  if (!new_jump_attack->frames[1]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_jump_attack, 1);
    return NULL;
  }

  new_jump_attack->frames[2] = al_load_bitmap("Sprites/Robert Garcia/Jump Attack A 3.png");
  if (!new_jump_attack->frames[2]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_jump_attack, 2);
    return NULL;
  }
  
  return new_jump_attack;
}

animation *create_robert_jump_attack_B() {
  animation *new_jump_attack;

  new_jump_attack = create_animation(3);
  if (!new_jump_attack)
    return NULL;
  
  new_jump_attack->frames[0] = al_load_bitmap("Sprites/Robert Garcia/Jump Attack B 1.png");
  if (!new_jump_attack->frames[0]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_jump_attack, 0);
    return NULL;
  }

  new_jump_attack->frames[1] = al_load_bitmap("Sprites/Robert Garcia/Jump Attack B 2.png");
  if (!new_jump_attack->frames[1]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_jump_attack, 1);
    return NULL;
  }

  new_jump_attack->frames[2] = al_load_bitmap("Sprites/Robert Garcia/Jump Attack B 3.png");
  if (!new_jump_attack->frames[2]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_jump_attack, 2);
    return NULL;
  }
  
  return new_jump_attack;
}

animation *create_robert_crouch_attack_A() {
  animation *new_attack;

  new_attack = create_animation(4);
  if (!new_attack)
    return NULL;

  new_attack->frames[0] = al_load_bitmap("Sprites/Robert Garcia/Crouch Attack A 1.png");
  if (!new_attack->frames[0]) {
    printf("Não foi possível carregar foto - crouch attack A robert.\n");
    destroy_animation(new_attack, 0);
    return NULL;
  }

  new_attack->frames[1] = al_load_bitmap("Sprites/Robert Garcia/Crouch Attack A 2.png");
  if (!new_attack->frames[1]) {
    printf("Não foi possível carregar foto - crouch attack A robert.\n");
    destroy_animation(new_attack, 1);
    return NULL;
  }

  new_attack->frames[2] = al_load_bitmap("Sprites/Robert Garcia/Crouch Attack A 3.png");
  if (!new_attack->frames[2]) {
    printf("Não foi possível carregar foto - crouch attack A robert.\n");
    destroy_animation(new_attack, 2);
    return NULL;
  }

  new_attack->frames[3] = al_load_bitmap("Sprites/Robert Garcia/Crouch Attack A 4.png");
  if (!new_attack->frames[3]) {
    printf("Não foi possível carregar foto - crouch attack A robert.\n");
    destroy_animation(new_attack, 3);
    return NULL;
  }

  return new_attack;
}

animation *create_robert_crouch_attack_B() {
  animation *new_attack;

  new_attack = create_animation(5);
  if (!new_attack)
    return NULL;
  
  new_attack->frames[0] = al_load_bitmap("Sprites/Robert Garcia/Crouch Attack B 1.png");
  if (!new_attack->frames[0]) {
    printf("Não foi possível carregar foto - crouch attack B robert.\n");
    destroy_animation(new_attack, 0);
    return NULL;
  }

  new_attack->frames[1] = al_load_bitmap("Sprites/Robert Garcia/Crouch Attack B 2.png");
  if (!new_attack->frames[1]) {
    printf("Não foi possível carregar foto - crouch attack B robert.\n");
    destroy_animation(new_attack, 1);
    return NULL;
  }

  new_attack->frames[2] = al_load_bitmap("Sprites/Robert Garcia/Crouch Attack B 3.png");
  if (!new_attack->frames[2]) {
    printf("Não foi possível carregar foto - crouch attack B robert.\n");
    destroy_animation(new_attack, 2);
    return NULL;
  }

  new_attack->frames[3] = al_load_bitmap("Sprites/Robert Garcia/Crouch Attack B 4.png");
  if (!new_attack->frames[3]) {
    printf("Não foi possível carregar foto - crouch attack B robert.\n");
    destroy_animation(new_attack, 3);
    return NULL;
  }

  new_attack->frames[4] = al_load_bitmap("Sprites/Robert Garcia/Crouch Attack B 5.png");
  if (!new_attack->frames[4]) {
    printf("Não foi possível carregar foto - crouch attack B robert.\n");
    destroy_animation(new_attack, 4);
    return NULL;
  }

  return new_attack;
}

animation *create_robert_special_attack() {
  animation *new_attack;

  new_attack = create_animation(20);
  if (!new_attack)
    return NULL;

  new_attack->frames[0] = al_load_bitmap("Sprites/Robert Garcia/Special Attack 1.png");
  if (!new_attack->frames[0]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack, 0);
    return NULL;
  }

  new_attack->frames[1] = al_load_bitmap("Sprites/Robert Garcia/Special Attack 2.png");
  if (!new_attack->frames[1]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack, 1);
    return NULL;
  }

  new_attack->frames[2] = al_load_bitmap("Sprites/Robert Garcia/Special Attack 3.png");
  if (!new_attack->frames[2]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack, 2);
    return NULL;
  }
  new_attack->frames[3] = al_load_bitmap("Sprites/Robert Garcia/Special Attack 4.png");
  if (!new_attack->frames[3]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack, 3);
    return NULL;
  }

  new_attack->frames[4] = al_load_bitmap("Sprites/Robert Garcia/Special Attack 5.png");
  if (!new_attack->frames[4]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack, 4);
    return NULL;
  }

  new_attack->frames[5] = al_load_bitmap("Sprites/Robert Garcia/Special Attack 6.png");
  if (!new_attack->frames[5]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack, 5);
    return NULL;
  }

  new_attack->frames[6] = al_load_bitmap("Sprites/Robert Garcia/Special Attack 7.png");
  if (!new_attack->frames[6]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack, 6);
    return NULL;
  }

  new_attack->frames[7] = al_load_bitmap("Sprites/Robert Garcia/Special Attack 8.png");
  if (!new_attack->frames[7]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack, 7);
    return NULL;
  }

  new_attack->frames[8] = al_load_bitmap("Sprites/Robert Garcia/Special Attack 9.png");
  if (!new_attack->frames[8]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack, 8);
    return NULL;
  }

  new_attack->frames[9] = al_load_bitmap("Sprites/Robert Garcia/Special Attack 10.png");
  if (!new_attack->frames[9]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack, 9);
    return NULL;
  }

  new_attack->frames[10] = al_load_bitmap("Sprites/Robert Garcia/Special Attack 11.png");
  if (!new_attack->frames[10]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack, 10);
    return NULL;
  }

  new_attack->frames[11] = al_load_bitmap("Sprites/Robert Garcia/Special Attack 12.png");
  if (!new_attack->frames[11]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack, 11);
    return NULL;
  }

  new_attack->frames[12] = al_load_bitmap("Sprites/Robert Garcia/Special Attack 13.png");
  if (!new_attack->frames[12]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack, 12);
    return NULL;
  }

  new_attack->frames[13] = al_load_bitmap("Sprites/Robert Garcia/Special Attack 14.png");
  if (!new_attack->frames[13]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack, 13);
    return NULL;
  }

  new_attack->frames[14] = al_load_bitmap("Sprites/Robert Garcia/Special Attack 15.png");
  if (!new_attack->frames[14]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack, 14);
    return NULL;
  }

  new_attack->frames[15] = al_load_bitmap("Sprites/Robert Garcia/Special Attack 16.png");
  if (!new_attack->frames[15]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack, 15);
    return NULL;
  }

  new_attack->frames[16] = al_load_bitmap("Sprites/Robert Garcia/Special Attack 17.png");
  if (!new_attack->frames[16]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack, 16);
    return NULL;
  }

  new_attack->frames[17] = al_load_bitmap("Sprites/Robert Garcia/Special Attack 18.png");
  if (!new_attack->frames[17]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack, 17);
    return NULL;
  }

  new_attack->frames[18] = al_load_bitmap("Sprites/Robert Garcia/Special Attack 19.png");
  if (!new_attack->frames[18]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack, 18);
    return NULL;
  }

  new_attack->frames[19] = al_load_bitmap("Sprites/Robert Garcia/Special Attack 20.png");
  if (!new_attack->frames[19]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack, 19);
    return NULL;
  }

  return new_attack;
}

animation *create_robert_death() {
  animation *new_death;

  new_death = create_animation(5);
  if (!new_death)
    return NULL;
    
  new_death->frames[0] = al_load_bitmap("Sprites/Robert Garcia/Death 1.png");
  if (!new_death->frames[0]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_death, 0);
    return NULL;
  }

  new_death->frames[1] = al_load_bitmap("Sprites/Robert Garcia/Death 2.png");
  if (!new_death->frames[1]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_death, 1);
    return NULL;
  }

  new_death->frames[2] = al_load_bitmap("Sprites/Robert Garcia/Death 3.png");
  if (!new_death->frames[2]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_death, 2);
    return NULL;
  }

  new_death->frames[3] = al_load_bitmap("Sprites/Robert Garcia/Death 4.png");
  if (!new_death->frames[3]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_death, 3);
    return NULL;
  }

  new_death->frames[4] = al_load_bitmap("Sprites/Robert Garcia/Death 5.png");
  if (!new_death->frames[4]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_death, 4);
    return NULL;
  }

  return new_death;
}

/*-------------------------------- QUARTO PERSONAGEM: JACK TURNER --------------------------------*/
animation *create_jack_neutral() {
  animation *new_neutral;

  new_neutral = create_animation(4);
  if (!new_neutral)
    return NULL;
  
  new_neutral->frames[0] = al_load_bitmap("Sprites/Jack Turner/Neutral 1.png");
  if (!new_neutral->frames[0]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_neutral, 0);
    return NULL;
  }

  new_neutral->frames[1] = al_load_bitmap("Sprites/Jack Turner/Neutral 2.png");
  if (!new_neutral->frames[1]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_neutral, 1);
    return NULL;
  }

  new_neutral->frames[2] = al_load_bitmap("Sprites/Jack Turner/Neutral 3.png");
  if (!new_neutral->frames[2]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_neutral, 2);
    return NULL;
  }

  new_neutral->frames[3] = al_load_bitmap("Sprites/Jack Turner/Neutral 4.png");
  if (!new_neutral->frames[3]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_neutral, 3);
    return NULL;
  }

  return new_neutral;
}

animation *create_jack_walk() {
  animation *new_walk;

  new_walk = create_animation(6);
  if (!new_walk)
    return NULL;
  
  new_walk->frames[0] = al_load_bitmap("Sprites/Jack Turner/Walk 1.png");
  if (!new_walk->frames[0]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_walk, 0);
    return NULL;
  }

  new_walk->frames[1] = al_load_bitmap("Sprites/Jack Turner/Walk 2.png");
  if (!new_walk->frames[1]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_walk, 1);
    return NULL;
  }

  new_walk->frames[2] = al_load_bitmap("Sprites/Jack Turner/Walk 3.png");
  if (!new_walk->frames[2]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_walk, 2);
    return NULL;
  }

  new_walk->frames[3] = al_load_bitmap("Sprites/Jack Turner/Walk 4.png");
  if (!new_walk->frames[3]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_walk, 3);
    return NULL;
  }

  new_walk->frames[4] = al_load_bitmap("Sprites/Jack Turner/Walk 5.png");
  if (!new_walk->frames[4]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_walk, 4);
    return NULL;
  }

  new_walk->frames[5] = al_load_bitmap("Sprites/Jack Turner/Walk 6.png");
  if (!new_walk->frames[5]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_walk, 5);
    return NULL;
  }

  return new_walk;
}

animation *create_jack_jump() {
  animation *new_jump;

  new_jump = create_animation(4);
  if (!new_jump)
    return NULL;
  
  new_jump->frames[0] = al_load_bitmap("Sprites/Jack Turner/Jump 1.png");
  if (!new_jump->frames[0]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_jump, 0);
    return NULL;
  }

  new_jump->frames[1] = al_load_bitmap("Sprites/Jack Turner/Jump 2.png");
  if (!new_jump->frames[1]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_jump, 1);
    return NULL;
  }

  new_jump->frames[2] = al_load_bitmap("Sprites/Jack Turner/Jump 3.png");
  if (!new_jump->frames[2]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_jump, 1);
    return NULL;
  }

  new_jump->frames[3] = al_load_bitmap("Sprites/Jack Turner/Jump 4.png");
  if (!new_jump->frames[3]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_jump, 1);
    return NULL;
  }

  return new_jump;
}

animation *create_jack_crouch() {
  animation *new_crouch;

  new_crouch = create_animation(1);
  if (!new_crouch)
    return NULL;
  
  new_crouch->frames[0] = al_load_bitmap("Sprites/Jack Turner/Crouch.png");
  if (!new_crouch->frames[0]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_crouch, 0);
    return NULL;
  }

  return new_crouch;
}

animation *create_jack_attack_A() {
  animation *new_attack_A;

  new_attack_A = create_animation(5);
  if (!new_attack_A)
    return NULL;
  
  new_attack_A->frames[0] = al_load_bitmap("Sprites/Jack Turner/Attack A 1.png");
  if (!new_attack_A->frames[0]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack_A, 0);
    return NULL;
  }

  new_attack_A->frames[1] = al_load_bitmap("Sprites/Jack Turner/Attack A 2.png");
  if (!new_attack_A->frames[1]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack_A, 1);
    return NULL;
  }

  new_attack_A->frames[2] = al_load_bitmap("Sprites/Jack Turner/Attack A 3.png");
  if (!new_attack_A->frames[2]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack_A, 2);
    return NULL;
  }

  new_attack_A->frames[3] = al_load_bitmap("Sprites/Jack Turner/Attack A 4.png");
  if (!new_attack_A->frames[3]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack_A, 3);
    return NULL;
  }

  new_attack_A->frames[4] = al_load_bitmap("Sprites/Jack Turner/Attack A 5.png");
  if (!new_attack_A->frames[4]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack_A, 4);
    return NULL;
  }

  return new_attack_A;
}

animation *create_jack_attack_B() {
  animation *new_attack_B;

  new_attack_B = create_animation(4);
  if (!new_attack_B)
    return NULL;
  
  new_attack_B->frames[0] = al_load_bitmap("Sprites/Jack Turner/Attack B 1.png");
  if (!new_attack_B->frames[0]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack_B, 0);
    return NULL;
  }

  new_attack_B->frames[1] = al_load_bitmap("Sprites/Jack Turner/Attack B 2.png");
  if (!new_attack_B->frames[1]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack_B, 1);
    return NULL;
  }

  new_attack_B->frames[2] = al_load_bitmap("Sprites/Jack Turner/Attack B 3.png");
  if (!new_attack_B->frames[2]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack_B, 2);
    return NULL;
  }

  new_attack_B->frames[3] = al_load_bitmap("Sprites/Jack Turner/Attack B 4.png");
  if (!new_attack_B->frames[3]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_attack_B, 3);
    return NULL;
  }

  return new_attack_B;
}

animation *create_jack_jump_attack_A() {
  animation *new_jump_attack;

  new_jump_attack = create_animation(3);
  if (!new_jump_attack)
    return NULL;
  
  new_jump_attack->frames[0] = al_load_bitmap("Sprites/Jack Turner/Jump Attack 1.png");
  if (!new_jump_attack->frames[0]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_jump_attack, 0);
    return NULL;
  }

  new_jump_attack->frames[1] = al_load_bitmap("Sprites/Jack Turner/Jump Attack 2.png");
  if (!new_jump_attack->frames[1]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_jump_attack, 1);
    return NULL;
  }

  new_jump_attack->frames[2] = al_load_bitmap("Sprites/Jack Turner/Jump Attack 3.png");
  if (!new_jump_attack->frames[2]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_jump_attack, 2);
    return NULL;
  }

  return new_jump_attack;
}

animation *create_jack_death() {
  animation *new_death;

  new_death = create_animation(4);
  if (!new_death)
    return NULL;
    
  new_death->frames[0] = al_load_bitmap("Sprites/Jack Turner/Death 1.png");
  if (!new_death->frames[0]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_death, 0);
    return NULL;
  }

  new_death->frames[1] = al_load_bitmap("Sprites/Jack Turner/Death 2.png");
  if (!new_death->frames[1]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_death, 1);
    return NULL;
  }

  new_death->frames[2] = al_load_bitmap("Sprites/Jack Turner/Death 3.png");
  if (!new_death->frames[2]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_death, 2);
    return NULL;
  }

  new_death->frames[3] = al_load_bitmap("Sprites/Jack Turner/Death 4.png");
  if (!new_death->frames[3]) {
    printf("Não foi possível carregar foto.\n");
    destroy_animation(new_death, 3);
    return NULL;
  }

  return new_death;
}