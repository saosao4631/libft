/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42.ja>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:00:52 by ksaotome          #+#    #+#             */
/*   Updated: 2026/04/22 13:12:04 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_num(int n);

static int	count_num(int n)
{
	int	cnt;

	cnt = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		cnt++;
	while (n)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	num;

	num = n;
	len = count_num(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	else if (num == 0)
		str[0] = '0';
	while (num)
	{
		str[len] = (num % 10) + '0';
		--len;
		num /= 10;
	}
	return (str);
}