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







#ifndef SETTING_H_INCLUDED
#define SETTING_H_INCLUDED

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

using namespace std;
using namespace sf;
sf::RenderWindow window(sf::VideoMode(1366, 768), "A Halloween Night's Dream", Style::None);
int choose = 0;
sf::Music mainTheme;


void music()
{
    mainTheme.openFromFile("Sounds/Profondeurs.flac");
    mainTheme.setLoop(true);
}

void backpl()
{

    SoundBuffer bufferForBack;
    bufferForBack.loadFromFile("Sounds/Back.wav");
    Sound changeBack;
    changeBack.setBuffer(bufferForBack);

}


class settingsClass
{
private:
    string textureForPlayer1;
    string textureForPlayer2;
    int limitOfOgjects;
public:
    settingsClass()
    {
        textureForPlayer1 = "P1";
        textureForPlayer2 = "P1";
        limitOfOgjects = 5;
    };
    void setTextureForPlayer1(string tmp)
    {
        textureForPlayer1 = tmp;
    }
    void setTextureForPlayer2(string tmp)
    {
        textureForPlayer2 = tmp;
    }
    void setLimitOfOgjects(int tmp)
    {
        limitOfOgjects = tmp;
    }
    string getTextureForPlayer1()
    {
        return textureForPlayer1;
    }
    string getTextureForPlayer2()
    {
        return textureForPlayer2;
    }
    int getLimitOfOgjects()
    {
        return limitOfOgjects;
    }
};
settingsClass settings;

