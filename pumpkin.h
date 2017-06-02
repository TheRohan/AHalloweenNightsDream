/*
 * Copyright © 2017 Rohan <https://github.com/TheRohan/AHalloweenNightsDream>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */






#ifndef PUMPKIN_H_INCLUDED
#define PUMPKIN_H_INCLUDED

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class PumpkinEvent
{
private:
    int x;
    int y;
public:
    int varForVoordinate = 0;
    int coordinate[6][2] = // pumpkin coordinate X , Y
    {
        {6336,14016},
        {6336,17344},
        {9856,14720},
        {6336,11776},
        {2816,14720},
        {6336,15552}
    };
    Image image;
    Texture texture;
	Sprite sprite;
	PumpkinEvent()
	{
	    image.loadFromFile("TexturesPack/MapTextures/Pumpkin/pumpkinEvent.png"); // load img
        texture.loadFromImage(image); // set texture
		sprite.setTexture(texture); // set sprite
		x = coordinate[0][0]; // set X pos
		y = coordinate[0][1]; // set Y pos
		sprite.setTextureRect(IntRect(0, 0, image.getSize().x, image.getSize().y)); //create sprite
		sprite.setPosition(x, y);
	};
	void setPumpkinCoorX(int X)
	{
	    x = X;
	}
    void setPumpkinCoorY(int Y)
	{
	    x = Y;
	}
	void newPlaceForPumkin()
	{
	    varForVoordinate++;
        if(varForVoordinate>5)
        {
            varForVoordinate = 0;
        }
        sprite.setPosition(coordinate[varForVoordinate][0], coordinate[varForVoordinate][1]);
	}
};


#endif // PUMPKIN_H_INCLUDED
