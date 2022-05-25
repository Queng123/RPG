##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## root Makefile
##

CC			=	gcc

NAME		=	my_rpg

SRC_GAME	=	src/game/game.c					 							\
				src/game/gameplay/gameplay.c 								\
				src/game/inventory/inventory.c 								\
				src/game/pause/pause.c 										\
				src/game/gameplay/build/build_struct.c 						\
				src/game/gameplay/build/build_bullet.c 						\
				src/game/gameplay/build/build_player.c 						\
				src/game/gameplay/build/build_obj_function.c				\
				src/game/gameplay/build/build_bar.c 						\
				src/game/gameplay/build/build_inventory.c					\
				src/game/gameplay/build/build_tab_sprite_p_tab_nine_fivety.c \
				src/game/gameplay/build/build_tab_sprite_p_tab_zero_nine.c 	\
				src/game/gameplay/build/build_chest.c						\
				src/game/gameplay/build/build_quest.c						\
				src/game/gameplay/player.c 									\
				src/game/gameplay/physics/friction.c						\
				src/game/gameplay/physics/find_collisions.c 				\
				src/game/gameplay/physics/get_hitbox_size.c 				\
				src/game/gameplay/physics/replace_obj_for_x_or_y.c 			\
				src/game/gameplay/physics/specific_collisions.c 			\
				src/game/gameplay/destroy/destroy_all.c 					\
				src/game/gameplay/destroy/destroy_sprite.c 					\
				src/game/gameplay/destroy/handle_end_musique.c				\
				src/game/gameplay/event/analyse_event.c 					\
				src/game/gameplay/event/analyse_event_functions.c			\
				src/game/gameplay/build/build_all_obj.c 					\
				src/game/gameplay/destroy/destroy_tab_entitie.c 			\
				src/game/gameplay/clock/create_clock.c 						\
				src/game/gameplay/clock/manage_clock_obj.c 					\
				src/game/gameplay/display_sprite.c 							\
				src/game/gameplay/player/sprite_player.c 					\
				src/game/gameplay/player/display_player.c 					\
				src/game/gameplay/player/move_player.c 						\
				src/game/gameplay/player/player_attack.c 					\
				src/game/gameplay/player/player_sprite_movement.c			\
				src/game/gameplay/player/check_is_obj_click.c 				\
				src/game/gameplay/player/player_shooting.c					\
				src/game/gameplay/player/player_heal.c						\
				src/game/gameplay/player/player_sleep.c						\
				src/game/gameplay/player/player_attack_function.c			\
				src/game/gameplay/player/player_death.c						\
				src/game/gameplay/player/drop_current_item.c				\
				src/game/gameplay/player/player_run.c						\
				src/game/gameplay/zombies/spawn_zombies.c 					\
				src/game/gameplay/zombies/move_zombies.c 					\
				src/game/gameplay/zombies/zombie_collision.c 				\
				src/game/gameplay/zombies/get_obj_dead.c 					\
				src/game/gameplay/zombies/dead_zombie.c 					\
				src/game/gameplay/zombies/zombies_attack.c 					\
				src/game/gameplay/zombies/display_zombies.c					\
				src/game/gameplay/zombies/spawn_zombies_function.c			\
				src/game/gameplay/display/display_sprite_distance.c 		\
				src/game/gameplay/health/display_health.c 					\
				src/game/gameplay/build/build_map.c							\
				src/game/gameplay/map/display_map.c							\
				src/game/gameplay/map/display_map_p.c						\
				src/game/inventory/display_inside.c							\
				src/game/inventory/current_item.c							\
				src/game/inventory/inventory_interaction.c					\
				src/game/inventory/inventory_rules.c						\
				src/game/inventory/inventory_transactions.c     			\
				src/game/inventory/switch_items.c							\
				src/game/pause/init_pause.c									\
				src/game/gameplay/manage_date.c								\
				src/game/gameplay/tablet/build_tablet.c						\
				src/game/gameplay/tablet/display_tablet.c					\
				src/game/gameplay/chest/set_chest_map.c						\
				src/game/gameplay/chest/chest_menu.c						\
				src/game/gameplay/chest/chest_interaction.c					\
				src/game/gameplay/quest/display_npc.c						\
				src/game/gameplay/quest/npc_interaction.c					\
				src/game/gameplay/quest/display_sell_menu.c					\
				src/game/gameplay/quest/buy_actions.c						\
				src/game/gameplay/quest/sell_actions.c						\
				src/game/gameplay/quest/lauch_qte.c							\
				src/game/gameplay/quest/experience_functions.c				\
				src/game/gameplay/tablet/manage_tablet_event.c				\
				src/game/gameplay/tablet/choose_tablet_screen.c				\
				src/game/boss/build_boss/build_ring.c 						\
				src/game/boss/build_boss/build_boss.c 						\
				src/game/boss/display_boss.c 								\
				src/game/boss/init_boss.c 									\
				src/game/boss/analyse_event_boss.c 							\
				src/game/boss/build_boss/build_tab_letter_key.c 			\
				src/game/boss/build_boss/build_versus.c 					\
				src/game/boss/handling_frame_boss.c 						\
				src/game/boss/frame_boss/frame_zero.c 						\
				src/game/boss/build_boss/build_button_confirm.c 			\
				src/game/boss/frame_boss/frame_one.c 						\
				src/game/boss/build_boss/build_howtoplay_boss.c 			\
				src/game/boss/frame_boss/frame_two.c 						\
				src/game/boss/build_boss/build_ouch.c 						\
				src/game/boss/build_boss/build_paf.c 						\
				src/game/boss/build_boss/build_heart_player.c 				\
				src/game/boss/display_animation/display_paf.c 				\
				src/game/boss/display_animation/display_ouch.c 				\
				src/game/boss/display_animation/display_systeme_qte.c		\
				src/game/boss/restart_clock_boss.c 							\
				src/game/boss/display_animation/display_key_rand.c 			\
				src/game/boss/display_animation/display_pop_art.c 			\
				src/game/boss/systeme_fight.c 								\
				src/game/boss/build_boss/build_heart_boss.c 				\
				src/game/boss/display_animation/display_heart_player.c 		\
				src/game/boss/display_animation/display_heart_boss.c 		\
				src/game/boss/frame_boss/frame_three.c 						\
				src/game/boss/build_boss/build_button_next_boss.c 			\
				src/game/boss/build_boss/build_msg_boss_zero.c 				\
				src/game/boss/build_boss/build_msg_boss_one.c 				\
				src/game/boss/frame_boss/frame_fourr.c 						\
				src/game/boss/build_boss/build_msg_boss_two.c 				\
				src/game/boss/frame_boss/frame_five.c 						\
				src/game/boss/build_boss/build_skelleton.c 					\
				src/game/boss/build_boss/build_os.c 						\
				src/game/gameplay/tablet/display_mini_map.c					\
				src/game/gameplay/sound/update_sound.c						\
				src/game/gameplay/sound/play_song.c							\
				src/game/gameplay/build/build_audio.c             			\
				src/game/gameplay/tablet/change_quest_tablet.c				\
				src/game/gameplay/quest/display_dialog.c					\
				src/game/gameplay/tablet/manage_skill_tree.c				\
				src/game/gameplay/tablet/build_tablet_text.c				\
				src/game/stamina/stamina.c                           		\
				src/game/gameplay/tablet/display_player_info_text.c			\
				src/game/gameplay/display_game_bar/display_game_bar.c		\
				src/game/gameplay/display_game_bar/init_game_bar.c			\
				src/game/gameplay/tablet/display_player_intellect.c			\
				src/game/gameplay/map/display_tree.c						\
				src/game/gameplay/tablet/build_tablet_function.c

