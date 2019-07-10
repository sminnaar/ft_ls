#include "list.h"

int	main(void)
{
	t_link *link;

	link = NULL;

	link = add_link(link, "nr1\n");
	link = add_link(link, "nr2\n");
	link = add_link(link, "nr3\n");

	print_list(link);
	
	return (0);
}
