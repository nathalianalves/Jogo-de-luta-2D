#include "animation.h"

animation *create_animation(int num_frames) {
  animation *new_animation;

  new_animation = (animation*) malloc(sizeof(animation));
  if (!new_animation)
    return NULL;
  
  new_animation->num_frames = num_frames;
  new_animation->frames = (ALLEGRO_BITMAP**) malloc(sizeof(ALLEGRO_BITMAP*) * new_animation->num_frames);
  if (!new_animation->frames) {
    free(new_animation);
    return NULL;
  }

  new_animation->current_frame = 0;

  return new_animation;
}

void destroy_animation(animation *element, int num_valid) {
  if (num_valid > element->num_frames)
    return;

  for (int i = 0; i < num_valid; i++)
    al_destroy_bitmap(element->frames[i]);
  
  free(element->frames);
  free(element);
}