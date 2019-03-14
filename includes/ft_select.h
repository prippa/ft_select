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

# include "libft.h"
# include "ft_printf.h"
# include <termios.h>
# include <term.h>

typedef struct		s_point
{
	uint16_t		y;
	uint16_t		x;
}					t_point;

typedef struct		s_argument
{
	char			*name;
	int32_t			color;
	int32_t			color_type;
	t_bool			selected;
	t_bool			chosen_one;
	t_point			p;
}					t_argument;

typedef struct		s_select
{
	struct termios	base_attr;
	struct termios	new_attr;
	char			*termtype;
	t_list2			*args_start;
	t_list2			*args_end;
	uint16_t		col_size;
	uint16_t		row_size;
	t_bool			ok_size_of_window;
}					t_select;

t_select			*sl(void);

void				sl_init(int argc, char **argv);
void				sl_init_term(void);
void				sl_init_args(char **argv);

void				sl_exit(int32_t exit_code);
void				sl_fatal_err_exit(const char *message);
void				sl_init_fatal_err_exit(const char *message);

void				sl_key_events(int64_t key);

void				sl_goto(int32_t y, int32_t x);
int32_t				sl_print_key(int32_t n);
void				sl_del_arg(void *content, size_t content_size);
void				sl_set_base_settings(void);

void				sl_print_all(void);
void				sl_print_elem(t_list *elem);

#endif
