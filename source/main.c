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
#include "keys.h"

void	print_list(t_list2 *elem) // debug
{
	t_argument *arg;

	arg = (t_argument *)elem->content;
	if (arg->chosen_one)
		ft_dprintf(STDIN_FILENO, "%~s\n", F_BACK_RED_WHITE, arg->name);
	else
		ft_dprintf(STDIN_FILENO, "%~s\n", arg->color, arg->name);
}

static void	sl_loop(void)
{
	int64_t key;

	while (true)
	{
		key = 0;
		if ((read(STDIN_FILENO, &key, 8)) == ERR)
			sl_fatal_err_exit(READ_ERR);
		tputs(tgetstr("cl", NULL), 1, sl_print_key);
		ft_lst2iter(sl()->args_start, print_list); // debug
		sl_key_events(key);
		// ft_dprintf(0, "[%lld]\n", key); // debug
	}

}

int			main(int argc, char **argv)
{
	sl_init(argc, argv);
	sl_loop();
	sl_exit(EXIT_SUCCESS);
}
