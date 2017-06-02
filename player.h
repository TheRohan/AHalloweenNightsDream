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




#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include "Loader/level.h"
#include "pumpkin.h"
#include "pause.h"
using namespace std;
using namespace sf;


class Player //player's class
{
private:
    float x; // x coordinate
    float y; // y coordinate
    float firstXcoord; //const first X coord
    float firstYCoord; //const first Y coord
public:
    float savedYCoordForDeth; // for deth anim
    Clock clockForTopMoveTime; //DONT FOGOT TO CHECK!! Time's var
    float topMoveTime; // topMoveTime
    float toGetTopMoveTime;
    Clock clockForCurrentFrame;
    float currentFrame;
    Clock clockForStayAnim;
    float stayAnim;
    Clock clockForDethAnim;
    float curretDethAnim; //for anim
    float curretDethAnim2; //for reborn
    float chechGravityY;
    float chechGravityXBegin;
    float chechGravityXEnd;
    enum  { stay, die, right, left, up, upRight, upLeft, down } playerAction; // player's move
    enum  {leftOne, rightOne} playerSide;;
    bool onGroung; // grav
    bool moveLeft;
    bool moveTop;
    bool moveBottom;
    bool moveRight;
    bool moveIs;
    bool rightMovingIs;
    bool liveIs;
    bool deadCheck=true;
    float w; //width
    float h; //height
    float dy; // move by y
    float dx; //move by x
    int collectedPumpkin;
    string nameOfCharacter; //path to...
    float speed; //speed of moving
    String File; //name of img
    Image image;
    Texture texture;
	Sprite sprite;


	Player(String F, float X, float Y, float W, float H,String P)
	{
	    firstXcoord = X;
	    firstYCoord = Y;
	    nameOfCharacter = P;
        topMoveTime = 0;
	    moveBottom = true;
	    moveTop = true;
	    moveIs = true;
        moveLeft =true;
        moveRight = true;
	    onGroung = false;
	    liveIs = true;
	    dy = 0;
	    dx = 0;
	    speed = 0;
	    File = F;
	    w = W;
	    h = H;
	    image.loadFromFile("TexturesPack/Player/"+nameOfCharacter+"/Animation/Run1.png"); //load img
        texture.loadFromImage(image); // get texture
		sprite.setTexture(texture); // set sprite
		x = X; // set X pos
		y = Y; // set Y pos
		sprite.setTextureRect(IntRect(0, 0, image.getSize().x, image.getSize().y)); //create sprite

	}


	void update(float time)
	{
		switch (playerAction)
        {
            case stay: dx = 0; dy = 0; break; // nothing preessed
            case die: dx = 0; dy = 0;  break; // player is dead
            case right: dx = speed*1.5; dy = 0;  break; // pressed - right
            case left: dx = -speed*1.5; dy = 0; break; // pressed - left
            case up: dx = 0; dy= -speed*1.3; onGroung=false; break; // pressed - up
            case upRight: dx = speed; dy = -speed; onGroung=false; break; // pressed - up+right
            case upLeft: dx = -speed; dy = -speed; onGroung=false; break; // pressed up+left
            case down: dy = speed; break; //gravity
        }
        x += dx*time; // update x pos
		y += dy*time; // update y pos
		speed = 0; // clear speed
		sprite.setPosition(x, y); //set sprite pos
	}

	void jump()
	{
        if ((getPlayerCoordinateY()+h+10<chechGravityY)&&!onGroung)
        {

            topMoveTime = clockForTopMoveTime.getElapsedTime().asSeconds();
            toGetTopMoveTime=topMoveTime*8;
		    if(topMoveTime*8>4)toGetTopMoveTime=4;
            image.loadFromFile("TexturesPack/Player/"+nameOfCharacter+"/Animation/Jump"+to_string(int32_t(toGetTopMoveTime))+".png");
            texture.loadFromImage(image);
            if(rightMovingIs)sprite.setTextureRect(IntRect(0, 0, image.getSize().x, image.getSize().y));
            if(!rightMovingIs)sprite.setTextureRect(IntRect(image.getSize().x, 0, -image.getSize().x, image.getSize().y));
        }
        if(topMoveTime>0.6 && !onGroung)
        {
            moveTop = false;
        }

	}

