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



#ifndef HELPMENU_H_INCLUDED
#define HELPMENU_H_INCLUDED


#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

void helpMenu()
{
    bool isHelpMenu = true;

    Image iBGH,iTextMovingP1,iTextMovingP2, iPassivMoveButton, iTextW, iTextA, iTextD, iTextL, iTextU, iTextR, iTextCollect, iTextCareful, iBackButton, iTextBack;
    Texture tBGH,tTextMovingP1,tTextMovingP2, tPassivMoveButton, tTextW, tTextA, tTextD, tTextL, tTextU, tTextR, tTextCollect, tTextCareful, tBackButton, tTextBack;
    Sprite sBGH,sTextMovingP1,sTextMovingP2, sTextW, sTextA, sTextD, sTextL, sTextU, sTextR, sTextCollect, sTextCareful, sBackButton, sTextBack;

    iBGH.loadFromFile("TexturesPack/MainMenuTexture/settingBG.png");
    iTextMovingP1.loadFromFile("TexturesPack/MainMenuTexture/1stplayeR.png");
    iTextMovingP2.loadFromFile("TexturesPack/MainMenuTexture/2ndplayeR.png");
    iPassivMoveButton.loadFromFile("TexturesPack/MainMenuTexture/acriveBoxChoose.png");
    iTextW.loadFromFile("TexturesPack/MainMenuTexture/w.png");
    iTextA.loadFromFile("TexturesPack/MainMenuTexture/a.png");
    iTextD.loadFromFile("TexturesPack/MainMenuTexture/d.png");
    iTextL.loadFromFile("TexturesPack/MainMenuTexture/left.png");
    iTextU.loadFromFile("TexturesPack/MainMenuTexture/up.png");
    iTextR.loadFromFile("TexturesPack/MainMenuTexture/right.png");
    iTextCollect.loadFromFile("TexturesPack/MainMenuTexture/If.png");
    iTextCareful.loadFromFile("TexturesPack/MainMenuTexture/1careful.png");
    iBackButton.loadFromFile("TexturesPack/MainMenuTexture/activeButton.png");
    iTextBack.loadFromFile("TexturesPack/MainMenuTexture/back.png");

    tBGH.loadFromImage(iBGH);
    tTextMovingP1.loadFromImage(iTextMovingP1);
    tTextMovingP2.loadFromImage(iTextMovingP2);
    tPassivMoveButton.loadFromImage(iPassivMoveButton);
    tTextW.loadFromImage(iTextW);
    tTextA.loadFromImage(iTextA);
    tTextD.loadFromImage(iTextD);
    tTextL.loadFromImage(iTextL);
    tTextU.loadFromImage(iTextU);
    tTextR.loadFromImage(iTextR);
    tTextCollect.loadFromImage(iTextCollect);
    tTextCareful.loadFromImage(iTextCareful);
    tBackButton.loadFromImage(iBackButton);
    tTextBack.loadFromImage(iTextBack);

    sBGH.setTexture(tBGH);
    sTextMovingP1.setTexture(tTextMovingP1);
    sTextMovingP2.setTexture(tTextMovingP2);
    sTextW.setTexture(tTextW);
    sTextA.setTexture(tTextA);
    sTextD.setTexture(tTextD);
    sTextL.setTexture(tTextL);
    sTextU.setTexture(tTextU);
    sTextR.setTexture(tTextR);
    sTextCollect.setTexture(tTextCollect);
    sTextCareful.setTexture(tTextCareful);
    sBackButton.setTexture(tBackButton);
    sTextBack.setTexture(tTextBack);

    sTextCollect.setPosition(15,iBGH.getSize().y-iTextCollect.getSize().y-50);
    sTextMovingP1.setPosition(30,50);
    sTextMovingP2.setPosition(iBGH.getSize().x-iTextMovingP2.getSize().x-30,50);
    sBackButton.setPosition(iBGH.getSize().x-iBackButton.getSize().x-30,iBGH.getSize().y-iBackButton.getSize().y-30);
    sTextBack.setPosition(sBackButton.getPosition());

    sTextW.setPosition(sTextMovingP1.getPosition().x+iTextMovingP1.getSize().x/2,sTextMovingP1.getPosition().y+iTextMovingP1.getSize().y);
    sTextA.setPosition(sTextW.getPosition().x-iTextA.getSize().x,sTextW.getPosition().y+iTextA.getSize().y-20);
    sTextD.setPosition(sTextW.getPosition().x+iTextA.getSize().x,sTextA.getPosition().y);

    sTextU.setPosition(sTextMovingP2.getPosition().x+iTextMovingP2.getSize().x/2,sTextMovingP2.getPosition().y+iTextMovingP2.getSize().y);
    sTextL.setPosition(sTextU.getPosition().x-iTextA.getSize().x,sTextU.getPosition().y+iTextA.getSize().y-20);
    sTextR.setPosition(sTextU.getPosition().x+iTextA.getSize().x,sTextA.getPosition().y);

    sTextCareful.setPosition(sTextCareful.getPosition().x+20,sTextCareful.getPosition().y+200);


    Clock helpClock;
    float helpTime;
    helpClock.restart();


    while(isHelpMenu)
    {

        helpTime = helpClock.getElapsedTime().asMicroseconds();
        if(helpTime/800>800)
        {
            if(Keyboard::isKeyPressed(Keyboard::Return))isHelpMenu=false;
        }
        window.draw(sBGH);
        window.draw(sTextMovingP1);
        window.draw(sTextMovingP2);
        window.draw(sTextW);
        window.draw(sTextA);
        window.draw(sTextD);
        window.draw(sTextL);
        window.draw(sTextU);
        window.draw(sTextR);
        window.draw(sTextCollect);
        window.draw(sBackButton);
        window.draw(sTextBack);
        window.draw(sTextCareful);
        window.display();
        window.clear();
    }
}


#endif // HELPMENU_H_INCLUDED
