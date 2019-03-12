/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 15:55:41 by prippa            #+#    #+#             */
/*   Updated: 2019/03/12 15:55:42 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# define ESC 27
# define UP 4283163
# define DOWN 4348699
# define RIGHT 4414235
# define LEFT 4479771

t_list2		*sl_ke_get_chosen_one(t_list2 *args_start);

void		sl_ke_esc(void);
void		sl_ke_up(void);
void		sl_ke_down(void);
void		sl_ke_right(void);
void		sl_ke_left(void);

#endif
