/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_intro.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 10:19:29 by prippa            #+#    #+#             */
/*   Updated: 2019/03/16 10:19:47 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_INTRO_H
# define PRINT_INTRO_H

# include "ft_select.h"

# define INFO_ROWS_SIZE 9
# define INFO_COL_SIZE 50
# define SEPARATORS 4
# define FRAME_SIZE 3
# define INTRO_ROW_SIZE 7
# define INTRO_COL_SIZE 106
# define INTRO_80S_ROW_SIZE 4
# define INTRO_80S_COL_SIZE 69

# define BACK_80S_USLEEP		50000
# define FRAME_USLEEP			3500
# define NAME_UP_TO_DOWN_USLEEP	45000
# define NAME_DOWN_TO_UP_USLEEP	4000
# define INFO_SLEEP				20000

void			sl_print_80s(t_point p);
void			sl_print_frame(t_point p);
void			sl_print_name(t_point p);
void			sl_print_info(t_point p);

#endif
