#include "ft_select.h"
#include "messages.h"

void		sl_fatal_exit(const char *message, t_bool set_oldtio_flag)
{
	if (set_oldtio_flag)
	{

	}
	ft_dprintf(STDERR_FILENO, SL_ERROR, message);
	ft_putendl_fd(EMPTY_STR, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

