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
#include <sys/ioctl.h>
#include <signal.h>

static void	sl_ctrl_z(void)
{
	sl_set_base_settings();
	signal(SIGTSTP, SIG_DFL);
	ioctl(STDIN_FILENO, TIOCSTI, "\x1A");
}

void		sl_sig_hendler(int32_t sig)
{
	if (sig == SIGWINCH)
		sl_print_all();
	else if (sig == SIGTSTP)
		sl_ctrl_z();
	else if (sig == SIGCONT)
	{
		sl_init_term();
		sl_init_signals();
		sl_print_all();
	}
	else
		sl_exit(EXIT_FAILURE);
}

void		sl_init_signals(void)
{
	if (sl()->print_intro)
		signal(SIGWINCH, sl_print_window_rwh);
	else
		signal(SIGWINCH, sl_sig_hendler);
	signal(SIGINT, sl_sig_hendler);
	signal(SIGCONT, sl_sig_hendler);
	signal(SIGTSTP, sl_sig_hendler);
	signal(SIGABRT, sl_sig_hendler);
	signal(SIGSTOP, sl_sig_hendler);
	signal(SIGKILL, sl_sig_hendler);
	signal(SIGQUIT, sl_sig_hendler);
}
