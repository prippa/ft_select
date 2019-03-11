/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 13:08:27 by prippa            #+#    #+#             */
/*   Updated: 2019/02/23 13:08:29 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "../libft/includes/libc/libft.h"
# include "../libft/includes/printf/ft_printf.h"
# include <termios.h>

typedef struct		s_argument
{
	char			*name;
	int32_t			color;
	t_bool			selected;
}					t_argument;

typedef struct		s_select
{
	struct termios	oldtio;
	struct termios	newtio;
	int32_t			fd;
	char			*termtype;
	t_list2			*args_start;
	t_list2			*args_end;
}					t_select;

t_select			*sl(void);

void				sl_init(int argc, char **argv);
void				sl_init_args(char **argv);
void				sl_fatal_exit(const char *message, t_bool set_oldtio_flag);

#endif
