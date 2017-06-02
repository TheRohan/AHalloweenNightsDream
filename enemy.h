#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include "player.h"
using namespace std;
using namespace sf;

class Enemy
{
private:
    float x;
    float y;
    string color; //monster's skin
    float minXPosition; //mix X pos
    float maxXPosition; //max X pos
public:
    Clock clockForFrames;
    float frames; // frame
    Clock clockForAfk; //afk time
    float afk; // frame
    bool liveIs; //afk
    bool rightMoveIs;
    Image image;
    Texture texture;
	Sprite sprite;
	int moveFrame;
	Sound ddeadSound;
    SoundBuffer bbdeadSound;
    Enemy(string Color, float minX, float maxX, float X, float Y)
    {
        liveIs = true;
        rightMoveIs = true;
        color=Color;
        minXPosition = minX;
        maxXPosition = maxX;
        x = X;
        y = Y+20;
        image.loadFromFile("TexturesPack/Monster/"+color+"/frame-1.png"); // load img
        texture.loadFromImage(image); // set texture
		sprite.setTexture(texture); // set sprite
        sprite.setTextureRect(IntRect(0, 0, image.getSize().x, image.getSize().y)); //create sprite
		sprite.setPosition(x, y);
    };
    float getPositionX()
    {
        return x;
    }

    float getPositionY()
    {
        return y;
    }

    void setPositionX(float X)
    {
        x = X;
    }

    void setPositionY(float Y)
    {
        x = Y;
    }

    void movingEnemy(float speed, float time)
    {
        if(frames>4)clockForFrames.restart();
        frames = clockForFrames.getElapsedTime().asSeconds();
        frames *=8;
        if(frames<2)moveFrame=1;
        if(frames>2)moveFrame=2;
        if(rightMoveIs&&liveIs)
        {
            setPositionX((getPositionX())+(speed*time));
            sprite.setPosition(x, y);
            image.loadFromFile("TexturesPack/Monster/"+color+"/frame-"+to_string(int32_t(moveFrame))+".png");
            texture.loadFromImage(image);
            sprite.setTextureRect(IntRect(image.getSize().x, 0, -image.getSize().x, image.getSize().y));
                        if(getPositionX()+image.getSize().x>maxXPosition)rightMoveIs=false;
        }
        if(!rightMoveIs&&liveIs)
        {
            setPositionX((getPositionX())-(speed*time));
            sprite.setPosition(x, y);
            image.loadFromFile("TexturesPack/Monster/"+color+"/frame-"+to_string(int32_t(moveFrame))+".png");
            texture.loadFromImage(image);
            sprite.setTextureRect(IntRect(0, 0, image.getSize().x, image.getSize().y));
            if(getPositionX()<minXPosition)rightMoveIs=true;
        }
        if(!liveIs)
        {
            afk = clockForAfk.getElapsedTime().asSeconds();
            if(afk>5)liveIs=true;
            image.loadFromFile("TexturesPack/Monster/"+color+"/gframe-"+to_string(int32_t(moveFrame))+".png");
            texture.loadFromImage(image);
            if(!rightMoveIs)sprite.setTextureRect(IntRect(0, 0, image.getSize().x, image.getSize().y));
            if(rightMoveIs)sprite.setTextureRect(IntRect(image.getSize().x, 0, -image.getSize().x, image.getSize().y));
        }
    }

    void enemyAnim()
    {
        if(frames>4)clockForFrames.restart();
        frames = clockForFrames.getElapsedTime().asSeconds();
        frames *=8;
        if(frames<2)moveFrame=1;
        if(frames>2)moveFrame=2;
        image.loadFromFile("TexturesPack/Monster/"+color+"/frame-"+to_string(int32_t(moveFrame))+".png");
        texture.loadFromImage(image);
        sprite.setTextureRect(IntRect(image.getSize().x, 0, -image.getSize().x, image.getSize().y));
    }

    void collisionWithPlayer(Player player)
    {


        if(player.getPlayerCoordinateY()+player.h<getPositionY()+40)
        {
            bbdeadSound.loadFromFile("Sounds/Hit_02.wav");
            ddeadSound.setBuffer(bbdeadSound);
            ddeadSound.play();
            clockForAfk.restart();
            liveIs = false;
        }
    }
};

#endif // ENEMY_H_INCLUDED
