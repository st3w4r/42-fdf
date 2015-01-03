/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 21:29:41 by ybarbier          #+#    #+#             */
/*   Updated: 2015/01/02 21:29:57 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook(int keycode, t_param *param)
{
	ft_putnbr(keycode);
	ft_putchar(' ');
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(param->e->mlx, param->e->win);
		exit(0);
	}
	else if (keycode == KEY_ROT_LEFT)
		ft_cal_rotation(param->map, MOVE_ROT_LEFT);
	else if (keycode == KEY_ROT_RIGHT)
		ft_cal_rotation(param->map, MOVE_ROT_RIGHT);
	else if (keycode == KEY_UP)
		ft_cal_translation(param->map, 0, MOVE_UP, 0);
	else if (keycode == KEY_DOWN)
		ft_cal_translation(param->map, 0, MOVE_DOWN, 0);
	draw_reload(*(param->map), *(param->e));
	return (0);
}
