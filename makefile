ALLEGRO_FLAGS = $(shell pkg-config allegro-5 allegro_main-5 allegro_image-5 allegro_primitives-5 allegro_font-5 allegro_ttf-5 --libs --cflags)
parametrosCompilacao = -Wall
nomePrograma = A4

all: $(nomePrograma)

$(nomePrograma): main.o animation.o character_animations.o joystick.o player.o game.o character_selection.o menu.o
	gcc -o $(nomePrograma) main.o animation.o character_animations.o joystick.o player.o game.o character_selection.o menu.o $(parametrosCompilacao) $(ALLEGRO_FLAGS)

main.o: main.c
	gcc -c main.c $(parametrosCompilacao) $(ALLEGRO_FLAGS)

animation.o: animation.c
	gcc -c animation.c $(parametrosCompilacao) $(ALLEGRO_FLAGS)

character_animations.o: character_animations.c
	gcc -c character_animations.c $(parametrosCompilacao) $(ALLEGRO_FLAGS)

joystick.o: joystick.c
	gcc -c joystick.c $(parametrosCompilacao)

player.o: player.c
	gcc -c player.c $(parametrosCompilacao) $(ALLEGRO_FLAGS)
	
game.o : game.c
	gcc -c game.c $(parametrosCompilacao) $(ALLEGRO_FLAGS)

character_selection.o: character_selection.c
	gcc -c character_selection.c $(parametrosCompilacao) $(ALLEGRO_FLAGS)

menu.o: menu.c
	gcc -c menu.c $(parametrosCompilacao)

clean:
	rm -f *.o *.gch

purge:
	make clean
	rm -f $(nomePrograma)
