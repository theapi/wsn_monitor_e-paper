#ifndef _BITMAPS_H_
#define _BITMAPS_H_

#if defined(ESP8266) || defined(ESP32)
#include <pgmspace.h>
#else
#include <avr/pgmspace.h>
#endif

// exported using http://javl.github.io/image2cpp/
// Available locally in tools/iamge2cpp/image2cpp.html

const unsigned char level_empty[] PROGMEM =
{
// 'level_empty', 25x25px
0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x80, 
0xff, 0xff, 0xff, 0x80, 0xea, 0xaa, 0xab, 0x80, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x80, 
0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x80, 0xfa, 0xaa, 0xaf, 0x80, 0xff, 0xff, 0xff, 0x80, 
0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x80, 0xfe, 0xaa, 0xbf, 0x80, 
0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x80, 
0xff, 0xaa, 0xff, 0x80, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x80, 
0xff, 0xff, 0xff, 0x80
};

const unsigned char level_quarter[] PROGMEM =
{
// 'level_quarter', 25x25px
0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x80, 
0xff, 0xff, 0xff, 0x80, 0xea, 0xaa, 0xab, 0x80, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x80, 
0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x80, 0xfa, 0xaa, 0xaf, 0x80, 0xff, 0xff, 0xff, 0x80, 
0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x80, 0xfe, 0xaa, 0xbf, 0x80, 
0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x80, 0xff, 0x80, 0x7f, 0x80, 
0xff, 0x80, 0x7f, 0x80, 0xff, 0x80, 0x7f, 0x80, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x80, 
0xff, 0xff, 0xff, 0x80
};

const unsigned char level_half[] PROGMEM =
{
// 'level_half', 25x25px
0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x80, 
0xff, 0xff, 0xff, 0x80, 0xea, 0xaa, 0xab, 0x80, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x80, 
0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x80, 0xfa, 0xaa, 0xaf, 0x80, 0xff, 0xff, 0xff, 0x80, 
0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x80, 0xfe, 0x00, 0x1f, 0x80, 0xfe, 0x00, 0x1f, 0x80, 
0xfe, 0x00, 0x1f, 0x80, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x80, 0xff, 0x80, 0x7f, 0x80, 
0xff, 0x80, 0x7f, 0x80, 0xff, 0x80, 0x7f, 0x80, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x80, 
0xff, 0xff, 0xff, 0x80
};

const unsigned char level_3quarter[] PROGMEM =
{
// 'level_3quarter', 25x25px
0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x80, 
0xff, 0xff, 0xff, 0x80, 0xea, 0xaa, 0xab, 0x80, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x80, 
0xff, 0xff, 0xff, 0x80, 0xf8, 0x00, 0x0f, 0x80, 0xf8, 0x00, 0x0f, 0x80, 0xf8, 0x00, 0x0f, 0x80, 
0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x80, 0xfe, 0x00, 0x1f, 0x80, 0xfe, 0x00, 0x1f, 0x80, 
0xfe, 0x00, 0x1f, 0x80, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x80, 0xff, 0x80, 0x7f, 0x80, 
0xff, 0x80, 0x7f, 0x80, 0xff, 0x80, 0x7f, 0x80, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x80, 
0xff, 0xff, 0xff, 0x80
};

const unsigned char level_full[] PROGMEM =
{
// 'level_full', 25x25px
0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x80, 
0xe0, 0x00, 0x03, 0x80, 0xe0, 0x00, 0x03, 0x80, 0xe0, 0x00, 0x03, 0x80, 0xff, 0xff, 0xff, 0x80, 
0xff, 0xff, 0xff, 0x80, 0xf8, 0x00, 0x0f, 0x80, 0xf8, 0x00, 0x0f, 0x80, 0xf8, 0x00, 0x0f, 0x80, 
0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x80, 0xfe, 0x00, 0x1f, 0x80, 0xfe, 0x00, 0x1f, 0x80, 
0xfe, 0x00, 0x1f, 0x80, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x80, 0xff, 0x80, 0x7f, 0x80, 
0xff, 0x80, 0x7f, 0x80, 0xff, 0x80, 0x7f, 0x80, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x80, 
0xff, 0xff, 0xff, 0x80
};

const unsigned char water_drop[] PROGMEM =
{
// 'water-drop', 20x30px
0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0x9f, 0xf0, 0xff, 0x9f, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 
0x0f, 0xf0, 0xfe, 0x07, 0xf0, 0xfe, 0x07, 0xf0, 0xfc, 0x03, 0xf0, 0xf8, 0x01, 0xf0, 0xf8, 0x01, 
0xf0, 0xf0, 0x00, 0xf0, 0xe0, 0x00, 0x70, 0xe0, 0x00, 0x70, 0xc0, 0x00, 0x30, 0xc0, 0x00, 0x30, 
0x80, 0x00, 0x10, 0x80, 0x00, 0x10, 0x80, 0x00, 0x10, 0x80, 0x00, 0x10, 0x90, 0x00, 0x10, 0x98, 
0x00, 0x10, 0x98, 0x00, 0x10, 0x88, 0x00, 0x10, 0xce, 0x00, 0x30, 0xc7, 0xc0, 0x30, 0xe1, 0xc0, 
0x70, 0xf8, 0x01, 0xf0, 0xfe, 0x07, 0xf0, 0xff, 0xff, 0xf0
};

