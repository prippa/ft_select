/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isuppercase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:05:37 by prippa            #+#    #+#             */
/*   Updated: 2017/11/09 15:11:28 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdint.h>

int32_t	ft_isupper(int32_t c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}
