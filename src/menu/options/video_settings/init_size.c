/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** init_size
*/

#include "rpg.h"

int init_size_buttons(game_t *game)
{
    for (int i = 29; i != 34; i++) {
        game->menu->buttons[i] = malloc(sizeof(button_t));
        if (game->menu->buttons[i] == NULL)
            return (84);
        game->menu->buttons[i]->sprite = malloc(sizeof(sprite_t));
        if (game->menu->buttons[i]->sprite == NULL)
            return (84);
        game->menu->buttons[i]->sprite->sprite = NULL;
        game->menu->buttons[i]->sprite->pos = (sfVector2f) {770,
        600 + (i - 29) * 100 * 1.3 / 2};
        game->menu->buttons[i]->sprite->size = (sfVector2f) {700 * 1.3 / 2,
        100 * 1.3 / 2};
        game->menu->buttons[i]->text = malloc(sizeof(text_t));
        if (game->menu->buttons[i]->text == NULL)
            return (84);
        game->menu->buttons[i]->text->text = NULL;
    }
    return (0);
}

int init_size_bg(game_t *game)
{
    game->menu->background[7] = build_bg("assets/menu/screen_size.jpg");
    if (game->menu->background[7] == NULL)
        return (84);
    game->menu->background[7]->pos = (sfVector2f) {770, 600};
    game->menu->background[7]->scale = (sfVector2f) {1.3 / 2, 1.3 / 2};
    game->menu->background[7]->size = (sfVector2f) {100, 100};
    game->menu->background[7]->rect = (sfIntRect) {0, 0, 700, 100};
    game->menu->buttons[28] = malloc(sizeof(button_t));
    game->menu->buttons[28]->sprite = build_bg("assets/menu/triangle.png");
    if (game->menu->buttons[28]->sprite == NULL)
        return (84);
    game->menu->buttons[28]->sprite->pos = (sfVector2f) {1150, 600};
    game->menu->buttons[28]->sprite->scale = (sfVector2f) {1.3 / 2, 1.3 / 2};
    game->menu->buttons[28]->sprite->size = (sfVector2f) {50 * 1.3, 50 * 1.3};
    game->menu->buttons[28]->text = malloc(sizeof(text_t));
    if (game->menu->buttons[28]->text == NULL)
        return (84);
    game->menu->buttons[28]->text->text = NULL;
    return (0);
}

int init_size(game_t *game)
{
    game->menu->buttons[27] = malloc(sizeof(button_t));
    if (game->menu->buttons[27] == NULL)
        return (84);
    game->menu->buttons[27]->sprite = build_bg("assets/menu/empty_size.jpg");
    game->menu->buttons[27]->sprite->scale = (sfVector2f) {1.3 / 2, 1.3 / 2};
    game->menu->buttons[27]->sprite->pos = (sfVector2f) {770, 600};
    game->menu->buttons[27]->sprite->size = (sfVector2f)
    {500 * 1.3 / 2, 100 * 1.3 / 2};
    game->menu->buttons[27]->text = build_text("assets/font/verdana.ttf");
    if (game->menu->buttons[27]->text == NULL ||
    game->menu->buttons[27]->sprite == NULL)
        return (84);
    game->menu->buttons[27]->text->scale = (sfVector2f) {1.4, 1.4};
    game->menu->buttons[27]->text->pos = (sfVector2f) {845, 605};
    if (init_size_buttons(game) == 84 || init_size_bg(game) == 84)
        return (84);
    return (0);
}

void create_button_particles(game_t *game)
{
    game->menu->buttons[26]->text->text = NULL;
    game->menu->buttons[26]->sprite->scale = (sfVector2f) {0.3, 0.3};
    game->menu->buttons[26]->sprite->rect = (sfIntRect) {0, 256, 487, 256};
    game->menu->buttons[26]->sprite->pos = (sfVector2f) {927, 790};
    game->menu->buttons[26]->sprite->size = (sfVector2f) {487 * 0.3, 256 * 0.3};
}
