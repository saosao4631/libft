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

		if (result > (LONG_MAX - (*str - '0')) / 10)
			return (0);
		result = result * 10 + (*str - '0');


		final_cheak = sign * result;
		if (final_cheak > INT_MAX || final_cheak < INT_MIN)
			return (0);
long(intも)を超えた値を返す際に0を返すように