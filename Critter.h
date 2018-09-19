#pragma once
// includes
#include <SFML/Graphics.hpp>

class Critter
{


	// --------------------------------
   //           BEHAVIOUR
  // ----------------------------------

public:

	// Constructor
	Critter();

	// Render the critter to the target
	void Draw(sf::RenderTarget & _target);


	// --------------------------------
   //          END BEHAVIOUR
  // ----------------------------------
	

	// --------------------------------
   //             DATA
  // ----------------------------------

private:

	sf::Sprite m_sprite;
	sf::Texture m_texture;

	// --------------------------------
   //            END DATA
  // ----------------------------------


}; // end critter class
