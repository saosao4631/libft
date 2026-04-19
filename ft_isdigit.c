/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42.ja>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 01:12:01 by ksaotome          #+#    #+#             */
/*   Updated: 2026/04/20 01:17:56 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	int	flag;

	flag = 0;
	if (c >= '0' && c <= '9')
		flag = 1;
	return (flag);
}

// #include <stdio.h>
// int	main(void)
// {
//     char c1 = '5';
//     char c2 = 'a';
//     char c3 = '9';

//     printf("%d\n", ft_isdigit(c1)); // 1
//     printf("%d\n", ft_isdigit(c2)); // 0
//     printf("%d\n", ft_isdigit(c3)); // 1

//     return 0;
// }