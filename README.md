*This project has been created as part of the 42 curriculum by ksaotome.*

## Description
- 42 curriculum

## Instructions

## Resources
- https://daeudaeu.com/list-structure/
- https://github.com/usatie/libft-tester-tokyo
- AI Used
	- test




atoi

			while (*str >= '0' && *str <= '9')
	{
		prev_result = result;
		result = result * 10 + (*str - '0');
		if (result < 0 || result < prev_result)
		{
			if (sign == 1)
				return (-1);
			else
				return (0);
		}
		str++;

long(intも)を超えた値を返す際に0を返すように(負の数は-1を返す)



calloc

	if (t == 0)
		t = 1;

	malloc(0)を防ぐ（環境によってアドレス箇所が確保されてfreeしなくてはいけなくなる）