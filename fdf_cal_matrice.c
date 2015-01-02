/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_cal_matrice.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 17:44:14 by ybarbier          #+#    #+#             */
/*   Updated: 2014/12/18 17:44:19 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_cal_matrice(t_point *p, t_matrice *m)
{
	// p->x = p->x - 200;
	// p->y = p->y - 200;
	// p->z = p->z + 300;
	p->s = 1;
	p->x =  p->x * m->a1 + p->y * m->a2 + p->z * m->a3 + p->s * m->a4;
	p->y =  p->x * m->b1 + p->y * m->b2 + p->z * m->b3 + p->s * m->b4;
	p->z =  p->x * m->c1 + p->y * m->c2 + p->z * m->c3 + p->s * m->c4;

	// ft_putnbr(p->x);
	// ft_putchar(' ');
	// ft_putnbr(p->y);
	// ft_putchar(' ');
	// ft_putnbr(p->z);
	// ft_putchar(' ');
	// ft_putnbr(p->s);
	// ft_putchar('\n');
	// p->x = p->x + 200;
	// p->y = p->y + 200;

}

void	ft_cal_rotation(t_map *map)
{
	t_matrice *m_rot;

	m_rot = ft_matrice_rotation(0.5);
	ft_cal_matice_all_points(map, m_rot);
	free(m_rot);
}

void	ft_cal_translation_x(t_map *map)
{
	t_matrice *m_tran;

	m_tran = ft_matrice_translation_x(300);
	ft_cal_matice_all_points(map, m_tran);
	free(m_tran);
}

void	ft_cal_translation_y(t_map *map)
{
	t_matrice *m_tran;

	m_tran = ft_matrice_translation_y(300);
	ft_cal_matice_all_points(map, m_tran);
	free(m_tran);
}

void	ft_cal_translation_z(t_map *map)
{
	t_matrice *m_tran;

	m_tran = ft_matrice_translation_z(10);
	ft_cal_matice_all_points(map, m_tran);
	free(m_tran);
}

void	ft_cal_matice_all_points(t_map *map, t_matrice *m)
{
	int x;
	int y;

	y = 0;
	while (y < map->len)
	{
		x = 0;
		while (x < (map->lines[y]->len))
		{
			ft_cal_matrice(map->lines[y]->points[x], m);
			x++;
		}
		y++;
	}
}
