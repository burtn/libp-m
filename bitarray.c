#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "definitions.h"
#include "headings.h"
#include "bitarray.h"
#define USE_INDEX_0 0

int lastAllocation;

int ba_getLastAllocationSize()
{
	printf("Last allocated %d bytes.\n", lastAllocation);
	return lastAllocation;
}

BitArray* newBitArray(int width, int height)
{
	BitArray *bitArray = malloc(sizeof(BitArray));
	/** Compact files...
	lastAllocation = ceil((width * height)/(double)8);
	bitArray->array = malloc(sizeof(lastAllocation));
	*/
	int bytesPerRow = ceil(width/8.0);
	lastAllocation = bytesPerRow * height;
	bitArray->array = malloc(sizeof(lastAllocation));
	bitArray->width = width;
	bitArray->height = height;
	return bitArray;
}

BitArray* set(BitArray *bitArray, int row, int column)
{
	if (!USE_INDEX_0)
	{
		row--;
		column--;
	}
	/** For compact files...
	printf("Set in byte %d @ bit %d.\n", ((row * bitArray->width) + column)/8, ((row * bitArray->width) + column) %8);
	bitArray->array[((row * bitArray->width) + column)/8] |= (0x80 >> (((row * bitArray->width) + column) %8));
	*/
	/* Byte = row + column /8 % width */
	int bytesPerRow = ceil(bitArray->width/8.0);
	bitArray->array[((row * bytesPerRow) + (column / 8))] |= (0x80 >> (column % 8));
	printf("Set in byte %d @ bit %d.\n", ((row * bytesPerRow) + (column / 8)), (0x80 >> (column % 8)));
	return bitArray;
}

BitArray* clear(BitArray *bitArray, int row, int column)
{
	bitArray->array[((row * bitArray->width) + column)/8] |= (0x7F >> (((row * bitArray->width) + column) %8));
	return bitArray;
}

void bitArrayPrint(BitArray *bitArray, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		printf("(size: %d) Position %d: %X\n", arraySize, i, bitArray->array[i]);
	}
}

int bitArrayToFile(BitArray *bitArray, int arraySize, const char *filePath)
{
	FILE *outputFile = fopen(filePath, "w");
	int bytesWritten;
	fputs(getPBMHeader(BINARY, bitArray->width, bitArray->height), outputFile);
	bytesWritten = fwrite(bitArray->array, 1, arraySize, outputFile);
	putc(0, outputFile);
	fclose(outputFile);
	return bytesWritten;
}