#include "firstMapgameStart.h"
#include "mainMenu.h"
#include "helpMenu.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>


int main()
{
    music();
    mainTheme.play();
    while (window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)window.close();
            }
        choose = mainMenu();
        gameIsPlay=0;
        switch(choose)
        {
            case 1: firstMapGameStart(); break;
            case 2: settingMenu(); break;
            case 3: window.close(); break;
            case 4: helpMenu(); break;
        }
    }

	return 0;
}
