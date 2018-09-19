// --------------------------------
//Includes 
// ---------------------------------

// libraries
#include <SFML/Graphics.hpp>
#include<cstdlib> // gives access to random function	
#include<ctime> // gives accrss to time functions

// Project Includes
#include"Critter.h"


int main()

{
	// game setup 

	// Render window creation 

	

	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode::getDesktopMode(), "Quick Draw",
		sf::Style::Titlebar | sf::Style::Close);
	
	// Timer Functioality 
	sf::Clock gameClock;

	// Seed our random number generator
	srand(time(NULL));

	// Create an instance of our critter class
	Critter myCriiter;

	

	// game loop 

	while (gameWindow.isOpen())

		// --------------------------------
       //           INPUT
      // ---------------------------------
	{
		sf::Event event;
		while (gameWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				gameWindow.close();

			} // end if closed 
		} // end event polling loop 


	    // --------------------------------
	   //          END INPUT
	  // ---------------------------------
		
	    // --------------------------------
	   //          UPDATE
	  // ---------------------------------

		
		sf::Time frameTime = gameClock.restart();

		// --------------------------------
       //        END UPDATE
      // ---------------------------------

	    // --------------------------------
	   //          DRAW
	  // ---------------------------------

		// clear the window to a single colour
	    gameWindow.clear();
		
		// draw everything
		myCriiter.Draw(gameWindow);

		// display the window contents 

		gameWindow.display();

		// --------------------------------
       //          END DRAW
      // ---------------------------------

	} // end of the game while loop 

	// exit point for the program
	return 0;

} // end of the main() function
