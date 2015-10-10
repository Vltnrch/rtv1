/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/09 18:15:06 by vroche            #+#    #+#             */
/*   Updated: 2015/10/09 16:43:38 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	ft_usage(void)
{
	ft_dprintf(2, "usage: rtv1 [1-9]\n");
	exit(0);
}

static void	ft_check_scene(char *av, t_env *env)
{
	if (ft_strcmp(av, "1") == 0)
		ft_scene_1(env);
	else if (ft_strcmp(av, "2") == 0)
		ft_scene_2(env);
	else if (ft_strcmp(av, "3") == 0)
		ft_scene_3(env);
	else if (ft_strcmp(av, "4") == 0)
		ft_scene_4(env);
	else if (ft_strcmp(av, "5") == 0)
		ft_scene_5(env);
	else if (ft_strcmp(av, "6") == 0)
		ft_scene_6(env);
	else if (ft_strcmp(av, "7") == 0)
		ft_scene_7(env);
	else if (ft_strcmp(av, "8") == 0)
		ft_scene_8(env);
	else if (ft_strcmp(av, "9") == 0)
		ft_scene_9(env);
	else
		ft_usage();
}

static void	ft_init_env(t_env *env)
{
	env->lobjects = NULL;
	env->lspots = NULL;
	env->eyes.x = 0;
	env->eyes.y = 0;
	env->eyes.z = -LENGHT / (2 * tan(ANGLE / 2));
}

int			main(int ac, char **av)
{
	t_env	env;

	if (ac != 2)
		ft_usage();
	ft_init_env(&env);
	ft_check_scene(av[1], &env);
	if (!(env.mlx = mlx_init()))
		ft_perror_exit("mlx_init() fails\n");
	if (!(env.win = mlx_new_window(env.mlx, LENGHT, HEIGHT, "rtv1")))
		ft_perror_exit("mlx_new_window() fails to create a new window\n");
	if (!(env.img = mlx_new_image(env.mlx, LENGHT, HEIGHT)))
		ft_perror_exit("mlx_new_image() fails\n");
	env.data = mlx_get_data_addr(env.img, &(env.bpp), \
				&(env.sizeline), &(env.endian));
	ft_rtv1(&env);
	mlx_expose_hook(env.win, ft_expose, &env);
	mlx_key_hook(env.win, key_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}
