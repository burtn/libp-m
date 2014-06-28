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
	image->backing_array = malloc(sizeof(image->size));
	image->width = width;
	image->height = height;
	return image;
}

Image * image_setPixel(Image * image, int row, int column, Colour * colour)
{
	if (!USE_INDEX_0)
	{
		row--;
		column--;
	}
	int bytesPerRow = ceil(image->width/8.0);
	image->backing_array[((row * bytesPerRow) + (column / 8))] |= (0x80 >> (column % 8));
	return image;
}

Image * image_clearPixel(Image * image, int row, int column)
{
	image->backing_array[((row * image->width) + column)/8] |= (0x7F >> (((row * image->width) + column) %8));
	return image;
}

int image_writeToFile(Image * image, const char * filePath)
{
	FILE *outputFile = fopen(filePath, "w");
	int bytesWritten = 1;
	fputs(getPBMHeader(BINARY, image->width, image->height), outputFile);
	bytesWritten = fwrite(image->backing_array, 1, image->size, outputFile);
	putc(0, outputFile);
	fclose(outputFile);
	return bytesWritten;
}