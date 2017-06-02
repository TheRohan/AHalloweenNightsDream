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




#ifndef MAINMENU_H_INCLUDED
#define MAINMENU_H_INCLUDED

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include "setting.h"
using namespace std;
using namespace sf;



    int mainMenu()
    {
        SoundBuffer bufferForActive;
        bufferForActive.loadFromFile("Sounds/Select.wav");
        Sound select;
        select.setBuffer(bufferForActive);

        SoundBuffer bufferForChangePos;
        bufferForChangePos.loadFromFile("Sounds/foom_0.wav");
        Sound changePos;
        changePos.setBuffer(bufferForChangePos);

        int check = 0;

        Image startImage,settingImage, exitImage;
        Texture startTexture,settingTexture, exitTexture;
        Sprite startSprite,settingSprite, exitSprite;

        startImage.loadFromFile("TexturesPack/MainMenuTexture/start.png");
        settingImage.loadFromFile("TexturesPack/MainMenuTexture/setting.png");
        exitImage.loadFromFile("TexturesPack/MainMenuTexture/exit.png");

        startTexture.loadFromImage(startImage);
        settingTexture.loadFromImage(settingImage);
        exitTexture.loadFromImage(exitImage);

        startSprite.setTexture(startTexture);
        settingSprite.setTexture(settingTexture);
        exitSprite.setTexture(exitTexture);

        Image b1image, bgimage;
        Texture b1texture, bgtexture;
        Sprite b1sprite, b2sprite, b3sprite, bgsprite;

        Image abimage; //active
        Texture abtexture;
        Sprite absprite;

        b1image.loadFromFile("TexturesPack/MainMenuTexture/passivButton.png"); // load img
        b1texture.loadFromImage(b1image); // set texture

		b1sprite.setTexture(b1texture); // set sprite
		b2sprite.setTexture(b1texture); // set sprite
		b3sprite.setTexture(b1texture); // set sprite

		bgimage.loadFromFile("TexturesPack/MainMenuTexture/mainMenu.png");
		bgtexture.loadFromImage(bgimage);
		bgsprite.setTexture(bgtexture);

        abimage.loadFromFile("TexturesPack/MainMenuTexture/activeButton.png");
		abtexture.loadFromImage(abimage);
		absprite.setTexture(abtexture);

		b1sprite.setTextureRect(IntRect(0, 0, b1image.getSize().x, b1image.getSize().y));
		b2sprite.setTextureRect(IntRect(0, 0, b1image.getSize().x, b1image.getSize().y));
		b3sprite.setTextureRect(IntRect(0, 0, b1image.getSize().x, b1image.getSize().y));
		bgsprite.setTextureRect(IntRect(0, 0, bgimage.getSize().x, bgimage.getSize().y));
		absprite.setTextureRect(IntRect(0, 0, abimage.getSize().x, abimage.getSize().y));
        absprite.setPosition(0,0);
        View menuView;
        menuView.setSize(1280,720);
        menuView.setCenter(bgsprite.getPosition().x+bgimage.getSize().x/2,bgsprite.getPosition().y+bgimage.getSize().y/2);

        b3sprite.setPosition(bgimage.getSize().x/2-b1image.getSize().x/2,bgimage.getSize().y-b1image.getSize().y-40);
        b2sprite.setPosition(bgimage.getSize().x/2-b1image.getSize().x/2,b3sprite.getPosition().y-b1image.getSize().y-20);
        b1sprite.setPosition(bgimage.getSize().x/2-b1image.getSize().x/2,b2sprite.getPosition().y-b1image.getSize().y-20);

        startSprite.setPosition(b1sprite.getPosition());
        settingSprite.setPosition(b2sprite.getPosition());
        exitSprite.setPosition(b3sprite.getPosition());

        Image iPassiveBox, iAcriveBox, iTextQ, iTextC;
        Texture tPassiveBox, tAcriveBox, tTextQ, tTextC;
        Sprite sPassiveBox1,sPassiveBox2, sAcriveBox, sTextQ, sTextC;

        iTextQ.loadFromFile("TexturesPack/MainMenuTexture/quesion.png");
        iPassiveBox.loadFromFile("TexturesPack/MainMenuTexture/passiveBoxChoose.png");
        iAcriveBox.loadFromFile("TexturesPack/MainMenuTexture/acriveBoxChoose.png");
        iTextC.loadFromFile("TexturesPack/MainMenuTexture/pc.png");

        tTextQ.loadFromImage(iTextQ);
        tPassiveBox.loadFromImage(iPassiveBox);
        tAcriveBox.loadFromImage(iAcriveBox);
        tTextC.loadFromImage(iTextC);

        sTextQ.setTexture(tTextQ);
        sPassiveBox1.setTexture(tPassiveBox);
        sPassiveBox2.setTexture(tPassiveBox);
        sAcriveBox.setTexture(tAcriveBox);
        sTextC.setTexture(tTextC);

        sPassiveBox1.setPosition(settingSprite.getPosition().x-iPassiveBox.getSize().x,settingSprite.getPosition().y);
        sPassiveBox2.setPosition(settingSprite.getPosition().x+settingImage.getSize().x,settingSprite.getPosition().y);
        sAcriveBox.setPosition(bgimage.getSize().x,bgimage.getSize().y);
        sTextQ.setPosition(sPassiveBox1.getPosition());
        sTextC.setPosition(sPassiveBox2.getPosition());

        Image iName;
        Texture tName;
        Sprite sName;

        iName.loadFromFile("TexturesPack/MainMenuTexture/DreaM.png");
        tName.loadFromImage(iName);
        sName.setTexture(tName);
        sName.setPosition(bgimage.getSize().x/2-iName.getSize().x/2,10);

        bool menuIsOpen = true;
        absprite.setPosition(b1sprite.getPosition());

        Clock menuClock;
        float menuTime = menuClock.getElapsedTime().asMicroseconds();
		menuClock.restart();
		menuTime /=800;

		int checkLR =1;

        while (menuIsOpen)
        {

            float menuTime = menuClock.getElapsedTime().asMicroseconds();
            menuTime /=1000;
            if(menuTime>300)
            {
                sAcriveBox.setPosition(bgimage.getSize().x,bgimage.getSize().y);
                absprite.setPosition(bgimage.getSize().x,bgimage.getSize().y);
                if(checkLR==0&&check==1){sAcriveBox.setPosition(sPassiveBox1.getPosition());}
                if(checkLR==2&&check==1){sAcriveBox.setPosition(sPassiveBox2.getPosition());}
                if((Keyboard::isKeyPressed(Keyboard::Up))||(Keyboard::isKeyPressed(Keyboard::W)))
                    {check--;if(check < 0)check = 2;menuClock.restart();checkLR=1;changePos.play();}
                if((Keyboard::isKeyPressed(Keyboard::Down))||(Keyboard::isKeyPressed(Keyboard::S)))
                    {check++; if(check > 2)check = 0;menuClock.restart();checkLR=1;changePos.play();}
                if(check==0)absprite.setPosition(b1sprite.getPosition());
                if(check==1&&checkLR==1)absprite.setPosition(b2sprite.getPosition());
                if(check==2)absprite.setPosition(b3sprite.getPosition());
                if(check==1)
                {
                    if((Keyboard::isKeyPressed(Keyboard::D))||(Keyboard::isKeyPressed(Keyboard::Right)))
                    {
                        checkLR++;if(checkLR>1){checkLR=0;}menuClock.restart();select.play();
                    }
                    if((Keyboard::isKeyPressed(Keyboard::A))||(Keyboard::isKeyPressed(Keyboard::Left)))
                    {
                        checkLR--;if(checkLR<0){checkLR=1;}menuClock.restart();select.play();
                    }
                }
                if(check==0&&(Keyboard::isKeyPressed(Keyboard::Return))){return 1;}
                if(check==1&&checkLR==1&&(Keyboard::isKeyPressed(Keyboard::Return))){return 2;select.play();}
                if(check==1&&checkLR==0&&(Keyboard::isKeyPressed(Keyboard::Return))){return 4;select.play();}
                if(check==2&&(Keyboard::isKeyPressed(Keyboard::Return))){return 3;select.play();}

                window.setView(menuView);
                window.draw(bgsprite);
                window.draw(b1sprite);
                window.draw(b2sprite);
                window.draw(b3sprite);
                window.draw(absprite);
                window.draw(startSprite);
                window.draw(settingSprite);
                window.draw(exitSprite);
                window.draw(sPassiveBox1);
                window.draw(sAcriveBox);
                window.draw(sTextQ);
                window.draw(sName);
                window.display();
                window.clear();
            }
        }


    return 0;
    }



#endif // MAINMENU_H_INCLUDED
