/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:37:20 by ksaotome          #+#    #+#             */
/*   Updated: 2026/04/28 20:43:10 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	if (!s)
		return ;
	len = ft_strlen(s);
	write(fd, s, len);
}

// int	main(void)
// {
// 	ft_putstr_fd("a", 1);
// 	printf("\n");
// 	ft_putstr_fd("abc", 1);
// 	printf("\n");
// 	ft_putstr_fd("", 1);
// 	printf("\n");
// 	ft_putstr_fd("a\nb           c", 1);
// 	printf("\n");
// 	ft_putstr_fd("a", 2);
// }