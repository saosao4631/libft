/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:00:52 by ksaotome          #+#    #+#             */
/*   Updated: 2026/04/28 21:08:40 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_num(long n)
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
	len = count_num(num);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	if (num == 0)
		str[0] = '0';
	while (num > 0)
	{
		str[len - 1] = (num % 10) + '0';
		num /= 10;
		len--;
	}
	return (str);
}

// int	main(void)
// {
// 	char	*result;

// 	result = ft_itoa(42);
// 	printf("通常        => \"%s\"\n", result);
// 	free(result);

// 	result = ft_itoa(-42);
// 	printf("負の数      => \"%s\"\n", result);
// 	free(result);

// 	result = ft_itoa(0);
// 	printf("ゼロ        => \"%s\"\n", result);
// 	free(result);

// 	result = ft_itoa(7);
// 	printf("1桁         => \"%s\"\n", result);
// 	free(result);

// 	result = ft_itoa(-7);
// 	printf("負の1桁     => \"%s\"\n", result);
// 	free(result);

// 	result = ft_itoa(-1);
// 	printf("-1          => \"%s\"\n", result);
// 	free(result);

// 	result = ft_itoa(2147483647);
// 	printf("INT_MAX     => \"%s\"\n", result);
// 	free(result);

// 	result = ft_itoa(-2147483648);
// 	printf("INT_MIN     => \"%s\"\n", result);
// 	free(result);

// 	result = ft_itoa(1000);
// 	printf("10の倍数    => \"%s\"\n", result);
// 	free(result);

// 	result = ft_itoa(-1000);
// 	printf("負の10の倍数 => \"%s\"\n", result);
// 	free(result);

// 	return (0);
// }