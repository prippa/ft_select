#include "ft_select.h"
#include "messages.h"

void		sl_exit(int32_t exit_code)
{
	sl_set_base_settings();
	exit(exit_code);
}

static void	sl_print_err(const char *message)
{
	ft_dprintf(STDERR_FILENO, SL_ERROR, message);
	ft_putendl_fd(EMPTY_STR, STDERR_FILENO);
}

void		sl_fatal_err_exit(const char *message)
{
	sl_print_err(message);
	sl_exit(EXIT_FAILURE);
}

void		sl_init_fatal_err_exit(const char *message)
{
	sl_print_err(message);
	exit(EXIT_FAILURE);
}
