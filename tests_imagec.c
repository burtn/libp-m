#include <stdio.h>
#include "image.h"
#include "definitions.h"
#include "headings.h"

int main()
{
	Image * myImage = newImage(5, 5, P_BITMAP_BINARY);
	image_setPixel(myImage, 1, 1, NULL);
	image_setPixel(myImage, 2, 2, NULL);
	image_setPixel(myImage, 3, 3, NULL);
	image_setPixel(myImage, 4, 4, NULL);
	image_setPixel(myImage, 5, 5, NULL);
	image_writeToFile(myImage, "image_test_PBM.pbm");
}