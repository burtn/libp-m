int image_saveToFile(void * image, const char * filepath);
int image_getHeight(void * image);
int image_getWidth(void * image);
const char * image_getType(void image);
Image * image_setPixel(int row, int column, Colour * colour);
Image * image_clearPixel(int row, int column, void * image);
const char * image_getBackingArray(void * image);
void image_prettyPrint(void * image);

Image * newImage(int width, int height, const char * type)
{
	Image * image = malloc(sizeof(Image));
	/** Compact files...
	lastAllocation = ceil((width * height)/(double)8);
	bitArray->array = malloc(sizeof(lastAllocation));
	*/
	int bytesPerRow = ceil(width/8.0);
	if (strcmp(type, P_BITMAP_BINARY) == 0)
	{
		image->size = bytesPerRow * height;
	}
	else if (strcmp(type, P_GREYMAP_BINARY) == 0)
	{
		image->size = width * height;
	}
	else
	{
		image->size = 3 * (width * height)
	}
	image->backing_array = malloc(sizeof(image->size));
	image->width = width;
	image->height = height;
	return image;
}