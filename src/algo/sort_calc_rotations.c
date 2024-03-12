

#include "../../include/ps.h"

#include <limits.h>

int	calc_rotate_ab(t_deque *a, t_deque *b)
{
	int				n;
	size_t			i;
	t_deque_node	*cur;

	cur = a->head;
	// n = calc_rrr(a, b, cur);
	n = __INT_MAX__;
	i = 0;
	while (cur && i < a->size)
	{
		if (n > calc_rr(a, b, cur))
			n = calc_rr(a, b, cur);
		if (n > calc_rrr(a, b, cur))
			n = calc_rrr(a, b, cur);
		if (n > calc_rarrb(a, b, cur))
			n = calc_rarrb(a, b, cur);
		if (n > calc_rrarb(a, b, cur))
			n = calc_rrarb(a, b, cur);
		cur = cur->next;
		i++;
	}
	return (n);
}
