#ifndef _CONNDUINO_GFX_H
#define _CONNDUINO_GFX_H

#if ARDUINO >= 100
 #include "Arduino.h"
 #include "Print.h"
#else
 #include "WProgram.h"
#endif

#define swap(a, b) { int16_t t = a; a = b; b = t; }

class eepromI2C;	//forward decl

class ConnD_GFX : public Print {

 protected:	
	 eepromI2C* _ee;				//object for interfacing an eeprom i2c module. Used by the i2c routines 

	 uint8_t   _fontByteH;			//the byte height of each char (number of bytes per column)
	 char      _fontFirstChar;
	 char      _fontLastChar;
	 uint16_t  _fontDataAddr0;		//the 1st mem address of actual font pixel data
	 uint8_t*  _fontCharW;			//an array where the widths of each font char is stored  
	 uint16_t* _fontCharOffset;		//an array where the offset of each char from 1st one is stored (in bytes)
	


 public:

  ConnD_GFX(int16_t w, int16_t h); // Constructor

  // This MUST be defined by the subclass:
  virtual void drawPixel(int16_t x, int16_t y, uint16_t color) = 0;

  // These MAY be overridden by the subclass to provide device-specific
  // optimized code.  Otherwise 'generic' versions are used.
  virtual void  drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
  virtual void  drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color);
  virtual void  drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color);
  virtual void  drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
  virtual void  fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
  virtual void  fillScreen(uint16_t color);
  virtual void  invertDisplay(boolean i);

  //eeprom setup
  void  useEEPROM(eepromI2C& eeObj);

  //fonts
  //read and store character widths & offsets in array. Should have sufficient size. 
  void  useFont_i2c(uint16_t memAddr, uint8_t* charWidths, uint16_t* charOffsets);	



  // These exist only with Adafruit_GFX (no subclass overrides)
  void	drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
  
  void	drawCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername,
                          uint16_t color);
  void	fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
  
  void	fillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername,
						 int16_t delta, uint16_t color);
                     
  void	drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1,
                        int16_t x2, int16_t y2, uint16_t color);
                        
  void	fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1,
                        int16_t x2, int16_t y2, uint16_t color);
                        
  void	drawRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h,
                         int16_t radius, uint16_t color);
                         
  void	fillRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h,
                         int16_t radius, uint16_t color);
                         
  void	drawBitmap(int16_t x, int16_t y, const uint8_t *bitmap,
                      int16_t w, int16_t h, uint16_t color);
                      
  void	drawBitmap(int16_t x, int16_t y, const uint8_t *bitmap,
                       int16_t w, int16_t h, uint16_t color, uint16_t bg);
                       
  void	drawBitmapInSketch	(int16_t x, int16_t y, const  uint8_t *bitmap,
							  int16_t w, int16_t h, uint16_t color);

  void  drawBitmap_i2c(int16_t x, int16_t y, int16_t memAddr,
									int16_t w, int16_t h, uint16_t color);

  void  drawBitmap2_i2c(int16_t x, int16_t y, int16_t memAddr,
									int16_t w, int16_t h, uint16_t color);

  void	drawXBitmap(int16_t x, int16_t y, const uint8_t *bitmap, 
                       int16_t w, int16_t h, uint16_t color);
  void	drawChar(int16_t x, int16_t y, unsigned char c, uint16_t color,
                    uint16_t bg, uint8_t size);

  void  drawChar_i2c(int16_t x, int16_t y, unsigned char c, uint16_t color, uint16_t bg);

                    
  void	setCursor(int16_t x, int16_t y);
  void	setTextColor(uint16_t c);
  void	setTextColor(uint16_t c, uint16_t bg);
  void	setTextSize(uint8_t s);
  void	setTextWrap(boolean w);
  void	setRotation(uint8_t r);

#if ARDUINO >= 100
  virtual size_t write(uint8_t);
#else
  virtual void   write(uint8_t);
#endif

  int16_t height(void) const;
  int16_t width(void) const;

  uint8_t getRotation(void) const;

 protected:
  const int16_t
    WIDTH, HEIGHT;   // This is the 'raw' display w/h - never changes
  int16_t
    _width, _height, // Display w/h as modified by current rotation
    cursor_x, cursor_y;
  uint16_t
    textcolor, textbgcolor;
  uint8_t
    textsize,
    rotation;
  boolean
    wrap; // If set, 'wrap' text at right edge of display
};

#endif // _CONNDUINO_GFX_H
