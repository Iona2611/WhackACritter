// --------------------------------
//Includes 
// ---------------------------------

// libraries
#include <SFML/Graphics.hpp>
#include<cstdlib> // gives access to random function	
#include<ctime> // gives access to time functions
#include<string> // gives access to string functions

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
	

	const int NUM_CRITTERS = 5;
	Critter critters[NUM_CRITTERS];
	critters[0].Setup("graphics/bear.png", 10);
	critters[1].Setup("graphics/sloth.png", 5);
	critters[2].Setup("graphics/panda.png", 25);
	critters[3].Setup("graphics/chicken.png", 100);
	critters[4].Setup("graphics/giraffe.png", 2);

	// Game font
	sf::Font gameFont;
	gameFont.loadFromFile("fonts/mainFont.ttf");

	// Score tracking 
	int score = 0;
	sf::Text scoreText;
	scoreText.setFont(gameFont);
	scoreText.setString("Score: " + std::to_string(score));
	scoreText.setCharacterSize(50);
	scoreText.setFillColor(sf::Color::Cyan);
	scoreText.setPosition(50, 50);

	

	// game loop 

	while (gameWindow.isOpen())

		// --------------------------------
       //           INPUT
      // ---------------------------------
	{
		sf::Event event;
		while (gameWindow.pollEvent(event))
		{
			// Process input on critters 
			
			for (int i = 0; i < NUM_CRITTERS; ++i)
			{
				critters[i].Input(event);
			}


			if (event.type == sf::Event::Closed)
			{
				gameWindow.close();

			} // end if closed 
		} // end event polling loop 


	    // --------------------------------
	   //          END INPUT
	  // ----------------------------------
		
	    // --------------------------------
	   //          UPDATE
	  // ----------------------------------

		
		sf::Time frameTime = gameClock.restart();

		// See if there is any pending score 
		
		

		for (int i = 0; i < NUM_CRITTERS; ++i)
		{
			score += critters[i].GetPendingScore();
			critters[i].ClearPendingScore();
		}

		scoreText.setString("Score: " + std::to_string(score));


		// --------------------------------
       //        END UPDATE
      // ---------------------------------

	    // --------------------------------
	   //          DRAW
	  // ---------------------------------

		// clear the window to a single colour
	    gameWindow.clear();
		
		// draw everything

		for (int i = 0; i < NUM_CRITTERS; ++i)
		{
			
			critters[i].Draw(gameWindow);
		}

		gameWindow.draw(scoreText);

		// display the window contents 

		gameWindow.display();

		// --------------------------------
       //          END DRAW
      // ---------------------------------

	} // end of the game while loop 

	// exit point for the program
	return 0;

} // end of the main() function
