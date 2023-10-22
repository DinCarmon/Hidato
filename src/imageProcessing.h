#ifndef imageProcessing_H

#include <MagickWand/MagickWand.h>
#include "common.h"

#define ThrowWandException(wand)                                            \
{                                                                           \
  char                                                                      \
    *description;                                                           \
                                                                            \
  ExceptionType                                                             \
    severity;                                                               \
                                                                            \
  description=MagickGetException(wand,&severity);                           \
  (void) fprintf(stderr,"%s %s %lu %s\n",GetMagickModule(),description);    \
  description=(char *) MagickRelinquishMemory(description);                 \
  exit(-1);                                                                 \
}

int contrast(char* readFromPath, char* writeToPath);
int readAndDisplay(char* readFromPath);

#endif // imageProcessing_H