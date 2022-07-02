/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:33:26 by sgerace           #+#    #+#             */
/*   Updated: 2022/07/01 20:02:31 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*DA RICORDARE:
    se la mappa è vuota il counter delle righe viene messo manualmente = 1
    dove ci sono i = -1 servono per non andare in seg fault, di solito nella condizione del while ci sarà un i++ così controlla se è vera o falsa e la pone = 0
*/
#include "so_long.h"

int count_rows()
{
	int		counter;
    int     fd;
	char	*row;

    counter = 0;
	fd = open("./maps/map1.ber", O_RDONLY);
	row = get_next_line(fd, 1);
    if (row == NULL)    //questo serve perchè anche se la mappa è vuota per fare almeno un controllo counter deve essere almeno 1
    {
        counter++;
    }
	while (row)
	{
		row = get_next_line(fd, 1);
		counter++;
	}
	close(fd);
	free(row);
    return (counter);
}

void empty_checker(char **map)
{
    if (map[0] == NULL)
    {
        ft_printf("E' vuota bro\n");
        return ;
    }
    ft_printf("E' piena bro\n");
}

void walls_checker(char **map)
{
    size_t i = 0;
    size_t j = 0;
    //size_t num_rows = 0;

    //num_rows = count_rows();

    while (map[i++])
    {
        /*while (map[0][j] != '\n')
        {
            if (map[0][j] != '1')
            {
                ft_printf("Solo muri sulla prima riga!\n");
                return ;
            }    
        }*/
        /*if (((map[i][0]) != '1') || ((map[i][ft_strlen(map[i])]) != '1'))
        {
            ft_printf("Solo muri nei bordi!\n");
            return ;
        }*/
        /*while (map[num_rows][j] != '\n')
        {
            if (map[num_rows][j] != '1')
            {
                ft_printf("Solo muri sull'ultima riga!\n");
                return ;
            }   
        }*/
        ft_printf("La mappa è good\n");
        j++;
    }
}

void   rectangle_checker(char   **map)
{
    size_t i = 0;
    size_t tmp = 0;
    size_t num_rows;

    num_rows = count_rows();
    tmp = ft_strlen(map[0]);
    while (map[i++])
	{
        if (tmp != ft_strlen(map[i]) && i < num_rows && map[i][0] != '\n')
        {
		    ft_printf("Not rectangular\n");
            return ;
        }
	}
    ft_printf("Rettangolare cazo\n");
}

void    check_map_errors(char **map)
{
    empty_checker(map);
    rectangle_checker(map);
    //walls_checker(map);
}

char	**upload_map()
{
	int		    fd;
	int		    i;
    int         num_rows;
	char	    **map;

    i = -1; //i = -1 così posso risparmiare un rigo e aumentare la i nella condizione del while riga 106
    num_rows = count_rows();
	fd = open("./maps/map1.ber", O_RDONLY);
	map = (char **) malloc (sizeof(char *) * (num_rows + 1));
	while (i++ < num_rows - 1)
    {
        map[i] = get_next_line(fd, 1);
        //ft_printf("%s", map[i]);
    }
    close(fd);
	return (map);
}

int main(void)
{
    char **map;

    map = upload_map();
    check_map_errors(map);
}