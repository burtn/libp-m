#include "definitions.h"
#define B_ARRAY_TYPE unsigned char *

typedef struct ByteArray
{
	B_ARRAY_TYPE array;
	int width;
	int height;
	const char * header;
} ByteArray;

void byteArrayPrint(ByteArray *byteArray, int arraySize);
int bytea_getLastAllocationSize();
ByteArray* newByteArray(int width, int height, const char * magicNumber);
ByteArray* set(ByteArray *byteArray, int row, int column, int value);
ByteArray* clear(ByteArray *byteArray, int row, int column);
int byteArrayToFile(ByteArray *byteArray, int arraySize, const char *filePath);