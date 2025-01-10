#include "philosopher.h"

void	clear_memory(void *ptr, size_t size)
{
	unsigned char	*byte_ptr;
	size_t			i;

	byte_ptr = (unsigned char *)ptr;
	i = 0;
	while (i < size)
	{
		byte_ptr[i] = 0;
		i++;
	}
}

int	str_to_int(const char *str)
{
	int	neg;
	int	i;
	int	num;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * neg);
}

void	check_min_values(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (str_to_int(argv[i]) <= 0)
			show_error(2);
		if (str_to_int(argv[i]) > INT_MAX)
			show_error(2);
	}
}

int	show_error(int code)
{
	if (code == 1)
		printf("Error\n\nInvalid number of arguments!");
	else if (code == 2)
		printf("Error\n\nInvalid argument value!");
	else if (code == 3)
		printf("Error\n\nMemory allocation failure");
	printf("\nExample: ./philosopher 5 800 200 200\n");
	exit (1);
	return (0);
}
