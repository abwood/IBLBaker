//------------------------------------------------------------------------------------//
//                                                                                    //
//    ._____________.____   __________         __                                     //
//    |   \______   \    |  \______   \_____  |  | __ ___________                     //
//    |   ||    |  _/    |   |    |  _/\__  \ |  |/ // __ \_  __ \                    //
//    |   ||    |   \    |___|    |   \ / __ \|    <\  ___/|  | \/                    //
//    |___||______  /_______ \______  /(____  /__|_ \\___  >__|                       //
//                \/        \/      \/      \/     \/    \/                           //
//                                                                                    //
//    IBLBaker is provided under the MIT License(MIT)                                 //
//    IBLBaker uses portions of other open source software.                           //
//    Please review the LICENSE file for further details.                             //
//                                                                                    //
//    Copyright(c) 2014 Matt Davidson                                                 //
//                                                                                    //
//    Permission is hereby granted, free of charge, to any person obtaining a copy    //
//    of this software and associated documentation files(the "Software"), to deal    //
//    in the Software without restriction, including without limitation the rights    //
//    to use, copy, modify, merge, publish, distribute, sublicense, and / or sell     //
//    copies of the Software, and to permit persons to whom the Software is           //
//    furnished to do so, subject to the following conditions :                       //
//                                                                                    //
//    1. Redistributions of source code must retain the above copyright notice,       //
//    this list of conditions and the following disclaimer.                           //
//    2. Redistributions in binary form must reproduce the above copyright notice,    //
//    this list of conditions and the following disclaimer in the                     //
//    documentation and / or other materials provided with the distribution.          //
//    3. Neither the name of the copyright holder nor the names of its                //
//    contributors may be used to endorse or promote products derived                 //
//    from this software without specific prior written permission.                   //
//                                                                                    //
//    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR      //
//    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,        //
//    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE      //
//    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER          //
//    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,   //
//    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN       //
//    THE SOFTWARE.                                                                   //
//                                                                                    //
//------------------------------------------------------------------------------------//
/* Based on code from the OGRE engine:
-----------------------------------------------------------------------------
This source file is part of OGRE
(Object-oriented Graphics Rendering Engine)
For the latest info, see http://www.ogre3d.org/

Copyright (c) 2000-2012 Torus Knot Software Ltd

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
-----------------------------------------------------------------------------
*/

#include <IblColourValue.h>
#include <IblMath.h>
#include <IblLimits.h>

namespace Bb
{

    const ColourValue ColourValue::ZERO = ColourValue(0.0,0.0,0.0,0.0);
    const ColourValue ColourValue::Black = ColourValue(0.0,0.0,0.0);
    const ColourValue ColourValue::White = ColourValue(1.0,1.0,1.0);
    const ColourValue ColourValue::Red = ColourValue(1.0,0.0,0.0);
    const ColourValue ColourValue::Green = ColourValue(0.0,1.0,0.0);
    const ColourValue ColourValue::Blue = ColourValue(0.0,0.0,1.0);

    //---------------------------------------------------------------------

    RGBA ColourValue::getAsRGBA(void) const
    {
        uint8_t val8;
        uint32_t val32 = 0;

        // Convert to 32bit pattern
        // (RGBA = 8888)

        // Red
        val8 = static_cast<uint8_t>(r * 255);
        val32 = val8 << 24;

        // Green
        val8 = static_cast<uint8_t>(g * 255);
        val32 += val8 << 16;

        // Blue
        val8 = static_cast<uint8_t>(b * 255);
        val32 += val8 << 8;

        // Alpha
        val8 = static_cast<uint8_t>(a * 255);
        val32 += val8;

        return val32;
    }

    ARGB ColourValue::getAsARGB(void) const
    {
        uint8_t val8;
        uint32_t val32 = 0;

        // Convert to 32bit pattern
        // (ARGB = 8888)

        // Alpha
        val8 = static_cast<uint8_t>(a * 255);
        val32 = val8 << 24;

        // Red
        val8 = static_cast<uint8_t>(r * 255);
        val32 += val8 << 16;

        // Green
        val8 = static_cast<uint8_t>(g * 255);
        val32 += val8 << 8;

        // Blue
        val8 = static_cast<uint8_t>(b * 255);
        val32 += val8;


        return val32;
    }

    BGRA ColourValue::getAsBGRA(void) const
    {
        uint8_t val8;
        uint32_t val32 = 0;

        // Convert to 32bit pattern
        // (ARGB = 8888)

        // Blue
        val8 = static_cast<uint8_t>(b * 255);
        val32 = val8 << 24;

        // Green
        val8 = static_cast<uint8_t>(g * 255);
        val32 += val8 << 16;

        // Red
        val8 = static_cast<uint8_t>(r * 255);
        val32 += val8 << 8;

        // Alpha
        val8 = static_cast<uint8_t>(a * 255);
        val32 += val8;


        return val32;
    }

    ABGR ColourValue::getAsABGR(void) const
    {
        uint8_t val8;
        uint32_t val32 = 0;

        // Convert to 32bit pattern
        // (ABRG = 8888)

        // Alpha
        val8 = static_cast<uint8_t>(a * 255);
        val32 = val8 << 24;

        // Blue
        val8 = static_cast<uint8_t>(b * 255);
        val32 += val8 << 16;

        // Green
        val8 = static_cast<uint8_t>(g * 255);
        val32 += val8 << 8;

        // Red
        val8 = static_cast<uint8_t>(r * 255);
        val32 += val8;


        return val32;
    }

