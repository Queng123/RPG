/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

/******************************include*****************************************/

//!csfml
    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <SFML/Network.h>
    #include <stdbool.h>

//!project
    #include "enum.h"
    #include "useful_structs.h"
    #include "info.h"
    #include "particles.h"

/*****************************CONST GLOBALS***********************************/

    extern const int NB_ENT;

    extern const float COEF_FRI;

    extern const int START_BUILDING;

/******************************structurs***************************************/

//!menu
typedef struct menu_s {
    button_t *buttons[45];
    sprite_t *background[12];
    music_t *menu_music;
    sound_t *soudn[2];
    clockk_t *options_clock;
    clockk_t *fps_clock;
    int show_fps;
    int show_size;
} menu_t;

//!new game

typedef struct character_s {
    sfSprite *spr;
    sfTexture *text;
    sfVector2f pos;
    sfIntRect rect;
} character_t;

typedef struct class_menu_s {
    sfSprite *spr;
    sfTexture *text;
    sfVector2f pos;
} class_menu_t;

typedef struct cat_s {
    sfSprite *spr;
    sfTexture *text;
    sfVector2f pos;
    sfIntRect rect;
    sfClock *clock;
    sfTime time;
    int total_time;
} cat_t;

typedef struct cursor_s {
    int x;
    int y;
} cursor_t;

typedef struct stat_charac_s {
    int speed;
    int stamina;
    int strenght;
    int intellect;
    int shoot;
} stat_charac_t;

typedef struct new_game_s {
    cursor_t cursor;
    cat_t cat;
    class_menu_t class_menu[4];
    character_t character[20];
    stat_charac_t stat_charac[4];
    int color;
    int top_size;
    int class;
    char *name[4];
} new_game_t;

//!load_game

typedef struct save_charact_s {
    sfSprite *spr;
    sfTexture *text;
    sfVector2f pos;
    sfVector2f scale;
    sfIntRect rect;
    text_t *name;
} save_charact_t;

typedef struct support_save_s {
    sfSprite *spr;
    sfTexture *text;
    sfVector2f pos;
} support_save_t;

typedef struct load_game_s {
    support_save_t support_save;
    support_save_t save_full[3];
    support_save_t save_empty[3];
    support_save_t delete_save;
    sfBool save[3];
    sfBool delete;
    save_charact_t save_charact[3];
    int nb_save;
    int load_save;
    text_t *time[3];
    text_t *day[3];
} load_game_t;

//!Gameplay
typedef enum axe_e {
    X,
    Y,
} axe_t;

typedef struct bar_s {
    sprite_t *info;
    int current_score;
    int max_score;
} bar_t;

typedef enum type_e {
    ENEMY,
    TANK,
    BULLET,
    FIREBALL,
    ARROW,
    PLAYER,
    CANON,
    WIZARD,
    ARCHER,
    THROW,
    BLOW,
    IMMU,
    SCENE,
} type_t;

typedef enum state_e {
    ALIVE,
    DEAD,
    DISPLAYED,
    NEAR_DEAD,
} state_t;

typedef struct map_s {
    char **map_g;
    char **map_p;
    int max_x;
    int max_y;
    int ratio;
    int pos_x;
    int pos_y;
    int x_player;
    int y_player;
    sprite_t *ground_g[9];
    sprite_t *ground_p[22];
} map_t;

typedef struct obj_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f scale;
    sfVector2f inertia;
    sfIntRect rect;
    sfIntRect hitbox;
    state_t state_s;
    type_t type;
    int level;
    float abs;
    int damage;
    int hp;
    int speed_max;
    float time;
    clockk_t *clock_sprite;
    clockk_t *clock_attack;
    clockk_t *clock_move;
} obj_t;

typedef struct item_s {
    sprite_t **sprite_s;
    enum_item_t enum_item_e;
    int nb_item;
} item_t;

typedef struct chest_s {
    item_t *item;
    sprite_t *sprite_s;
    state_t state;
} chest_t;

typedef struct tab_chest_s {
    chest_t *chest[30];
    int is_display;
    sprite_t *sprite_s;
    int pos_chest;
} tab_chest_t;

typedef struct inventory_s {
    sprite_t *backpack;
    sprite_t *switch_b;
    sprite_t *square;
    item_t *items[16];
    int is_display;
    int is_clicked;
    int item_idx;
    text_t *text;
} inventory_t;

typedef struct stat_s {
    int speed;
    int stamina;
    int strength;
    int intellect;
    int shoot;
} stat_t;

typedef struct player_s {
    obj_t *obj;
    bar_t *health;
    inventory_t *inventory;
    item_t *item_hand;
    stat_t *stat;
    char *filepath_character;
    int is_running;
    int exp;
    int level;
    int step;
    int point_competences;
    int stamina;
    int stamina_max;
    sfRectangleShape *bar;
} player_t;

typedef struct intro_s {
    sprite_t *background[21];
    int frame_one;
    int cinema;
    int bubulle_legende;
    sfIntRect rect;
    sfClock *clock;
    sfTime time;
    float sec;
    int error;
} intro_t;

typedef struct howtwoplay_s {
    sprite_t *background[21];
    button_t *button[2];
    int error;
    int scene;
} howtwoplay_t;

typedef struct pause_s {
    button_t *button[3];
    sprite_t *background;
    bool display;
} pause_t;

typedef struct audio_s {
    sfMusic *boss_fight;
    sfSound *ak_sound;
    sfMusic *night_music;
    sfMusic *menu_music;
    sfSound *eat_sound;
    sfMusic *classic_fight;
    sfMusic *intro;
    sfSound *zombie;
    int is_played;
} audio_t;

typedef struct npc_s {
    char *name;
    sprite_t *npc;
    const char **text;
    int idx_current_txt;
    sprite_t *bull;
} npc_t;

typedef struct quest_s {
    int item_collected;
    int current_level_quest;
    npc_t *mayor;
    npc_t *seller;
    sprite_t *sell_menu;
    sprite_t *rect;
    int is_display;
    int mayor_talk;
    clockk_t *clock;
    int display_text;
} quest_t ;

typedef struct tablet_s {
    button_t *button[10];
    sprite_t *background[9];
    clockk_t *tablet_clock;
    clockk_t *screen_clock;
    bool display;
    text_t *text[12];
} tablet_t;

typedef struct boss_s {
    sprite_t *background[20];
    clockk_t *clock_s;
    clockk_t *ck_boss;
    int life_boss;
    int life_player;
    int frame_boss;
    int bubulle_legende;
    int menu_boss;
    int error;
    sfKeyCode key_qte;
    sfKeyCode key_rand;
    bool fight;
    int display_pop_art;
} boss_t;

typedef struct gameplay_s {
    clockk_t *timer;
    int time;
    button_t *date;
    pause_t *pause;
    tablet_t *tablet;
    sprite_t *background[5];
} gameplay_t;

typedef struct game_s {
    audio_t *audio;
    pixel_t *pixel_s;
    boss_t *boss_s;
    map_t *map;
    menu_t *menu;
    quest_t *quest;
    intro_t *intro_s;
    howtwoplay_t *howtwoplay_s;
    new_game_t *new_game;
    load_game_t *load_game;
    info_t *game_info;
    sfSprite *ground;
    player_t *player;
    obj_t *entitie[500];
    tab_chest_t *chests;
    clockk_t *clock_s;
    gameplay_t *gameplay;
    sfEvent event;
    generator_t *generator;
} game_t;

#endif/* !STRUCT_H_ */
