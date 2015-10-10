/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene_7.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/09 13:53:53 by vroche            #+#    #+#             */
/*   Updated: 2015/10/09 13:55:01 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	ft_init_object_4(t_env *env)
{
	t_object	*plan;

	plan = ft_coor_equ_obj(0, 1, 0, -500);
	ft_color_obj(plan, 0xFF, 0x00, 0x00);
	ft_add_obj(env, plan, PLAN);
}

static void	ft_init_spot_4(t_env *env)
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

void		ft_scene_4(t_env *env)
{
	ft_init_object_4(env);
	ft_init_spot_4(env);
	ft_printf("One plan with one spot\n");
}
