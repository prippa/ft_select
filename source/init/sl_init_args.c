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

static void sl_set_default_color(t_argument *arg)
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

void			sl_init_args(char **argv)
{
	t_argument	arg;
	t_list2		*new_obj;

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
