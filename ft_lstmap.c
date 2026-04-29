/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42.ja>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:46:52 by ksaotome          #+#    #+#             */
/*   Updated: 2026/04/29 15:58:21 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;

	if (!lst || !f)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}

// void	*to_upper(void *content)
// {
// 	char	*str = (char *)content;
// 	char	*upper_str = strdup(str);
// 	if (!upper_str)
// 		return (NULL);
// 	for (int i = 0; upper_str[i]; i++)
// 	{
// 		if (upper_str[i] >= 'a' && upper_str[i] <= 'z')
// 			upper_str[i] -= 32;
// 	}
// 	return (upper_str);
// }

// int	main(void)
// {
// 	t_list	*head = NULL;
// 	t_list	*node1 = ft_lstnew(strdup("Node 1"));
// 	t_list	*node2 = ft_lstnew(strdup("Node 2"));
// 	t_list	*node3 = ft_lstnew(strdup("Node 3"));

// 	ft_lstadd_back(&head, node1);
// 	ft_lstadd_back(&head, node2);
// 	ft_lstadd_back(&head, node3);

// 	t_list	*new_head = ft_lstmap(head, to_upper, free);

// 	t_list	*current = new_head;
// 	while (current)
// 	{
// 		printf("%s\n", (char *)current->content);
// 		current = current->next;
// 	}
// 	ft_lstclear(&head, free);
// 	ft_lstclear(&new_head, free);
// 	return (0);
// }