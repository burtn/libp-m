#include <stdio.h>
#include "bytearray.h"
#include "definitions.h"
#include "headings.h"

int main()
{
	ByteArray * myArray = newByteArray(5, 5, P_GREYMAP_BINARY);
	set(myArray, 1, 1, 55);
	set(myArray, 2, 2, 55);
	set(myArray, 3, 3, 55);
	set(myArray, 4, 4, 55);
	set(myArray, 5, 5, 55);
	byteArrayToFile(myArray, bytea_getLastAllocationSize(), "test_pgm.pgm");
}