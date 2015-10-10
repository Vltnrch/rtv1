/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/19 22:08:59 by vroche            #+#    #+#             */
/*   Updated: 2015/10/09 13:45:07 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	ft_init_object_2(t_env *env)
{
	t_object	*cylinder;

	cylinder = ft_coor_equ_obj(1, 0, 1, -(200 * 200));
	ft_initobj_matrix(cylinder, 0 * M_PI / 180, 0 * M_PI / 180);
	ft_color_obj(cylinder, 0x00, 0xFF, 0x00);
	ft_pos_obj(cylinder, 0, 0, 1000);
	cylinder->w = ft_hit_obj_init(cylinder);
	ft_add_obj(env, cylinder, CYLINDER);
}

static void	ft_init_spot_2(t_env *env)
{
	t_spot	spot1;

	spot1.pos.x = 500;
	spot1.pos.y = 0;
	spot1.pos.z = -300;
	spot1.color.r = 0xFF;
	spot1.color.g = 0xFF;
	spot1.color.b = 0xFF;
	ft_add_spot(env, &spot1);
}

void		ft_scene_2(t_env *env)
{
	ft_init_object_2(env);
	ft_init_spot_2(env);
	ft_printf("One cylinder with one spot\n");
}
