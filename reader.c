#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "image.h"
#include "definitions.h"
#include "reader.h"

Image * reader_imageFromFile(const char * filepath)
{
	FILE * imageFile = fopen(filepath, "r");
	long imgfileSize = fileSize(filepath);
	
	if (imageFile == NULL)
	{
  		fprintf(stderr, "Could not open image file.\n");
  		return NULL;
	}
	unsigned char buffer[imgfileSize];
	fread(&buffer, imgfileSize, 1, imageFile);
	/* Magic Number: 1 byte */
	char magicNumber[3];
	magicNumber[0] = buffer[0];
	magicNumber[1] = buffer[1];
	magicNumber[2] = '\0';
	int index = 2;
	if (!(strcmp(magicNumber, P_BITMAP_BINARY) == 0 || strcmp(magicNumber, P_GREYMAP_BINARY) == 0 || 
			strcmp(magicNumber, P_PIXMAP_BINARY) == 0))
	{
		fprintf(stderr, "Image file does not have valid magic number (%s).\n", magicNumber);
  		return NULL;
	}
	
	/* Any whitespace */
	while (isspace(buffer[index]))
	{
		index++;
	}
	/* Width as ASCII decimal */
	unsigned char width[3];
	int widthCounter = 0;
	while (!isspace(buffer[index]))
	{
		width[widthCounter] = buffer[index];
		widthCounter++;
		index++;
	}
	width[widthCounter] = '\0';
	/* Any whitespace */
	do
	{
		index++;
	}
	while (isspace(buffer[index]));
	/* Height as ASCII decimal */
	unsigned char height[3];
	int heightCounter = 0;
	while (!isspace(buffer[index]))
	{
		height[heightCounter] = buffer[index];
		heightCounter++;
		index++;
	}
	height[heightCounter] = '\0';
	/* Any whitespace */
	do
	{
		index++;
	}
	while (isspace(buffer[index]));
	/* Comments + CR or LF */
	if (buffer[index] == '#')
	{
		/* printf("Comments found! Consult the original file for details.\n"); */
		while (!isspace(buffer[index]))
		{
			index++;
		}
		index++;
	}
	/* Remainder of image is data (less last byte): */
	Image * tmpImage = newImage(atoi(width), atoi(height), magicNumber);
	int imageIndexer = 0;
	while (index < imgfileSize)
	{
		tmpImage->backing_array[imageIndexer] = buffer[index];
		imageIndexer++;
		index++;
	}
	
	/* printf("Read image of type: %s and dimensions %s x %s.\n", magicNumber, width, height); */
	return tmpImage;
}