#pragma once

#define P_BITMAP_ASCII "P1"
#define P_BITMAP_BINARY "P4"
#define P_GREYMAP_ASCII	"P2"
#define P_GREYMAP_BINARY "P5"
#define P_PIXMAP_ASCII	"P3"
#define P_PIXMAP_BINARY "P6"
#define EXT_PBM ".pbm"
#define EXT_PGM ".pgm"
#define EXT_PPM ".ppm"
#define BINARY 1
#define ASCII 0
#define COLOUR_MAX 255

#define LEN(x)  (sizeof(x) / sizeof(x[0]))

typedef const char * string_t;

static int constrain(float x, int a, int b)
{
	if (x < a)
	{
		return a;
	}
	
	if (x > b)
	{
		return b;
	}
	
	return floor(x);
}

static long fileSize(const char* filePath)
{
  struct stat stat_buffer;
  stat(filePath, &stat_buffer);
  return stata_buffer.st_size;
}