SRC_GENERIC_FONCTIONS	=	src/generic_fonctions/generic_fonctions.c		\
src/generic_fonctions/free_game.c 											\
src/generic_fonctions/init_game.c 											\
src/generic_fonctions/analyse_event.c										\
src/generic_fonctions/button_is_clicked.c									\
src/generic_fonctions/display_button.c										\
src/generic_fonctions/text_is_clicked.c										\
src/generic_fonctions/generator_pixels/create_pixel_s.c 					\
src/generic_fonctions/generator_pixels/draw_pixel.c 						\
src/generic_fonctions/generator_pixels/my_put_pixel.c 						\
src/generic_fonctions/generator_pixels/selected_color_pixel.c 				\
src/generic_fonctions/generator_pixels/draw_square.c 						\
src/generic_fonctions/particle_generator_2.0/build_struct_pixel_info.c 		\
src/generic_fonctions/particle_generator_2.0/clear_frame_buffer.c 			\
src/generic_fonctions/particle_generator_2.0/fill_generator_struct.c 		\
src/generic_fonctions/particle_generator_2.0/use_generator.c	 			\
src/generic_fonctions/particle_generator_2.0/make_animation.c	 			\
src/generic_fonctions/error_handling.c

SRC_NEW_GAME	=	src/new_game/new_game.c 								\
					src/new_game/analyse_event_new_game.c					\
					src/new_game/init_new_game.c							\
					src/new_game/active_default_value_new_game.c			\
					src/new_game/create_sporty.c							\
					src/new_game/create_soldier.c							\
					src/new_game/create_cop.c								\
					src/new_game/create_researcher.c						\
					src/new_game/create_class.c								\
					src/new_game/create_cat.c								\
					src/new_game/create_all_character.c						\
					src/new_game/move_animation_cat.c						\
					src/new_game/check_hitbox_tablet_button.c				\
					src/new_game/check_hitbox_confirm_button.c				\
					src/new_game/check_hitbox_choose_class.c				\
					src/new_game/restore_default_rotation_character.c		\
					src/new_game/check_hitbox_turn_character.c				\
					src/new_game/check_hitbox_character_color.c				\
					src/new_game/check_hitbox_reset_character.c				\
					src/new_game/move_animation_reseau_charger.c			\
					src/new_game/send_stat_character.c						\
					src/new_game/clean_all_character.c						\
					src/new_game/init_stat_character.c

