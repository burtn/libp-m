/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/
#pragma once
#include "colour.h"
#define B_ARRAY_TYPE unsigned char
#define USE_INDEX_0 0

typedef struct Image
{
	int width;
	int height;
	int size;
	B_ARRAY_TYPE * backing_array;
	const char heading;
} Image;

Image * newImage(int width, int height, const char * type);
int image_writeToFile(Image * image, const char * filePath);
int image_getHeight(Image * image);
int image_getWidth(Image * image);
const char * image_getType(Image * image);
Image * image_setPixel(Image * image, int row, int column, Colour * colour);
Image * image_clearPixel(Image * image, int row, int column);
const char * image_getBackingArray(void * image);
void image_prettyPrint(Image * image);