void settingMenu()
{

    SoundBuffer bufferForActive;
    bufferForActive.loadFromFile("Sounds/Select.wav");
    Sound select;
    select.setBuffer(bufferForActive);

    SoundBuffer bufferForChangePos;
    bufferForChangePos.loadFromFile("Sounds/foom_0.wav");
    Sound changePos;
    changePos.setBuffer(bufferForChangePos);



    Image iBackGround, iPassivB, iActiveB, iPBox, iABox, iBackPassive, iBackActive;
    Texture tBackGround, TPassivB, tActiveB, tPBox, tABox, tBackPassive, tBackActive;
    Sprite s1Player, s2Player, sBack, sBackGround , s5, s10, s15,s20;

    iBackGround.loadFromFile("TexturesPack/MainMenuTexture/settingBG.png");
    iPassivB.loadFromFile("TexturesPack/MainMenuTexture/passiveButtonChoose.png");
    iActiveB.loadFromFile("TexturesPack/MainMenuTexture/activeButtonChoose.png");
    iPBox.loadFromFile("TexturesPack/MainMenuTexture/passiveBoxChoose.png");
    iABox.loadFromFile("TexturesPack/MainMenuTexture/acriveBoxChoose.png");
    iBackPassive.loadFromFile("TexturesPack/MainMenuTexture/passivButton.png");
    iBackActive.loadFromFile("TexturesPack/MainMenuTexture/activeButton.png");

    tBackGround.loadFromImage(iBackGround);
    TPassivB.loadFromImage(iPassivB);
    tActiveB.loadFromImage(iActiveB);
    tPBox.loadFromImage(iPBox);
    tABox.loadFromImage(iABox);
    tBackPassive.loadFromImage(iBackPassive);
    tBackActive.loadFromImage(iBackActive);

    s1Player.setTexture(TPassivB);
    s2Player.setTexture(TPassivB);
    sBackGround.setTexture(tBackGround);
    sBack.setTexture(tBackPassive);
    s5.setTexture(tPBox);
    s10.setTexture(tPBox);
    s15.setTexture(tPBox);
    s20.setTexture(tPBox);

    s1Player.setPosition(iBackGround.getSize().x/2-iPassivB.getSize().x/2,35);
    s2Player.setPosition(iBackGround.getSize().x/2-iPassivB.getSize().x/2, s1Player.getPosition().y+iPassivB.getSize().y+35);
    sBack.setPosition(iBackGround.getSize().x/2-iBackPassive.getSize().x/2,iBackGround.getSize().y-iBackPassive.getSize().y-35);
    s10.setPosition(iBackGround.getSize().x/2-iPBox.getSize().x-iPBox.getSize().x/2,s2Player.getPosition().y+iPassivB.getSize().y+35);
    s5.setPosition(s10.getPosition().x-iPBox.getSize().x*2,s2Player.getPosition().y+iPassivB.getSize().y+35);
    s15.setPosition(iBackGround.getSize().x/2+iPBox.getSize().x/2,s2Player.getPosition().y+iPassivB.getSize().y+35);
    s20.setPosition(s15.getPosition().x+iPBox.getSize().x*2,s2Player.getPosition().y+iPassivB.getSize().y+35);

    Image iPlayer1SetTextureText,iPlayer2SetTextureText, iText5,iText10,iText15,iText20,iTextBack;//text
    Texture tPlayer1SetTextureText,tPlayer2SetTextureText, tText5,tText10,tText15,tText20,tTextBack;
    Sprite sPlayer1SetTextureText,sPlayer2SetTextureText, sText5,sText10,sText15,sText20,sTextBack;

    iPlayer1SetTextureText.loadFromFile("TexturesPack/MainMenuTexture/player1.png");
    iPlayer2SetTextureText.loadFromFile("TexturesPack/MainMenuTexture/player2.png");
    iText5.loadFromFile("TexturesPack/MainMenuTexture/t5.png");
    iText10.loadFromFile("TexturesPack/MainMenuTexture/t10.png");
    iText15.loadFromFile("TexturesPack/MainMenuTexture/t15.png");
    iText20.loadFromFile("TexturesPack/MainMenuTexture/t20.png");
    iTextBack.loadFromFile("TexturesPack/MainMenuTexture/back.png");

    tPlayer1SetTextureText.loadFromImage(iPlayer1SetTextureText);
    tPlayer2SetTextureText.loadFromImage(iPlayer2SetTextureText);
    tText5.loadFromImage(iText5);
    tText10.loadFromImage(iText10);
    tText15.loadFromImage(iText15);
    tText20.loadFromImage(iText20);
    tTextBack.loadFromImage(iTextBack);

    sPlayer1SetTextureText.setTexture(tPlayer1SetTextureText);
    sPlayer2SetTextureText.setTexture(tPlayer2SetTextureText);
    sText5.setTexture(tText5);
    sText10.setTexture(tText10);
    sText15.setTexture(tText15);
    sText20.setTexture(tText20);
    sTextBack.setTexture(tTextBack);

    sPlayer1SetTextureText.setPosition(s1Player.getPosition().x+100,s1Player.getPosition().y);
    sPlayer2SetTextureText.setPosition(s2Player.getPosition().x+100,s2Player.getPosition().y);
    sText5.setPosition(s5.getPosition());
    sText10.setPosition(s10.getPosition());
    sText15.setPosition(s15.getPosition());
    sText20.setPosition(s20.getPosition());
    sTextBack.setPosition(sBack.getPosition());

    int checkSettingX =0;
    int checkSettingY =0;
    int setTextureFor1stPlayer=0;
    int setTextureFor2ndPlayer=0;

    bool settingIsOpen = true;

    string animPlayer1 = "P1";
    string animPlayer2 = "P2";

    Image i1PlayerAnim, i2PlayerAnim;
    Texture t1PlayerAnim, t2PlayerAnim;
    Sprite s1PlayerAnim, s2PlayerAnim;

    i1PlayerAnim.loadFromFile("TexturesPack/Player/P"+to_string(setTextureFor1stPlayer+1)+"/Animation/Walk1.png");
    i2PlayerAnim.loadFromFile("TexturesPack/Player/P"+to_string(setTextureFor2ndPlayer+1)+"/Animation/Walk1.png");

    t1PlayerAnim.loadFromImage(i1PlayerAnim);
    t2PlayerAnim.loadFromImage(i2PlayerAnim);

    s1PlayerAnim.setTexture(t1PlayerAnim);
    s2PlayerAnim.setTexture(t2PlayerAnim);

    s1PlayerAnim.setTextureRect(IntRect(0, 0, i1PlayerAnim.getSize().x, i1PlayerAnim.getSize().y));
    s2PlayerAnim.setTextureRect(IntRect(i2PlayerAnim.getSize().x, 0, -i2PlayerAnim.getSize().x, i2PlayerAnim.getSize().y));

    s1PlayerAnim.setPosition(sPlayer1SetTextureText.getPosition().x-300,sPlayer1SetTextureText.getPosition().y);
    s2PlayerAnim.setPosition(sPlayer1SetTextureText.getPosition().x+iPlayer1SetTextureText.getSize().x+170,sPlayer1SetTextureText.getPosition().y);

    Clock clockForTextureAnum;
    float timeForTextureAnum = clockForTextureAnum.getElapsedTime().asMicroseconds();

    Clock settingClock;
    float settingTime = settingClock.getElapsedTime().asMicroseconds();
    settingClock.restart();
    settingTime /=800;
    while (settingIsOpen)
    {
        settingTime = settingClock.getElapsedTime().asMicroseconds();
        settingTime /=1000;
        if(settingTime>300)
            {
            s1Player.setTexture(TPassivB); //redrawing textures
            s2Player.setTexture(TPassivB);
            sBack.setTexture(tBackPassive);
            s5.setTexture(tPBox);
            s10.setTexture(tPBox);
            s15.setTexture(tPBox);
            s20.setTexture(tPBox);


            if((Keyboard::isKeyPressed(Keyboard::Up))||(Keyboard::isKeyPressed(Keyboard::W))) //moving button UP-DOWN
                {
                    checkSettingX--;if(checkSettingX < 0)checkSettingX = 3;settingClock.restart();changePos.play();
                }
            if((Keyboard::isKeyPressed(Keyboard::Down))||(Keyboard::isKeyPressed(Keyboard::S)))
                {
                    checkSettingX++; if(checkSettingX > 3)checkSettingX = 0;settingClock.restart();changePos.play();
                }

            if(checkSettingX==0){s1Player.setTexture(tActiveB);} //1st player choose
            if(checkSettingX==0)
            {
                if((Keyboard::isKeyPressed(Keyboard::Left))||(Keyboard::isKeyPressed(Keyboard::A)))
                {
                    setTextureFor1stPlayer--;if(setTextureFor1stPlayer < 0)setTextureFor1stPlayer = 3;settingClock.restart();select.play();
                }
                if((Keyboard::isKeyPressed(Keyboard::Right))||(Keyboard::isKeyPressed(Keyboard::D)))
                {
                    setTextureFor1stPlayer++;if(setTextureFor1stPlayer > 3)setTextureFor1stPlayer = 0;settingClock.restart();select.play();
                }
            }
            settings.setTextureForPlayer1("P"+to_string(setTextureFor1stPlayer+1));

            if(checkSettingX==1){s2Player.setTexture(tActiveB);}//2nd player choose
            if(checkSettingX==1)
            {
                if((Keyboard::isKeyPressed(Keyboard::Left))||(Keyboard::isKeyPressed(Keyboard::A)))
                {
                    setTextureFor2ndPlayer--;if(setTextureFor2ndPlayer < 0)setTextureFor2ndPlayer = 3;settingClock.restart();select.play();
                }
                if((Keyboard::isKeyPressed(Keyboard::Right))||(Keyboard::isKeyPressed(Keyboard::D)))
                {
                    setTextureFor2ndPlayer++;if(setTextureFor2ndPlayer > 3)setTextureFor2ndPlayer = 0;settingClock.restart();select.play();
                }
            }
            settings.setTextureForPlayer2("P"+to_string(setTextureFor2ndPlayer+1));

            if(checkSettingY==0){s5.setTexture(tABox);} //limit choose
            if(checkSettingY==1){s10.setTexture(tABox);}
            if(checkSettingY==2){s15.setTexture(tABox);}
            if(checkSettingY==3){s20.setTexture(tABox);}
            if(checkSettingX==2)
            {
                if((Keyboard::isKeyPressed(Keyboard::Left))||(Keyboard::isKeyPressed(Keyboard::A)))
                {
                    checkSettingY--;if(checkSettingY < 0)checkSettingY = 3;settingClock.restart();select.play();
                }
                if((Keyboard::isKeyPressed(Keyboard::Right))||(Keyboard::isKeyPressed(Keyboard::D)))
                {
                    checkSettingY++;if(checkSettingY > 3)checkSettingY = 0;settingClock.restart();select.play();
                }
            }
            settings.setLimitOfOgjects(5*(checkSettingY+1));


            timeForTextureAnum = clockForTextureAnum.getElapsedTime().asSeconds();//animation
            if(timeForTextureAnum*5>6)
            {
                clockForTextureAnum.restart();
                timeForTextureAnum = clockForTextureAnum.getElapsedTime().asSeconds();
            }
            timeForTextureAnum*=5;
            i1PlayerAnim.loadFromFile("TexturesPack/Player/P"+to_string(setTextureFor1stPlayer+1)+"/Animation/Walk"+to_string(int32_t(timeForTextureAnum+1))+".png");
            i2PlayerAnim.loadFromFile("TexturesPack/Player/P"+to_string(setTextureFor2ndPlayer+1)+"/Animation/Walk"+to_string(int32_t(timeForTextureAnum+1))+".png");
            t1PlayerAnim.loadFromImage(i1PlayerAnim);
            t2PlayerAnim.loadFromImage(i2PlayerAnim);
            s1PlayerAnim.setTexture(t1PlayerAnim);
            s2PlayerAnim.setTexture(t2PlayerAnim);
            s1PlayerAnim.setTextureRect(IntRect(0, 0, i1PlayerAnim.getSize().x, i1PlayerAnim.getSize().y));
            s2PlayerAnim.setTextureRect(IntRect(i2PlayerAnim.getSize().x, 0, -i2PlayerAnim.getSize().x, i2PlayerAnim.getSize().y));


            if(checkSettingX==3){sBack.setTexture(tBackActive);}//back button
            if(checkSettingX==3&&(Keyboard::isKeyPressed(Keyboard::Return))){settingIsOpen=false;}

            window.draw(sBackGround);//drawing all sprites
            window.draw(s1Player);
            window.draw(s2Player);
            window.draw(sBack);
            window.draw(s5);
            window.draw(s10);
            window.draw(s15);
            window.draw(s20);
            window.draw(sPlayer1SetTextureText);
            window.draw(sPlayer2SetTextureText);
            window.draw(sText5);
            window.draw(sText10);
            window.draw(sText15);
            window.draw(sText20);
            window.draw(sTextBack);
            window.draw(s1PlayerAnim);
            window.draw(s2PlayerAnim);
            window.display();
            window.clear();
            }
        }
        backpl();
}

#endif // SETTING_H_INCLUDED




