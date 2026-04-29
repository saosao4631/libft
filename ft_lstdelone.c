/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42.ja>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:46:06 by ksaotome          #+#    #+#             */
/*   Updated: 2026/04/29 15:48:41 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

// int	main(void)
// {
// 	t_list	*node = ft_lstnew("Hello, World!");
// 	printf("Before deletion: %s\n", (char *)node->content);
// 	ft_lstdelone(node, free);
// 	// After deletion, we cannot access node->content as it has been freed.
// 	return (0);
// }