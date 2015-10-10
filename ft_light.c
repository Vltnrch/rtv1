/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/19 21:26:02 by vroche            #+#    #+#             */
/*   Updated: 2015/09/28 19:12:29 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	ft_corr_color(t_env *env, t_light *light)
{
	light->color.r /= ft_list_size(env->lspots);
	light->color.g /= ft_list_size(env->lspots);
	light->color.b /= ft_list_size(env->lspots);
	light->color.r += (light->color2.r * 0.4);
	light->color.g += (light->color2.g * 0.4);
	light->color.b += (light->color2.b * 0.4);
	if (light->color.r > 255)
		light->color.r = 255;
	if (light->color.g > 255)
		light->color.g = 255;
	if (light->color.b > 255)
		light->color.b = 255;
	if (light->color.r < 0)
		light->color.r = 0;
	if (light->color.g < 0)
		light->color.g = 0;
	if (light->color.b < 0)
		light->color.b = 0;
	light->color.r /= (light->shadow + 1);
	light->color.g /= (light->shadow + 1);
	light->color.b /= (light->shadow + 1);
}

static void	ft_init_vect(t_env *env, double k, t_object *obj, t_light *light)
{
	light->n.x = +k * PX;
	light->n.y = +k * PY;
	light->n.z = (1 - k) * PZ;
	light->s.x = obj->mtxi[0][0] * light->n.x + obj->mtxi[0][1] * light->n.y + \
				obj->mtxi[0][2] * light->n.z - obj->pos.x;
	light->s.y = obj->mtxi[1][0] * light->n.x + obj->mtxi[1][1] * light->n.y + \
				obj->mtxi[1][2] * light->n.z - obj->pos.y;
	light->s.z = obj->mtxi[2][0] * light->n.x + obj->mtxi[2][1] * light->n.y + \
				obj->mtxi[2][2] * light->n.z - obj->pos.z;
	if (obj->type == CYLINDER)
		light->s.y = 0;
	else if (obj->type == CONE)
		light->s.y = sqrt(-obj->b);
	light->n.x = obj->mtx[0][0] * light->s.x + obj->mtx[0][1] * light->s.y + \
				obj->mtx[0][2] * light->s.z;
	light->n.y = obj->mtx[1][0] * light->s.x + obj->mtx[1][1] * light->s.y + \
				obj->mtx[1][2] * light->s.z;
	light->n.z = obj->mtx[2][0] * light->s.x + obj->mtx[2][1] * light->s.y + \
				obj->mtx[2][2] * light->s.z;
}

static void	ft_calc_spot_final_calc(t_object *obj, t_light *light)
{
	light->color.r += obj->color.r * 0.2 + obj->color.r * light->cosa * DIF + \
				light->spot->color.r * pow(light->cosb, POW) * SPEC + \
				light->spot->color.r * light->cosa * AMB;
	light->color.g += obj->color.g * 0.2 + obj->color.g * light->cosa * DIF + \
				light->spot->color.g * pow(light->cosb, POW) * SPEC + \
				light->spot->color.g * light->cosa * AMB;
	light->color.b += obj->color.b * 0.2 + obj->color.b * light->cosa * DIF + \
				light->spot->color.b * pow(light->cosb, POW) * SPEC + \
				light->spot->color.b * light->cosa * AMB;
	light->color2.r += light->spot->color.r * pow(light->cosb, POW) * SPEC;
	light->color2.g += light->spot->color.g * pow(light->cosb, POW) * SPEC;
	light->color2.b += light->spot->color.b * pow(light->cosb, POW) * SPEC;
	light->lspots = light->lspots->next;
}

static void	ft_calc_spot(t_env *env, double k, t_object *obj, t_light *light)
{
	while (light->lspots)
	{
		light->spot = light->lspots->content;
		light->s.x = light->spot->pos.x - k * PX;
		light->s.y = light->spot->pos.y - k * PY;
		light->s.z = light->spot->pos.z - (1 - k) * PZ;
		light->cosa = ((light->n.x * light->s.x) + (light->n.y * light->s.y) + \
			(light->n.z * light->s.z)) / sqrt(((light->n.x * light->n.x) + \
			(light->n.y * light->n.y) + (light->n.z * light->n.z)) * \
			((light->s.x * light->s.x) + \
			(light->s.y * light->s.y) + (light->s.z * light->s.z)));
		if (light->cosa < (sqrt(2) / 2) || light->shadow > 0)
			light->cosb = 0;
		else
			light->cosb = cos(acos(light->cosa) * 2);
		if (obj->type == PLAN)
			light->cosa = cos(acos(light->cosa) * 0.85);
		ft_calc_spot_final_calc(obj, light);
	}
}

int			ft_calc_lum(t_env *env, double k, t_object *obj, t_list *lspots)
{
	t_light	light;

	light.lspots = lspots;
	if (obj->type != PLAN)
		ft_init_vect(env, k, obj, &light);
	else
	{
		light.n.x = -obj->a;
		light.n.y = -obj->b;
		light.n.z = -obj->c;
	}
	light.shadow = ft_check_shadow(env, k, obj, env->lspots);
	light.color.r = 0;
	light.color.g = 0;
	light.color.b = 0;
	light.color2.r = 0;
	light.color2.g = 0;
	light.color2.b = 0;
	ft_calc_spot(env, k, obj, &light);
	ft_corr_color(env, &light);
	return (light.color.b + (light.color.g << 8) + (light.color.r << 16));
}
