/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 12:43:00 by ksaotome          #+#    #+#             */
/*   Updated: 2026/04/28 20:03:33 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c);
static char	*dup_word(char const *s, char c);
static char	**fill_split(char **split, char const *s, char c);
static char	**free_split(char **split, int count);

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!split)
		return (NULL);
	return (fill_split(split, s, c));
}

static int	count_words(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	*dup_word(char const *s, char c)
{
	size_t	len;
	char	*dup;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s, len + 1);
	return (dup);
}

static char	**fill_split(char **split, char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		split[j] = dup_word(&s[i], c);
		if (!split[j])
			return (free_split(split, j));
		j++;
		while (s[i] && s[i] != c)
			i++;
	}
	split[j] = NULL;
	return (split);
}

static char	**free_split(char **split, int count)
{
	while (count > 0)
	{
		count--;
		free(split[count]);
	}
	free(split);
	return (NULL);
}

// int main(void)
// {
// 	char	**result;

// 	result = ft_split("hello world foo", ' ');
// 	printf("[%s] 通常 => \"%s\" \"%s\" \"%s\"\n",
// 		strcmp(result[0], "hello") == 0
// 		&& strcmp(result[1], "world") == 0
// 		&& strcmp(result[2], "foo") == 0
// 		&& result[3] == NULL ? "OK" : "NG",
// 		result[0], result[1], result[2]);
// 	free(result[0]); free(result[1]); free(result[2]); free(result);

// 	result = ft_split(",,hello,,world,,", ',');
// 	printf("[%s] 区切り文字が連続 => \"%s\" \"%s\"\n",
// 		strcmp(result[0], "hello") == 0
// 		&& strcmp(result[1], "world") == 0
// 		&& result[2] == NULL ? "OK" : "NG",
// 		result[0], result[1]);
// 	free(result[0]); free(result[1]); free(result);

// 	result = ft_split(",,hello,,", ',');
// 	printf("[%s] 区切り文字が前後のみ => \"%s\"\n",
// 		strcmp(result[0], "hello") == 0
// 		&& result[1] == NULL ? "OK" : "NG",
// 		result[0]);
// 	free(result[0]); free(result);

// 	result = ft_split("hello", ',');
// 	printf("[%s] 区切り文字なし => \"%s\"\n",
// 		strcmp(result[0], "hello") == 0
// 		&& result[1] == NULL ? "OK" : "NG",
// 		result[0]);
// 	free(result[0]); free(result);

// 	result = ft_split(",,,", ',');
// 	printf("[%s] 区切り文字のみ => (空配列)\n",
// 		result[0] == NULL ? "OK" : "NG");
// 	free(result);

// 	result = ft_split("", ',');
// 	printf("[%s] 空文字列 => (空配列)\n",
// 		result[0] == NULL ? "OK" : "NG");
// 	free(result);

// 	result = ft_split("a,b,c", ',');
// 	printf("[%s] 1文字の単語 => \"%s\" \"%s\" \"%s\"\n",
// 		strcmp(result[0], "a") == 0
// 		&& strcmp(result[1], "b") == 0
// 		&& strcmp(result[2], "c") == 0
// 		&& result[3] == NULL ? "OK" : "NG",
// 		result[0], result[1], result[2]);
// 	free(result[0]); free(result[1]); free(result[2]); free(result);

// 	result = ft_split("hello|world", '|');
// 	printf("[%s] 区切り文字が| => \"%s\" \"%s\"\n",
// 		strcmp(result[0], "hello") == 0
// 		&& strcmp(result[1], "world") == 0
// 		&& result[2] == NULL ? "OK" : "NG",
// 		result[0], result[1]);
// 	free(result[0]); free(result[1]); free(result);

// 	result = ft_split(NULL, ',');
// 	printf("[%s] sがNULL\n", result == NULL ? "OK" : "NG");

// 	return (0);
// }