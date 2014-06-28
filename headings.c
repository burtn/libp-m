#include "definitions.h"
#include <stdlib.h>
#include <stdio.h>

string_t getPBMHeader(int format, int width, int height)
{
	char *stringBuffer = malloc(sizeof *stringBuffer);
	if (format == BINARY)
	{
		sprintf(stringBuffer, "%s\n%d %d\n", P_BITMAP_BINARY, width, height);
	}
	else
	{
		sprintf(stringBuffer, "%s\n%d %d\n", P_BITMAP_ASCII, width, height);
	}
	return stringBuffer;
}

string_t getPGMHeader(int format, int width, int height, int white)
{
	char *stringBuffer = malloc(sizeof *stringBuffer);
	if (format == BINARY)
	{
		sprintf(stringBuffer, "%s\n%d %d\n%d\n", P_GREYMAP_BINARY, width, height, white);
	}
	else
	{
		sprintf(stringBuffer, "%s\n%d %d\n%d\n", P_GREYMAP_ASCII, width, height, white);
	}
	return stringBuffer;
}

string_t getPPMHeader(int format, int width, int height)
{	
	char *stringBuffer = malloc(sizeof *stringBuffer);
	if (format == BINARY)
	{
		sprintf(stringBuffer, "%s\n%d %d\n%d\n", P_PIXMAP_BINARY, width, height, COLOUR_MAX);
	}
	else
	{
		sprintf(stringBuffer, "%s\n%d %d\n%d\n", P_PIXMAP_ASCII, width, height, COLOUR_MAX);
	}
	return stringBuffer;
}