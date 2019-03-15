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
#include "keys.h"
#include <math.h>

#define SEPARATOR_SIZE 1

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

static void		sl_set_coords(size_t width, t_list2 *start)
{
	t_point		p;

	ft_bzero(&p, sizeof(t_point));
	while (start)
	{
		((t_argument *)start->content)->p = p;
		if (p.y + 1 < sl()->row_size)
			++p.y;
		else
		{
			p.y = 0;
			p.x += width;
		}
		start = start->next;
	}
}

static t_bool	sl_print_all_logic(void)
{
	size_t			width;
	size_t			col_size;
	size_t			row_size;

	width = sl_get_max_len(sl()->args_start) + SEPARATOR_SIZE;
	if ((col_size = sl_ws_col() / width) == 0)
		return (false);
	row_size = (size_t)ceil(
		(double)ft_lstsize((t_list *)sl()->args_start) / col_size);
	if (row_size >= sl_ws_row())
		return (false);
	sl()->col_size = (uint16_t)col_size;
	sl()->row_size = (uint16_t)row_size;
	sl_set_coords(width, sl()->args_start);
	return (true);
}

void			sl_print_elem(t_list *elem)
{
	t_argument *arg;

	if (!sl()->ok_size_of_window)
		return ;
	arg = (t_argument *)elem->content;
	sl_goto(arg->p.y, arg->p.x);
	ft_dprintf(STDIN_FILENO, "%s%s%~s\n",
		(arg->selected ? BACK : EMPTY_STR),
		(arg->chosen_one ? UNDER_LINE : EMPTY_STR),
		arg->color_type,
		arg->color,
		arg->name);
}

void			sl_print_all(void)
{
	tputs(tgetstr("cl", NULL), 1, sl_print_key);
	if (sl_print_all_logic() == false)
	{
		ft_putstr_fd(NO_ROOM, STDIN_FILENO);
		sl()->ok_size_of_window = false;
		return ;
	}
	sl()->ok_size_of_window = true;
	ft_lstiter((t_list *)sl()->args_start, sl_print_elem);
}
