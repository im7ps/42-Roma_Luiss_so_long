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
    per ragioni di norma la funzione empty_checker è diventata empty_or_invalid_checker svolgendo DUE funzioni
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

int items_counter(char c)
{
    static int p_toggler = 0;   //lo trova e aumenta di 1, alla fine se non è 1 o non lo ha trovato mai o l ha trovato troppe volte
    static int e_toggler = 0;
    static int c_toggler = 0;

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

void    items_checker(char  **map)
{
    int i;
    int j;
    int num_rows;
    int e_check;
    int c_check;

    i = -1;
    num_rows = count_rows();
    while(i < num_rows - 1 && map[i++])
    {
        j = -1;
        while(map[i][++j] != '\n')
        {
            if (map[i][j] == 'P')
                items_counter(map[i][j]);
            else if (map[i][j] == 'E')
                e_check = items_counter(map[i][j]);
            else if (map[i][j] == 'C')
                c_check = items_counter(map[i][j]);
        }
    }
    if (items_counter(map[i][j]) != 1 || e_check != 1 || c_check != 2)
        ft_printf("Error\n");
}

int empty_or_invalid_checker(char **map)
{
    int i;
    int j;
    int num_rows;

    if (map[0] == NULL)
    {
        ft_printf("E' vuota bro\n");
        return (1);
    }
    i = -1;
    num_rows = count_rows();
    while(i < num_rows - 1 && map[i++])
    {
        j = -1;
        while(map[i][++j] != '\n')
        {
            if (!(map[i][j] == '0' || map[i][j] == '1' || map[i][j] == 'P' || \
                map[i][j] == 'E' || map[i][j] == 'C'))
                ft_printf("Presenta caratteri non validi\n"); 
        }
    }
    return (0);
}

void walls_checker(char **map)
{
    int i = -1;
    int j = 0;
    int num_rows = 0;

    num_rows = count_rows() - 1; //tolgo uno perchè gli array partono da 0 e questo lo uso come indice
    while (i < num_rows && map[i++])
    {
        while (map[0][j] != '\n')
        {
            if (map[0][j] != '1')
            {
                ft_printf("Solo muri sulla prima riga!\n");
                return ;
            }
            j++;    
        }
        j = 0;
        if (((map[i][0]) != '1') || ((map[i][ft_strlen(map[i]) - 2]) != '1'))
        {
            ft_printf("Solo muri nei bordi!\n");
            return ;
        }
        while (map[num_rows][j] != '\n')
        {
            if (map[num_rows][j] != '1')
            {
                ft_printf("Solo muri sull'ultima riga!\n");
                return ;
            }
            j++;
        }
    }
    ft_printf("La mappa è good\n");
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
    //if (empty_or_invalid_checker(map) == 1)
       // return;
    //rectangle_checker(map);
    walls_checker(map);
    //items_checker(map);
}

char	**upload_map()
{
	int		    fd;
	int		    i;
    int         num_rows;
	char	    **map;

    i = -1; //i = -1 così posso risparmiare un rigo e aumentare la i nella condizione del while 4 righe in basso
    num_rows = count_rows();
	fd = open("./maps/map1.ber", O_RDONLY);
	map = (char **) malloc (sizeof(char *) * (num_rows + 1));
	while (i++ < num_rows - 1)
        map[i] = get_next_line(fd, 1);
    close(fd);
	return (map);
}

int main(void)
{
    char **map;

    map = upload_map();
    check_map_errors(map);
}