/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include <stdlib.h>
#include "colour.h"

int colour_getRed(Colour * colour)
{
	return colour->red;
}

int colour_getGreen(Colour * colour)
{
	return colour->green;
}

int colour_getBlue(Colour * colour)
{
	return colour->blue;
}

int colour_getGrey(Colour * colour)
{
	return colour_getRed(colour);
}

Colour * colour_new(int red, int green, int blue)
{
	Colour * colour = malloc(sizeof(*colour));
	colour->red = red;
	colour->green = green;
	colour->blue = blue;
	return colour;
}

Colour * colour_newGrey(int grey)
{
	Colour * colour = malloc(sizeof(*colour));
	colour->red = colour->green = colour->blue = grey;
	return colour;
}
	
void colour_delete(Colour * colour)
{
	free(colour);
}