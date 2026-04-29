/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:36:29 by ksaotome          #+#    #+#             */
/*   Updated: 2026/04/28 20:39:46 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// int	main(void)
// {
// 	ft_putchar_fd('a', 1);
// 	ft_putchar_fd('\n', 1);
// 	ft_putchar_fd('1', 1);
// 	ft_putchar_fd('\n', 1);
// 	ft_putchar_fd(' ', 1);
// }
