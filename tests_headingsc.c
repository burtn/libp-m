#include <stdlib.h>
#include <stdio.h>
#include "headings.h"
#include "definitions.h"

int main()
{
	printf("%s", getPBMHeader(ASCII, 50, 50));
	printf("%s", getPBMHeader(BINARY, 50, 50));
	printf("%s", getPGMHeader(ASCII, 50, 50, 40));
	printf("%s", getPGMHeader(BINARY, 50, 50, 40));
	printf("%s", getPPMHeader(ASCII, 50, 50));
	printf("%s", getPPMHeader(BINARY, 50, 50));
}
