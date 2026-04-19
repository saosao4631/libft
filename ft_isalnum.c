/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42.ja>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 01:21:08 by ksaotome          #+#    #+#             */
/*   Updated: 2026/04/20 01:47:27 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	int	flag;

	flag = 0;
	if (ft_isalpha(c) || ft_isdigit(c))
		flag = 1;
	return (flag);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char c1 = 'a';
// 	char c2 = 'Z';
// 	char c3 = '1';
// 	char c4 = '@';

// 	printf("%d\n", ft_isalnum(c1)); // 1
// 	printf("%d\n", ft_isalnum(c2)); // 1
// 	printf("%d\n", ft_isalnum(c3)); // 1
// 	printf("%d\n", ft_isalnum(c4)); // 0

// 	return (0);
// }