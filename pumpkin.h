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
