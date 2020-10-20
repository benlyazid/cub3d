#include "cub3d.h"

void set_error(int type_of_error)
{

	//free 
	//norm
	//makefile
	//espace in the maps
	//resolution is 0
	// EXECUTE save 
	//correct the key
	char *error = ft_strdup("error\n");
	ft_putstr_fd(error, 1);
	free(error);
	if (type_of_error == 0)
		error = ft_strdup("Error in Resolution");
	if (type_of_error == 1)
		ft_putstr_fd("Error in texteur path", 1);
	if (type_of_error == 2)
		error = ft_strdup("Error in sprite path");
	if (type_of_error == 3)
		error = ft_strdup("Error in color format");
	if (type_of_error == 4)
		error = ft_strdup("Error in the maps");
	if (type_of_error == 5)
		error = ft_strdup("Error in the file");
	if (type_of_error == 6)
		error = ft_strdup("Error in the file data");
	ft_putstr_fd(error, 1);
	free(error);
}