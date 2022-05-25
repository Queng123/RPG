/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** init_controls
*/

#include "rpg.h"

void init_commands_rect(game_t *game)
{
    game->menu->buttons[33]->sprite->rect.left = (sfKeyZ % 10) * 193;
    game->menu->buttons[33]->sprite->rect.top = (sfKeyZ / 10) * 157;
    game->menu->buttons[34]->sprite->rect.left = (sfKeyS % 10) * 193;
    game->menu->buttons[34]->sprite->rect.top = (sfKeyS / 10) * 157;
    game->menu->buttons[35]->sprite->rect.left = (sfKeyQ % 10) * 193;
    game->menu->buttons[35]->sprite->rect.top = (sfKeyQ / 10) * 157;
    game->menu->buttons[36]->sprite->rect.left = (sfKeyD % 10) * 193;
    game->menu->buttons[36]->sprite->rect.top = (sfKeyD / 10) * 157;
    game->menu->buttons[37]->sprite->rect.left = (sfKeyLShift % 10) * 193;
    game->menu->buttons[37]->sprite->rect.top = (sfKeyLShift / 10) * 157;
    game->menu->buttons[38]->sprite->rect.left = (sfKeyI % 10) * 193;
    game->menu->buttons[38]->sprite->rect.top = (sfKeyI / 10) * 157;
    game->menu->buttons[39]->sprite->rect.left = (sfKeyE % 10) * 193;
    game->menu->buttons[39]->sprite->rect.top = (sfKeyE / 10) * 157;
    game->menu->buttons[40]->sprite->rect.left = (sfKeyA % 10) * 193;
    game->menu->buttons[40]->sprite->rect.top = (sfKeyA / 10) * 157;
    game->menu->buttons[41]->sprite->rect.left = (sfKeyM % 10) * 193;
    game->menu->buttons[41]->sprite->rect.top = (sfKeyM / 10) * 157;
}

void init_commands_buttons(game_t *game)
{
    game->menu->buttons[33]->sprite->pos = (sfVector2f) {1255, 490};
    game->menu->buttons[34]->sprite->pos = (sfVector2f) {1255, 610};
    game->menu->buttons[35]->sprite->pos = (sfVector2f) {1255, 730};
    game->menu->buttons[36]->sprite->pos = (sfVector2f) {1255, 840};
    game->menu->buttons[37]->sprite->pos = (sfVector2f) {1255, 960};
    game->menu->buttons[38]->sprite->pos = (sfVector2f) {1255, 1410};
    game->menu->buttons[39]->sprite->pos = (sfVector2f) {1255, 1525};
    game->menu->buttons[40]->sprite->pos = (sfVector2f) {1255, 1640};
    game->menu->buttons[41]->sprite->pos = (sfVector2f) {1255, 2315};
    init_commands_rect(game);
}

int build_controls_buttons(game_t *game)
{
    for (int i = 33; i != 42; i++) {
        game->menu->buttons[i] = malloc(sizeof(button_t));
        if (game->menu->buttons[i] == NULL)
            return (84);
        game->menu->buttons[i]->sprite = build_bg("assets/menu/keyboard.png");
        if (game->menu->buttons[i]->sprite == NULL)
            return (84);
        game->menu->buttons[i]->sprite->rect = (sfIntRect) {0, 0, 0, 0};
        game->menu->buttons[i]->sprite->scale = (sfVector2f) {0.6, 0.6};
        game->menu->buttons[i]->sprite->size = (sfVector2f)
        {193 * 0.6, 157 * 0.6};
        game->menu->buttons[i]->sprite->rect = (sfIntRect) {0, 0, 193, 157};
        game->menu->buttons[i]->text = malloc(sizeof(text_t));
        if (game->menu->buttons[i]->text == NULL)
            return (84);
        game->menu->buttons[i]->text->text = NULL;
        game->menu->buttons[i]->status = 0;
    }
    init_commands_buttons(game);
    return (0);
}

int build_press_key(game_t *game)
{
    game->menu->buttons[42] = malloc(sizeof(button_t));
    if (game->menu->buttons[42] == NULL)
        return (84);
    game->menu->buttons[42]->sprite = malloc(sizeof(sprite_t));
    if (game->menu->buttons[42]->sprite == NULL)
        return (84);
    game->menu->buttons[42]->sprite->sprite = NULL;
    game->menu->buttons[42]->text = build_text("assets/font/Roboto-Black.ttf");
    if (game->menu->buttons[42]->text == NULL)
        return (84);
    game->menu->buttons[42]->text->str = "Press any key to assign it";
    game->menu->buttons[42]->text->scale = (sfVector2f) {2.3, 2.3};
    game->menu->buttons[42]->text->pos = (sfVector2f) {600, 600};
    game->menu->buttons[42]->text->size = (sfVector2f) {100, 100};
    sfText_setOutlineThickness(game->menu->buttons[42]->text->text, 5);
    sfText_setFillColor(game->menu->buttons[42]->text->text, sfBlack);
    sfText_setColor(game->menu->buttons[42]->text->text, sfWhite);
    return (0);
}

int init_controls(game_t *game)
{
    if (build_controls_buttons(game) == 84)
        return (84);
    game->menu->background[9] = build_bg("assets/menu/bg_controls.jpg");
    game->menu->background[10] = build_bg("assets/menu/scrolling_bar.jpg");
    if (game->menu->background[9] == NULL || game->menu->background[10] == NULL)
        return (84);
    game->menu->background[9]->pos = (sfVector2f) {375, 257};
    game->menu->background[9]->scale = (sfVector2f) {1.3 / 2, 1.3 / 2};
    game->menu->background[9]->size = (sfVector2f) {100, 100};
    game->menu->background[9]->rect = (sfIntRect) {0, 0, 1918, 1011};
    game->menu->background[10]->pos = (sfVector2f) {1589, 257};
    game->menu->background[10]->scale = (sfVector2f) {1.3 / 2, 1.3 / 2};
    game->menu->background[10]->size = (sfVector2f) {50, 303};
    if (build_press_key(game) == 84)
        return (84);
    return (0);
}
