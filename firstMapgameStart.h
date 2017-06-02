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



#ifndef FIRSTMAPGAMESTART_H_INCLUDED
#define FIRSTMAPGAMESTART_H_INCLUDED

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "setting.h"
#include "player.h"
#include "enemy.h"
#include "mainMenu.h"


void firstMapGameStart()
{
    sf::Music gameMusic;
    gameMusic.openFromFile("Sounds/Nox Arcana Oblivion.wav");
    gameMusic.setLoop(true);
    gameMusic.setVolume(30);
    gameMusic.play();

    mainTheme.stop();
    bool isEnd=true;
    Text textForObjects;
    Font forntForObject;
    forntForObject.loadFromFile("Font/AmazDooMLeft2.ttf");
    textForObjects.setFont(forntForObject);
    textForObjects.setCharacterSize(150);
    textForObjects.setStyle(Text::Bold);
    textForObjects.setString("10/10");
    Image Cimage;
    Texture Ctexture;
    Sprite C1sprite;
    Cimage.loadFromFile("TexturesPack/MapTextures/Pumpkin/pumpkinObject.png"); // load img
    Ctexture.loadFromImage(Cimage); // set texture
    C1sprite.setTexture(Ctexture); // set sprite
    C1sprite.setTextureRect(IntRect(0, 0, Cimage.getSize().x, Cimage.getSize().y)); //create sprite
    C1sprite.setPosition(2376, 17152);
    //////background////////////////////////////////
    Image imageForBackGround;
    imageForBackGround.loadFromFile("TexturesPack/MapTextures/FirstMapTexture/MainBG.jpg");
    Texture textureForBackGround;
	Sprite spriteForBackGround;
	textureForBackGround.loadFromImage(imageForBackGround); // get texture
    spriteForBackGround.setTexture(textureForBackGround); // set sprite
	spriteForBackGround.setTextureRect(IntRect(0, 0, imageForBackGround.getSize().x, imageForBackGround.getSize().y)); //create sprite
    spriteForBackGround.setPosition(2115,14200);
    //view/////////////////////////////////////////
    View player1view;
    //View player2view;
    player1view.setSize(1600,1600);//view for player
    player1view.setViewport(sf::FloatRect(0, 0, 0.5, 1));
    int limmit = settings.getLimitOfOgjects();
    Player player1("Jump1.png",2376,17152,200,405,settings.getTextureForPlayer1());
    Player player2("Jump1.png",10306,17152,200,405,settings.getTextureForPlayer2());
    player2.collectedPumpkin=0;
    player1.collectedPumpkin=0;
    Enemy enemy1("Green",4416,5440,4864,18112);
    Enemy enemy2("Blue",7488,8512,7872,18112);
    Enemy enemy3("Red",2112,3904,3072,14784);
    Enemy enemy4("Green",9024,10816,9152,14784);
    Enemy enemy5("Blue",5440,7488,6400,14016);
    Enemy enemy6("Green",2880,5120,4160,12224);
    Enemy enemy7("Red",7808,10048,9344,12224);

    SoundBuffer bdeadSound;
    bdeadSound.loadFromFile("Sounds/enemy_dead_25.wav");
    Sound deadSound;
    deadSound.setBuffer(bdeadSound);

    PumpkinEvent pumpkin; //crate an event object

    SoundBuffer pumpkinPuffer;
    pumpkinPuffer.loadFromFile("Sounds/Collect_Point_01.wav");
    Sound pumpkinSound;
    pumpkinSound.setVolume(60);
    pumpkinSound.setBuffer(pumpkinPuffer);

    SoundBuffer player1Jump;
    player1Jump.loadFromFile("Sounds/enemy_dead_54.wav");
    Sound player1JumpSound;
    player1JumpSound.setVolume(300);
    player1JumpSound.setBuffer(player1Jump);

    Level map(&window); //create map
    map.loadLevel("./firstLvl.tmx");//load map

	list<Rect_ML*> solidObjects = map.getRectsWithType("solid");
	for (auto it = solidObjects.begin(); it != solidObjects.end(); it++)
    {

		(*it)->tTexture = new Texture();
		(*it)->sSprite = new Sprite( *((*it)->tTexture) );
		FloatRect &itRect = ((*it)->fRect);
		(*it)->sSprite->setPosition( itRect.left, itRect.top );
		(*it)->sSprite->setTextureRect(IntRect( 0, 0, itRect.width,itRect.height ));
        window.draw( *((*it)->sSprite) );
	}

	Clock clock; //clock for moving

    bool isLevel = true;

    while(isLevel)
    {
        float time = clock.getElapsedTime().asMicroseconds(); //time for moving
		clock.restart();
		time = time / 800;
            if (player1.sprite.getGlobalBounds().intersects(pumpkin.sprite.getGlobalBounds()))
            {
                pumpkin.newPlaceForPumkin();
                player1.collectedPumpkin++;
                pumpkinSound.play();

            } //player1 event
        if (player2.sprite.getGlobalBounds().intersects(pumpkin.sprite.getGlobalBounds()))
            {
                pumpkin.newPlaceForPumkin();
                player2.collectedPumpkin++;
                pumpkinSound.play();
            } //player2 event


        ////////PLAYER 1//////////////////////////////
        if (player1.liveIs)
        {
            if(player1.moveLeft)
            {
                if (Keyboard::isKeyPressed(Keyboard::A))
                {
                    player1.movingLeftSide();
                }
            }
            if(player1.moveRight)
            {
                if (Keyboard::isKeyPressed(Keyboard::D))
                {
                    player1.movingRightSide();
                }
            }
            if(player1.moveTop)
            {
                if (Keyboard::isKeyPressed(Keyboard::W))
                {
                    if(player1.onGroung)player1JumpSound.play();
                    player1.movingUpSide();
                }
            }
            if(player1.moveRight&&player1.moveTop)
            {
                if (Keyboard::isKeyPressed(Keyboard::W) && Keyboard::isKeyPressed(Keyboard::D))
                {
                    player1.movingUpRightSide();
                }
            }
            if(player1.moveLeft&&player1.moveTop)
            {
                if (Keyboard::isKeyPressed(Keyboard::W) && Keyboard::isKeyPressed(Keyboard::A))
                {
                    player1.movingUpLeftSide();
                }
            }
            if(!(
                (Keyboard::isKeyPressed(Keyboard::W)) ||
                (Keyboard::isKeyPressed(Keyboard::A))||
                (Keyboard::isKeyPressed(Keyboard::D))||
                (Keyboard::isKeyPressed(Keyboard::S)))
                &&player1.onGroung)
            {
                player1.stayMove();
            }
        }


        if(!player1.liveIs)
        { if(player1.deadCheck)player1.deadCheck=false;

            {
                player1.setPlayerCoordinateY(player1.getPlayerCoordinateY()+time*0.7);//30
                player1.sprite.setPosition(player1.getPlayerCoordinateX(),player1.getPlayerCoordinateY());
                collisionForPlayerObject(solidObjects, player1, time);
            }
            player1.dethAnim();


        }
        if(player1.liveIs)player1.deadCheck=true;

        player1.jump(); //jump time
        player1.graviry(time,0.7); //gravitation
        ////////PLAYER 1//////////////////////////////

        ////////PLAYER 2//////////////////////////////
        if (player2.liveIs)
        {
            if(player1.moveLeft)
            {
                if (Keyboard::isKeyPressed(Keyboard::Left))
                {
                    player2.movingLeftSide();
                }
            }
            if(player2.moveRight)
            {
                if (Keyboard::isKeyPressed(Keyboard::Right))
                {
                    player2.movingRightSide();
                }
            }
            if(player2.moveTop)
            {
                if (Keyboard::isKeyPressed(Keyboard::Up))
                {
                    if(player2.onGroung)player1JumpSound.play();
                    player2.movingUpSide();
                }
            }
            if(player2.moveRight&&player2.moveTop)
            {
                if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Right))
                {
                    player2.movingUpRightSide();
                }
            }
            if(player1.moveLeft&&player2.moveTop)
            {
                if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Left))
                {
                    player2.movingUpLeftSide();
                }
            }
            if(!(
                (Keyboard::isKeyPressed(Keyboard::Up)) ||
                (Keyboard::isKeyPressed(Keyboard::Left))||
                (Keyboard::isKeyPressed(Keyboard::Right))||
                (Keyboard::isKeyPressed(Keyboard::Down)))
                &&player1.onGroung)
            {
                player2.stayMove();
            }
        }

        if(!player2.liveIs)
        {
            {
                player2.setPlayerCoordinateY(player2.getPlayerCoordinateY()+time*0.7);//30
                player2.sprite.setPosition(player2.getPlayerCoordinateX(),player2.getPlayerCoordinateY());
                collisionForPlayerObject(solidObjects, player2, time);
            }
            player2.dethAnim();

        }
        player2.jump(); //jump time
        player2.graviry(time,0.7); //gravitation
        ////////PLAYER 2//////////////////////////////

        ////////ATTACK//////////////////////////////
        if(player1.sprite.getGlobalBounds().intersects(player2.sprite.getGlobalBounds()))
        {
            if(((player1.getPlayerCoordinateY()+player1.h)<(player2.getPlayerCoordinateY()+15))&&(player2.liveIs==true))
               {
                    deadSound.play();
                    player2.clockForDethAnim.restart();
                    player2.liveIs=false;
               }
            if(((player2.getPlayerCoordinateY()+player2.h)<(player1.getPlayerCoordinateY()+15))&&(player1.liveIs==true))
               {
                    deadSound.play();
                    player1.clockForDethAnim.restart();
                    player1.liveIs=false;
               }
        }
        ////////ATTACK//////////////////////////////
        collisionForPlayerObject(solidObjects, player1, time); //collision player 1
        collisionForPlayerObject(solidObjects, player2, time); //collision player 2

        ////////ENEMY//////////////////////////////
        enemy1.movingEnemy(0.2,time);//enemy 1
        {
           if((player1.sprite.getGlobalBounds().intersects(enemy1.sprite.getGlobalBounds()))&&enemy1.liveIs)
            {
                enemy1.collisionWithPlayer(player1);
                if(enemy1.liveIs&&player1.liveIs)
                {
                    deadSound.play();
                    player1.liveIs=false;
                    player1.clockForDethAnim.restart();
                }
            }
            if((player2.sprite.getGlobalBounds().intersects(enemy1.sprite.getGlobalBounds()))&&enemy1.liveIs)
            {
                enemy1.collisionWithPlayer(player2);
                if(enemy1.liveIs&&player2.liveIs)
                {
                    deadSound.play();
                    player2.liveIs=false;
                    player2.clockForDethAnim.restart();
                }
            }
        }
        enemy2.movingEnemy(0.2,time);//enemy 2
        {
           if((player1.sprite.getGlobalBounds().intersects(enemy2.sprite.getGlobalBounds()))&&enemy2.liveIs)
            {
                enemy2.collisionWithPlayer(player1);
                if(enemy2.liveIs&&player1.liveIs)
                {
                    deadSound.play();
                    player1.liveIs=false;
                    player1.clockForDethAnim.restart();
                }
            }
            if((player2.sprite.getGlobalBounds().intersects(enemy2.sprite.getGlobalBounds()))&&enemy2.liveIs)
            {
                enemy2.collisionWithPlayer(player2);
                if(enemy2.liveIs&&player2.liveIs)
                {
                    deadSound.play();
                    player2.liveIs=false;
                    player2.clockForDethAnim.restart();
                }
            }
        }
                enemy3.movingEnemy(0.2,time);//enemy 3
        {
           if((player1.sprite.getGlobalBounds().intersects(enemy3.sprite.getGlobalBounds()))&&enemy3.liveIs)
            {
                enemy3.collisionWithPlayer(player1);
                if(enemy3.liveIs&&player1.liveIs)
                {
                    deadSound.play();
                    player1.liveIs=false;
                    player1.clockForDethAnim.restart();
                }
            }
            if((player2.sprite.getGlobalBounds().intersects(enemy3.sprite.getGlobalBounds()))&&enemy3.liveIs)
            {
                enemy3.collisionWithPlayer(player2);
                if(enemy3.liveIs&&player2.liveIs)
                {
                    deadSound.play();
                    player2.liveIs=false;
                    player2.clockForDethAnim.restart();
                }
            }
        }
                enemy4.movingEnemy(0.2,time);//enemy 4
        {
           if((player1.sprite.getGlobalBounds().intersects(enemy4.sprite.getGlobalBounds()))&&enemy4.liveIs)
            {
                enemy4.collisionWithPlayer(player1);
                if(enemy4.liveIs&&player1.liveIs)
                {
                    deadSound.play();
                    player1.liveIs=false;
                    player1.clockForDethAnim.restart();
                }
            }
            if((player2.sprite.getGlobalBounds().intersects(enemy4.sprite.getGlobalBounds()))&&enemy4.liveIs)
            {
                enemy4.collisionWithPlayer(player2);
                if(enemy4.liveIs&&player2.liveIs)
                {
                    deadSound.play();
                    player2.liveIs=false;
                    player2.clockForDethAnim.restart();
                }
            }
        }
                enemy5.movingEnemy(0.2,time);//enemy 5
        {
           if((player1.sprite.getGlobalBounds().intersects(enemy5.sprite.getGlobalBounds()))&&enemy5.liveIs)
            {
                enemy5.collisionWithPlayer(player1);
                if(enemy5.liveIs&&player1.liveIs)
                {
                    deadSound.play();
                    player1.liveIs=false;
                    player1.clockForDethAnim.restart();
                }
            }
            if((player2.sprite.getGlobalBounds().intersects(enemy5.sprite.getGlobalBounds()))&&enemy5.liveIs)
            {
                enemy5.collisionWithPlayer(player2);
                if(enemy5.liveIs&&player2.liveIs)
                {
                    deadSound.play();
                    player2.liveIs=false;
                    player2.clockForDethAnim.restart();
                }
            }
        }
                enemy6.movingEnemy(0.2,time);//enemy 6
        {
           if((player1.sprite.getGlobalBounds().intersects(enemy6.sprite.getGlobalBounds()))&&enemy6.liveIs)
            {
                enemy6.collisionWithPlayer(player1);
                if(enemy6.liveIs&&player1.liveIs)
                {
                    deadSound.play();
                    player1.liveIs=false;
                    player1.clockForDethAnim.restart();
                }
            }
            if((player2.sprite.getGlobalBounds().intersects(enemy6.sprite.getGlobalBounds()))&&enemy6.liveIs)
            {
                enemy6.collisionWithPlayer(player2);
                if(enemy6.liveIs&&player2.liveIs)
                {
                    deadSound.play();
                    player2.liveIs=false;
                    player2.clockForDethAnim.restart();
                }
            }
        }
                enemy7.movingEnemy(0.2,time);//enemy 7
        {
           if((player1.sprite.getGlobalBounds().intersects(enemy7.sprite.getGlobalBounds()))&&enemy7.liveIs)
            {
                enemy7.collisionWithPlayer(player1);
                if(enemy7.liveIs&&player1.liveIs)
                {
                    deadSound.play();
                    player1.liveIs=false;
                    player1.clockForDethAnim.restart();
                }
            }
            if((player2.sprite.getGlobalBounds().intersects(enemy7.sprite.getGlobalBounds()))&&enemy7.liveIs)
            {
                enemy7.collisionWithPlayer(player2);
                if(enemy7.liveIs&&player2.liveIs)
                {
                    deadSound.play();
                    player2.liveIs=false;
                    player2.clockForDethAnim.restart();
                }
            }
        }

        ////////ENEMY//////////////////////////////
        player1.update(time);
        player2.update(time);

    if((Keyboard::isKeyPressed(Keyboard::Escape)))//pause
    {
        player1.onGroung=true;
        player2.onGroung=true;
        pause();
        if(gameIsPlay==1){isLevel=false;isEnd=false;mainTheme.play();}
    }


        window.setView(player1view);

        //viewE

        if(player1.getPlayerCoordinateY()>18688)player1.getRiseAndShine();
        if(player2.getPlayerCoordinateY()>18688)player2.getRiseAndShine();

        player1view.setViewport(sf::FloatRect(0, 0, 0.5, 1));

        //if(player1.liveIs)
        {
            spriteForBackGround.setPosition(player2.getPlayerCoordinateX()-imageForBackGround.getSize().x/2,player2.getPlayerCoordinateY()-imageForBackGround.getSize().y/2);
            C1sprite.setPosition(player2.getPlayerCoordinateX()+300,player2.getPlayerCoordinateY()-700);
            if(player1.getPlayerCoordinateX()<3008)
            {
                player1view.setCenter(3008, player1.getPlayerCoordinateY());
            }
            else if(player1.getPlayerCoordinateX()>9920)
            {
                player1view.setCenter(9920, player1.getPlayerCoordinateY());
            }
            else
            {
                player1view.setCenter(player1.getPlayerCoordinateX(), player1.getPlayerCoordinateY());
            }
            if(player2.getPlayerCoordinateX()<3008)
            {
                spriteForBackGround.setPosition(3008-imageForBackGround.getSize().x/2,player2.getPlayerCoordinateY()-imageForBackGround.getSize().y/2);
                C1sprite.setPosition(3008+300,player2.getPlayerCoordinateY()-700);
            }
            else if(player2.getPlayerCoordinateX()>9920)
            {
                spriteForBackGround.setPosition(9920-imageForBackGround.getSize().x/2,player2.getPlayerCoordinateY()-imageForBackGround.getSize().y/2);
                C1sprite.setPosition(9920+300,player2.getPlayerCoordinateY()-700);
            }
        }

        textForObjects.setString(to_string(player2.collectedPumpkin)+"/"+to_string(limmit));
        textForObjects.setPosition(C1sprite.getPosition().x+90,C1sprite.getPosition().y+70);
        window.draw(spriteForBackGround);
        map.drawLevel();
        window.draw(enemy1.sprite);
        window.draw(enemy2.sprite);
        window.draw(enemy3.sprite);
        window.draw(enemy4.sprite);
        window.draw(enemy5.sprite);
        window.draw(enemy6.sprite);
        window.draw(enemy7.sprite);
        window.draw(pumpkin.sprite);
        window.draw(player1.sprite);
        window.draw(player2.sprite);
        window.draw(C1sprite);
        window.draw(textForObjects);


        window.setView(player1view);
        player1view.setViewport(sf::FloatRect(0.5, 0, 0.5, 1));


        {
            spriteForBackGround.setPosition(player1.getPlayerCoordinateX()-imageForBackGround.getSize().x/2,player1.getPlayerCoordinateY()-imageForBackGround.getSize().y/2);
            C1sprite.setPosition(player1.getPlayerCoordinateX()-620,player1.getPlayerCoordinateY()-700);
            if(player2.getPlayerCoordinateX()<3008)
            {
                player1view.setCenter(3008, player2.getPlayerCoordinateY());
            }
            else if(player2.getPlayerCoordinateX()>9920)
            {
                player1view.setCenter(9920, player2.getPlayerCoordinateY());
            }
            else
            {
                player1view.setCenter(player2.getPlayerCoordinateX(), player2.getPlayerCoordinateY());
            }
            if(player1.getPlayerCoordinateX()<3008)
            {
                spriteForBackGround.setPosition(3008-imageForBackGround.getSize().x/2,player1.getPlayerCoordinateY()-imageForBackGround.getSize().y/2);
                C1sprite.setPosition(3008-620,player1.getPlayerCoordinateY()-700);
            }
            else if(player1.getPlayerCoordinateX()>9920)
            {
                spriteForBackGround.setPosition(9920-imageForBackGround.getSize().x/2,player1.getPlayerCoordinateY()-imageForBackGround.getSize().y/2);
                C1sprite.setPosition(9920-620,player1.getPlayerCoordinateY()-700);
            }
        }
        textForObjects.setString(to_string(player1.collectedPumpkin)+"/"+to_string(limmit));
        textForObjects.setPosition(C1sprite.getPosition().x+90,C1sprite.getPosition().y+70);

        window.draw(spriteForBackGround);
        map.drawLevel();
        window.draw(enemy1.sprite);
        window.draw(enemy2.sprite);
        window.draw(enemy3.sprite);
        window.draw(enemy4.sprite);
        window.draw(enemy5.sprite);
        window.draw(enemy6.sprite);
        window.draw(enemy7.sprite);
        window.draw(pumpkin.sprite);
        window.draw(player1.sprite);
        window.draw(player2.sprite);
        window.draw(C1sprite);
        window.draw(textForObjects);

        window.display();

        window.clear();
        if(player1.collectedPumpkin==limmit||player2.collectedPumpkin==limmit)isLevel=false;
    }

    map.closeLevel();
    gameMusic.stop();

    {

    Level map(&window); //create map
    map.loadLevel("./end.tmx");

    View endView;
    endView.setSize(3100,1600);//view for  player
    endView.setCenter(2000,1000);
    window.setView(endView);
    player1.onGroung=true;
    player2.onGroung=true;

    sf::Music winMusic;
    winMusic.openFromFile("Sounds/marilyn-manson-this-is-halloween-best-muzon.cc.wav");
    winMusic.setLoop(true);
    winMusic.play();


    if(player1.collectedPumpkin>player2.collectedPumpkin)
    {
        player1.rightMovingIs=true;
        player1.setPlayerCoordinateX(1088-player1.h);
        player1.setPlayerCoordinateY(704-player1.h);
        player1.sprite.setPosition(player1.getPlayerCoordinateX(),player1.getPlayerCoordinateY());
        player1.stayMove();

        player2.rightMovingIs=true;
        player2.sprite.setPosition(700,1536-player2.h);
        player2.stayMove();
    }
        if(player1.collectedPumpkin<player2.collectedPumpkin)
    {
        player2.rightMovingIs=true;
        player2.setPlayerCoordinateX(1088-player2.h);
        player2.setPlayerCoordinateY(704-player2.h);
        player2.sprite.setPosition(player2.getPlayerCoordinateX(),player2.getPlayerCoordinateY());
        player2.stayMove();

        player1.rightMovingIs=true;
        player1.sprite.setPosition(700,1536-player1.h);
        player1.stayMove();
    }

    enemy1.rightMoveIs=false;
    enemy2.rightMoveIs=true;
    enemy3.rightMoveIs=true;
    enemy1.sprite.setPosition(player2.sprite.getPosition().x-enemy1.image.getSize().x-30,1536-enemy1.image.getSize().y);
    enemy2.sprite.setPosition(enemy1.sprite.getPosition().x-enemy2.image.getSize().x-20,1536-enemy2.image.getSize().y);
    enemy3.sprite.setPosition(enemy2.sprite.getPosition().x-enemy3.image.getSize().x-30,1536-enemy3.image.getSize().y);

    Clock clockPM;


    Image iT1, iT2, iT3;
    Texture tT1,tT2,tT3;
    Sprite sT1,sT2,sT3;
    iT3.loadFromFile("TexturesPack/EndOfLevel/activeButton22.png");
    tT3.loadFromImage(iT3);
    sT3.setTexture(tT3);

    if(player1.collectedPumpkin>player2.collectedPumpkin)
    {
        iT1.loadFromFile("TexturesPack/EndOfLevel/1stplayeR.png");
        tT1.loadFromImage(iT1);
        sT1.setTexture(tT1);
        iT2.loadFromFile("TexturesPack/EndOfLevel/Winner.png");
        tT2.loadFromImage(iT2);
        sT2.setTexture(tT2);
    }
    if(player1.collectedPumpkin<player2.collectedPumpkin)
    {
        iT1.loadFromFile("TexturesPack/EndOfLevel/2ndplayeR.png");
        tT1.loadFromImage(iT1);
        sT1.setTexture(tT1);
        iT2.loadFromFile("TexturesPack/EndOfLevel/Winner.png");
        tT2.loadFromImage(iT2);
        sT2.setTexture(tT2);
    }
    sT1.setPosition(2048,300);
    sT2.setPosition(2100,300+iT1.getSize().y+5);
    sT3.setPosition(2416,1472);
    while (isEnd)
    {
        float time = clock.getElapsedTime().asMicroseconds(); //time for moving
		clock.restart();
		time = time / 800;
		enemy1.enemyAnim();
		enemy2.enemyAnim();
		enemy3.enemyAnim();


            if(player1.collectedPumpkin>player2.collectedPumpkin)
            {
                player2.moveAnim();
                if(player2.rightMovingIs)player2.sprite.setPosition(player2.sprite.getPosition().x+time*0.5,player2.sprite.getPosition().y);
                player1.stayMove();
                if(enemy3.sprite.getPosition().x>3776)player2.sprite.setPosition(0,player2.sprite.getPosition().y);
                enemy1.sprite.setPosition(player2.sprite.getPosition().x-enemy1.image.getSize().x-20,1536-enemy1.image.getSize().y);
                enemy2.sprite.setPosition(enemy1.sprite.getPosition().x-enemy2.image.getSize().x-20,1536-enemy2.image.getSize().y);
                enemy3.sprite.setPosition(enemy2.sprite.getPosition().x-enemy3.image.getSize().x-20,1536-enemy3.image.getSize().y);
            }
            if(player2.collectedPumpkin>player1.collectedPumpkin)
            {
                player1.moveAnim();
                if(player1.rightMovingIs)player1.sprite.setPosition(player1.sprite.getPosition().x+time*0.5,player1.sprite.getPosition().y);
                player2.stayMove();
                if(enemy3.sprite.getPosition().x>3776)player1.sprite.setPosition(0,player1.sprite.getPosition().y);
                enemy1.sprite.setPosition(player1.sprite.getPosition().x-enemy1.image.getSize().x-20,1536-enemy1.image.getSize().y);
                enemy2.sprite.setPosition(enemy1.sprite.getPosition().x-enemy2.image.getSize().x-20,1536-enemy2.image.getSize().y);
                enemy3.sprite.setPosition(enemy2.sprite.getPosition().x-enemy3.image.getSize().x-20,1536-enemy3.image.getSize().y);
            }



        if((Keyboard::isKeyPressed(Keyboard::Return)))isEnd=false;

        map.drawLevel();

        window.draw(player1.sprite);
        window.draw(player2.sprite);
        window.draw(enemy1.sprite);
        window.draw(enemy2.sprite);
        window.draw(enemy3.sprite);
        window.draw(sT1);
        window.draw(sT2);
        window.draw(sT3);

        window.display();

        window.clear();
    }
    winMusic.stop();
    mainTheme.play();
    }
    map.closeLevel();
    player1.collectedPumpkin=0;
    player2.collectedPumpkin=0;


}

#endif // FIRSTMAPGAMESTART_H_INCLUDED
