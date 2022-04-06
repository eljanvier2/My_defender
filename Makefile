##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## task 01
##

SRC_MAIN =	./src/main_file.c

SRC	=	./src/start.c	\
		./src/checks_folder/various_init_checks.c	\
		./src/checks_folder/filepath_ops.c			\
		./src/checks_folder/tile_type.c				\
		./src/ennemy_actions/ennemy_moves.c			\
		./src/ennemy_actions/moves_selector_utils.c	\
		./src/ennemy_actions/ennemy_health_check.c	\
		./src/ennemy_actions/ennemy_animation.c	\
		./src/ennemy_actions/base_attack.c	\
		./src/event_ops/analyse_events.c	\
		./src/init_folder/menu_init.c	\
		./src/init_folder/scenes_init.c	\
		./src/init_folder/utils_init.c	\
		./src/init_folder/sounds_init.c	\
		./src/init_folder/tower_init.c	\
		./src/init_folder/wallet_struct_init.c	\
		./src/map_creation/map_loader.c	\
		./src/map_creation/tile_gen.c	\
		./src/menu/fade.c	\
		./src/menu/menu_background.c	\
		./src/menu/parallax_handling.c	\
		./src/game_menu/game_menu.c	\
		./src/game_menu/analyse_game_menu.c	\
		./src/game_menu/hover_utils.c	\
		./src/game_menu/menu_showhide.c	\
		./src/game_menu/pause.c	\
		./src/game_menu/end_screen.c	\
		./src/utils/my_putstr.c	\
		./src/utils/object_creators.c	\
		./src/utils/parallax_obj_create.c	\
		./src/utils/my_strcmp.c	\
		./src/utils/menu_draw.c	\
		./src/utils/draw_ennemies.c	\
		./src/utils/draws.c	\
		./src/utils/my_revstr.c	\
		./src/utils/my_strlen.c	\
		./src/window_ops.c	\
		./src/run.c	\
		./src/free_folder/tiles_freer.c	\
		./src/init_folder/ennemy_init.c	\
		./src/free_folder/utils_freer.c	\
		./src/free_folder/sound_freer.c	\

NAME 	=	my_defender

CPPFLAGS =	-I./include
CPPFLAGS += -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window
CFLAGS =	-W -Wall -Wextra

LDFLAGS =

TESTS_FLAGS = --coverage -lcriterion
TESTS_FLAGS += -I./include

#TESTS_SRC =

OBJ	=	$(SRC:.c=.o)
OBJ_GCDA =	$(SRC:.c=.gcda)
OBJ_GCNO =	$(SRC:.c=.gcno)
OBJ_MAIN =	$(SRC_MAIN:.c=.o)
OBJ_TEST = 	$(TESTS_SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ) $(OBJ_MAIN)
	gcc -o $(NAME) $(OBJ) $(OBJ_MAIN) $(CPPFLAGS) $(CFLAGS)

debug:	CFLAGS += -g
debug:	fclean $(NAME)

clean:
	rm -rf $(OBJ) $(OBJ_MAIN) $(OBJ_TEST) $(OBJ_GCDA) $(OBJ_GCNO)
	rm -rf unit*
	rm -rf vgcore*
	rm -rf .cache
	rm -rf tests/*.gcno
	rm -rf tests/*.gcda

fclean: clean
	rm -rf $(NAME)

re:	fclean all

tests_run: CFLAGS += -fprofile-arcs -ftest-coverage
tests_run: LDFLAGS += -lcriterion -lgcov
tests_run:	fclean $(OBJ) $(OBJ_TEST)
	rm -rf unit*
	echo $(OBJ_TEST)
	gcc -o unit_tests $(OBJ) $(OBJ_TEST) $(LDFLAGS) $(CFLAGS) -g
	./unit_tests
	gcovr

cover:
	mkdir -p crit_result
	gcovr --exclude tests/ --html --html-details -o crit_result/cov.html
	gcovr --branches --exclude tests/

auteur:
	echo $(USER) > auteur

.PHONY:	all clean fclean re auteur debug tests_run cover
