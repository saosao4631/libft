#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <limits.h>
#include "libft.h"

#define TEST(name, result, expected) \
	printf("%s: %s (result=%d, expected=%d)\n", name, result == expected ? "✓" : "✗", result, expected)

#define TEST_STR(name, result, expected) \
	printf("%s: %s (result='%s', expected='%s')\n", name, \
		(result && expected && strcmp(result, expected) == 0) || (result == expected) ? "✓" : "✗", \
		result ? result : "(nil)", expected ? expected : "(nil)")

#define TEST_PTR(name, result, expected) \
	printf("%s: %s (result=%p, expected=%p)\n", name, result == expected ? "✓" : "✗", result, expected)

/* Helper functions */
static void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static void	free_list(t_list *lst)
{
	while (lst)
	{
		t_list	*temp;

		temp = lst->next;
		if (lst->content)
			free(lst->content);
		free(lst);
		lst = temp;
	}
}

static char	map_add_index(unsigned int i, char c)
{
	return (char)(c + i);
}

static void	iter_upper(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}

static void	*map_dup(void *content)
{
	return (ft_strdup((char *)content));
}

int	main(void)
{
	char	buf[200];
	char	*str;
	char	**split;
	t_list	*lst;
	t_list	*new_lst;
	int		i;

	printf("=== ft_isalpha: alphabetic characters ===\n");
	printf("ft_isalpha('a') = %d (expected 1)\n", ft_isalpha('a'));
	printf("ft_isalpha('Z') = %d (expected 1)\n", ft_isalpha('Z'));
	printf("ft_isalpha('5') = %d (expected 0)\n", ft_isalpha('5'));
	printf("ft_isalpha(' ') = %d (expected 0)\n", ft_isalpha(' '));

	printf("\n=== ft_isdigit: digit characters ===\n");
	printf("ft_isdigit('5') = %d (expected 1)\n", ft_isdigit('5'));
	printf("ft_isdigit('0') = %d (expected 1)\n", ft_isdigit('0'));
	printf("ft_isdigit('a') = %d (expected 0)\n", ft_isdigit('a'));

	printf("\n=== ft_isalnum: alphanumeric ===\n");
	printf("ft_isalnum('a') = %d (expected 1)\n", ft_isalnum('a'));
	printf("ft_isalnum('5') = %d (expected 1)\n", ft_isalnum('5'));
	printf("ft_isalnum(' ') = %d (expected 0)\n", ft_isalnum(' '));

	printf("\n=== ft_isascii: ASCII range 0-127 ===\n");
	printf("ft_isascii('a') = %d (expected 1)\n", ft_isascii('a'));
	printf("ft_isascii(127) = %d (expected 1)\n", ft_isascii(127));
	printf("ft_isascii(128) = %d (expected 0)\n", ft_isascii(128));

	printf("\n=== ft_isprint: printable characters ===\n");
	printf("ft_isprint('a') = %d (expected 1)\n", ft_isprint('a'));
	printf("ft_isprint(' ') = %d (expected 1)\n", ft_isprint(' '));
	printf("ft_isprint('\\n') = %d (expected 0)\n", ft_isprint('\n'));

	printf("\n=== ft_strlen: null-terminated string length ===\n");
	printf("ft_strlen(\"\") = %zu (expected 0)\n", ft_strlen(""));
	printf("ft_strlen(\"Hello\") = %zu (expected 5)\n", ft_strlen("Hello"));
	printf("ft_strlen(\"Hello, World!\") = %zu (expected 13)\n", ft_strlen("Hello, World!"));

	printf("\n=== ft_toupper: convert to uppercase ===\n");
	printf("ft_toupper('a') = %c (expected A)\n", ft_toupper('a'));
	printf("ft_toupper('Z') = %c (expected Z)\n", ft_toupper('Z'));
	printf("ft_toupper('5') = %c (expected 5)\n", ft_toupper('5'));

	printf("\n=== ft_tolower: convert to lowercase ===\n");
	printf("ft_tolower('A') = %c (expected a)\n", ft_tolower('A'));
	printf("ft_tolower('z') = %c (expected z)\n", ft_tolower('z'));
	printf("ft_tolower('5') = %c (expected 5)\n", ft_tolower('5'));

	printf("\n=== ft_memset: fill memory with byte ===\n");
	ft_memset(buf, 'X', 5);
	buf[5] = '\0';
	printf("ft_memset(buf, 'X', 5) = \"%s\" (expected \"XXXXX\")\n", buf);
	
	memset(buf, 0, 10);
	ft_memset(buf, 'A', 3);
	printf("ft_memset(buf, 'A', 3): buf[0]='%c', buf[1]='%c', buf[2]='%c', buf[3]=%d\n", buf[0], buf[1], buf[2], buf[3]);
	
	ft_memset(buf, 0, 5);
	printf("ft_memset(buf, 0, 5): buf[0]=%d, buf[4]=%d\n", buf[0], buf[4]);

	printf("\n=== ft_bzero: zero out memory ===\n");
	strcpy(buf, "Hello");
	ft_bzero(buf, 3);
	printf("After ft_bzero(buf, 3): buf[0]=%d buf[1]=%d buf[2]=%d (expected 0, 0, 0)\n", buf[0], buf[1], buf[2]);
	printf("buf[3]='%c' (expected l)\n", buf[3]);
	
	memset(buf, 'X', 10);
	ft_bzero(buf + 2, 3);
	printf("After ft_bzero(buf+2, 3): buf[1]='%c', buf[2]=%d, buf[3]=%d, buf[4]=%d, buf[5]='%c'\n", buf[1], buf[2], buf[3], buf[4], buf[5]);

	printf("\n=== ft_strchr: find character in string ===\n");
	printf("ft_strchr(\"Hello\", 'l') = \"%s\" (expected \"llo\")\n", ft_strchr("Hello", 'l'));
	printf("ft_strchr(\"Hello\", 'x') = %p (expected NULL)\n", ft_strchr("Hello", 'x'));
	printf("ft_strchr(\"Hello\", '\\0') = %s (expected empty string)\n", ft_strchr("Hello", '\0'));
	printf("ft_strchr(\"aaa\", 'a') = \"%s\" (expected \"aaa\", first match)\n", ft_strchr("aaa", 'a'));

	printf("\n=== ft_strrchr: find last occurrence ===\n");
	printf("ft_strrchr(\"Hello\", 'l') = \"%s\" (expected \"lo\")\n", ft_strrchr("Hello", 'l'));
	printf("ft_strrchr(\"Hello\", 'x') = %p (expected NULL)\n", ft_strrchr("Hello", 'x'));
	printf("ft_strrchr(\"aaa\", 'a') = \"%s\" (expected \"a\", last match)\n", ft_strrchr("aaa", 'a'));
	printf("ft_strrchr(\"abcabc\", 'b') = \"%s\" (expected \"bc\")\n", ft_strrchr("abcabc", 'b'));

	printf("\n=== ft_strncmp: compare first n bytes ===\n");
	printf("ft_strncmp(\"abc\", \"abd\", 2) = %d (expected 0, compare first 2 chars)\n", ft_strncmp("abc", "abd", 2));
	printf("ft_strncmp(\"abc\", \"abd\", 3) = %d (expected < 0)\n", ft_strncmp("abc", "abd", 3));
	printf("ft_strncmp(\"xyz\", \"abc\", 1) = %d (expected > 0)\n", ft_strncmp("xyz", "abc", 1));
	printf("ft_strncmp(\"abc\", \"abc\", 3) = %d (expected 0)\n", ft_strncmp("abc", "abc", 3));
	printf("ft_strncmp(\"abc\", \"abd\", 0) = %d (expected 0, n=0)\n", ft_strncmp("abc", "abd", 0));

	printf("\n=== ft_memcpy: copy memory (non-overlapping) ===\n");
	strcpy(buf, "Hello");
	char dst[10];
	ft_memcpy(dst, buf, 5);
	dst[5] = '\0';
	printf("ft_memcpy result = \"%s\" (expected \"Hello\")\n", dst);
	
	memset(dst, 0, 10);
	ft_memcpy(dst, "ABC", 3);
	printf("ft_memcpy(dst, \"ABC\", 3): dst[0-2] = '%c' '%c' '%c'\n", dst[0], dst[1], dst[2]);

	printf("\n=== ft_memmove: copy memory (may overlap) ===\n");
	strcpy(buf, "12345678");
	ft_memmove(buf + 2, buf, 5);
	buf[7] = '\0';
	printf("ft_memmove(buf+2, buf, 5) = \"");
	for (int j = 0; j < 7; j++)
		printf("%c", buf[j]);
	printf("\" (expected \"12123458\")\n");
	
	strcpy(buf, "abcdef");
	ft_memmove(buf, buf + 1, 4);
	printf("ft_memmove(buf, buf+1, 4): \"");
	for (int j = 0; j < 4; j++)
		printf("%c", buf[j]);
	printf("\" (expected \"bcde\")\n");

	printf("\n=== ft_strlcpy: copy with size limit ===\n");
	i = ft_strlcpy(buf, "Hello", 10);
	printf("ft_strlcpy returned %d (expected 5), buf = \"%s\" (expected \"Hello\")\n", i, buf);
	i = ft_strlcpy(buf, "Hello", 3);
	printf("ft_strlcpy(size=3) returned %d (expected 5), buf = \"%s\" (expected \"He\")\n", i, buf);
	i = ft_strlcpy(buf, "Hello", 1);
	printf("ft_strlcpy(size=1) returned %d (expected 5), buf[0] = %d (expected 0)\n", i, buf[0]);
	i = ft_strlcpy(buf, "Hello", 0);
	printf("ft_strlcpy(size=0) returned %d (expected 5)\n", i);

	printf("\n=== ft_strlcat: concatenate with size limit ===\n");
	strcpy(buf, "Hello");
	i = ft_strlcat(buf, " World", 20);
	printf("ft_strlcat returned %d (expected 11), buf = \"%s\" (expected \"Hello World\")\n", i, buf);
	strcpy(buf, "Hello");
	i = ft_strlcat(buf, " World", 8);
	printf("ft_strlcat(size=8) returned %d (expected 11), buf = \"%s\" (truncated)\n", i, buf);
	strcpy(buf, "Hello");
	i = ft_strlcat(buf, "X", 6);
	printf("ft_strlcat(size=6) with \"X\" returned %d (expected 6), buf = \"%s\" (expected \"HelloX\")\n", i, buf);

	printf("\n=== ft_strnstr: find substring ===\n");
	printf("ft_strnstr(\"libft library\", \"lib\", 20) = \"%s\" (expected \"libft library\")\n", ft_strnstr("libft library", "lib", 20));
	printf("ft_strnstr(\"libft library\", \"lib\", 1) = %p (expected NULL)\n", ft_strnstr("libft library", "lib", 1));
	printf("ft_strnstr(\"libft library\", \"\", 20) = \"%s\" (empty needle)\n", ft_strnstr("libft library", "", 20));
	printf("ft_strnstr(\"libft library\", \"library\", 20) = \"%s\" (expected \"library\")\n", ft_strnstr("libft library", "library", 20));
	printf("ft_strnstr(\"libft library\", \"library\", 6) = %p (len too short)\n", ft_strnstr("libft library", "library", 6));

	printf("\n=== ft_atoi: ASCII to integer ===\n");
	printf("ft_atoi(\"  -42\") = %d (expected -42)\n", ft_atoi("  -42"));
	printf("ft_atoi(\"123\") = %d (expected 123)\n", ft_atoi("123"));
	printf("ft_atoi(\"\\t+99\") = %d (expected 99)\n", ft_atoi("\t+99"));
	printf("ft_atoi(\"0\") = %d (expected 0)\n", ft_atoi("0"));
	printf("ft_atoi(\"   0\") = %d (expected 0)\n", ft_atoi("   0"));
	printf("ft_atoi(\"abc\") = %d (expected 0, no digits)\n", ft_atoi("abc"));
	printf("ft_atoi(\"42abc\") = %d (expected 42, stop at non-digit)\n", ft_atoi("42abc"));
	printf("ft_atoi(\"+100\") = %d (expected 100)\n", ft_atoi("+100"));
	printf("ft_atoi(\"  -999\") = %d (expected -999)\n", ft_atoi("  -999"));

	printf("\n=== ft_strdup: duplicate string ===\n");
	str = ft_strdup("Hello");
	printf("ft_strdup(\"Hello\") = \"%s\" (expected \"Hello\")\n", str);
	free(str);
	str = ft_strdup("");
	printf("ft_strdup(\"\") = \"%s\" (expected empty)\n", str);
	free(str);
	str = ft_strdup("a");
	printf("ft_strdup(\"a\") = \"%s\"\n", str);
	free(str);

	printf("\n=== ft_substr: extract substring ===\n");
	str = ft_substr("Hello, World!", 7, 5);
	printf("ft_substr(\"Hello, World!\", 7, 5) = \"%s\" (expected \"World\")\n", str);
	free(str);
	str = ft_substr("Hello", 10, 5);
	printf("ft_substr(\"Hello\", 10, 5) = \"%s\" (expected empty)\n", str);
	free(str);
	str = ft_substr("Hello", 0, 0);
	printf("ft_substr(\"Hello\", 0, 0) = \"%s\" (expected empty)\n", str);
	free(str);
	str = ft_substr("Hello", 1, 1);
	printf("ft_substr(\"Hello\", 1, 1) = \"%s\" (expected \"e\")\n", str);
	free(str);
	str = ft_substr("Hello", 2, 100);
	printf("ft_substr(\"Hello\", 2, 100) = \"%s\" (expected \"llo\")\n", str);
	free(str);

	printf("\n=== ft_strjoin: join two strings ===\n");
	str = ft_strjoin("Hello", " World");
	printf("ft_strjoin(\"Hello\", \" World\") = \"%s\" (expected \"Hello World\")\n", str);
	free(str);
	
	str = ft_strjoin("", "test");
	printf("ft_strjoin(\"\", \"test\") = \"%s\" (expected \"test\")\n", str);
	free(str);
	
	str = ft_strjoin("test", "");
	printf("ft_strjoin(\"test\", \"\") = \"%s\" (expected \"test\")\n", str);
	free(str);
	
	str = ft_strjoin("a", "b");
	printf("ft_strjoin(\"a\", \"b\") = \"%s\" (expected \"ab\")\n", str);
	free(str);

	printf("\n=== ft_strtrim: trim charset from edges ===\n");
	str = ft_strtrim("  \\tHello ft_trim\\n ", " \t\n");
	printf("ft_strtrim with spaces/tabs/newlines = \"%s\"\n", str);
	free(str);
	
	str = ft_strtrim("xxxHelloxxx", "x");
	printf("ft_strtrim(\"xxxHelloxxx\", \"x\") = \"%s\" (expected \"Hello\")\n", str);
	free(str);
	
	str = ft_strtrim("Hello", "x");
	printf("ft_strtrim(\"Hello\", \"x\") = \"%s\" (no trim)\n", str);
	free(str);
	
	str = ft_strtrim("xxxxx", "x");
	printf("ft_strtrim(\"xxxxx\", \"x\") = \"%s\" (all trimmed, expected empty)\n", str);
	free(str);
	
	str = ft_strtrim("xHx", "x");
	printf("ft_strtrim(\"xHx\", \"x\") = \"%s\" (expected \"H\")\n", str);
	free(str);

	printf("\n=== ft_split: split string by delimiter ===\n");
	split = ft_split("one:two:three", ':');
	printf("ft_split(\"one:two:three\", ':'):\n");
	for (i = 0; split && split[i]; i++)
		printf("  [%d] = \"%s\"\n", i, split[i]);
	free_split(split);
	
	split = ft_split("a::b", ':');
	printf("ft_split(\"a::b\", ':'): ");
	for (i = 0; split && split[i]; i++)
		printf("[%s] ", split[i]);
	printf("(consecutive delimiters)\n");
	free_split(split);
	
	split = ft_split(":::", ':');
	printf("ft_split(\":::\", ':'): ");
	if (split && split[0])
	{
		for (i = 0; split[i]; i++)
			printf("[%s] ", split[i]);
	}
	else
		printf("(empty)");
	printf("\n");
	free_split(split);
	
	split = ft_split("hello", 'x');
	printf("ft_split(\"hello\", 'x'): [%s] (no delimiter)\n", split[0]);
	free_split(split);

	printf("\n=== ft_strmapi: map function over string ===\n");
	str = ft_strmapi("abc", map_add_index);
	printf("ft_strmapi(\"abc\", add_index) = \"%s\" (expected \"ace\" a+0=a, b+1=c, c+2=e)\n", str);
	free(str);
	
	str = ft_strmapi("", map_add_index);
	printf("ft_strmapi(\"\", add_index) = \"%s\" (expected empty)\n", str);
	free(str);

	printf("\n=== ft_striteri: iterate with index ===\n");
	strcpy(buf, "hello");
	ft_striteri(buf, iter_upper);
	printf("ft_striteri(\"hello\", to_upper) = \"%s\" (expected \"HELLO\")\n", buf);
	
	strcpy(buf, "aBc");
	ft_striteri(buf, iter_upper);
	printf("ft_striteri(\"aBc\", to_upper) = \"%s\" (expected \"ABC\")\n", buf);

	printf("\n=== ft_memchr: find byte in memory ===\n");
	str = (char *)ft_memchr("ABCDEF", 'C', 6);
	printf("ft_memchr(\"ABCDEF\", 'C', 6) = \"%s\" (expected \"CDEF\")\n", str);
	
	str = (char *)ft_memchr("ABCDEF", 'F', 6);
	printf("ft_memchr(\"ABCDEF\", 'F', 6) = \"%s\" (expected \"F\")\n", str);
	
	printf("ft_memchr(\"ABC\", 'D', 3) = %p (expected NULL)\n", ft_memchr("ABC", 'D', 3));
	
	printf("ft_memchr(\"ABCABC\", 'B', 6) = %s (first B)\n", (char *)ft_memchr("ABCABC", 'B', 6));

	printf("\n=== ft_memcmp: compare memory ===\n");
	printf("ft_memcmp(\"ABC\", \"ABD\", 3) = %d (expected < 0)\n", ft_memcmp("ABC", "ABD", 3));
	printf("ft_memcmp(\"ABC\", \"ABC\", 3) = %d (expected 0)\n", ft_memcmp("ABC", "ABC", 3));
	printf("ft_memcmp(\"ABD\", \"ABC\", 3) = %d (expected > 0)\n", ft_memcmp("ABD", "ABC", 3));
	printf("ft_memcmp(\"ABC\", \"ABD\", 2) = %d (expected 0, compare first 2)\n", ft_memcmp("ABC", "ABD", 2));

	printf("\n=== ft_calloc: allocate and zero memory ===\n");
	str = (char *)ft_calloc(10, 1);
	printf("ft_calloc(10, 1): str[0]=%d, str[9]=%d (expected 0, 0)\n", str[0], str[9]);
	free(str);
	
	str = (char *)ft_calloc(5, 2);
	printf("ft_calloc(5, 2): allocated 10 bytes, all zero = %d\n", str[9] == 0);
	free(str);

	printf("\n=== ft_itoa: integer to string ===\n");
	str = ft_itoa(42);
	printf("ft_itoa(42) = \"%s\" (expected \"42\")\n", str);
	free(str);
	str = ft_itoa(-1234);
	printf("ft_itoa(-1234) = \"%s\" (expected \"-1234\")\n", str);
	free(str);
	str = ft_itoa(0);
	printf("ft_itoa(0) = \"%s\" (expected \"0\")\n", str);
	free(str);
	str = ft_itoa(1);
	printf("ft_itoa(1) = \"%s\" (expected \"1\")\n", str);
	free(str);
	str = ft_itoa(-1);
	printf("ft_itoa(-1) = \"%s\" (expected \"-1\")\n", str);
	free(str);
	str = ft_itoa(INT_MIN);
	printf("ft_itoa(INT_MIN) = \"%s\" (expected \"%d\")\n", str, INT_MIN);
	free(str);
	str = ft_itoa(INT_MAX);
	printf("ft_itoa(INT_MAX) = \"%s\" (expected \"%d\")\n", str, INT_MAX);
	free(str);

	printf("\n=== ft_lstnew: create new list node ===\n");
	lst = ft_lstnew(ft_strdup("first"));
	printf("ft_lstnew created node with content \"%s\"\n", (char *)lst->content);
	free(lst->content);
	free(lst);

	printf("\n=== ft_lstadd_front / ft_lstadd_back ===\n");
	lst = NULL;
	ft_lstadd_front(&lst, ft_lstnew(ft_strdup("a")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("b")));
	ft_lstadd_front(&lst, ft_lstnew(ft_strdup("z")));
	printf("List after operations: ");
	for (t_list *n = lst; n; n = n->next)
		printf("[%s] ", (char *)n->content);
	printf("(expected [z] [a] [b])\n");
	free_list(lst);

	printf("\n=== ft_lstsize: count list nodes ===\n");
	lst = ft_lstnew(ft_strdup("1"));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("2")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("3")));
	printf("ft_lstsize = %d (expected 3)\n", ft_lstsize(lst));
	free_list(lst);

	printf("\n=== ft_lstlast: get last node ===\n");
	lst = ft_lstnew(ft_strdup("first"));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("middle")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("last")));
	printf("ft_lstlast content = \"%s\" (expected \"last\")\n", (char *)ft_lstlast(lst)->content);
	free_list(lst);

	printf("\n=== ft_lstmap: map function over list ===\n");
	lst = ft_lstnew(ft_strdup("a"));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("b")));
	new_lst = ft_lstmap(lst, map_dup, free);
	printf("ft_lstmap result: ");
	for (t_list *n = new_lst; n; n = n->next)
		printf("[%s] ", (char *)n->content);
	printf("(expected [a] [b])\n");
	free_list(lst);
	free_list(new_lst);

	return (0);
}
