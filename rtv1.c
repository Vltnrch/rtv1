/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 17:58:30 by vroche            #+#    #+#             */
/*   Updated: 2015/09/28 19:01:09 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_vect	**ft_initvect_cam(t_env *env)
{
	t_vect	*v0;
	t_vect	*vdir;
	t_vect	**vect;

	vect = (t_vect **)malloc(2 * sizeof(t_vect *));
	v0 = (t_vect *)malloc(sizeof(t_vect));
	vdir = (t_vect *)malloc(sizeof(t_vect));
	vect[0] = v0;
	vect[1] = vdir;
	v0->x = env->eyes.x;
	v0->y = env->eyes.y;
	v0->z = env->eyes.z;
	vdir->x = PX - env->eyes.x;
	vdir->y = PY - env->eyes.y;
	vdir->z = -PZ;
	return (vect);
}

void			ft_rtv1_part2(t_object *obj, t_vect **vect, \
							t_object **vtmp, double *dtmp)
{
	double		k;
	int			touch;

	touch = 0;
	if (obj->type != PLAN && ft_hit_obj(obj, &k, vect))
		touch = 1;
	else if (obj->type == PLAN && ft_hit_plan(obj, &k, vect))
		touch = 1;
	if (touch == 1)
	{
		if (!*vtmp || k < *dtmp)
		{
			*dtmp = k;
			*vtmp = obj;
		}
	}
}

void			ft_rtv1_part1(t_env *env, t_list *lobjects, t_vect **vect)
{
	t_object	*vtmp;
	int			color;
	double		dtmp;

	vtmp = NULL;
	dtmp = 0;
	while (lobjects)
	{
		ft_rtv1_part2(lobjects->content, vect, &vtmp, &dtmp);
		lobjects = lobjects->next;
	}
	free(vect[0]);
	free(vect[1]);
	free(vect);
	if (vtmp != NULL)
	{
		color = ft_calc_lum(env, dtmp, vtmp, env->lspots);
		ft_put_pixel_to_image(color, env, env->px, env->py);
	}
}

void			ft_rtv1(t_env *env)
{
	env->py = 0;
	while (env->py < HEIGHT)
	{
		env->px = 0;
		while (env->px < LENGHT)
		{
			ft_rtv1_part1(env, env->lobjects, ft_initvect_cam(env));
			env->px++;
		}
		env->py++;
	}
}
