#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "definitions.h"
#include "colour.h"
#include "image.h"
#include "headings.h"

Image * newImage(int width, int height, const char * type)
{
	Image * image = malloc(sizeof(Image));
	int bytesPerRow = ceil(width/8.0);
	if (strcmp(type, P_BITMAP_BINARY) == 0)
	{
		image->size = bytesPerRow * height;
	}
	else if (strcmp(type, P_GREYMAP_BINARY) == 0)
	{
		image->size = width * height;
	}
	else
	{
		image->size = 3 * (width * height);
	}
	image->backing_array = (B_ARRAY_TYPE *) calloc(image->size, 1);
	image->width = width;
	image->height = height;
	image->type = type;
	image->white_value = 255;
	return image;
}

Image * image_makeGreyscale(Image * image, int white)
{
	image->white_value = white;
	return image;
}

Image * image_setPixel(Image * image, int row, int column, Colour * colour)
{
	if (!USE_INDEX_0)
	{
		row--;
		column--;
	}
	if (strcmp(image->type, P_BITMAP_BINARY) == 0)
	{
		int bytesPerRow = ceil(image->width/8.0);
		image->backing_array[((row * bytesPerRow) + (column / 8))] |= (0x80 >> (column % 8));
		return image;
	}
	if (strcmp(image->type, P_GREYMAP_BINARY) == 0)
	{
		image->backing_array[((row * image->width) + column)] = constrain(colour_getGrey(colour), 0, image->white_value);
		return image;
	}
	if (strcmp(image->type, P_PIXMAP_BINARY) == 0)
	{
		image->backing_array[(3 * row * image->width) + (column * 3)] = constrain(colour_getRed(colour), 0, 255);
		image->backing_array[(3 * row * image->width) + (column * 3) + 1] = constrain(colour_getGreen(colour), 0, 255);
		image->backing_array[(3 * row * image->width) + (column * 3) + 2] = constrain(colour_getBlue(colour), 0, 255);
		return image;
	}
	return image;
}

Image * image_clearPixel(Image * image, int row, int column)
{
	if (!USE_INDEX_0)
	{
		row--;
		column--;
	}
	if (strcmp(image->type, P_BITMAP_BINARY) == 0)
	{
		image->backing_array[((row * image->width) + column)/8] |= (0x7F >> (((row * image->width) + column) %8));
		return image;
	}
	if (strcmp(image->type, P_GREYMAP_BINARY) == 0)
	{
		image->backing_array[((row * image->width) + column)] = 0x00;
		return image;
	}
	return image;
}

int image_writeToFile(Image * image, const char * filePath)
{
	FILE *outputFile = fopen(filePath, "w");
	int bytesWritten = 1;
	
	if (strcmp(image->type, P_BITMAP_BINARY) == 0)
	{
		fputs(getPBMHeader(BINARY, image->width, image->height), outputFile);
	}
	if (strcmp(image->type, P_GREYMAP_BINARY) == 0)
	{
		fputs(getPGMHeader(BINARY, image->width, image->height, image->white_value), outputFile);
	}
	if (strcmp(image->type, P_PIXMAP_BINARY) == 0)
	{
		fputs(getPPMHeader(BINARY, image->width, image->height), outputFile);
	}
	
	bytesWritten = fwrite(image->backing_array, 1, image->size, outputFile);
	putc(0, outputFile);
	fclose(outputFile);
	return bytesWritten;
}