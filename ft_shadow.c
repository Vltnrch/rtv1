/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shadow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/19 21:22:36 by vroche            #+#    #+#             */
/*   Updated: 2015/09/28 17:38:05 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_vect	**ft_initvect_spot(t_env *env, t_spot *spot, double k)
{
	t_vect	*v0;
	t_vect	*vdir;
	t_vect	**vect;

	vect = (t_vect **)malloc(2 * sizeof(t_vect *));
	v0 = (t_vect *)malloc(sizeof(t_vect));
	vdir = (t_vect *)malloc(sizeof(t_vect));
	vect[0] = v0;
	vect[1] = vdir;
	v0->x = spot->pos.x;
	v0->y = spot->pos.y;
	v0->z = spot->pos.z;
	vdir->x = +k * PX - spot->pos.x;
	vdir->y = +k * PY - spot->pos.y;
	vdir->z = (1 - k) * PZ - spot->pos.z;
	return (vect);
}

static int		ft_check_shadow_part(t_vect **vect, t_object *obj, \
									t_object *object)
{
	double	k2;

	if (obj != object)
	{
		if (object->type != PLAN && ft_hit_obj(object, &k2, vect))
		{
			if (k2 < 1)
				return (1);
		}
		else if (object->type == PLAN && ft_hit_plan(object, &k2, vect))
		{
			if (k2 < 1)
				return (1);
		}
		free(vect[0]);
		free(vect[1]);
		free(vect);
	}
	return (0);
}

int				ft_check_shadow(t_env *env, double k, t_object *obj, \
								t_list *lspots)
{
	t_list		*lobjects;
	t_object	*object;
	int			touch;
	t_vect		**vect;

	touch = 0;
	if (lspots->next != NULL)
		touch = ft_check_shadow(env, k, obj, lspots->next);
	lobjects = env->lobjects;
	while (lobjects)
	{
		object = lobjects->content;
		vect = ft_initvect_spot(env, lspots->content, k);
		if (ft_check_shadow_part(vect, obj, object))
			return (++touch);
		lobjects = lobjects->next;
	}
	return (touch);
}
