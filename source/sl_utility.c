/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 15:48:34 by prippa            #+#    #+#             */
/*   Updated: 2019/03/12 15:48:36 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int32_t		sl_print_key(int32_t n)
{
	return (write(STDIN_FILENO, &n, 1));
}

void		sl_del_arg(void *content, size_t content_size)
{
	t_argument *arg;

	arg = (t_argument *)content;
	(void)content_size;
	ft_memdel((void **)&arg->name);
}
