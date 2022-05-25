/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** init_options
*/

#include "rpg.h"

const char *options_page[] = {"How2Play", "Controls", "Audio Settings",
"Video settings", NULL};

int init_home_buttons(game_t *game)
{
    game->menu->buttons[8] = malloc(sizeof(button_t));
    if (game->menu->buttons[8] == NULL)
        return (84);
    game->menu->buttons[8]->sprite = malloc(sizeof(sprite_t));
    if (game->menu->buttons[8]->sprite == NULL)
        return (84);
    game->menu->buttons[8]->sprite->sprite = NULL;
    game->menu->buttons[8]->sprite->pos = (sfVector2f) {1659, 345};
    game->menu->buttons[8]->sprite->size = (sfVector2f) {50, 50};
    game->menu->buttons[9] = malloc(sizeof(button_t));
    if (game->menu->buttons[9] == NULL)
        return (84);
    game->menu->buttons[9]->sprite = malloc(sizeof(sprite_t));
    if (game->menu->buttons[9]->sprite == NULL)
        return (84);
    game->menu->buttons[9]->sprite->sprite = NULL;
    game->menu->buttons[9]->sprite->pos = (sfVector2f) {1655, 485};
    game->menu->buttons[9]->sprite->size = (sfVector2f) {50, 110};
    return (0);
}

int init_options_text(game_t *game, int i)
{
    game->menu->buttons[i]->text = build_text("assets/font/Roboto-Black.ttf");
    if (game->menu->buttons[i]->text == NULL)
        return (84);
    game->menu->buttons[i]->text->scale = (sfVector2f) {1.5, 1.5};
    game->menu->buttons[i]->text->str = options_page[i - 4];
    game->menu->buttons[i]->text->size = (sfVector2f) {
    my_strlen(options_page[i - 4]) * 35, 70};
    sfText_setColor(game->menu->buttons[i]->text->text, sfBlack);
    return (0);
}

int init_options_buttons(game_t *game)
{
    for (int i = 4; i != 8; i++) {
        game->menu->buttons[i] = malloc(sizeof(button_t));
        if (game->menu->buttons[i] == NULL)
            return (84);
        game->menu->buttons[i]->sprite = malloc(sizeof(sprite_t));
        if (game->menu->buttons[i]->sprite == NULL)
            return (84);
        game->menu->buttons[i]->sprite->sprite = NULL;
        game->menu->buttons[i]->sprite->pos = (sfVector2f) {220, 640};
        game->menu->buttons[i]->sprite->size = (sfVector2f) {30, 200};
        if (init_options_text(game, i) == 84)
            return (84);
    }
    game->menu->buttons[4]->text->pos = (sfVector2f) {400, 185};
    game->menu->buttons[5]->text->pos = (sfVector2f) {670, 185};
    game->menu->buttons[6]->text->pos = (sfVector2f) {920, 185};
    game->menu->buttons[7]->text->pos = (sfVector2f) {1300, 185};
    if (init_home_buttons(game) == 84)
        return (84);
    return (0);
}

int init_tablette(game_t *game)
{
    game->menu->background[2] = malloc(sizeof(sprite_t));
    if (game->menu->background[2] == NULL)
        return (84);
    game->menu->background[2] = build_bg("assets/menu/options.jpg");
    if (game->menu->background[2] == NULL)
        return (84);
    game->menu->background[2]->pos = (sfVector2f) {375, 185};
    game->menu->background[2]->scale = (sfVector2f) {1.3 / 2, 1.3 / 2};
    game->menu->background[2]->size = (sfVector2f) {100, 100};
    return (0);
}

int init_options(game_t *game)
{
    game->menu->background[1] = malloc(sizeof(sprite_t));
    if (game->menu->background[1] == NULL)
        return (84);
    game->menu->background[1] = build_bg("assets/menu/tablette.png");
    if (game->menu->background[1] == NULL)
        return (84);
    game->menu->background[1]->pos = (sfVector2f) {-250, -100};
    game->menu->background[1]->scale = (sfVector2f) {1.3, 1.3};
    game->menu->background[1]->size = (sfVector2f) {100, 100};
    if (init_tablette(game) == 84 || init_options_buttons(game) == 84 ||
        init_settings_bg(game) == 84 || init_colored_button(game) == 84 ||
        init_reseau(game) == 84)
        return (84);
    game->menu->buttons[4]->status = 0;
    game->menu->buttons[5]->status = 1;
    game->menu->buttons[6]->status = 1;
    game->menu->buttons[7]->status = 1;
    return (0);
}
