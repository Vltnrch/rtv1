/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/13 18:44:15 by vroche            #+#    #+#             */
/*   Updated: 2015/06/19 17:57:55 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_list_size(t_list *begin_list)
{
	t_list	*tmp;
	int		i;

	i = 1;
	tmp = begin_list;
	if (tmp == NULL)
		return (0);
	while (tmp->next != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