    void graviry(float time, float speed)
    {
        if(!onGroung)
        {
            setPlayerCoordinateY(getPlayerCoordinateY()+time*speed);//30
            sprite.setPosition(getPlayerCoordinateX(),getPlayerCoordinateY());
        }
        if(
        (getPlayerCoordinateX()+w<chechGravityXBegin||getPlayerCoordinateX()>chechGravityXEnd)&&
        !((Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Left))||
        ((Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Right)))))
        {
            moveTop = false;
            onGroung = false;
            image.loadFromFile("TexturesPack/Player/"+nameOfCharacter+"/Animation/Jump4.png");
            texture.loadFromImage(image);
            if(rightMovingIs)sprite.setTextureRect(IntRect(0, 0, image.getSize().x, image.getSize().y));
            if(!rightMovingIs)sprite.setTextureRect(IntRect(image.getSize().x, 0, -image.getSize().x, image.getSize().y));
        }
    }

    float getPlayerCoordinateX() // get x cor
    {
		return x;
	}
	float getPlayerCoordinateY() //get y cor
	{
		return y;
	}
    void setPlayerCoordinateY(float Y)
    {
        y = Y;
    }
    void setPlayerCoordinateX(float X)
    {
        x = X;
    }
    void st()
    {
        setPlayerCoordinateY(getPlayerCoordinateY()+3);
    }
    //moving
        void movingLeftSide()
        {
            moveIs = true;
            rightMovingIs = false;
            moveRight = true;
		    speed = 0.6;
		    playerAction = left;
		    currentFrame = clockForCurrentFrame.getElapsedTime().asSeconds();
		    if(onGroung)
            {
		    if(currentFrame*6>5)
            {
                clockForCurrentFrame.restart();
            }
		    sprite.setPosition(getPlayerCoordinateX(), getPlayerCoordinateY());
            currentFrame = clockForCurrentFrame.getElapsedTime().asSeconds();
            image.loadFromFile("TexturesPack/Player/"+nameOfCharacter+"/Animation/Run"+to_string(int32_t(currentFrame*6))+".png");
            texture.loadFromImage(image);
            w = image.getSize().x;
            h = image.getSize().y;
            }
            sprite.setTextureRect(IntRect(image.getSize().x, 0, -image.getSize().x, image.getSize().y));
        }
        void moveAnim()
        {

            stayAnim = clockForStayAnim.getElapsedTime().asSeconds();
            if(stayAnim*7>5)
            {
                clockForStayAnim.restart();
                stayAnim = clockForStayAnim.getElapsedTime().asSeconds();
            }
            image.loadFromFile("TexturesPack/Player/"+nameOfCharacter+"/Animation/Run"+to_string(int32_t(stayAnim*7))+".png");
            texture.loadFromImage(image);
            w = image.getSize().x;
            h = image.getSize().y;
            if(rightMovingIs)sprite.setTextureRect(IntRect(0, 0, w, h));
            if(!rightMovingIs)sprite.setTextureRect(IntRect(w, 0, -w, h));
        }
        void movingRightSide()
        {
            moveIs = true;
            rightMovingIs = true;
            moveLeft = true;
            speed = 0.6;
            playerAction = right;
            currentFrame = clockForCurrentFrame.getElapsedTime().asSeconds();
            if(onGroung)
            {
                if(currentFrame*6>5)
                {
                    clockForCurrentFrame.restart();
                    currentFrame = clockForCurrentFrame.getElapsedTime().asSeconds();
                }
            sprite.setPosition(getPlayerCoordinateX(), getPlayerCoordinateY());
            image.loadFromFile("TexturesPack/Player/"+nameOfCharacter+"/Animation/Run"+to_string(int32_t(currentFrame*6))+".png");
            texture.loadFromImage(image);
            w = image.getSize().x;
            h = image.getSize().y;
            sprite.setTextureRect(IntRect(0, 0, image.getSize().x, image.getSize().y));
            }
        }
        void movingUpSide()
        {
            moveIs = true;
            topMoveTime = clockForTopMoveTime.getElapsedTime().asSeconds();
            moveBottom = true;
            speed = 1.2;
            playerAction = up;
            sprite.setPosition(getPlayerCoordinateX(), getPlayerCoordinateY());
            onGroung = false;


        }
        void movingUpRightSide()
        {
            moveIs = true;
            rightMovingIs = true;
            topMoveTime = clockForTopMoveTime.getElapsedTime().asSeconds();
            moveBottom = true;
            moveLeft = true;
            speed = 1;
            playerAction = upRight;
            sprite.setPosition(getPlayerCoordinateX(), getPlayerCoordinateY());
            onGroung = false;
        }
        void movingUpLeftSide()
        {
            moveIs = true;
            rightMovingIs = false;
            topMoveTime = clockForTopMoveTime.getElapsedTime().asSeconds();
            moveBottom = true;
            moveRight = true;
            speed = 1;
            playerAction = upLeft;
            sprite.setPosition(getPlayerCoordinateX(), getPlayerCoordinateY());
            onGroung = false;
        }
        void stayMove()
        {
            stayAnim = clockForStayAnim.getElapsedTime().asSeconds();
            if(stayAnim*2>6)
            {
                clockForStayAnim.restart();
                stayAnim = clockForStayAnim.getElapsedTime().asSeconds();
            }
            image.loadFromFile("TexturesPack/Player/"+nameOfCharacter+"/Animation/Idle"+to_string(int32_t(stayAnim*2))+".png");
            texture.loadFromImage(image);
            w = image.getSize().x;
            h = image.getSize().y;
            if(rightMovingIs)sprite.setTextureRect(IntRect(0, 0, w, h));
            if(!rightMovingIs)sprite.setTextureRect(IntRect(w, 0, -w, h));
        }
        void dethAnim()
        {
            savedYCoordForDeth = getPlayerCoordinateY()+h;
            curretDethAnim = clockForDethAnim.getElapsedTime().asSeconds()*8;
            curretDethAnim2 = clockForDethAnim.getElapsedTime().asSeconds()*8;
            if(curretDethAnim>7)
            {
                curretDethAnim=7;
            }
            image.loadFromFile("TexturesPack/Player/"+nameOfCharacter+"/Animation/Dead"+to_string(int32_t(curretDethAnim))+".png");
            texture.loadFromImage(image);
            w = image.getSize().x;
            h = image.getSize().y;
            if(rightMovingIs)sprite.setTextureRect(IntRect(0, 0, w, h));
            if(!rightMovingIs)sprite.setTextureRect(IntRect(w, 0, -w, h));
            setPlayerCoordinateY(getPlayerCoordinateY()+(savedYCoordForDeth-(getPlayerCoordinateY()+h)));
            sprite.setPosition(getPlayerCoordinateX(), getPlayerCoordinateY());
            if(curretDethAnim2>20)
            {
                getRiseAndShine();
            }
        }
        void getRiseAndShine()
        {
            onGroung = false;
            liveIs = true;
            setPlayerCoordinateX(firstXcoord);
            setPlayerCoordinateY(firstYCoord);
            sprite.setPosition(getPlayerCoordinateX(), getPlayerCoordinateY());
        }
};