    void ColourValue::setAsRGBA(const RGBA val)
    {
        uint32_t val32 = val;

        // Convert from 32bit pattern
        // (RGBA = 8888)

        // Red
        r = ((val32 >> 24) & 0xFF) / 255.0f;

        // Green
        g = ((val32 >> 16) & 0xFF) / 255.0f;

        // Blue
        b = ((val32 >> 8) & 0xFF) / 255.0f;

        // Alpha
        a = (val32 & 0xFF) / 255.0f;
    }

    void ColourValue::setAsARGB(const ARGB val)
    {
        uint32_t val32 = val;

        // Convert from 32bit pattern
        // (ARGB = 8888)

        // Alpha
        a = ((val32 >> 24) & 0xFF) / 255.0f;

        // Red
        r = ((val32 >> 16) & 0xFF) / 255.0f;

        // Green
        g = ((val32 >> 8) & 0xFF) / 255.0f;

        // Blue
        b = (val32 & 0xFF) / 255.0f;
    }

    void ColourValue::setAsBGRA(const BGRA val)
    {
        uint32_t val32 = val;

        // Convert from 32bit pattern
        // (ARGB = 8888)

        // Blue
        b = ((val32 >> 24) & 0xFF) / 255.0f;

        // Green
        g = ((val32 >> 16) & 0xFF) / 255.0f;

        // Red
        r = ((val32 >> 8) & 0xFF) / 255.0f;

        // Alpha
        a = (val32 & 0xFF) / 255.0f;
    }
    //---------------------------------------------------------------------
    void ColourValue::setAsABGR(const ABGR val)
    {
        uint32_t val32 = val;

        // Convert from 32bit pattern
        // (ABGR = 8888)

        // Alpha
        a = ((val32 >> 24) & 0xFF) / 255.0f;

        // Blue
        b = ((val32 >> 16) & 0xFF) / 255.0f;

        // Green
        g = ((val32 >> 8) & 0xFF) / 255.0f;

        // Red
        r = (val32 & 0xFF) / 255.0f;
    }
    //---------------------------------------------------------------------
    bool ColourValue::operator==(const ColourValue& rhs) const
    {
        return (r == rhs.r &&
            g == rhs.g &&
            b == rhs.b &&
            a == rhs.a);
    }
    //---------------------------------------------------------------------
    bool ColourValue::operator!=(const ColourValue& rhs) const
    {
        return !(*this == rhs);
    }
    //---------------------------------------------------------------------
    void ColourValue::setHSB(float  hue, float  saturation, float  brightness)
    {
        // wrap hue
        if (hue > 1.0f)
        {
            hue -= (int)hue;
        }
        else if (hue < 0.0f)
        {
            hue += (int)hue + 1;
        }
        // clamp saturation / brightness
        saturation = Ibl::minValue(saturation, (float )1.0);
        saturation = Ibl::maxValue(saturation, (float )0.0);
        brightness = Ibl::minValue(brightness, (float )1.0);
        brightness = Ibl::maxValue(brightness, (float )0.0);

        if (brightness == 0.0f)
        {   
            // early exit, this has to be black
            r = g = b = 0.0f;
            return;
        }

        if (saturation == 0.0f)
        {   
            // early exit, this has to be grey

            r = g = b = brightness;
            return;
        }


        float  hueDomain  = hue * 6.0f;
        if (hueDomain >= 6.0f)
        {
            // wrap around, and allow mathematical errors
            hueDomain = 0.0f;
        }
        unsigned short domain = (unsigned short)hueDomain;
        float  f1 = brightness * (1 - saturation);
        float  f2 = brightness * (1 - saturation * (hueDomain - domain));
        float  f3 = brightness * (1 - saturation * (1 - (hueDomain - domain)));

        switch (domain)
        {
        case 0:
            // red domain; green ascends
            r = brightness;
            g = f3;
            b = f1;
            break;
        case 1:
            // yellow domain; red descends
            r = f2;
            g = brightness;
            b = f1;
            break;
        case 2:
            // green domain; blue ascends
            r = f1;
            g = brightness;
            b = f3;
            break;
        case 3:
            // cyan domain; green descends
            r = f1;
            g = f2;
            b = brightness;
            break;
        case 4:
            // blue domain; red ascends
            r = f3;
            g = f1;
            b = brightness;
            break;
        case 5:
            // magenta domain; blue descends
            r = brightness;
            g = f1;
            b = f2;
            break;
        }


    }
    //---------------------------------------------------------------------
    void ColourValue::getHSB(float * hue, float * saturation, float * brightness) const
    {

        float  vMin = Ibl::minValue(r, Ibl::minValue(g, b));
        float  vMax = Ibl::maxValue(r, Ibl::maxValue(g, b));
        float  delta = vMax - vMin;

        *brightness = vMax;

        if (Ibl::Limits<float >::isEqual(delta, 0.0f))
        {
            // grey
            *hue = 0;
            *saturation = 0;
        }
        else
        {
            // a colour
            *saturation = delta / vMax;

            float  deltaR = (((vMax - r) / 6.0f) + (delta / 2.0f)) / delta;
            float  deltaG = (((vMax - g) / 6.0f) + (delta / 2.0f)) / delta;
            float  deltaB = (((vMax - b) / 6.0f) + (delta / 2.0f)) / delta;

            if (Ibl::Limits<float >::isEqual(r, vMax))
                *hue = deltaB - deltaG;
            else if (Ibl::Limits<float >::isEqual(g, vMax))
                *hue = 0.3333333f + deltaR - deltaB;
            else if (Ibl::Limits<float >::isEqual(b, vMax)) 
                *hue = 0.6666667f + deltaG - deltaR;

            if (*hue < 0.0f) 
                *hue += 1.0f;
            if (*hue > 1.0f)
                *hue -= 1.0f;
        }

        
    }

}

