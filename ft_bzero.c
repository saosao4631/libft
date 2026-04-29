/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42.ja>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 21:30:58 by ksaotome          #+#    #+#             */
/*   Updated: 2026/04/29 16:10:35 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}

// int main(void)
// {
// 	char	buf1[20] = "Hello, World!";
// 	char	buf2[20] = "Hello, World!";
// 	ft_bzero(buf1, 20);
// 	bzero(buf2, 20);
// 	printf("ft_bzeroの場合: %s\n", buf1);
// 	printf("bzeroの場合: %s\n", buf2);

// 	char	buf3[20] = "Hello, World!";
// 	char	buf4[20] = "Hello, World!";
// 	ft_bzero(buf3, (0));
// 	bzero(buf4, (0));
// 	printf("ft_bzeroの場合: %s\n", buf3);
// 	printf("bzeroの場合: %s\n", buf4);

// 	return (0);
// }