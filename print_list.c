#include "list.h"

void	print_list(t_link *link)
{
	while (link)
	{
		ft_putstr(link->str);
		link = link->next;
	}
}
