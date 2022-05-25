/*
** EPITECH PROJECT, 2021
** B-PSU-101-NAN-1-1-navy-quentin.brejoin
** File description:
** free_double_array
*/

#include <stdlib.h>

void free_double_array(char **str)
{
    for (int i = 0; str[i] != NULL; i++)
        free(str[i]);
    free(str);
}
