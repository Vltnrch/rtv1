/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 11:10:36 by vroche            #+#    #+#             */
/*   Updated: 2015/09/20 20:51:41 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_add_obj(t_env *env, t_object *object, int type)
{
	t_list	*newlink;

	object->type = type;
	newlink = ft_lstnew((void *)object, sizeof(t_object));
	ft_lstadd_back(&(env->lobjects), newlink);
}

void	ft_add_spot(t_env *env, t_spot *spot)
{
	t_list	*newlink;

	newlink = ft_lstnew((void *)spot, sizeof(t_spot));
	ft_lstadd_back(&(env->lspots), newlink);
}
