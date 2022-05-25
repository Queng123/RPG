/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** build_tablet
*/

#include "rpg.h"

tablet_t *build_bg_tab(tablet_t *tablet)
{
    tablet->background[0] = build_bg("assets/game/tablet_menu.png");
    tablet->background[0]->pos = (sfVector2f) {10, 1080};
    tablet->background[0]->scale = (sfVector2f) {0.8, 0.8};
    tablet->background[1] = build_bg("assets/game/bg_tablet.jpg");
    tablet->background[1]->scale = (sfVector2f) {0.8, 0.8};
    tablet->background[2] = build_bg("assets/game/screen_on.jpg");
    tablet->background[2]->scale = (sfVector2f) {0.8, 0.8};
    tablet->background[2]->rect = (sfIntRect) {0, 0, 951, 665};
    tablet->background[3] = build_bg("assets/game/ground.jpg");
    tablet->background[3]->scale = (sfVector2f) {0.8, 0.8};
    tablet->background[4] = build_bg("assets/game/quest/bg_tablet.jpg");
    tablet->background[4]->scale = (sfVector2f) {0.8, 0.8};
    tablet->background[4]->rect = (sfIntRect) {0, 0, 951, 665};
    tablet->background[5] = build_bg("assets/game/quest/missions.jpg");
    tablet->background[5]->scale = (sfVector2f) {0.8, 0.8};
    tablet->background[5]->rect = (sfIntRect) {0, 0, 951, 120};
    tablet->background[6] = build_bg("assets/game/quest/missions_done.jpg");
    tablet->background[6]->scale = (sfVector2f) {0.8, 0.8};
    tablet->background[6]->rect = (sfIntRect) {0, 0, 951, 0};
    return (tablet);
}

tablet_t *build_button_tab(tablet_t *tablet)
{
    tablet->button[0] = malloc(sizeof(button_t));
    tablet->button[0]->sprite = build_bg("assets/game/player_info.jpg");
    tablet->button[1] = malloc(sizeof(button_t));
    tablet->button[1]->sprite = build_bg("assets/game/skill_tree.jpg");
    tablet->button[2] = malloc(sizeof(button_t));
    tablet->button[2]->sprite = build_bg("assets/game/map.jpg");
    tablet->button[3] = malloc(sizeof(button_t));
    tablet->button[3]->sprite = build_bg("assets/game/quest.jpg");
    for (int i = 0; i != 4; i++) {
        tablet->button[i]->text = build_text("assets/font/pixel.ttf");
        tablet->button[i]->sprite->scale = (sfVector2f) {0.8, 0.8};
        tablet->button[i]->sprite->size = (sfVector2f) {82 * 0.8, 82 * 0.8};
        tablet->button[i]->text->scale = (sfVector2f) {0.5, 0.5};
        tablet->button[i]->text->pos = (sfVector2f) {0, 0};
        tablet->button[i]->status = 0;
    }
    init_tablet(tablet);
    return (tablet);
}

button_t *build_button(char *filepath_sprite, char *filepath_text)
{
    button_t *button = malloc(sizeof(button_t));

    button->sprite = build_bg(filepath_sprite);
    if (filepath_text == NULL) {
        button->text = malloc(sizeof(text_t));
        button->text->text = NULL;
    } else
        button->text = build_text(filepath_text);
    return (button);
}

tablet_t *build_skill_tree(tablet_t *tablet)
{
    tablet->background[7] = build_bg("assets/game/tablet/bg_skill_tree.jpg");
    tablet->background[7]->scale = (sfVector2f) {0.8, 0.8};
    tablet->button[4] = build_button("assets/game/tablet/stamina_1.png", NULL);
    tablet->button[5] = build_button("assets/game/tablet/stamina_2.png", NULL);
    tablet->button[6] = build_button("assets/game/tablet/life_1.png", NULL);
    tablet->button[7] = build_button("assets/game/tablet/life_2.png", NULL);
    tablet->button[8] = build_button("assets/game/tablet/force_1.png", NULL);
    tablet->button[9] = build_button("assets/game/tablet/force_2.png", NULL);
    for (int i = 4; i != 10; i++) {
        tablet->button[i]->sprite->scale = (sfVector2f) {0.8, 0.8};
        tablet->button[i]->sprite->rect = (sfIntRect) {0, 0, 196, 163};
        tablet->button[i]->sprite->size = (sfVector2f) {196 * 0.8, 153 * 0.8};
        tablet->button[i]->status = 0;
    }
    return (tablet);
}

tablet_t *build_tablet(void)
{
    tablet_t *tablet = malloc(sizeof(tablet_t));

    tablet->display = false;
    tablet->tablet_clock = malloc(sizeof(clockk_t));
    tablet->tablet_clock->clock = sfClock_create();
    tablet->tablet_clock->seconds = 0;
    tablet->tablet_clock->time.microseconds = 0;
    tablet->screen_clock = malloc(sizeof(clockk_t));
    tablet->screen_clock->clock = sfClock_create();
    tablet->screen_clock->seconds = 0;
    tablet->screen_clock->time.microseconds = 0;
    tablet = build_bg_tab(tablet);
    tablet = build_button_tab(tablet);
    tablet = build_skill_tree(tablet);
    tablet = build_text_tablet(tablet);
    tablet = build_tablet_player_info(tablet);
    tablet->button[0]->status = 1;
    return (tablet);
}
