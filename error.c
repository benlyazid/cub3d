#include "cub3d.h"

void set_error(int type_of_error)
{

	//norm
	//makefile
	//resolution is 0
	//correct the key
	// if resolution in big than int 
	//sprite
	//shec file is .cub

// line with all spaces is not valide
	char *error = ft_strdup("error\n");
	ft_putstr_fd(error, 1);
	free(error);
	if (type_of_error == 0)
		error = ft_strdup("Error in Resolution");
	else if (type_of_error == 1)
		ft_putstr_fd("Error in texteur path", 1);
	else if (type_of_error == 2)
		error = ft_strdup("Error in sprite path");
	else if (type_of_error == 3)
		error = ft_strdup("Error in color format");
	else if (type_of_error == 4)
		error = ft_strdup("Error in the maps");
	else if (type_of_error == 5)
		error = ft_strdup("Error in the file");
	else // if (type_of_error == 6)
		error = ft_strdup("Error in the file data");
	ft_putstr_fd(error, 1);
	//free(error);
}