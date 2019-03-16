/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_init_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 13:56:26 by prippa            #+#    #+#             */
/*   Updated: 2019/02/23 13:56:28 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <sys/stat.h>
#include "messages.h"

#define PRINT_INTRO_F "--intro"
#define AITYS_MUSIC_F "--music"

static void	sl_check_flags(char ***argv)
{
	while (**argv)
	{
		if (ft_strequ(**argv, PRINT_INTRO_F))
			sl()->print_intro = true;
		else if (ft_strequ(**argv, AITYS_MUSIC_F))
		{
			if (!(sl_init_song(argv)))
				break ;
		}
		else
			break ;
		++(*argv);
	}
}

static void	sl_set_default_color(t_argument *arg)
{
	arg->color_type = F_NONE;
	arg->color = F_NONE;
}

static void	sl_set_color(const char *file, t_argument *arg)
{
	struct stat	sb;

	if (lstat(file, &sb) == OK)
	{
		if (S_ISLNK(sb.st_mode))
		{
			arg->color_type = F_NONE;
			arg->color = C_MAGENTA;
		}
		else if (S_ISDIR(sb.st_mode))
		{
			arg->color_type = CT_BOLD;
			arg->color = C_CYAN;
		}
		else if (sb.st_mode & S_IXUSR)
		{
			arg->color_type = F_NONE;
			arg->color = C_RED;
		}
		else
			sl_set_default_color(arg);
	}
	else
		sl_set_default_color(arg);
}

void		sl_init_args(char **argv)
{
	t_argument	arg;
	t_list2		*new_obj;

	sl_check_flags(&argv);
	if (!*argv)
		sl_init_fatal_err_exit(SL_USAGE);
	while (*argv)
	{
		ft_bzero(&arg, sizeof(t_argument));
		if (!(arg.name = ft_strdup(*argv)))
			ft_perror_exit(MALLOC_ERR);
		sl_set_color(*argv, &arg);
		if (!(new_obj = ft_lst2new(&arg, sizeof(t_argument))))
			ft_perror_exit(MALLOC_ERR);
		ft_lst2_push_back(&sl()->args_start, &sl()->args_end, new_obj);
		++argv;
	}
	((t_argument *)sl()->args_start->content)->chosen_one = true;
}
