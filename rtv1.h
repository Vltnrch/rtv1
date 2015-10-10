/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 17:18:45 by vroche            #+#    #+#             */
/*   Updated: 2015/10/09 16:43:27 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <stdlib.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"

# define LENGHT 1024
# define HEIGHT 768
# define ANGLE 120

# define SPEC 0.5
# define AMB 0.1
# define DIF 1
# define POW 20

# define PX (env->px - (LENGHT / 2))
# define PY (env->py - (HEIGHT / 2))
# define PZ (env->eyes.z)

# define SPHERE 1
# define CONE 2
# define CYLINDER 3
# define PLAN 4

typedef struct	s_vect
{
	double		x;
	double		y;
	double		z;
}				t_vect;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	int			bpp;
	int			sizeline;
	int			endian;
	char		*data;
	int			px;
	int			py;
	t_vect		eyes;
	t_list		*lobjects;
	t_list		*lspots;
}				t_env;

typedef struct	s_work
{
	double		var1;
	double		var2;
	double		var3;
	double		var4;
	double		var5;
	double		var6;
	double		var7;
	double		var8;
	double		var9;
	double		var10;
}				t_work;

typedef struct	s_object
{
	t_vect		pos;
	double		mtx[3][3];
	double		mtxi[3][3];
	double		a;
	double		b;
	double		c;
	double		d;
	int			type;
	t_color		color;
	double		cost;
	double		sint;
	double		cosp;
	double		sinp;
	t_work		*w;
}				t_object;

typedef struct	s_spot
{
	t_vect		pos;
	t_color		color;
}				t_spot;

typedef struct	s_light
{
	t_vect		n;
	t_vect		s;
	t_color		color;
	t_color		color2;
	double		cosa;
	double		cosb;
	int			shadow;
	t_spot		*spot;
	t_list		*lspots;
}				t_light;

int				ft_hit_obj(t_object *obj, double *k, t_vect **vect);
int				ft_hit_plan(t_object *plan, double *k, t_vect **vect);

void			ft_initobj_matrix(t_object *obj, double anglet, double anglep);
t_object		*ft_coor_equ_obj(double a, double b, double c, double d);
void			ft_color_obj(t_object *obj, int r, int g, int b);
void			ft_pos_obj(t_object *obj, double x, double y, double z);

t_work			*ft_hit_obj_init(t_object *obj);

int				key_hook(int keycode, t_env *env);

int				ft_calc_lum(t_env *env, double k, t_object *obj, \
							t_list *lspots);

void			ft_add_obj(t_env *env, t_object *obj, int type);
void			ft_add_spot(t_env *env, t_spot *spot);

void			ft_put_pixel_to_image(size_t color, t_env *env, int x, int y);
int				ft_expose(t_env *env);
void			ft_perror_exit(const char *str);

void			ft_scene_1(t_env *env);
void			ft_scene_2(t_env *env);
void			ft_scene_3(t_env *env);
void			ft_scene_4(t_env *env);
void			ft_scene_5(t_env *env);
void			ft_scene_6(t_env *env);
void			ft_scene_7(t_env *env);
void			ft_scene_8(t_env *env);
void			ft_scene_9(t_env *env);

int				ft_check_shadow(t_env *env, double k, t_object *obj, \
								t_list *lspots);

void			ft_rtv1(t_env *env);

#endif
