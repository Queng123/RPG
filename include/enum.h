/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** enum
*/

#ifndef ENUM_H_
    #define ENUM_H_

/******************************enum*******************************************/
//!game
enum game_scene {PAUSE, INTRO, INVENTORY, GAMEPLAY, BOSS};

typedef enum game_scene enum_game_scene;
//!menu
enum menu_scene {OPTIONS, LOAD_SAVE, HELP, MAIN_MENU};

enum options_scene {HOW_TO_PLAY, CONTROLS, VIDEO, AUDIO};

typedef enum options_scene enum_options_scene;

enum how_to_play_scene {HISTORY, HOW2PLAY, TIPS, LOBBY};

typedef enum options_scene enum_options_scene;

enum size {FULL_SCREEN, BIG_SCREEN, MEDIUM_SCREEN, SMALL_SCREEN};

typedef enum menu_scene enum_menu_scene;

typedef enum how_to_play_scene enum_how_to_play_scene;

enum tablet {PLAYER_INFO, SKILL_TREE, MAP, QUEST};

typedef enum tablet enum_tablet;

//!others
enum scene {MENU, NEW_GAME, LOAD_GAME, GAME};

enum save {SAVE_1, SAVE_2, SAVE_3};

typedef enum scene enum_scene;

typedef enum save enum_save;
//!gameplay

typedef enum enum_item_e {BAT, AK47, BANDAGES,
BREAD, CHOCO, CARROT, KEY, LETTER, MONEY, AMMO,
SERRINGUE, HAND, BOOT, HAT, NONE} enum_item_t;

#endif/* !ENUM_H_ */
