/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:12:44 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/17 19:03:51 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int items_counter(char c)
{
    static int p_toggler;   //lo trova e aumenta di 1, alla fine se non è 1 o non lo ha trovato mai o l ha trovato troppe volte
    static int e_toggler;
    static int c_toggler;

    if (c == 'P')
        p_toggler++;
    else if (c == 'E')
    {
        e_toggler++;
        return (1); //se è presente almeno una volta verrà ritornato il valore e potrò controllare la variabile ad esso associata, se è 1 vuol dire che c'è almeno un'uscita
    }
    else if (c == 'C')
    {
        c_toggler++;
        return (2); //se è presente almeno una volta verrà ritornato il valore e potrò controllare la variabile ad esso associata, se è 2 vuol dire che c'è almeno un collezionabile
    }
    return (p_toggler);
}

int items_checker(t_map *map_ptr, const char *map_model)
{
    int i;
    int j;

    i = 0;
    map_ptr->e = 0;
    map_ptr->c = 0;
    map_ptr->p = 0;
    map_ptr->rows = ft_count_rows(map_model);
    while(i < map_ptr->rows && map_ptr->map[i])
    {
        j = -1;
        while(map_ptr->map[i][++j] != '\0')
        {
            if (map_ptr->map[i][j] == 'P')
                map_ptr->p = items_counter(map_ptr->map[i][j]);
            else if (map_ptr->map[i][j] == 'E')
                map_ptr->e = items_counter(map_ptr->map[i][j]);
            else if (map_ptr->map[i][j] == 'C')
                map_ptr->c = items_counter(map_ptr->map[i][j]);
        }
        i++;
    }
    if (map_ptr->p != 1 || map_ptr->e != 1 || map_ptr->c == 0)
        return (1);
    return (0);
}

int empty_or_invalid_checker(t_map  *map_ptr, const char *map_model) //controlla che esista la mappa e che sia riempita solo con caratteri accettati
{
    int i;
    int j;

    if (map_ptr->map[0] == NULL)
        return (1);
    if (map_ptr->map[0][0] == '\n' || map_ptr->map[0][0] == '\0')
        return (1);
    i = 0;
    map_ptr->rows = ft_count_rows(map_model);
    while(i < map_ptr->rows)
    {
        j = 0;
        while(map_ptr->map[i][j] != '\n' && map_ptr->map[i][j] != '\0')
        {
            if (!(map_ptr->map[i][j] == '0' || map_ptr->map[i][j] == '1' || \
                map_ptr->map[i][j] == 'P' || map_ptr->map[i][j] == 'E' \
                || map_ptr->map[i][j] == 'C'))
                return (2);
            j++;
        }
        i++;
    }
    return (0);
}

int walls_checker(t_map *map_ptr, const char *map_model)
{
    int i = 0;

    map_ptr->rows = ft_count_rows(map_model) - 1; //tolgo uno perchè gli array partono da 0 e questo lo uso come indice
    if(ft_findchar(map_ptr->map[0], '1') == 1)
        return (1);
    if(ft_findchar(map_ptr->map[map_ptr->rows], '1') == 1)
        return (3);
    while (i < map_ptr->rows && map_ptr->map[i++])
    {
        if (((map_ptr->map[i][0]) != '1') || ((map_ptr->map[i][ft_strlen(map_ptr->map[i]) - 2]) != '1'))
            return (2);
    }
    return (0);
}

int rectangle_checker(t_map  *map_ptr, const char *map_model)
{
    int     i = 0;
    char    last_elem; 
    int  tmp = 0;

    map_ptr->rows = ft_count_rows(map_model);
    if (map_ptr->rows < 3)
        return (1);
    last_elem = ft_find_last(map_ptr, map_model);
    tmp = ft_strlen(map_ptr->map[0]);
    while (i < map_ptr->rows)
	{
        if (last_elem == '\0' && i == (map_ptr->rows - 1))
            tmp--;
        if (tmp != ft_strlen(map_ptr->map[i]))
            return (1);
        i++;
	}
    return (0);
}
