/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count2darray.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 00:16:56 by caking            #+#    #+#             */
/*   Updated: 2018/12/19 00:16:58 by caking           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count2darray(char **arr)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (arr[++i])
		count++;
	return (count);
}