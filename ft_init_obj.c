/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/09 18:06:52 by vroche            #+#    #+#             */
/*   Updated: 2015/10/09 15:09:50 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		ft_initobj_matrix(t_object *obj, double anglet, double anglep)
{
	obj->cost = cos(anglet);
	obj->sint = sin(anglet);
	obj->cosp = cos(anglep);
	obj->sinp = sin(anglep);
	obj->mtx[0][0] = obj->cost;
	obj->mtx[1][0] = -obj->sint;
	obj->mtx[2][0] = 0;
	obj->mtx[0][1] = obj->sint * obj->cosp;
	obj->mtx[1][1] = obj->cost * obj->cosp;
	obj->mtx[2][1] = -obj->sinp;
	obj->mtx[0][2] = obj->sint * obj->sinp;
	obj->mtx[1][2] = obj->cost * obj->sinp;
	obj->mtx[2][2] = obj->cosp;
	obj->mtxi[0][0] = obj->cost;
	obj->mtxi[1][0] = obj->sint;
	obj->mtxi[2][0] = 0;
	obj->mtxi[0][1] = -obj->sint * obj->cosp;
	obj->mtxi[1][1] = obj->cost * obj->cosp;
	obj->mtxi[2][1] = obj->sinp;
	obj->mtxi[0][2] = obj->sint * obj->sinp;
	obj->mtxi[1][2] = -obj->cost * obj->sinp;
	obj->mtxi[2][2] = obj->cosp;
}

t_object	*ft_coor_equ_obj(double a, double b, double c, double d)
{
	t_object	*obj;

	obj = (t_object *)malloc(sizeof(t_object));
	obj->a = a;
	obj->b = b;
	obj->c = c;
	obj->d = d;
	return (obj);
}

void		ft_color_obj(t_object *obj, int r, int g, int b)
{
	obj->color.r = r;
	obj->color.g = g;
	obj->color.b = b;
}

void		ft_pos_obj(t_object *obj, double x, double y, double z)
{
	obj->pos.x = x;
	obj->pos.y = y;
	obj->pos.z = z;
}
