#include <stdio.h>
#include "bitarray.h"
#include "definitions.h"
#include "headings.h"

int main()
{
	BitArray * myArray = newBitArray(5, 5);
	set(myArray, 1, 1);
	set(myArray, 2, 2);
	set(myArray, 3, 3);
	set(myArray, 4, 4);
	set(myArray, 5, 5);
	bitArrayPrint(myArray, ba_getLastAllocationSize());
	bitArrayToFile(myArray, ba_getLastAllocationSize(), "test_ba.pbm");
}