/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 13:25:45 by ybarbier          #+#    #+#             */
/*   Updated: 2014/12/12 13:25:49 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int		ft_getnbr(char *str)
{
	int nbr;
	int neg;

	neg = 0;
	if (str[0] == '-')
		neg = 1, str++;
	nbr = 0;
	while ((*str >= '0') && (*str <= '9'))
		nbr = (nbr * 10) + *str++ - '0';
	return ((neg == 1)? -nbr : nbr);
}

// void	ft_parse_points (char *nb_str)
// {
//
// }

t_point		**ft_points(char *line, int nb_line)
{
	char **array_str;
	t_point **array_points;
	t_point *a_point;

	int i;
	int nb_points;

	array_str = ft_strsplit(line, ' ');
	i = 0;
	nb_points = 1;
	while (array_str[i] != 0)
	{
		i++;
		nb_points++;
	}
	array_points = (t_point**)malloc(sizeof(t_point) * nb_points);
	i = 0;
	while (array_str[i] != 0)
	{
		a_point = (t_point*)malloc(sizeof(t_point));
		a_point->x = i;
		a_point->y = nb_line;
		a_point->z = ft_getnbr(array_str[i]);

		// printf("x: %d y: %d z: %d", a_point->x, a_point->y, a_point->z);
		// puts("");
		array_points[i] = a_point;
		i++;
	}
	return (array_points);
}

int		ft_map_line(char *map)
{
	int fd;
	int nb_lines;
	char *buf;

	fd = 0;
	nb_lines = 0;
	buf = (char*)malloc(sizeof(char));
	if ((fd = open(map, O_RDONLY)))
	{
		while (read(fd, buf, 1))
		{
			if (ft_strcmp("\n", buf) == 0)
				nb_lines++;
		}
	}
	close(fd);
	return (nb_lines);
}

t_map	*ft_parse_map(char **av)
{
	char	*line;
	int		fd;
	int		val;
	int		nb_line;
	t_map	*map;
	t_line	*line_map;
	int		i;
	int		j;

	fd = 0;
	nb_line = 0;
	map = (t_map*)malloc(sizeof(t_map));
	map->lines = (t_line**)malloc(sizeof(t_line) * ft_map_line(av[1]));
	if ((fd = open(av[1], O_RDONLY)) > 0)
	{
		while ((val = get_next_line(fd, &line)) > 0)
		{
			line_map = (t_line*)malloc(sizeof(t_line));
			line_map->nb = nb_line;
			line_map->points = ft_points(line, nb_line);
			map->lines[nb_line] = line_map;

			// puts(line);
			// puts("Nb Points");
			// puts("");
			nb_line++;
		}
	}
	i = 0;
	while (i < nb_line)
	{
		j = 0;
		while (j < 19)
		{
			printf("x: %d y: %d z: %d", map->lines[i]->points[j]->x, map->lines[i]->points[j]->y, map->lines[i]->points[j]->z);
			puts(" ");
			// map->lines[i]->points[j]->x
			j++;
		}
		puts(" ");
		i++;
	}
	// ft_putnbr(nb_line);
	return (map);
}
