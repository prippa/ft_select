/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:20:28 by prippa            #+#    #+#             */
/*   Updated: 2019/02/11 13:17:23 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE	80

# include <stdint.h>
# include <stdlib.h>

# define GNL_FAILED	"get_next_line() failed"

typedef	struct		s_gnl
{
	char			*s;
	size_t			i;
	int32_t			fd;
	struct s_gnl	*next;
}					t_gnl;

int32_t				get_next_line(const int32_t fd, char **line);

#endif
