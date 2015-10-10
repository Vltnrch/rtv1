/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_obj_work.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/19 18:33:57 by vroche            #+#    #+#             */
/*   Updated: 2015/09/28 17:28:03 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	ft_hit_obj_init_part(t_object *obj, t_work *w)
{
	w->var5 = ((obj->mtx[0][0] * obj->mtx[2][0] * obj->a) + \
			(obj->mtx[0][1] * obj->mtx[2][1] * obj->b) + \
			(obj->mtx[0][2] * obj->mtx[2][2] * obj->c));
	w->var6 = ((obj->mtx[2][0] * obj->mtx[1][0] * obj->a) + \
			(obj->mtx[2][1] * obj->mtx[1][1] * obj->b) + \
			(obj->mtx[2][2] * obj->mtx[1][2] * obj->c));
	w->var7 = ((obj->mtx[0][0] * obj->pos.x * obj->a) + \
			(obj->mtx[0][1] * obj->pos.y * obj->b) + \
			(obj->mtx[0][2] * obj->pos.z * obj->c));
	w->var8 = ((obj->mtx[1][0] * obj->pos.x * obj->a) + \
			(obj->mtx[1][1] * obj->pos.y * obj->b) + \
			(obj->mtx[1][2] * obj->pos.z * obj->c));
	w->var9 = ((obj->mtx[2][0] * obj->pos.x * obj->a) + \
			(obj->mtx[2][1] * obj->pos.y * obj->b) + \
			(obj->mtx[2][2] * obj->pos.z * obj->c));
	w->var10 = (obj->pos.x * obj->pos.x) + (obj->pos.y * obj->pos.y) + \
			(obj->pos.z * obj->pos.z) + obj->d;
}

t_work		*ft_hit_obj_init(t_object *obj)
{
	t_work	*w;

	w = (t_work *)malloc(sizeof(t_work));
	w->var1 = (obj->a * obj->mtx[0][0] * obj->mtx[0][0]) + \
			(obj->b * obj->mtx[0][1] * obj->mtx[0][1]) + \
			(obj->c * obj->mtx[0][2] * obj->mtx[0][2]);
	w->var2 = (obj->a * obj->mtx[1][0] * obj->mtx[1][0]) + \
			(obj->b * obj->mtx[1][1] * obj->mtx[1][1]) + \
			(obj->c * obj->mtx[1][2] * obj->mtx[1][2]);
	w->var3 = (obj->a * obj->mtx[2][0] * obj->mtx[2][0]) + \
			(obj->b * obj->mtx[2][1] * obj->mtx[2][1]) + \
			(obj->c * obj->mtx[2][2] * obj->mtx[2][2]);
	w->var4 = ((obj->mtx[0][0] * obj->mtx[1][0] * obj->a) + \
			(obj->mtx[0][1] * obj->mtx[1][1] * obj->b) + \
			(obj->mtx[0][2] * obj->mtx[1][2] * obj->c));
	ft_hit_obj_init_part(obj, w);
	return (w);
}
