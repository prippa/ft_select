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

t_select	g_sl;

#define SL_USAGE "Usage: ft_select [arg1 arg2 arg3 ...]"



void		sl_init(int argc, char **argv)
{
	if (argc == 1)
		ft_fatal_err_exit(SL_USAGE);
	ft_bzero(&g_sl, sizeof(t_select));
	sl_init_args(argv + 1);
}
