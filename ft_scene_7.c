/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene_7.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/19 21:48:20 by vroche            #+#    #+#             */
/*   Updated: 2015/10/09 16:24:43 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	ft_init_object_7_part2(t_env *env)
{
	t_object	*cylinder;
	t_object	*cone;

	cylinder = ft_coor_equ_obj(1, 0, 1, -(200 * 200));
	ft_initobj_matrix(cylinder, 30 * M_PI / 180, 0 * M_PI / 180);
	ft_color_obj(cylinder, 0x70, 0x73, 0x73);
	ft_pos_obj(cylinder, 300, 0, 1500);
	cylinder->w = ft_hit_obj_init(cylinder);
	ft_add_obj(env, cylinder, CYLINDER);
	cone = ft_coor_equ_obj(1, -(tan(30 * M_PI / 180) * tan(30 * M_PI / 180))\
							, 1, 0);
	ft_initobj_matrix(cone, -30 * M_PI / 180, 0 * M_PI / 180);
	ft_color_obj(cone, 0x00, 0xFF, 0x00);
	ft_pos_obj(cone, 50, 0, 1500);
	cone->w = ft_hit_obj_init(cone);
	ft_add_obj(env, cone, CONE);
}

static void	ft_init_object_7(t_env *env)
{
	t_object	*sphere;
	t_object	*plan;
	t_object	*plan2;

	plan = ft_coor_equ_obj(0, 1, 0, -500);
	ft_color_obj(plan, 0xFF, 0x00, 0x00);
	ft_add_obj(env, plan, PLAN);
	plan2 = ft_coor_equ_obj(0, 0, 1, -4100);
	ft_color_obj(plan2, 0xFF, 100, 0x00);
	ft_add_obj(env, plan2, PLAN);
	sphere = ft_coor_equ_obj(1, 1, 1, -(200 * 200));
	ft_initobj_matrix(sphere, 0 * M_PI / 180, 0 * M_PI / 180);
	ft_color_obj(sphere, 0xFF, 0x00, 0x00);
	ft_pos_obj(sphere, 0, 0, 1500);
	sphere->w = ft_hit_obj_init(sphere);
	ft_add_obj(env, sphere, SPHERE);
	ft_init_object_7_part2(env);
}

static void	ft_init_spot_7(t_env *env)
{
	t_spot	spot1;

	spot1.pos.x = 900;
	spot1.pos.y = -500;
	spot1.pos.z = -1000;
	spot1.color.r = 0xFF;
	spot1.color.g = 0xFF;
	spot1.color.b = 0xFF;
	ft_add_spot(env, &spot1);
}

void		ft_scene_7(t_env *env)
{
	ft_init_object_7(env);
	ft_init_spot_7(env);
	ft_printf("One cylinder, one cone, one sphere, with angle, \
2 plans and one spot\n");
}
