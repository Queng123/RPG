/*
** EPITECH PROJECT, 2022
** B-PSU-101-NAN-1-1-minishell1-quentin.brejoin
** File description:
** my_arraycat
*/

#include <unistd.h>

int my_array_len(char **array);

char **my_arraycat(char **dest , char **src)
{
    int i = 0;
    int size = my_array_len(dest);

    for (i; src[i] != NULL; i++) {
        dest[size + i] = src[i];
    }
    dest[size + i] = NULL;
    return (dest);
}
