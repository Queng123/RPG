/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** init_video
*/

#include "rpg.h"

int init_button_particles(game_t *game)
{
    game->menu->buttons[26] = malloc(sizeof(button_t));
    if (game->menu->buttons[26] == NULL)
        return (84);
    game->menu->buttons[26]->sprite = build_bg("assets/menu/switch_button.png");
    if (game->menu->buttons[26]->sprite == NULL)
        return (84);
    game->menu->buttons[26]->text = malloc(sizeof(text_t));
    if (game->menu->buttons[26]->text == NULL)
        return (84);
    create_button_particles(game);
    return (0);
}

int init_fps_buttons(game_t *game)
{
    for (int i = 22; i != 26; i++) {
        game->menu->buttons[i] = malloc(sizeof(button_t));
        if (game->menu->buttons[i] == NULL)
            return (84);
        game->menu->buttons[i]->sprite = malloc(sizeof(sprite_t));
        if (game->menu->buttons[i]->sprite == NULL)
            return (84);
        game->menu->buttons[i]->sprite->sprite = NULL;
        game->menu->buttons[i]->sprite->pos = (sfVector2f) {830,
        380 + (i - 22) * 100 * 1.3 / 2};
        game->menu->buttons[i]->sprite->size = (sfVector2f) {500 * 1.3 / 2,
        100 * 1.3 / 2};
        game->menu->buttons[i]->text = malloc(sizeof(text_t));
        if (game->menu->buttons[i]->text == NULL)
            return (84);
        game->menu->buttons[i]->text->text = NULL;
    }
    return (0);
}

int init_button_fps(game_t *game)
{
    game->menu->buttons[20] = malloc(sizeof(button_t));
    if (game->menu->buttons[20] == NULL)
        return (84);
    game->menu->buttons[20]->sprite = build_bg("assets/menu/empty_fps.jpg");
    game->menu->buttons[20]->sprite->scale = (sfVector2f) {1.3 / 2, 1.3 / 2};
    game->menu->buttons[20]->sprite->pos = (sfVector2f) {830, 380};
    game->menu->buttons[20]->sprite->size = (sfVector2f)
    {500 * 1.3 / 2, 100 * 1.3 / 2};
    game->menu->buttons[20]->text = build_text("assets/font/verdana.ttf");
    if (game->menu->buttons[20]->text == NULL ||
    game->menu->buttons[20]->sprite == NULL)
        return (84);
    game->menu->buttons[20]->text->scale = (sfVector2f) {1.5, 1.5};
    game->menu->buttons[20]->text->pos = (sfVector2f) {965, 380};
    game->menu->buttons[20]->text->str = int_to_char(game->game_info->fps);
    return (0);
}

int init_fps_options(game_t *game)
{
    game->menu->background[6] = build_bg("assets/menu/fps_options.jpg");
    if (game->menu->background[6] == NULL)
        return (84);
    game->menu->background[6]->pos = (sfVector2f) {830, 380};
    game->menu->background[6]->scale = (sfVector2f) {1.3 / 2, 1.3 / 2};
    game->menu->background[6]->size = (sfVector2f) {100, 100};
    game->menu->background[6]->rect = (sfIntRect) {0, 0, 500, 100};
    game->menu->buttons[21] = malloc(sizeof(button_t));
    if (game->menu->buttons[21] == NULL)
        return (84);
    game->menu->buttons[21]->sprite = build_bg("assets/menu/triangle.png");
    if (game->menu->buttons[21]->sprite == NULL)
        return (84);
    game->menu->buttons[21]->sprite->pos = (sfVector2f) {1080, 380};
    game->menu->buttons[21]->sprite->scale = (sfVector2f) {1.3 / 2, 1.3 / 2};
    game->menu->buttons[21]->sprite->size = (sfVector2f) {50 * 1.3, 50 * 1.3};
    game->menu->buttons[21]->text = malloc(sizeof(text_t));
    if (game->menu->buttons[21]->text == NULL)
        return (84);
    return (0);
}

int init_video(game_t *game)
{
    game->menu->background[4] = build_bg("assets/menu/video_options.jpg");
    if (game->menu->background[4] == NULL)
        return (84);
    game->menu->background[4]->pos = (sfVector2f) {375, 257};
    game->menu->background[4]->scale = (sfVector2f) {1.3 / 2, 1.3 / 2};
    game->menu->background[4]->size = (sfVector2f) {100, 100};
    game->menu->show_fps = 0;
    game->menu->show_size = 0;
    game->menu->fps_clock = malloc(sizeof(clockk_t));
    if (game->menu->fps_clock == NULL)
        return (84);
    game->menu->fps_clock->clock = sfClock_create();
    game->menu->fps_clock->seconds = 0;
    game->menu->fps_clock->time.microseconds = 0;
    if (init_fps_options(game) == 84 || init_button_fps(game) == 84 ||
    init_fps_buttons(game) == 84 || init_button_particles(game) == 84 ||
    init_size(game) == 84)
        return (84);
    game->menu->buttons[21]->text->text = NULL;
    return (0);
}
