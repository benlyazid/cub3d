/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 17:24:08 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/11/03 10:31:03 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int save(t_all_info *info)
{
	uint16_t bitcount = 24;
	int width = (int) info->width;
	int height = (int) info->height;
	int width_in_bytes = ((width * bitcount + 31) / 32) * 4;
	uint32_t imagesize = width_in_bytes * height;
	uint32_t biSize = 40;
	uint32_t bfOffBits = 54; 
	uint32_t filesize = 54 + imagesize;
	uint16_t biPlanes = 1;
	unsigned char *header = malloc(54);

	

    ft_memcpy(header, "BM", 2);
    ft_memcpy(header + 2 , &filesize, 4);
    ft_memcpy(header + 10, &bfOffBits, 4);
    ft_memcpy(header + 14, &biSize, 4);
    ft_memcpy(header + 18, &width, 4);
    ft_memcpy(header + 22, &height, 4);
    ft_memcpy(header + 26, &biPlanes, 2);
    ft_memcpy(header + 28, &bitcount, 2);
    ft_memcpy(header + 34, &imagesize, 4);
    char* buf = malloc(imagesize);
    for(int row = height - 1; row >= 0; row--)
    {
        for(int col = 0; col < width; col++)
        {      int color = info->data_3d[row * width + col];
                 int r =  (color / 65536) % 256;
                int g = (color / 256) % 256;
                int b = color % 256;;
            buf[row * width_in_bytes + col * 3 + 0] = b;//blue
            buf[row * width_in_bytes + col * 3 + 1] = g;//green
            buf[row * width_in_bytes + col * 3 + 2] = r;//red
        }
    }

	FILE *fout = fopen("save.bmp", "wb");

	fwrite(header, 1, 54, fout);
	fwrite((char*)buf, 1, imagesize, fout);
	fclose(fout);
	free(buf);
	return (0);
}
