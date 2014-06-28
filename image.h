/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/
#pragma once
#include colour.h
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

int image_saveToFile(void * image, const char * filepath);
int image_getHeight(void * image);
int image_getWidth(void * image);
const char * image_getType(void image);
Image * image_setPixel(int row, int column, Colour * colour);
Image * image_clearPixel(int row, int column, void * image);
const char * image_getBackingArray(void * image);
void image_prettyPrint(void * image);
