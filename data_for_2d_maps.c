#include "cub3d.h"

int	number_of_width(char *maps)
{
	int	i;
	int result;

	i = 0;
	result = 0;
	while (maps[i] && maps[i] != '\n')
	{
		if (maps[i] == '1')
			result++;
		i++;
	}
	return (result);
}
int	number_of_height(char *maps)
{
	int	i;
	int result;

	i = 0;
	result = 0;
	while (maps[i])
	{	
		if (maps[i] == '\n')
			result++;
		i++;
	}	
	return (result + 1);
}

int	size_of_widht(int number, int width)
{
	return ((width / number));
}

int	size_of_height(int number, int height)
{
	return ((height / number));
}