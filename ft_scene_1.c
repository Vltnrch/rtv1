/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/19 21:55:27 by vroche            #+#    #+#             */
/*   Updated: 2015/10/09 13:43:37 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	ft_init_object_1(t_env *env)
{
	t_object	*sphere;

	sphere = ft_coor_equ_obj(1, 1, 1, -(200 * 200));
	ft_initobj_matrix(sphere, 0 * M_PI / 180, 0 * M_PI / 180);
	ft_color_obj(sphere, 0xFF, 0x00, 0x00);
	ft_pos_obj(sphere, 0, 0, 1800);
	sphere->w = ft_hit_obj_init(sphere);
	ft_add_obj(env, sphere, SPHERE);
}

static void	ft_init_spot_1(t_env *env)
{
	t_spot	spot1;

	spot1.pos.x = 900;
	spot1.pos.y = -500;
	spot1.pos.z = 300;
	spot1.color.r = 0xFF;
	spot1.color.g = 0xFF;
	spot1.color.b = 0xFF;
	ft_add_spot(env, &spot1);
}

void		ft_scene_1(t_env *env)
{
	ft_init_object_1(env);
	ft_init_spot_1(env);
	ft_printf("One sphere with one spot\n");
}
