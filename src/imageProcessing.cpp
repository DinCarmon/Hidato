#include "imageProcessing.h"

int contrast(char* readFromPath, char* writeToPath)
{
#define SigmoidalContrast(x) \
  (QuantumRange*(1.0/(1+exp(10.0*(0.5-QuantumScale*x)))-0.0066928509)*1.0092503)

    long y;
    MagickBooleanType status;
    MagickWand * contrast_wand, * image_wand;
    PixelInfo pixel;
    PixelIterator * contrast_iterator, * iterator;
    PixelWand ** contrast_pixels, ** pixels;
    register long x;
    size_t width;

    /*
      Read an image.
    */
    MagickWandGenesis();
    image_wand = NewMagickWand();
    status = MagickReadImage(image_wand, readFromPath);
    if (status == MagickFalse)
        ThrowWandException(image_wand);
    contrast_wand = CloneMagickWand(image_wand);
    /*
      Sigmoidal non-linearity contrast control.
    */
    iterator = NewPixelIterator(image_wand);
    contrast_iterator = NewPixelIterator(contrast_wand);
    if ((iterator == (PixelIterator*)NULL) ||
        (contrast_iterator == (PixelIterator*)NULL))
        ThrowWandException(image_wand);
    for (y = 0; y < (long)MagickGetImageHeight(image_wand); y++)
    {
        pixels = PixelGetNextIteratorRow(iterator, &width);
        contrast_pixels = PixelGetNextIteratorRow(contrast_iterator, &width);
        if ((pixels == (PixelWand**)NULL) ||
            (contrast_pixels == (PixelWand**)NULL))
            break;
        for (x = 0; x < (long)width; x++)
        {
            PixelGetMagickColor(pixels[x], &pixel);
            pixel.red = SigmoidalContrast(pixel.red);
            pixel.green = SigmoidalContrast(pixel.green);
            pixel.blue = SigmoidalContrast(pixel.blue);
            pixel.index = SigmoidalContrast(pixel.index);
            PixelSetPixelColor(contrast_pixels[x], &pixel);
        }
        (void)PixelSyncIterator(contrast_iterator);
    }
    if (y < (long)MagickGetImageHeight(image_wand))
        ThrowWandException(image_wand);
    contrast_iterator = DestroyPixelIterator(contrast_iterator);
    iterator = DestroyPixelIterator(iterator);
    image_wand = DestroyMagickWand(image_wand);
    /*
      Write the image then destroy it.
    */
    status = MagickWriteImages(contrast_wand, writeToPath, MagickTrue);
    if (status == MagickFalse)
        ThrowWandException(image_wand);
    contrast_wand = DestroyMagickWand(contrast_wand);
    MagickWandTerminus();
    return(0);
}

int readAndDisplay(char* readFromPath)
{
    // Read the image file as 
    // imread("default.jpg"); 
    Mat image = imread(readFromPath,
        IMREAD_GRAYSCALE);

    // Error Handling 
    if (image.empty()) {
        std::cout << "Image File "
            << "Not Found" << std::endl;

        // wait for any key press 
        std::cin.get();
        return -1;
    }

    // Show Image inside a window with 
    // the name provided 
    imshow("Window Name", image);

    // Wait for any keystroke 
    waitKey(0);
    return 0;
}