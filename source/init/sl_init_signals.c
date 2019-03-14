/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_init_signals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:22:00 by prippa            #+#    #+#             */
/*   Updated: 2019/03/14 15:22:02 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <signal.h>

static void	sl_sig_hendler(int32_t sig)
{
	if (sig == SIGWINCH)
		sl_print_all();
	else
		sl_exit(EXIT_FAILURE);
}

void		sl_init_signals(void)
{
	signal(SIGINT, sl_sig_hendler);
	signal(SIGWINCH, sl_sig_hendler);
}
