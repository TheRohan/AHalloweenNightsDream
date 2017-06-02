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
