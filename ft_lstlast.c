/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42.ja>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:45:39 by ksaotome          #+#    #+#             */
/*   Updated: 2026/04/29 15:44:31 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// int	main(void)
// {
// 	t_list	*head = NULL;
// 	t_list	*node1 = ft_lstnew("Node 1");
// 	t_list	*node2 = ft_lstnew("Node 2");
// 	t_list	*node3 = ft_lstnew("Node 3");

// 	ft_lstadd_front(&head, node1);
// 	ft_lstadd_front(&head, node2);
// 	ft_lstadd_front(&head, node3);

// 	t_list	*last_node = ft_lstlast(head);
// 	if (last_node)
// 		printf("Last: %s\n", (char *)last_node->content);
// 	else
// 		printf("Last: empty.\n");
// 	return (0);
// }