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
#include "messages.h"

t_select	*sl(void)
{
	static t_select sl;

	return (&sl);
}

#ifdef unix
static char term_buffer[2048];
#else
#define term_buffer 0
#endif

init_terminal_data ()
{
  char *termtype = getenv ("TERM");
  int success;

  if (termtype == 0)
    fatal ("Specify a terminal type with 'setenv TERM <yourtype>'.\n");

  success = tgetent (term_buffer, termtype);
  if (success < 0)
    fatal ("Could not access the termcap data base.\n");
  if (success == 0)
    fatal ("Terminal type `%s' is not defined.\n", termtype);
}

static void	sl_init_term(void)
{
	if (!(sl()->termtype = getenv("TERM")))
		sl_fatal_exit(NO_TERM, false);
	
}

void		sl_init(int argc, char **argv)
{
	if (argc == 1)
		ft_fatal_err_exit(SL_USAGE);
	ft_bzero(sl(), sizeof(t_select));
	sl()->fd = STDIN_FILENO;
	sl_init_args(argv + 1);
}
