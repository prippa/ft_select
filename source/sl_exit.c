#include "ft_select.h"
#include "messages.h"

void		sl_exit(int32_t exit_code)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &sl()->base_attr);
	tputs(tgetstr("ve", NULL), 1, sl_print_key);
	tputs(tgetstr("te", NULL), 1, sl_print_key);
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
