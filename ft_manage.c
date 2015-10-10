/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 11:10:36 by vroche            #+#    #+#             */
/*   Updated: 2015/09/28 19:01:18 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_put_pixel_to_image (all is said)
** ft_expose : put image to window
** ft_perror_exit to manage error message and exit program
*/

#include "rtv1.h"

void	ft_put_pixel_to_image(size_t img_color, t_env *env, int x, int y)
{
	char	*pixel;

	if (!(x >= 0 && x < LENGHT && y >= 0 && y < HEIGHT))
		return ;
	pixel = env->data + y * env->sizeline + x * env->bpp / 8;
	*pixel++ = (img_color & 0xFF);
	*pixel++ = (img_color & 0xFF00) >> 8;
	*pixel++ = (img_color & 0xFF0000) >> 16;
	*pixel = (img_color & 0xFF000000) >> 24;
}

int		ft_expose(t_env *env)
{
	if (!mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0))
		ft_perror_exit("mlx_put_image_to_window fails\n");
	return (0);
}

void	ft_perror_exit(const char *str)
{
	ft_dprintf(2, "Error: %s\n", str);
	exit(EXIT_FAILURE);
}