//collision
void collisionForPlayerObject(LRect &rects, Player &player, float time)
{
	for (auto it = rects.begin(); it != rects.end(); it++)
    {
		if (player.sprite.getGlobalBounds().intersects( (*it)->sSprite->getGlobalBounds() ))
            {
                player.chechGravityY = ((*it)->fRect.top);
                player.chechGravityXBegin = ((*it)->fRect.left);
                player.chechGravityXEnd = ((*it)->fRect.left)+((*it)->fRect.width);
                player.chechGravityY = ((*it)->fRect.top);

                if(
                (player.getPlayerCoordinateX()+player.w < ((*it)->fRect.left)+((*it)->fRect.width)/2)
                    &&
                    (player.getPlayerCoordinateY()<=(((*it)->fRect.top)+((*it)->fRect.height)-80)
                    &&
                    player.getPlayerCoordinateY()+player.h>=(((*it)->fRect.top)+80)))
                {
                    cout<<"right"<<endl;
                    player.setPlayerCoordinateX((*it)->fRect.left-player.w);
                    player.setPlayerCoordinateY(player.getPlayerCoordinateY());
                    player.sprite.setPosition(player.getPlayerCoordinateX(),player.getPlayerCoordinateY());
                    player.moveRight=false;
                    player.moveLeft=true;
                    cout<<player.getPlayerCoordinateX()<<endl;continue;
                }
                if((player.getPlayerCoordinateX() > ((*it)->fRect.left)+((*it)->fRect.width)/2)
                    &&
                    (player.getPlayerCoordinateY()<=(((*it)->fRect.top)+((*it)->fRect.height)-80)
                    &&
                    player.getPlayerCoordinateY()+player.h>=(((*it)->fRect.top)+80)))
                {
                    player.setPlayerCoordinateX((*it)->fRect.left+(*it)->fRect.width);
                    player.setPlayerCoordinateY(player.getPlayerCoordinateY());
                    player.sprite.setPosition(player.getPlayerCoordinateX(),player.getPlayerCoordinateY());
                    player.moveLeft=false;
                    player.moveRight=true;
                    cout<<player.getPlayerCoordinateX()<<endl;
                    cout<<"left"<<endl; continue;
                }

                if((player.getPlayerCoordinateY()<(((*it)->fRect.top)+(*it)->fRect.height/2))
                    &&
                    (player.getPlayerCoordinateX()+player.w)>=((*it)->fRect.left)
                    &&
                    (player.getPlayerCoordinateX()<=(*it)->fRect.left+(*it)->fRect.width))
                {
                    player.image.loadFromFile("TexturesPack/Player/"+player.nameOfCharacter+"/Animation/Idle1.png");
                    player.texture.loadFromImage(player.image);
                    player.w = player.image.getSize().x;
                    player.h = player.image.getSize().y;
                    if(player.rightMovingIs)player.sprite.setTextureRect(IntRect(0, 0, player.image.getSize().x, player.image.getSize().y));
                    if(!player.rightMovingIs)player.sprite.setTextureRect(IntRect(player.image.getSize().x, 0, -player.image.getSize().x, player.image.getSize().y));
                    player.clockForTopMoveTime.restart();
                    player.topMoveTime = 0;
                    player.moveTop=true;
                    player.moveLeft=true;
                    player.moveRight=true;
                    player.setPlayerCoordinateY((*it)->fRect.top-player.h-8);
                    player.sprite.setPosition(player.getPlayerCoordinateY(),player.getPlayerCoordinateY());
                    cout<<player.getPlayerCoordinateY()<<endl;
                    player.moveBottom = false;
                    player.onGroung = true;
                    cout<<"bot"<<endl; continue;
                }
               if(((player.getPlayerCoordinateY()>((*it)->fRect.top)+((*it)->fRect.height/2)))
                    &&
                    (player.getPlayerCoordinateX()+player.w)>=((*it)->fRect.left)
                    &&
                    (player.getPlayerCoordinateX()<=(*it)->fRect.left+(*it)->fRect.width))
                {
                    player.setPlayerCoordinateY((*it)->fRect.top+(*it)->fRect.height);
                    player.sprite.setPosition(player.getPlayerCoordinateY(),player.getPlayerCoordinateY());
                    cout<<player.getPlayerCoordinateY()<<endl;
                    player.moveTop=false;
                    player.moveBottom=true;
                    cout<<"top"<<endl; continue;
                }
            }
    }
}



#endif // PLAYER_H_INCLUDED
