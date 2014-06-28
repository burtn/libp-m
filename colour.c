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

Colour * colour_new(int red, int green, int blue)
{
	Colour * colour = malloc(sizeof(Colour));
	colour->red = red;
	colour->green = green;
	colour->blue = blue;
	return colour;
}

void colour_delete(Colour * colour)
{
	free(colour);
}