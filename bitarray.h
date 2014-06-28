#include "definitions.h"
#define B_ARRAY_TYPE unsigned char *

typedef struct BitArray
{
	B_ARRAY_TYPE array;
	int width;
	int height;
} BitArray;

int ba_getLastAllocationSize();
BitArray* newBitArray(int width, int height);
BitArray* set(BitArray *bitArray, int row, int column);
BitArray* clear(BitArray *bitArray, int row, int column);
void bitArrayPrint(BitArray *bitArray, int arraySize);
int bitArrayToFile(BitArray *bitArray, int arraySize, const char *filePath);