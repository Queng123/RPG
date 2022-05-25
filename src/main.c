/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** main
*/

#include "rpg.h"
#include <time.h>

const int NB_ENT = 100;
const float COEF_FRI = 0.997;
const int START_BUILDING = 30;

int main(int ac, char **av)
{
    srand(time(NULL));
    (void)av;
    if (ac != 1)
        return (ERROR);
    if (error_handling() == 84)
        return (84);
    if (my_rpg() == ERROR)
        return (ERROR);
    return (SUCCESS);
}
