This is a fork of the Adafruit_GFX library for Arduino and combatible boards. The purpose of the fork is to add capabilities for:
 1. drawing bitmaps stored in an external eeprom (i2c)
 2. drawing bitmaps stored in ram (without the progmem directive)
 3. include user interface widgets
 
This library will be used for the ConnDuino board projects. For more info about the board visit:  www.connduino.com

              INSTALLATION 
=========================================================================
To download, click the DOWNLOAD ZIP button, uncompress and rename the uncompressed folder to "ConnD_GFX". Place the "ConnD_GFX" library folder to your arduino environment "<sketch folder>/libraries" subfolder. You can see, and even change, your <sketch folder> in the IDE under the menu File>Preferences. You may need to create the libraries subfolder if this is your first library. Restart the IDE.


              ADAFRUIT_GFX master, README 
=========================================================================
This is the core graphics library for all our displays, providing a common set of graphics primitives (points, lines, circles, etc.).  It needs to be paired with a hardware-specific library for each display device we carry (to handle the lower-level functions).

Adafruit invests time and resources providing this open source code, please support Adafruit and open-source hardware by purchasing products from Adafruit!

Written by Limor Fried/Ladyada for Adafruit Industries.
BSD license, check license.txt for more information.
All text above must be included in any redistribution.


Useful Resources
================

-  Image2Code
   This is a handy Java GUI utility to convert a BMP file into the array code necessary to display the image with the drawBitmap function.  Check out the code at ehubin's GitHub repository:
     https://github.com/ehubin/Adafruit-GFX-Library/tree/master/Img2Code

-  drawXBitmap function
   You can use the GIMP photo editor to save a .xbm file and use the array saved in the file to draw a bitmap with the drawXBitmap function. See the pull request here for more details:
     https://github.com/adafruit/Adafruit-GFX-Library/pull/31
