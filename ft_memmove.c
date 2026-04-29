/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 21:39:28 by ksaotome          #+#    #+#             */
/*   Updated: 2026/04/26 20:42:29 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (d < s)
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		d += n;
		s += n;
		while (n--)
			*--d = *--s;
	}
	return (dst);
}

// int main(void)
// {
//     printf("dst が src より後ろにある場合\n");

//     char str_mov1[10] = "123456789";
//     char str_std[10]  = "123456789";

//     ft_memmove(str_mov1 + 2, str_mov1, 5);
//     memmove(str_std + 2, str_std, 5);

//     printf("ft_memmoveの結果: %s\n", str_mov1);
//     printf("memmove の結果: %s\n\n", str_std);

//     printf("dst が src より前にある場合\n");

//     char str_mov2[10] = "123456789";
//     char str_std2[10] = "123456789";

//     ft_memmove(str_mov2, str_mov2 + 2, 3);
//     memmove(str_std2, str_std2 + 2, 3);

//     printf("ft_memmoveの結果: %s\n", str_mov2);
//     printf("本家memmove の結果: %s\n", str_std2);

//     return (0);
// }