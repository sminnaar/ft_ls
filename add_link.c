#include "list.h"

t_link	*add_link(t_link *list, char *str)
{
	t_link *tmp;

	tmp = malloc(sizeof(t_link));
	if (tmp)
	{
		tmp->str = str;
		tmp->next = list;
	}
	return (tmp);
}
