/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** gameplay
*/

#include "gameplay.h"

void select_color(pixel_t *pixel_s, int time, sfIntRect rect)
{
    sfColor color;

    color = (sfColor){0, 0, 0, time};
    for (int i = rect.left; i < rect.width; i++) {
        for (int j = rect.top; j < rect.height; j++) {
            my_put_pixel(pixel_s, i, j, &color);
        }
    }
}

void select_color_circle(pixel_t *pixel_s, sfVector2i center, int radius)
{
    int pt = 0;
    int temp_i = center.y - radius;
    int temp_j = center.x - radius;
    sfColor color = (sfColor){255, 255, 150, 20};

    for (int i = temp_i; i <= (2 * radius) + temp_i; i++) {
        for (int j = temp_j; j <= (2 * radius) + temp_j; j++) {
            pt = (j - center.x) * (j - center.x) + (i - center.y) * \
            (i - center.y);
            if (pt <= radius * radius)
                my_put_pixel(pixel_s, i, j, &color);
        }
    }
}

void set_night_texture(int m, int s, game_t *game)
{
    if (m >= 6 && m < 7) {
        select_color(game->pixel_s, 240 - s * 4,
        (sfIntRect) {0, 0, 1920, 1080});
        if (s < 30)
            select_color_circle(game->pixel_s, (sfVector2i) {600, 1050}, 200);
        draw_pixel(game, game->pixel_s);
    }
    if (m >= 21 && m < 22) {
        select_color(game->pixel_s, s * 4, (sfIntRect) {0, 0, 1920, 1080});
        if (s > 30)
            select_color_circle(game->pixel_s, (sfVector2i) {600, 1050}, 200);
        draw_pixel(game, game->pixel_s);
    }
    if (m < 6 || m >= 22) {
        select_color(game->pixel_s, 240, (sfIntRect) {0, 0, 1920, 1080});
        select_color_circle(game->pixel_s, (sfVector2i) {600, 1050}, 200);
        draw_pixel(game, game->pixel_s);
    }
}

void print_time(int sec, button_t *button, sfRenderWindow *window, game_t *game)
{
    int h = (sec / 1440);
    int m = (sec - (1440 * h)) / 60;
    int s = (sec - (1440 * h) - (m * 60));

    set_night_texture(m, s, game);
    display_button(game->gameplay->date, game->game_info->window);
    change_hours(button, window, h);
    change_minutes(button, window, m);
    change_seconds(button, window, s);
}

void play_game(game_t *game)
{
    while (game->clock_s->seconds > 0.1) {
        manage_clock_obj(game);
        spawn_zombies(game);
        display_obj(game);
        check_if_dead(game);
        game->clock_s->seconds -= 0.1;
    }
    display_game_bar(game);
    display_tablet(game);
    display_inventory(game);
    reset_inventory_item(game);
    if (game->gameplay->pause->display == true)
        display_pause(game);
    if (game->quest->display_text != 0)
        display_dialog(game);
}