SRC_LOAD_GAME 	=	src/load_game/load_game.c 								\
					src/load_game/active_default_value_load_game.c 			\
					src/load_game/analyse_event_load_game.c 				\
					src/load_game/init_load_game.c							\
					src/load_game/save_game.c								\
					src/load_game/create_save_empty_full.c					\
					src/load_game/create_support_save.c						\
					src/load_game/create_delete_save.c						\
					src/load_game/my_arraylen.c								\
					src/load_game/init_value_load_game.c					\
					src/load_game/write_data.c								\
					src/load_game/write_str_and_int.c						\
					src/load_game/check_save_file.c							\
					src/load_game/save_data_in_file.c						\
					src/load_game/read_file.c								\
					src/load_game/delete_data_file.c						\
					src/load_game/display_save_one.c 						\
					src/load_game/display_save_two.c 						\
					src/load_game/display_save_three.c						\
					src/load_game/check_hitbox_delete_save.c 				\
					src/load_game/check_hitbox_return_menu_button.c 		\
					src/load_game/check_hitbox_save_one.c 					\
					src/load_game/check_hitbox_save_two.c 					\
					src/load_game/check_hitbox_save_three.c 				\
					src/load_game/launch_save.c								\
					src/load_game/restart_default_value_game.c				\
					src/load_game/create_save_charact.c 					\
					src/load_game/create_name_charact.c						\
					src/load_game/create_date_survivor.c


SRC_INTRO		=	src/game/game_intro/init_intro.c 						\
					src/game/game_intro/game_intro.c 						\
					src/game/game_intro/check_if_click_true.c 				\
					src/game/game_intro/frame_intro/handling_frame.c 		\
					src/game/game_intro/frame_intro/draw_frame_one.c 		\
					src/game/game_intro/frame_intro/draw_frame_zero.c 		\
					src/game/game_intro/frame_intro/start_frame_one.c 		\
		src/game/game_intro/frame_intro/check_condition_frame_one_actif.c 	\
					src/game/game_intro/frame_intro/draw_frame_two.c 		\
					src/game/game_intro/frame_intro/draw_frame_three.c 		\
					src/game/game_intro/frame_intro/draw_frame_four.c 		\
					src/game/game_intro/frame_intro/draw_frame_five.c 		\
					src/game/game_intro/frame_intro/draw_frame_six.c 		\
					src/game/game_intro/frame_intro/draw_frame_seven.c 		\
					src/game/game_intro/frame_intro/draw_frame_eight.c 		\
					src/game/game_intro/build_intro/build_search_job.c 		\
					src/game/game_intro/build_intro/build_save_sister.c 	\
					src/game/game_intro/build_intro/build_post_world.c 		\
					src/game/game_intro/build_intro/build_play_game.c 		\
					src/game/game_intro/build_intro/build_last_mission.c 	\
					src/game/game_intro/build_intro/build_last_mission_player.c\
					src/game/game_intro/build_intro/build_invasion_zombie.c \
					src/game/game_intro/build_intro/build_intro.c 			\
					src/game/game_intro/build_intro/build_frame_one.c 		\
					src/game/game_intro/build_intro/build_clap_board.c 		\
					src/game/game_intro/build_intro/build_button_skip.c 	\
					src/game/game_intro/build_intro/build_bubulle_leg_two.c \
					src/game/game_intro/build_intro/build_bubulle_leg_three.c \
					src/game/game_intro/build_intro/build_bubulle_leg_one.c \
					src/game/game_intro/build_intro/build_bubulle_leg_four.c\
					src/game/game_intro/build_intro/build_bubulle_leg_five.c \
					src/game/game_intro/build_intro/build_bubulle_leg_six.c \
					src/game/game_intro/build_intro/build_boss_zombie.c 	\
					src/game/game_intro/build_intro/build_arrow_right.c 	\
					src/game/game_intro/build_intro/build_button_next.c 	\
					src/game/game_intro/build_intro/build_bar_info.c

