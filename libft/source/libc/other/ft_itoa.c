/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:59:31 by prippa            #+#    #+#             */
/*   Updated: 2017/11/06 13:59:40 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_def.h"
#include "ft_other.h"
#include "ft_str.h"

char	*ft_itoa(int32_t n)
{
	char		*new_obj;
	uint16_t	size;

	size = ft_nbrlen(n);
	size += (n < 0 ? 1 : 0);
	if (!(new_obj = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	new_obj[size] = 0;
	new_obj[0] = (n < 0 ? '-' : '0');
	while (n)
	{
		new_obj[--size] = ABS((n % 10)) + '0';
		n /= 10;
	}
	return (new_obj);
}

char	*ft_itoa_max(intmax_t n)
{
	char		*new_obj;
	uint16_t	size;

	size = ft_nbrlen(n);
	size += (n < 0 ? 1 : 0);
	if (!(new_obj = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	new_obj[size] = 0;
	new_obj[0] = (n < 0 ? '-' : '0');
	while (n)
	{
		new_obj[--size] = ABS((n % 10)) + '0';
		n /= 10;
	}
	return (new_obj);
}

char	*ft_itoa_base(uintmax_t num, int32_t base, int32_t letter)
{
	int32_t		i;
	uintmax_t	tmp;
	uintmax_t	op;
	char		buf[65];

	if (base < 2 || base > 16)
		return (NULL);
	buf[64] = 0;
	if (num == 0)
		return (ft_strdup("0"));
	tmp = num;
	i = 64;
	while (tmp)
	{
		op = tmp % base;
		tmp = tmp / base;
		i--;
		if (base > 10 && op > 9)
			buf[i] = op + letter;
		else
			buf[i] = op + 48;
	}
	return (ft_strdup(buf + i));
}
