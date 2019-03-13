/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 13:08:41 by prippa            #+#    #+#             */
/*   Updated: 2019/02/23 13:08:42 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	sl_loop(void)
{
	int64_t key;

	sl_print_all();
	while (true)
	{
		key = 0;
		if ((read(STDIN_FILENO, &key, 8)) == ERR)
			sl_fatal_err_exit(READ_ERR);
		tputs(tgetstr("cl", NULL), 1, sl_print_key);
		sl_key_events(key);
		sl_print_all();
		// ft_dprintf(0, "[%lld]\n", key); // debug
	}
}

int			main(int argc, char **argv)
{
	sl_init(argc, argv);
	sl_loop();
	sl_exit(EXIT_SUCCESS);
}
