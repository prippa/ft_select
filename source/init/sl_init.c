/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 13:23:55 by prippa            #+#    #+#             */
/*   Updated: 2019/02/23 13:23:56 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_select	*sl(void)
{
	static t_select sl;

	return (&sl);
}

void		sl_init(int argc, char **argv)
{
	(void)argc;
	ft_bzero(sl(), sizeof(t_select));
	sl_init_args(argv);
	sl_init_term();
	sl_init_signals();
}
