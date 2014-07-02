#include "reader.h"
#include "image.h"

int main()
{
	Image * myImage = reader_imageFromFile("image_test_PBM.pbm");
	image_writeToFile(myImage, "reader_test_out.pbm");
}