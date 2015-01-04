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

void	ft_cal_matrice(t_point *p, t_matrice *m, t_param *param)
{
	double tmp_x;
	double tmp_y;
	double tmp_z;
	// t_point p_center;
	//
	// p_center = get_center(p, m);

	p->x -= param->center.x;
	p->y -= param->center.y;

	// p->z = p->z - 200;

	tmp_x = p->x * m->a1 + p->y * m->a2 + p->z * m->a3 + p->s * m->a4;
	tmp_y = p->x * m->b1 + p->y * m->b2 + p->z * m->b3 + p->s * m->b4;
	tmp_z = p->x * m->c1 + p->y * m->c2 + p->z * m->c3 + p->s * m->c4;
	p->z = tmp_z;
	p->y = tmp_y;
	p->x = tmp_x;

	p->x += param->center.x;
	p->y += param->center.y;
	// p->x = p->x + 200;
	// p->y = p->y + 200;
	// p->z = p->z + 200;

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

void	ft_cal_rotation_x(t_param *param, double rot)
{
	t_matrice *m_rot;

	m_rot = ft_matrice_rotation_x(rot);
	ft_cal_matrice_all_points(param->map, m_rot, param);
	free(m_rot);
}

void	ft_cal_rotation_y(t_param *param, double rot)
{
	t_matrice *m_rot;

	m_rot = ft_matrice_rotation_y(rot);
	ft_cal_matrice_all_points(param->map, m_rot, param);
	free(m_rot);
}

void	ft_cal_rotation_z(t_param *param, double rot)
{
	t_matrice *m_rot;

	m_rot = ft_matrice_rotation_z(rot);
	ft_cal_matrice_all_points(param->map, m_rot, param);
	free(m_rot);
}

void	ft_cal_translation(t_param *param, double x, double y, double z)
{
	t_matrice *m_tran;

	m_tran = ft_matrice_translation(x, y, z);
	ft_cal_matrice_all_points(param->map, m_tran, param);
	get_center(param, param->map);
	free(m_tran);
}

/*
void	ft_cal_translation_x(t_map *map)
{
	t_matrice *m_tran;

	m_tran = ft_matrice_translation_x(300);
	ft_cal_matrice_all_points(map, m_tran);
	free(m_tran);
}

void	ft_cal_translation_y(t_map *map)
{
	t_matrice *m_tran;

	m_tran = ft_matrice_translation_y(300);
	ft_cal_matrice_all_points(map, m_tran);
	free(m_tran);
}

void	ft_cal_translation_z(t_map *map)
{
	t_matrice *m_tran;

	m_tran = ft_matrice_translation_z(10);
	ft_cal_matrice_all_points(map, m_tran);
	free(m_tran);
}
*/
void	ft_cal_matrice_all_points(t_map *map, t_matrice *m, t_param *param)
{
	int x;
	int y;

	y = 0;
	while (y < map->len)
	{
		x = 0;
		while (x < (map->lines[y]->len))
		{
			ft_cal_matrice(map->lines[y]->points[x], m, param);
			x++;
		}
		y++;
	}
}
