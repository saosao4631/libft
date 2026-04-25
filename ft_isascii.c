/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 01:51:44 by ksaotome          #+#    #+#             */
/*   Updated: 2026/04/25 13:33:45 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	int	flag;

	flag = 0;
	if (c >= 0 && c <= 127)
		flag = 1;
	return (flag);
}

// int	main(void)
// {
// 	int	c[9] = {'A', 'z', '2', 1, ' ', ',', '\0', 128, -1};
// 	// 128 以降は拡張ASCII（Extended ASCII）
// 	int	i;

// 	i = 0;
// 	while(i < 9)
// 	{
// 		if(ft_isascii(c[i]))
// 		{
// 			printf("%iはASCII文字です\n",c[i]);
// 		}
// 		else
// 		{
// 			printf("%iはASCII文字ではない\n",c[i]);
// 		}
// 		i++;
// 	}
// }