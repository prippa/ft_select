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
		sl_key_events(key);
	}
}

int			main(int argc, char **argv)
{
	++argv;
	sl_init(argc, argv);
	if (sl()->print_intro)
		sl_print_intro();
	sl_loop();
	sl_exit(EXIT_SUCCESS);
}
