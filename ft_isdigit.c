/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 01:12:01 by ksaotome          #+#    #+#             */
/*   Updated: 2026/04/25 13:26:00 by ksaotome         ###   ########.fr       */
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

// int	main(void)
// {
// 	int	c[7] = {'A', 'z', '2', 1, ' ', ',', '\0'};
// 	int	i;

// 	i = 0;
// 	while(i < 7)
// 	{
// 		if(ft_isdigit(c[i]))
// 		{
// 			printf("%iは数字です\n",c[i]);
// 		}
// 		else
// 		{
// 			printf("%iは数字ではない\n",c[i]);
// 		}
// 		i++;
// 	}
// }