SRC_MENU	=	src/menu/options/how2play/history/history.c 				\
				src/menu/options/how2play/how_to_play/display_howtoplay.c 	\
				src/menu/options/how2play/tips/display_tips.c 				\
				src/menu/options/how2play/lobby/display_lobby.c 			\
				src/menu/options/how2play/how2play.c 						\
				src/menu/load_save/load_save.c 								\
				src/menu/main_menu/main_menu.c 								\
				src/menu/options/options.c 									\
				src/menu/menu.c				 								\
				src/menu/init_menu.c				 						\
				src/menu/analyse_event_menu.c								\
				src/menu/options/init_options.c								\
				src/menu/options/analyse_options_event.c					\
				src/menu/options/audio_settings/audio_settings.c			\
				src/menu/options/video_settings/video_settings.c			\
				src/menu/options/controls/controls.c						\
				src/menu/options/init_settings_bg.c 						\
				src/menu/options/audio_settings/init_audio.c 				\
				src/menu/options/audio_settings/manage_audio.c 				\
				src/menu/options/video_settings/init_video.c 				\
				src/menu/options/init_colored_button.c		 				\
				src/menu/build_sprite.c						 				\
				src/menu/display_bg.c						 				\
				src/menu/build_text.c						 				\
				src/menu/options/video_settings/video_event.c				\
				src/menu/options/video_settings/init_size.c					\
				src/menu/options/video_settings/manage_size_settings.c		\
				src/menu/options/controls/init_controls.c					\
				src/menu/options/controls/analyse_event_controls.c 			\
				src/menu/options/video_settings/change_window_size.c 		\
				src/menu/options/how2play/init_howtwoplay.c 				\
				src/menu/options/how2play/build/build_all_howplay.c 		\
				src/menu/options/how2play/build/build_st_one.c 				\
				src/menu/options/how2play/build/build_st_two.c 				\
				src/menu/options/how2play/build/build_st_three.c			\
				src/menu/options/how2play/build/build_st_four.c 			\
				src/menu/options/how2play/build/build_st_five.c 			\
				src/menu/options/how2play/build/build_st_six.c 				\
				src/menu/options/manage_menu_movement.c						\
				src/menu/manage_menu_mouse_click.c

TEST_FONC	=

MAIN		=	src/main.c

OBJ_MAIN	=	$(MAIN:%.c=%.o)

OBJ_SRC		+=	$(SRC_GAME:%.c=%.o)
OBJ_SRC		+=	$(SRC_GENERIC_FONCTIONS:%.c=%.o)
OBJ_SRC		+=	$(SRC_NEW_GAME:%.c=%.o)
OBJ_SRC		+=	$(SRC_MENU:%.c=%.o)
OBJ_SRC		+=  $(SRC_GAME_PLAY:%.c=%.o)
OBJ_SRC 	+=  $(SRC_INTRO:%.c=%.o)
OBJ_SRC 	+=  $(SRC_LOAD_GAME:%.c=%.o)

OBJ_TEST	+=	$(OBJ_SRC)
OBJ_TEST	+=	$(TEST_FONC:.c=.o)

CFLAGS		=	-Wall -Wextra -I./include/

FLAGS		=	-lcsfml-audio -lcsfml-graphics -lm -lcsfml-system -lcsfml-window

TESTS_FLAGS	=	--coverage -lcriterion -I./include

LIB_FLAGS	=	-L./lib/ -lmy

TEST_BINARY	=	unit_tests

all	:	make_lib $(NAME)

make_lib:
	make -C lib/my

$(NAME):	$(OBJ_SRC) $(OBJ_MAIN)
			cp -r ./lib/my/include/. ./include/.
			$(CC) $(OBJ_SRC) $(OBJ_MAIN) $(LIB_FLAGS) $(FLAGS) -o $(NAME)

tests_run:
		make re
		gcc -o $(TEST_BINARY) $(SRC) $(TEST_FONC) $(LIB_FLAGS) $(TESTS_FLAGS) \
		$(FLAGS)
		./$(TEST_BINARY)
		gcovr --exclude tests --branches
		gcovr --exclude tests
		@sleep 3
		tests/test_assets.sh

clean	:
			rm -f $(OBJ_MAIN)
			rm -f $(OBJ_SRC)
			rm -f $(OBJ_TEST)
			make -C lib/my/ clean

cclean	:
	rm $(NAME)

fclean	:	clean
			rm -f $(NAME)
			rm -f $(TEST_BINARY)
			rm -f ./include/my.h
			rm -f vgcore.*
			rm -f ./lib/libmy.a
			rm -f *.gc*
			make -C lib/my/ fclean

re	: fclean all

full	:
	make full -C lib/my

.PHONY	:	all tests fclean

debug: CFLAGS += -g
debug: re
