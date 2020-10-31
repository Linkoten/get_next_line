#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *plst;

	if (alst && *alst)
	{
		plst = *alst;
		while (plst->next)
			plst = plst->next;
		plst->next = new;
	}
	else if (alst)
		*alst = new;
}