const unsigned char flower[] PROGMEM =
{
// 'flower', 30x30px
0xff, 0xf8, 0x3f, 0xfc, 0xff, 0xf0, 0x1f, 0xfc, 0xff, 0xe0, 0x1f, 0xfc, 0xff, 0xe0, 0x0f, 0xfc, 
0xff, 0xe0, 0x0f, 0xfc, 0xff, 0xe0, 0x1f, 0xfc, 0xff, 0xe0, 0x1f, 0xfc, 0xc0, 0xe0, 0x1f, 0xfc, 
0x80, 0x60, 0x3c, 0x1c, 0x00, 0x20, 0x20, 0x04, 0x00, 0x10, 0x40, 0x04, 0x00, 0x0f, 0x00, 0x00, 
0x00, 0x1f, 0x80, 0x00, 0x80, 0x1f, 0x80, 0x00, 0xc0, 0x1f, 0x80, 0x04, 0xf0, 0xdf, 0x80, 0x04, 
0xff, 0x1f, 0x18, 0x1c, 0xfe, 0x00, 0x0f, 0xfc, 0xfc, 0x00, 0x07, 0xfc, 0xf8, 0x00, 0x03, 0xfc, 
0xf0, 0x00, 0x01, 0xfc, 0xf0, 0x00, 0x00, 0xfc, 0xe0, 0x02, 0x00, 0xfc, 0xe0, 0x0a, 0x00, 0x7c, 
0xe0, 0x0a, 0x00, 0x7c, 0xf0, 0x1b, 0x00, 0x7c, 0xf0, 0x1b, 0x80, 0x7c, 0xf8, 0x3b, 0x80, 0xfc, 
0xff, 0xfb, 0xe1, 0xfc, 0xff, 0xfb, 0xff, 0xfc
};

const unsigned char Bitmap1[] PROGMEM =
{
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xc0, 0xff, 0xff, 0xff, 0xc3, 0xff, 0xff, 0xc0, 0xff, 0xff, 0xfe, 0x00, 0x7f, 0xff, 
0xc0, 0xff, 0xff, 0xf8, 0x7e, 0x3f, 0xff, 0xc0, 0xff, 0xff, 0xf1, 0xff, 0x8f, 0xff, 0xc0, 0xff, 
0xff, 0xe3, 0xff, 0xc7, 0xff, 0xc0, 0xff, 0xff, 0xe7, 0xff, 0xe7, 0xff, 0xc0, 0xff, 0xff, 0xcf, 
0xff, 0xf3, 0xff, 0xc0, 0xff, 0xff, 0xdf, 0xe3, 0xfb, 0xff, 0xc0, 0xff, 0xff, 0x9f, 0xc1, 0xf9, 
0xff, 0xc0, 0xff, 0xff, 0x9f, 0x80, 0xf9, 0xff, 0xc0, 0xff, 0xff, 0xbf, 0x00, 0x79, 0xff, 0xc0, 
0xff, 0xff, 0xbe, 0x00, 0x3d, 0xff, 0xc0, 0xff, 0xff, 0xbc, 0x00, 0x1c, 0xff, 0xc0, 0xff, 0xff, 
0xb8, 0x00, 0x04, 0xff, 0xc0, 0xff, 0xff, 0x90, 0x00, 0x02, 0xff, 0xc0, 0xff, 0xff, 0x80, 0x00, 
0x00, 0x7f, 0xc0, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x7f, 0xc0, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x7f, 
0xc0, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x3f, 0xc0, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x0f, 0xc0, 0xff, 
0xff, 0xf0, 0x00, 0x00, 0x0f, 0xc0, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x1f, 0xc0, 0xff, 0xfc, 0xfc, 
0x00, 0x00, 0x3f, 0xc0, 0xff, 0xf0, 0x1e, 0x00, 0x00, 0x7f, 0xc0, 0xff, 0xe0, 0x03, 0x00, 0x00, 
0xff, 0xc0, 0xff, 0xe3, 0x00, 0x00, 0x01, 0xff, 0xc0, 0xff, 0xff, 0xf0, 0x00, 0x03, 0xff, 0xc0, 
0xff, 0xff, 0xfc, 0x00, 0x07, 0xff, 0xc0, 0xff, 0xff, 0xff, 0x80, 0x0f, 0xff, 0xc0, 0xff, 0xf7, 
0xff, 0xe0, 0x1f, 0xff, 0xc0, 0xff, 0xe7, 0xff, 0xf8, 0x3f, 0xff, 0xc0, 0xff, 0xe7, 0xff, 0xfc, 
0x7f, 0xff, 0xc0, 0xff, 0xfd, 0xff, 0xfe, 0xff, 0xff, 0xc0, 0xff, 0x9c, 0xff, 0xff, 0xff, 0xff, 
0xc0, 0xff, 0x9c, 0xff, 0xff, 0xff, 0xff, 0xc0, 0xff, 0xbc, 0xff, 0xff, 0xff, 0xff, 0xc0, 0xfe, 
0xf7, 0xbf, 0xff, 0xff, 0xff, 0xc0, 0xfc, 0xe7, 0x3f, 0xff, 0xff, 0xff, 0xc0, 0xfc, 0xe3, 0x3f, 
0xff, 0xff, 0xff, 0xc0, 0xfe, 0xf7, 0xbf, 0xff, 0xff, 0xff, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0
   };

  
#endif

