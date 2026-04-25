/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 21:32:07 by ksaotome          #+#    #+#             */
/*   Updated: 2026/04/25 13:24:45 by ksaotome         ###   ########.fr       */
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

// int	main(void)
// {
// 	int	c[7] = {'A', 'z', '2', 1, ' ', ',', '\0'};
// 	int	i;

// 	i = 0;
// 	while(i < 7)
// 	{
// 		if(ft_isalpha(c[i]))
// 		{
// 			printf("%iは英字です\n",c[i]);
// 		}
// 		else
// 		{
// 			printf("%iは英字ではない\n",c[i]);
// 		}
// 		i++;
// 	}
// }