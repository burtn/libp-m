#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "definitions.h"
#include "headings.h"
#include "bytearray.h"
#define USE_INDEX_0 0

int lastAllocation;

int bytea_getLastAllocationSize()
{
	printf("Last allocated %d bytes.\n", lastAllocation);
	return lastAllocation;
}

ByteArray* newByteArray(int width, int height, const char * magicNumber)
{
	ByteArray *byteArray = malloc(sizeof(ByteArray));
	lastAllocation = width * height;
	byteArray->array = malloc(sizeof(lastAllocation));
	byteArray->width = width;
	byteArray->height = height;
	byteArray->header = magicNumber;
	return byteArray;
}

ByteArray* set(ByteArray *byteArray, int row, int column, int value)
{
	if (!USE_INDEX_0)
	{
		row--;
		column--;
	}
	/* Byte = row + column /8 % width */
	byteArray->array[((row * byteArray->width) + column)] = value;
	return byteArray;
}

ByteArray* clear(ByteArray *byteArray, int row, int column)
{
	byteArray->array[((row * byteArray->width) + column)] = 0;
	return byteArray;
}

void byteArrayPrint(ByteArray *byteArray, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		printf("(size: %d) Position %d: %X\n", arraySize, i, byteArray->array[i]);
	}
}

int byteArrayToFile(ByteArray *byteArray, int arraySize, const char *filePath)
{
	byteArrayPrint(byteArray, arraySize);
	FILE *outputFile = fopen(filePath, "w");
	int bytesWritten;
	if (strcmp(byteArray->header, P_GREYMAP_BINARY) == 0)
	{
		fputs(getPGMHeader(BINARY, byteArray->width, byteArray->height, 255), outputFile);
	}
	else
	{
		fputs(getPPMHeader(BINARY, byteArray->width, byteArray->height), outputFile);
	}
	bytesWritten = fwrite(byteArray->array, 1, arraySize, outputFile);
	putc(0, outputFile);
	fclose(outputFile);
	return bytesWritten;
}