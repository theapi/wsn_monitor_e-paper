#ifndef _TextDisplay_H_
#define _TextDisplay_H_

#include "GxEPD2_GFX.h"

void helloWorld(GxEPD2_GFX& display);
void helloWorldForDummies(GxEPD2_GFX& display);
void helloFullScreenPartialMode(GxEPD2_GFX& display);
void helloArduino(GxEPD2_GFX& display);
void helloEpaper(GxEPD2_GFX& display);
void helloValue(GxEPD2_GFX& display, double v, int digits);
void showFont(GxEPD2_GFX& display, const char name[], const GFXfont* f);
void drawFont(GxEPD2_GFX& display, const char name[], const GFXfont* f);

#endif

