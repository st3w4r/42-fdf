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

int		expose_hook(t_param *param)
{
	draw_map(*(param->map), *(param->e));
	return (0);
}

int		main(int argc, char **argv)
{
	t_param	*param;
	t_env	e;
	t_map	*map;

	if (argc == 2)
	{
		map = ft_parse_map(argv, 0);
		if (!(param = (t_param *)malloc(sizeof(t_param))))
			ft_exit();
		get_center(param, map);
		param->map = map;
		param->e = &e;
		draw_windows("42", 1000, 1000, param->e);
		mlx_expose_hook(e.win, expose_hook, param);
		mlx_hook(e.win, 2, 3, key_hook, param);
		mlx_loop(e.mlx);
		free(param);
	}
	return (0);
}
