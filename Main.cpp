#include <SFML/Graphics.hpp>

// --------------------------------
//Includes 
// ---------------------------------

// libraries




int main()

{
	// game setup 

	// Render window creation 

	

	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode::getDesktopMode(), "Quick Draw",
		sf::Style::Titlebar | sf::Style::Close);
	
	// Timer Functioality 
	sf::Clock gameClock;

	// end game set up

	// game loop 

	while (gameWindow.isOpen())

		// input
	{
		sf::Event event;
		while (gameWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				gameWindow.close();

			} // end if closed 
		} // end event polling loop 


		// end of input

		// Update 
		sf::Time frameTime = gameClock.restart();

		// end update 

		// draw

		// clear the window to a single colour
	    gameWindow.clear();
		
		// draw everything

		// display the window contents 

		gameWindow.display();

		// end draw
	} // end of the game while loop 

	// exit point for the program
	return 0;

} // end of the main() function
