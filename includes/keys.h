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

# include "ft_lst.h"

# define ESC		27
# define UP			4283163
# define DOWN		4348699
# define RIGHT		4414235
# define LEFT		4479771
# define RETURN		10
# define SPACE		32
# define BACK_SPACE	127
# define DEL		2117294875
# define CTRL_A		1
# define CTRL_W		23

void		sl_ke_esc(t_list2 *co);
void		sl_ke_up(t_list2 *co);
void		sl_ke_down(t_list2 *co);
void		sl_ke_right(t_list2 *co);
void		sl_ke_left(t_list2 *co);
void		sl_ke_return(t_list2 *co);
void		sl_ke_space(t_list2 *co);
void		sl_ke_back_space(t_list2 *co);
void		sl_ke_del(t_list2 *co);
void		sl_ke_select_all(t_list2 *co);
void		sl_ke_unselect_all(t_list2 *co);

#endif
