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
#include <sys/ioctl.h>

uint16_t	sl_ws_col(void)
{
	struct winsize	w;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &w);
	return (w.ws_col);
}

uint16_t	sl_ws_row(void)
{
	struct winsize	w;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &w);
	return (w.ws_row);
}

void		sl_goto(int32_t y, int32_t x)
{
	ft_putstr_fd(tgoto(tgetstr("cm", NULL), x, y), STDIN_FILENO);
}

int32_t		sl_print_key(int32_t n)
{
	return (write(STDIN_FILENO, &n, 1));
}

void		sl_set_base_settings(void)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &sl()->base_attr);
	tputs(tgetstr("ve", NULL), 1, sl_print_key);
	tputs(tgetstr("te", NULL), 1, sl_print_key);
}
