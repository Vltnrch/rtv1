/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene_8.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/09 14:07:27 by vroche            #+#    #+#             */
/*   Updated: 2015/10/09 16:38:10 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	ft_init_object_8_part2(t_env *env)
{
	t_object	*cylinder;
	t_object	*cone;

	cylinder = ft_coor_equ_obj(1, 0, 1, -(200 * 200));
	ft_initobj_matrix(cylinder, 30 * M_PI / 180, 0 * M_PI / 180);
	ft_color_obj(cylinder, 0x70, 0x73, 0x73);
	ft_pos_obj(cylinder, 300, 0, 2200);
	cylinder->w = ft_hit_obj_init(cylinder);
	ft_add_obj(env, cylinder, CYLINDER);
	cone = ft_coor_equ_obj(1, -(tan(30 * M_PI / 180) * tan(30 * M_PI / 180)), \
						1, 0);
	ft_initobj_matrix(cone, 30 * M_PI / 180, 0 * M_PI / 180);
	ft_color_obj(cone, 0x00, 0xFF, 0x00);
	ft_pos_obj(cone, 0, 0, 2200);
	cone->w = ft_hit_obj_init(cone);
	ft_add_obj(env, cone, CONE);
}

static void	ft_init_object_8(t_env *env)
{
	t_object	*sphere;
	t_object	*plan;
	t_object	*plan2;

	plan = ft_coor_equ_obj(0.53, 1, 0, -500);
	ft_color_obj(plan, 0xFF, 0x00, 0x00);
	ft_add_obj(env, plan, PLAN);
	plan2 = ft_coor_equ_obj(0, 0, 1, -4800);
	ft_color_obj(plan2, 0xFF, 100, 0x00);
	ft_add_obj(env, plan2, PLAN);
	sphere = ft_coor_equ_obj(1, 1, 1, -(200 * 200));
	ft_initobj_matrix(sphere, 30 * M_PI / 180, 0 * M_PI / 180);
	ft_color_obj(sphere, 0xFF, 0x00, 0x00);
	ft_pos_obj(sphere, -200, 0, 2500);
	sphere->w = ft_hit_obj_init(sphere);
	ft_add_obj(env, sphere, SPHERE);
	ft_init_object_8_part2(env);
}

static void	ft_init_spot_8(t_env *env)
{
	t_spot	spot1;

	spot1.pos.x = 700;
	spot1.pos.y = -800;
	spot1.pos.z = -400;
	spot1.color.r = 0xFF;
	spot1.color.g = 0xFF;
	spot1.color.b = 0xFF;
	ft_add_spot(env, &spot1);
}

void		ft_scene_8(t_env *env)
{
	ft_init_object_8(env);
	ft_init_spot_8(env);
	ft_printf("One cylinder, one cone, one sphere, \
2 plans and one spot, other view\n");
}
