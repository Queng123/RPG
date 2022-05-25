/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** build_quest
*/

#include "build.h"

static const char *saying_mayor[4] = {"Your sister have been attacked by"
"zombies you may find her in the ruined village\n",
"Well she could be in the"
"abandonned village\n", "So she must be in the mineshaft, be careful it's"
"really dangerous\n", NULL};

static const char *saying_seller[4] = {"Hi Sir do you want"
" some chocolatine ?\n",
NULL, NULL, NULL};

npc_t *build_npc(char *name, char *filepath, sfIntRect rect, const char **txt)
{
    npc_t *npc = malloc(sizeof(npc_t));
    sfVector2f scale = {2, 2};
    sfVector2f pos = {0, 0};

    if (npc == NULL)
        return (NULL);
    npc->name = name;
    npc->idx_current_txt = 0;
    npc->npc = build_sprit(rect, filepath, scale, pos);
    npc->text = txt;
    if (npc->npc == NULL)
        return (NULL);
    return (npc);
}

clockk_t *build_clock_quest(void)
{
    clockk_t *clock = malloc(sizeof(clockk_t));

    clock->clock = sfClock_create();
    clock->seconds = 0;
    clock->time.microseconds = 0;
    return (clock);
}

quest_t *set_quest(quest_t *quest)
{
    sfIntRect b_rect = {0, 0, 470, 310};
    sfIntRect r_rect = {0, 0, 27, 8};
    sfVector2f scale = {1.5, 1.5};
    sfIntRect h_rect = {0, 0, 42, 49};

    quest->current_level_quest = -1;
    quest->mayor_talk = -1;
    quest->item_collected = -1;
    quest->sell_menu = build_sprit(b_rect,
    "assets/game/booksell.png", scale, scale);
    quest->rect = build_sprit(r_rect,
    "assets/game/square_item.png", scale, scale);
    quest->is_display = -1;
    quest->clock = build_clock_quest();
    quest->display_text = 0;
    quest->seller = build_npc("Hugo", "assets/game/hugo.png",
    h_rect, saying_seller);
    quest->seller->bull = build_sprit((sfIntRect) {0, 0, 1920, 348},
    "assets/game/quest/hugo.png", (sfVector2f) {0.5, 0.5}, (sfVector2f)
    {500, 1080 - 348});
    return (quest);
}

quest_t *build_quest(void)
{
    quest_t *quest = malloc(sizeof(quest_t));
    sfIntRect a_rect = {0, 0, 27, 32};

    if (quest == NULL)
        return (NULL);
    quest->mayor = build_npc("Aymeric",
    "assets/game/aymeric.png", a_rect, saying_mayor);
    quest->mayor->bull = build_sprit((sfIntRect) {0, 0, 1920, 348},
    "assets/game/quest/aymeric.png", (sfVector2f) {0.5, 0.5}, (sfVector2f)
    {500, 1080 - 348});
    quest = set_quest(quest);
    if (quest->seller == NULL || quest->mayor == NULL ||
    quest->sell_menu == NULL || quest->rect == NULL) {
        return (NULL);
    }
    quest->seller->npc->scale = (sfVector2f){1.5, 1.5};
    return (quest);
}
