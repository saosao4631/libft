/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:38:17 by ksaotome          #+#    #+#             */
/*   Updated: 2026/04/28 20:49:20 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	len;

	if (!s)
		return ;
	len = ft_strlen(s);
	write(fd, s, len);
	write(fd, "\n", 1);
}

// int	main(void)
// {
// 	ft_putendl_fd("a", 1);
// 	ft_putendl_fd("abc", 1);
// 	ft_putendl_fd("", 1);
// 	ft_putendl_fd("a\nb           c", 1);
// 	ft_putendl_fd("a", 2);
// }