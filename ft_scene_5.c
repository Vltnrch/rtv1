/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/20 14:20:54 by vroche            #+#    #+#             */
/*   Updated: 2015/10/09 13:56:34 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	ft_init_object_5(t_env *env)
{
	t_object	*cone;
	t_object	*plan;

	cone = ft_coor_equ_obj(1, -(tan(30 * M_PI / 180) * tan(30 * M_PI / 180))\
							, 1, 0);
	ft_initobj_matrix(cone, 0 * M_PI / 180, 0 * M_PI / 180);
	ft_color_obj(cone, 0x00, 0xFF, 0xFF);
	ft_pos_obj(cone, 0, 0, 2500);
	cone->w = ft_hit_obj_init(cone);
	ft_add_obj(env, cone, CONE);
	plan = ft_coor_equ_obj(0, 1, 0, -300);
	ft_color_obj(plan, 0x00, 0x00, 0xFF);
	ft_add_obj(env, plan, PLAN);
}

static void	ft_init_spot_5(t_env *env)
{
	t_spot	spot1;

	spot1.pos.x = 500;
	spot1.pos.y = 0;
	spot1.pos.z = -1500;
	spot1.color.r = 0xFF;
	spot1.color.g = 0xFF;
	spot1.color.b = 0xFF;
	ft_add_spot(env, &spot1);
}

void		ft_scene_5(t_env *env)
{
	ft_init_object_5(env);
	ft_init_spot_5(env);
	ft_printf("One cone, a plan with one spot\n");
}
