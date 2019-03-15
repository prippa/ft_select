#include "ft_select.h"

static void	sl_unselect_all_args(t_list2 *start)
{
	while (start)
	{
		((t_argument *)start->content)->selected = false;
		start = start->next;
	}
}

void		sl_ke_unselect_all(t_list2 *co)
{
	(void)co;
	sl_unselect_all_args(sl()->args_start);
	sl_print_all();
}


