#include <stdio.h>
#include <stdlib.h>
#include "image.h"
#include "definitions.h"
#include "headings.h"
#include "colour.h"


int main()
{
	printf("Generating PBM...\n");
	Image * myImage = newImage(5, 5, P_BITMAP_BINARY);
	image_setPixel(myImage, 1, 1, BLACK);
	image_setPixel(myImage, 2, 2, BLACK);
	image_setPixel(myImage, 3, 3, BLACK);
	image_setPixel(myImage, 4, 4, BLACK);
	image_setPixel(myImage, 5, 5, BLACK);
	image_writeToFile(myImage, "image_test_PBM.pbm");
	
	printf("Generating PGM...\n");
	Image * myPGMImage = image_makeGreyscale(newImage(5, 5, P_GREYMAP_BINARY), 100);
	image_setPixel(myPGMImage, 1, 1, colour_newGrey(50));
	image_setPixel(myPGMImage, 2, 2, colour_newGrey(60));
	image_setPixel(myPGMImage, 3, 3, colour_newGrey(70));
	image_setPixel(myPGMImage, 4, 4, colour_newGrey(80));
	image_setPixel(myPGMImage, 5, 5, colour_newGrey(90));
	
	image_writeToFile(myPGMImage, "image_test_PGM.pgm");

}