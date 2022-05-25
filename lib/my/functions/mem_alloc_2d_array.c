/*
** EPITECH PROJECT, 2021
** B-CPE-110-NAN-1-1-bsbsq-quentin.brejoin
** File description:
** mem_alloc_2d_array
*/

#include <stdlib.h>
#include "../include/my.h"

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    char **tab = my_calloc((nb_rows + 1), sizeof(*tab));

    for (int i = 0; i != nb_rows; i++) {
        tab[i] = my_calloc((nb_cols + 1), sizeof(char));
    }
    return (tab);
}
