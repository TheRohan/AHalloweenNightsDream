#ifndef PAUSE_H_INCLUDED
#define PAUSE_H_INCLUDED

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int gameIsPlay =0;

void pause()
{

        SoundBuffer bufferForActive;
        bufferForActive.loadFromFile("Sounds/Select.wav");
        Sound select;
        select.setBuffer(bufferForActive);

        SoundBuffer bufferForChangePos;
        bufferForChangePos.loadFromFile("Sounds/foom_0.wav");
        Sound changePos;
        changePos.setBuffer(bufferForChangePos);

        Image iTextResume, iTextPause, iTextExit, iPassivepButtons, iActiveButtons, iBackGroundForPause;
        Texture tResume, tPause, tTextExit,  tPassivepButtons, tActiveButtons, tBackGroundForPause;
        Sprite sTextResume, sTextPause, sTextExit,  sPassivepButtons1,sPassivepButtons2, sActiveButtons, sBackGroundForPause;

        iTextResume.loadFromFile("TexturesPack/MainMenuTexture/resume.png");
        iTextPause.loadFromFile("TexturesPack/MainMenuTexture/pause.png");
        iTextExit.loadFromFile("TexturesPack/MainMenuTexture/exit.png");
        iPassivepButtons.loadFromFile("TexturesPack/MainMenuTexture/passivButton.png");
        iActiveButtons.loadFromFile("TexturesPack/MainMenuTexture/activeButton.png");
        iBackGroundForPause.loadFromFile("TexturesPack/MainMenuTexture/BG.jpg");

        tResume.loadFromImage(iTextResume);
        tPause.loadFromImage(iTextPause);
        tTextExit.loadFromImage(iTextExit);
        tPassivepButtons.loadFromImage(iPassivepButtons);
        tActiveButtons.loadFromImage(iActiveButtons);
        tBackGroundForPause.loadFromImage(iBackGroundForPause);

        sTextResume.setTexture(tResume);
        sTextPause.setTexture(tPause);
        sTextExit.setTexture(tTextExit);
        sPassivepButtons1.setTexture(tPassivepButtons);
        sPassivepButtons2.setTexture(tPassivepButtons);
        sActiveButtons.setTexture(tActiveButtons);
        sBackGroundForPause.setTexture(tBackGroundForPause);

        View pauseView;
        pauseView.setSize(1280,720);
        pauseView.setCenter(sBackGroundForPause.getPosition().x+iBackGroundForPause.getSize().x/2,sBackGroundForPause.getPosition().y+iBackGroundForPause.getSize().y/2);

        sPassivepButtons2.setPosition(sBackGroundForPause.getPosition().x+iBackGroundForPause.getSize().x/2-iPassivepButtons.getSize().x/2,sBackGroundForPause.getPosition().y+iBackGroundForPause.getSize().y/2+150);
        sPassivepButtons1.setPosition(sBackGroundForPause.getPosition().x+iBackGroundForPause.getSize().x/2-iPassivepButtons.getSize().x/2,sPassivepButtons2.getPosition().y-200);
        sTextResume.setPosition(sPassivepButtons1.getPosition());
        sActiveButtons.setPosition(sPassivepButtons1.getPosition());
        sTextExit.setPosition(sPassivepButtons2.getPosition());
        sTextPause.setPosition(sPassivepButtons1.getPosition().x,sPassivepButtons1.getPosition().y-200);

        int checkForPause=0;

        bool isPause = true;

        Clock pauseClock;
        float pauseTime = 301;
		pauseClock.restart();
		pauseTime /=800;

        while(isPause)
        {
            pauseTime = pauseClock.getElapsedTime().asMicroseconds();
            pauseTime /=1000;
            if(pauseTime>300)
            {

                if((Keyboard::isKeyPressed(Keyboard::Up))||(Keyboard::isKeyPressed(Keyboard::W)))
                    {checkForPause--;if(checkForPause < 0)checkForPause =1;pauseClock.restart();changePos.play();}
                if((Keyboard::isKeyPressed(Keyboard::Down))||(Keyboard::isKeyPressed(Keyboard::S)))
                    {checkForPause++; if(checkForPause > 1)checkForPause = 0;pauseClock.restart();changePos.play();}
                if(checkForPause==0) sActiveButtons.setPosition(sPassivepButtons1.getPosition());
                if(checkForPause==1) sActiveButtons.setPosition(sPassivepButtons2.getPosition());
                if(checkForPause==0&&(Keyboard::isKeyPressed(Keyboard::Return)))
                {
                    select.play(); isPause=false;
                }
                if(checkForPause==1&&(Keyboard::isKeyPressed(Keyboard::Return)))
                {
                    select.play();
                    gameIsPlay =1;
                    isPause=false;
                }

                window.setView(pauseView);
                window.draw(sBackGroundForPause);
                window.draw(sPassivepButtons1);
                window.draw(sPassivepButtons2);
                window.draw(sActiveButtons);
                window.draw(sTextResume);
                window.draw(sTextPause);
                window.draw(sTextExit);
                window.display();
                window.clear();
            }

        }

}

#endif // PAUSE_H_INCLUDED
