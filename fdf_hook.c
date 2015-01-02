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

int		key_hook(int keycode, t_env *e)
{
	ft_putnbr(keycode);
	ft_putchar(' ');
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	return (0);
}
