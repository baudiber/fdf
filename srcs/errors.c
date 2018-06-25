#include "fdf.h"

void	ft_errors(int type)
{
	if (type == 1)
	{
		write(1, "open() failed\n", 14);
		exit (0);
	}
	else if (type == 2)
	{
		write(1, "invalid map\n", 12);
		exit (0);
	}
	else if (type == 3)
	{
		write(1, "malloc error\n", 13);
		exit (0);
	}
}

void	free_all(t_setup *stp)
{
	free(stp->map.npts);
	free(stp->map.tpts);
}

void	free_ll(t_rows *head)
{
	t_rows	*tmp;

	while(head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
