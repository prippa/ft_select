/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tostrlowercase.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:24:42 by prippa            #+#    #+#             */
/*   Updated: 2017/11/09 15:25:26 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_to.h"
#include "ft_is.h"

void	ft_to_str_lower(char **str)
{
	char *tmp;

	tmp = *str;
	while (*tmp)
	{
		if (ft_isupper(*tmp))
			*tmp = ft_tolower(*tmp);
		++tmp;
	}
}
