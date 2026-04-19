/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42.ja>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 21:32:07 by ksaotome          #+#    #+#             */
/*   Updated: 2026/04/20 01:33:26 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	int	flag;

	flag = 0;
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		flag = 1;
	return (flag);
}

// #include <stdio.h>
// int	main(void)
// {
//     char c1 = 'a';
//     char c2 = 'Z';
//     char c3 = '1';

//     printf("%d\n", ft_isalpha(c1)); // 1
//     printf("%d\n", ft_isalpha(c2)); // 1
//     printf("%d\n", ft_isalpha(c3)); // 0

//     return 0;
// }
