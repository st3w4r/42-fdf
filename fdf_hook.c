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
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(param->e->mlx, param->e->win);
		exit(0);
	}
	else if (keycode == KEY_ROT_X_U)
		ft_cal_rotation_x(param, MOVE_ROT_X_U);
	else if (keycode == KEY_ROT_X_D)
		ft_cal_rotation_x(param, MOVE_ROT_X_D);
	else if (keycode == KEY_ROT_Y_U)
		ft_cal_rotation_y(param, MOVE_ROT_Y_U);
	else if (keycode == KEY_ROT_Y_D)
		ft_cal_rotation_y(param, MOVE_ROT_Y_D);
	else if (keycode == KEY_ROT_Z_U)
		ft_cal_rotation_z(param, MOVE_ROT_Z_U);
	else if (keycode == KEY_ROT_Z_D)
		ft_cal_rotation_z(param, MOVE_ROT_Z_D);
	else if (keycode == KEY_UP)
		ft_cal_translation(param, 0, MOVE_UP, 0);
	else if (keycode == KEY_DOWN)
		ft_cal_translation(param, 0, MOVE_DOWN, 0);
	else if (keycode == KEY_LEFT)
		ft_cal_translation(param, MOVE_LEFT, 0, 0);
	else if (keycode == KEY_RIGHT)
		ft_cal_translation(param, MOVE_RIGHT, 0, 0);
	else if (keycode == KEY_ZOOM_IN)
		ft_cal_scale(param, MOVE_ZOOM_IN);
	else if (keycode == KEY_ZOOM_OUT)
		ft_cal_scale(param, MOVE_ZOOM_OUT);
	draw_reload(*(param->map), *(param->e));
	return (0);
}
