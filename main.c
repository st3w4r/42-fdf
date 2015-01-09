/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 14:51:09 by ybarbier          #+#    #+#             */
/*   Updated: 2014/12/09 15:00:59 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose_hook(t_env *e)
{
	draw_reload(e);
	return (0);
}

int		main(int argc, char **argv)
{
	// t_param	*param;
	t_env	e;
	t_map	*map;

	if (argc == 2)
	{
		map = ft_parse_map(argv, 0);
		// if (!(param = (t_param *)malloc(sizeof(t_param))))
			// ft_exit();
		e.map = map;
		get_center(&e);
		// param->e = &e;
		draw_windows("42 FDF", WINDOW_SIZE_W, WINDOW_SIZE_H, &e);
		mlx_expose_hook(e.win, expose_hook, &e);
		mlx_hook(e.win, 2, 3, key_hook, &e);
		mlx_loop(e.mlx);
		// free(param);
	}
	return (0);
}
