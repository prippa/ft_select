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

#define STAT_FAILED "stat failed"

static int32_t	sl_get_color(const char *file)
{
	struct stat	sb;

	if ((stat(file, &sb)) == ERR)
		ft_fatal_err_exit(STAT_FAILED);
	if (S_ISDIR(sb.st_mode))
		return (F_BOLD_CYAN);
	if (sb.st_mode & S_IXUSR)
		return (F_RED);
	return (F_WHITE);

}

void			sl_init_args(char **argv)
{
	t_argument	arg;
	t_list2		*new_obj;

	while (*argv)
	{
		ft_bzero(&arg, sizeof(t_argument));
		if (!(arg.name = ft_strdup(*argv)))
			ft_fatal_err_exit(MALLOC_ERR);
		arg.color = sl_get_color(*argv);
		if (!(new_obj = ft_lst2new(&arg, sizeof(t_argument))))
			ft_fatal_err_exit(MALLOC_ERR);
		ft_lst2_push_back(&g_sl.args_start, &g_sl.args_end, new_obj);
		++argv;
	}
}