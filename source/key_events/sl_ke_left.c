/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_ke_left.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 18:02:51 by prippa            #+#    #+#             */
/*   Updated: 2019/03/12 18:02:52 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "keys.h"

static t_list2	*get_prev_n_obj(t_list2 *cur)
{
	uint16_t n;

	n = -1;
	while (true)
	{
		if (++n == sl()->row_size || !cur->prev)
			return (cur);
		cur = cur->prev;
	}
	return (NULL);
}

void			sl_ke_left(t_list2 *co)
{
	t_list2 *new_one;

	((t_argument *)co->content)->chosen_one = false;
	sl_print_elem((t_list *)co);
	new_one = get_prev_n_obj(co);
	((t_argument *)new_one->content)->chosen_one = true;
	sl_print_elem((t_list *)new_one);
}
