/*
 LCD.h - LCD library for GR-LYCHEE and GR-PEACH
 Copyright (c) 2018 Renesas Electronics.  All right reserved.

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef LCD_H_
#define LCD_H_

#include "mbed.h"
#if defined(TARGET_GR_LYCHEE)
#include "LCD_config_lychee.h"
#elif defined(TARGET_RZ_A1H)
#include "LCD_shield_config_4_3inch.h"
#endif


class LCD {
public:
	enum {
		FORMAT_YUV422 = 0,
		FORMAT_RGB888,
	};

	LCD(uint16_t width = LCD_PIXEL_WIDTH, uint16_t height = LCD_PIXEL_HEIGHT, uint8_t format = FORMAT_YUV422);
	~LCD();
	void begin(uint8_t* buf, uint16_t image_width, uint16_t image_height);
	void stop();
	void restart();
	void restart(uint8_t* buf);
	void clear();
	uint16_t getWidth();
	uint16_t getHeight();
	void BGR2YUV(uint8_t* inbuf, uint8_t* outbuf, int width, int height);
	void GRAY2YUV(uint8_t* inbuf, uint8_t* outbuf, int width, int height);

private:
	uint16_t _width;
	uint16_t _height;
	uint8_t _format;
	uint8_t* _buf;
};

#endif /* Camera_h */
