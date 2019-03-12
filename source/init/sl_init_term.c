/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_init_term.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 13:31:46 by prippa            #+#    #+#             */
/*   Updated: 2019/03/12 13:31:48 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "messages.h"
#include <fcntl.h>

static void	sl_set_new_attr(void)
{
	if ((tcgetattr(STDIN_FILENO, &sl()->base_attr)) == ERR)
		sl_init_fatal_err_exit("tcgetattr() failed");
	if ((tcgetattr(STDIN_FILENO, &sl()->new_attr)) == ERR)
		sl_init_fatal_err_exit("tcgetattr() failed");
	sl()->new_attr.c_lflag &= ~(ICANON | ECHO);
	// sl()->new_attr.c_oflag &= ~(OPOST);
	sl()->new_attr.c_cc[VMIN] = 1;
	sl()->new_attr.c_cc[VTIME] = 0;
	if ((tcsetattr(STDIN_FILENO, TCSANOW, &sl()->new_attr)) == ERR)
		sl_init_fatal_err_exit("tcsetattr() failed");
}

void		sl_init_term(void)
{
	int32_t	res;

	if (!isatty(STDIN_FILENO))
		sl_init_fatal_err_exit(NOT_A_TERM);
	if (!(sl()->termtype = getenv("TERM")))
		sl_init_fatal_err_exit(MSG(NO_TERM, NULL));
	if ((res = tgetent(NULL, sl()->termtype)) == ERR)
		sl_init_fatal_err_exit(NO_ACCESS_TO_DB);
	else if (res == 0)
		sl_init_fatal_err_exit(MSG(NO_SUCH_ENTRY, sl()->termtype));
	sl_set_new_attr();
	tputs(tgetstr("ti", NULL), 1, sl_print_key);
	tputs(tgetstr("vi", NULL), 1, sl_print_key);
}
