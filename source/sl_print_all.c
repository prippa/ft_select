/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_print_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 16:18:59 by prippa            #+#    #+#             */
/*   Updated: 2019/03/13 16:19:00 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "messages.h"
#include <sys/ioctl.h>

#define SEPARATOR_SIZE 2

// void	print_list(t_list2 *elem) // debug
// {
// 	t_argument *arg;

// 	arg = (t_argument *)elem->content;
// 	ft_dprintf(STDIN_FILENO, "%s%s%~s\n",
// 		(arg->selected ? BACK : EMPTY_STR),
// 		(arg->chosen_one ? UNDER_LINE : EMPTY_STR),
// 		arg->color_type,
// 		arg->color,
// 		arg->name);
// }

static size_t	sl_get_max_len(t_list2 *start)
{
	size_t	max;
	size_t	tmp;

	max = ft_strlen(((t_argument *)start->content)->name);
	while (start->next)
	{
		if ((tmp = ft_strlen(((t_argument *)start->next->content)->name)) > max)
			max = tmp;
		start = start->next;
	}
	return (max);
}

static void		sl_print_list(uint16_t col_size, size_t width, t_list2 *start)
{
	uint16_t	cs_save;
	t_argument	*arg;

	cs_save = col_size;
	while (start)
	{
		if (!col_size)
		{
			col_size = cs_save;
			ft_putendl_fd(EMPTY_STR, STDIN_FILENO);
		}
		arg = (t_argument *)start->content;
		ft_dprintf(STDIN_FILENO, "%s%s%~s",
			(arg->selected ? BACK : EMPTY_STR),
			(arg->chosen_one ? UNDER_LINE : EMPTY_STR),
			arg->color_type,
			arg->color,
			arg->name);
		ft_dprintf(STDIN_FILENO, "%*c", width - ft_strlen(arg->name), ' ');
		start = start->next;
		--col_size;
	}
}

void			sl_print_all(void)
{
	struct winsize	w;
	size_t			width;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &w);
	width = sl_get_max_len(sl()->args_start) + SEPARATOR_SIZE;
	sl()->col_size = w.ws_col / width;
	sl_print_list(sl()->col_size, width, sl()->args_start);
	// ft_dprintf(STDIN_FILENO, "col - %zu  row - %zu\n", w.ws_col, w.ws_row);
	// ft_dprintf(STDIN_FILENO, "col_size - %zu\n", col_size);	
	// ft_lst2iter(sl()->args_start, print_list); // debug
}
