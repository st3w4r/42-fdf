/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_matrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 16:23:59 by ybarbier          #+#    #+#             */
/*   Updated: 2014/12/16 16:25:16 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrice	*ft_matrice_rotation(double beta)
{
	t_matrice *m;

	if (!(m = (t_matrice*)ft_memalloc(sizeof(t_matrice))))
		ft_exit();
	m->a1 = cos(beta);
	m->a2 = -sin(beta);
	m->b1 = sin(beta);
	m->b2 = cos(beta);
	m->c3 = 1;
	m->d4 = 1;
	return (m);
}

t_matrice	*ft_matrice_translation_x(double tran)
{
	t_matrice *m;
	if (!(m = (t_matrice*)ft_memalloc(sizeof(t_matrice))))
		ft_exit();
	m->a4 = tran;
	m->a1 = 1;
	m->b2 = 1;
	m->c3 = 1;
	m->d4 = 1;
	return (m);
}

t_matrice	*ft_matrice_translation_y(double tran)
{
	t_matrice *m;
	if (!(m = (t_matrice*)ft_memalloc(sizeof(t_matrice))))
		ft_exit();
	m->b4 = tran;
	m->a1 = 1;
	m->b2 = 1;
	m->c3 = 1;
	m->d4 = 1;
	return (m);
}

t_matrice	*ft_matrice_translation_z(double tran)
{
	t_matrice *m;
	if (!(m = (t_matrice*)ft_memalloc(sizeof(t_matrice))))
		ft_exit();
	m->c4 = tran;
	m->a1 = 1;
	m->b2 = 1;
	m->c3 = 1;
	m->d4 = 1;
	return (m);
}