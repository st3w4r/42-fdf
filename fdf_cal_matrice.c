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

static void	ft_cal_matrice(t_point *p, t_matrice *m, t_env *e)
{
	double tmp_x;
	double tmp_y;
	double tmp_z;

	p->x -= e->center.x;
	p->y -= e->center.y;
	tmp_x = p->x * m->a1 + p->y * m->a2 + p->z * m->a3 + p->s * m->a4;
	tmp_y = p->x * m->b1 + p->y * m->b2 + p->z * m->b3 + p->s * m->b4;
	tmp_z = p->x * m->c1 + p->y * m->c2 + p->z * m->c3 + p->s * m->c4;
	p->z = tmp_z;
	p->y = tmp_y;
	p->x = tmp_x;
	p->x += e->center.x;
	p->y += e->center.y;
}

static void	ft_cal_matrice_all_points(t_matrice *m, t_env *e)
{
	int x;
	int y;

	y = 0;
	while (y < e->map->len)
	{
		x = 0;
		while (x < (e->map->lines[y]->len))
		{
			ft_cal_matrice(e->map->lines[y]->points[x], m, e);
			x++;
		}
		y++;
	}
}

void		ft_cal_rotation(t_env *e, double rot, char axe)
{
	t_matrice *m_rot;

	if (axe == 'x')
		m_rot = ft_matrice_rotation_x(rot);
	else if (axe == 'y')
		m_rot = ft_matrice_rotation_y(rot);
	else
		m_rot = ft_matrice_rotation_z(rot);
	ft_cal_matrice_all_points(m_rot, e);
	free(m_rot);
}

void		ft_cal_translat(t_env *e, double x, double y, double z)
{
	t_matrice *m_tran;

	m_tran = ft_matrice_translation(x, y, z);
	ft_cal_matrice_all_points(m_tran, e);
	get_center(e);
	free(m_tran);
}

void		ft_cal_scale(t_env *e, double s)
{
	t_matrice *m_tran;

	m_tran = ft_matrice_scale(s);
	ft_cal_matrice_all_points(m_tran, e);
	free(m_tran);
}
