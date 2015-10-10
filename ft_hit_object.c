/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hit_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 11:10:36 by vroche            #+#    #+#             */
/*   Updated: 2015/09/19 18:38:21 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static double	ft_hit_obj_a(t_work *w, t_vect **vect)
{
	return ((w->var1 * vect[1]->x * vect[1]->x) + \
			(w->var2 * vect[1]->y * vect[1]->y) + \
			(w->var3 * vect[1]->z * vect[1]->z) + \
			2 * ((vect[1]->x * vect[1]->y * w->var4) + \
				(vect[1]->x * vect[1]->z * w->var5) + \
				(vect[1]->y * vect[1]->z * w->var6)));
}

static double	ft_hit_obj_b(t_work *w, t_vect **vect)
{
	return (2 * ((vect[0]->x * vect[1]->x * w->var1) + \
		(vect[0]->y * vect[1]->y * w->var2) + \
		(vect[0]->z * vect[1]->z * w->var3) + \
		((vect[0]->x * vect[1]->y + vect[0]->y * vect[1]->x) * w->var4) + \
		((vect[0]->x * vect[1]->z + vect[0]->z * vect[1]->x) * w->var5) + \
		((vect[0]->y * vect[1]->z + vect[0]->z * vect[1]->y) * w->var6) \
		- (vect[1]->x * w->var7) - (vect[1]->y * w->var8) - \
		(vect[1]->z * w->var9)));
}

static double	ft_hit_obj_c(t_work *w, t_vect **vect)
{
	return ((w->var1 * vect[0]->x * vect[0]->x) + \
		(w->var2 * vect[0]->y * vect[0]->y) + \
		(w->var3 * vect[0]->z * vect[0]->z) + \
		2 * ((w->var4 * vect[0]->x * vect[0]->y) + \
			(w->var5 * vect[0]->x * vect[0]->z) + \
			(w->var6 * vect[0]->y * vect[0]->z) \
			- (w->var7 * vect[0]->x) - (w->var8 * vect[0]->y) - \
			(w->var9 * vect[0]->z)) + w->var10);
}

int				ft_hit_obj(t_object *obj, double *k, t_vect **vect)
{
	double	a;
	double	b;
	double	c;
	double	delta;

	a = ft_hit_obj_a(obj->w, vect);
	b = ft_hit_obj_b(obj->w, vect);
	c = ft_hit_obj_c(obj->w, vect);
	delta = (b * b) - (4 * a * c);
	if (!(delta >= 0.000001))
		return (0);
	*k = (-b - sqrt(delta)) / (2 * a);
	c = (-b + sqrt(delta)) / (2 * a);
	if (c < *k)
		*k = c;
	return (1);
}

int				ft_hit_plan(t_object *plan, double *k, t_vect **vect)
{
	double	a;
	double	b;

	b = plan->a * vect[1]->x + plan->b * vect[1]->y + plan->c * vect[1]->z;
	if (b <= 0.000001 && b >= 0.000001)
		return (0);
	a = -(plan->a * vect[0]->x + plan->b * vect[0]->y + \
		plan->c * vect[0]->z + plan->d);
	*k = a / b;
	if (!(*k >= 0.000001))
		return (0);
	return (1);
}
