/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_key_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:55:49 by prippa            #+#    #+#             */
/*   Updated: 2019/03/12 17:55:51 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "keys.h"

#define KE_SIZE 5

static const int64_t	g_keys[KE_SIZE] =
{
	ESC, UP, DOWN, RIGHT, LEFT
};

typedef void			(*t_events)(void);
static const			t_events g_ke[KE_SIZE] =
{
	sl_ke_esc, sl_ke_up, sl_ke_down, sl_ke_right, sl_ke_left
};

t_list2		*sl_ke_get_chosen_one(t_list2 *args_start)
{
	while (args_start)
	{
		if (((t_argument *)args_start->content)->chosen_one)
			return (args_start);
		args_start = args_start->next;
	}
	return (NULL);
}

void		sl_key_events(int64_t key)
{
	uint16_t i;

	i = -1;
	while (++i < KE_SIZE)
		if (g_keys[i] == key)
			g_ke[i]();
}
