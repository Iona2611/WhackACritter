#pragma once
// includes
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

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

	// Process input on the critter
	void Input(sf::Event _gameEvent);


	// --------------------------------
   //          END BEHAVIOUR
  // ----------------------------------
	

	// --------------------------------
   //             DATA
  // ----------------------------------

private:

	sf::Sprite m_sprite;
	sf::Texture m_texture;
	bool m_alive;
	sf::Sound m_deathSound;
	sf::SoundBuffer m_deathBuffer;

	// --------------------------------
   //            END DATA
  // ----------------------------------


}; // end critter class
