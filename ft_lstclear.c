/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42.ja>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:46:23 by ksaotome          #+#    #+#             */
/*   Updated: 2026/04/29 15:49:37 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}

// int	main(void)
// {
// 	t_list	*head = NULL;
// 	t_list	*node1 = ft_lstnew(strdup("Node 1"));
// 	t_list	*node2 = ft_lstnew(strdup("Node 2"));
// 	t_list	*node3 = ft_lstnew(strdup("Node 3"));

// 	ft_lstadd_back(&head, node1);
// 	ft_lstadd_back(&head, node2);
// 	ft_lstadd_back(&head, node3);

// 	ft_lstclear(&head, free);

// 	if (head == NULL)
// 		printf("List cleared successfully.\n");
// 	else
// 		printf("List not cleared.\n");

// 	return (0);
// }