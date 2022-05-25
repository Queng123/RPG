/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** init_menu
*/

#include "rpg.h"

const char *button_name[] = {"NEW GAME", "LOAD GAME", "SETTINGS", "QUIT", NULL};

const char *bg_path[] = {"assets/menu/panneau_menu.png", NULL};

int init_background_menu(game_t *game)
{
    game->menu->background[11] = malloc(sizeof(sprite_t));
    game->menu->background[11]->texture = sfTexture_createFromFile
    ("assets/load_game/Zelter.png", NULL);
    game->menu->background[11]->sprite = sfSprite_create();
    if (game->menu->background[11]->sprite == NULL)
        return (84);
    game->menu->background[11]->pos = (sfVector2f){0, 0};
    sfSprite_setPosition(game->menu->background[11]->sprite,
    game->menu->background[11]->pos);
    sfSprite_setTexture(game->menu->background[11]->sprite,
    game->menu->background[11]->texture, sfTrue);
    return (0);
}

int init_menu_text(game_t *game, int i)
{
    game->menu->buttons[i]->text = build_text("assets/font/Roboto-Black.ttf");
    if (game->menu->buttons[i]->text == NULL)
        return (84);
    game->menu->buttons[i]->text->pos = (sfVector2f) {220, 660 + i * 70};
    game->menu->buttons[i]->text->scale = (sfVector2f) {1.8, 1.8};
    game->menu->buttons[i]->text->str = button_name[i];
    game->menu->buttons[i]->text->size = (sfVector2f) {
    my_strlen(button_name[i]) * 35, 65};
    game->menu->buttons[i]->status = 0;
    sfText_setOutlineThickness(game->menu->buttons[i]->text->text, 3);
    sfText_setFillColor(game->menu->buttons[i]->text->text, sfBlack);
    sfText_setColor(game->menu->buttons[i]->text->text, sfWhite);
    return (0);
}

int init_menu_buttons(game_t *game)
{
    for (int i = 0; i != 4; i++) {
        game->menu->buttons[i] = malloc(sizeof(button_t));
        if (game->menu->buttons[i] == NULL)
            return (84);
        game->menu->buttons[i]->sprite = malloc(sizeof(sprite_t));
        if (game->menu->buttons[i]->sprite == NULL)
            return (84);
        game->menu->buttons[i]->sprite->sprite = NULL;
        game->menu->buttons[i]->sprite->pos = (sfVector2f) {220, 640 + i * 60};
        game->menu->buttons[i]->sprite->size = (sfVector2f) {30, 200};
        if (init_menu_text(game, i) == 84)
            return (84);
    }
    game->menu->options_clock = malloc(sizeof(clockk_t));
    game->menu->options_clock->clock = sfClock_create();
    game->menu->options_clock->seconds = 0;
    game->menu->options_clock->time.microseconds = 0;
    if (game->menu->options_clock->clock == NULL)
        return (84);
    return (0);
}

int init_menu_bg(game_t *game)
{
    for (int i = 0; i != 1; i++) {
        game->menu->background[i] = malloc(sizeof(sprite_t));
        if (game->menu->background[i] == NULL)
            return (84);
        game->menu->background[i]->texture =
        sfTexture_createFromFile(bg_path[i], NULL);
        if (game->menu->background[i]->texture == NULL)
            return (84);
        game->menu->background[i]->sprite = sfSprite_create();
        if (game->menu->background[i]->sprite == NULL)
            return (84);
        game->menu->background[i]->pos = (sfVector2f) {20, 400};
        game->menu->background[i]->scale = (sfVector2f) {1.5, 1.5};
        game->menu->background[i]->size = (sfVector2f) {100, 100};
        sfSprite_setTexture(game->menu->background[i]->sprite,
        game->menu->background[i]->texture, sfTrue);
    }
    return (0);
}

int init_menu(game_t *game)
{
    game->menu = malloc(sizeof(menu_t));
    if (game->menu == NULL)
        return (84);
    if (init_menu_bg(game) == 84 || init_menu_buttons(game) == 84
    || init_options(game) == 84 || init_new_game(game) == 84
    || init_load_game(game) == 84 || init_background_menu(game) == 84)
        return (84);
    return (0);
}
