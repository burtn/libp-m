/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/
#pragma once

typedef struct Colour
{
	int red;
	int green;
	int blue;
} Colour;

int colour_getRed(Colour * colour);
int colour_getGreen(Colour * colour);
int colour_getBlue(Colour * colour);

Colour * colour_new(int red, int green, int blue);
void colour_delete(Colour * colour);