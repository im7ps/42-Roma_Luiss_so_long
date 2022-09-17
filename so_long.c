/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:33:26 by sgerace           #+#    #+#             */
/*   Updated: 2022/09/17 20:42:37 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int count_rows(void)
{
	int     counter;
    int     fd;
	char    *row;

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

int items_checker(s_map *map_ptr)
{
    int i;
    int j;

    i = 0;
    map_ptr->e = 0;
    map_ptr->c = 0;
    map_ptr->p = 0;
    map_ptr->rows = count_rows();
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

int empty_or_invalid_checker(s_map  *map_ptr)
{
    int i;
    int j;

    if (map_ptr->map[0] == NULL)
        return (1);
    if (map_ptr->map[0][0] == '\n' || map_ptr->map[0][0] == '\0')
        return (1);
    i = 0;
    map_ptr->rows = count_rows();
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

int walls_checker(s_map *map_ptr)
{
    int i = 0;

    map_ptr->rows = count_rows() - 1; //tolgo uno perchè gli array partono da 0 e questo lo uso come indice
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

char find_last(s_map  *map_ptr)
{
    int i;
    int j;
    
    i = 0;
    while (map_ptr->map[i] && i < count_rows())
    {
        j = 0;
        while (map_ptr->map[i][j])
        {
            j++;
        }
        i++;
    }
    if (map_ptr->map[i-1][j-1] == '\n')
        return (map_ptr->map[i-1][j-1]);
    return (map_ptr->map[i-1][j]); 

}

int rectangle_checker(s_map  *map_ptr)
{
    int     i = 0;
    char    last_elem; 
    size_t  tmp = 0;

    map_ptr->rows = count_rows();
    if (map_ptr->rows < 3)
        return (1);
    last_elem = find_last(map_ptr);
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

int check_map_errors(s_map  *map_ptr)
{
    if (empty_or_invalid_checker(map_ptr) != 0)
        return (1);
    if (rectangle_checker(map_ptr) != 0)
        return (1);
    if (walls_checker(map_ptr) != 0)
        return (1);
    if (items_checker(map_ptr) != 0)
        return (1);
    return (0);
}

void	moves_counter(void	*mlx_ptr, void	*win_ptr)
{
	int x = 30;
	int y = 30;
	int color = 0x11FFAA;
	char *string = "moves counter";
	int wtf;

	wtf = mlx_string_put(mlx_ptr, win_ptr, x, y, color, string);
	printf("non so cosa sia ma mlx_string_put vale: %d\n", wtf);
}

void	insert_image(void	*mlx_ptr, void	*win_ptr, int image_posX, \
					int image_posY)
{
	void	*img_ptr;
	int w = 256;
	int h = 256;
	int	*width = &w;
	int	*height = &h;
	char *file_path = "./images/one_piece_img.xpm";

	img_ptr = mlx_xpm_file_to_image(mlx_ptr, file_path, width, height); //crea un'ímmagine in memoria, ritorna void* (l indirizzo in memoria) per poter essere manipolata
	if (img_ptr ==	(void *)0)
	{
		printf("errore nella creazione dell'immagine");
		exit (3);
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, image_posX, image_posY); //visualizza l immagine sul display secondo le coordinate desiderate (x e y)
}

void	*initialize_window(void	*mlx_ptr)
{
	void	*win_ptr;
	int		size_x = 1000;
	int		size_y = 1000;
	char	*title = "Hello!";

	win_ptr = mlx_new_window(mlx_ptr, size_x, size_y, title); //crea un nuovo display
	if (win_ptr == (void *)0)
	{
		free(win_ptr);
		printf("errore nella creazione della finestra");
		exit (2);
	}
	return (win_ptr);
}

void	*initialize_pointer()
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init(); //mlx_init ritorna un puntatore che contiene l indirizzo (è void *) del nostro display, lo si usa per manipolarlo, ritorna NULL se qualcosa va storto
	if (mlx_ptr == (void *)0) //come scritto nella guida, il puntatore ritorna (void *)0 in caso di fallimento
	{
		printf("errore di inizializzazione");
		exit (1);
	}
	return (mlx_ptr);
}

char **upload_map(s_map  *map_ptr)
{
	int		    fd;
	int		    i;

    i = -1; //i = -1 così posso risparmiare un rigo e aumentare la i nella condizione del while 4 righe in basso
    map_ptr->rows = count_rows();
	fd = open("./maps/map1.ber", O_RDONLY);
	map_ptr->map = (char **) malloc (sizeof(char *) * (map_ptr->rows + 1));
	while (i++ < map_ptr->rows - 1)
        map_ptr->map[i] = get_next_line(fd, 1);
    close(fd);
	return (map_ptr->map);
}

int main(void)
{
    s_map   *map_ptr;
	void	*mlx_ptr;
	void	*win_ptr;


    mlx_ptr = initialize_pointer();
	win_ptr = initialize_window(mlx_ptr);
    insert_image(mlx_ptr, win_ptr, 250, 250);
	moves_counter(mlx_ptr, win_ptr);
	//mlx_loop(mlx_ptr);
	mlx_destroy_window(mlx_ptr, win_ptr);

    map_ptr = (s_map *) malloc (sizeof(s_map));
    map_ptr->map = upload_map(map_ptr);
    if(check_map_errors(map_ptr) == 1)
        ft_printf("Error\n");
    else
        ft_printf("Valid\n");
}
