// --------------------------------
// Includes 
// ---------------------------------

// Library Includes
#include<cstdlib>

// Project Includes

#include "Critter.h"


Critter::Critter()
// initialisation list 
	: m_sprite()
	, m_texture()
	, m_alive(true)
	, m_deathSound()
	, m_deathBuffer()
	, m_pendingScore(0)
	, m_scoreValue(1)

{
	

	// Set up the death sound 
	m_deathBuffer.loadFromFile("audio/buttonclick.ogg");
	m_deathSound.setBuffer(m_deathBuffer);

}

void Critter::Draw(sf::RenderTarget & _target)
{
	// Only draw sprite if alive 
	if (m_alive)
	{
		_target.draw(m_sprite);
	}
	
}

void Critter::Input(sf::Event _gameEvent)
{
	// Only handle input if alive
	if (m_alive)
	{
		// check if this event is a clicked
		if (_gameEvent.type == sf::Event::MouseButtonPressed)
		{

			// Did they click on this critter?
			if (m_sprite.getGlobalBounds().contains(_gameEvent.mouseButton.x, _gameEvent.mouseButton.y))
			{
				// They clicked it!

				// we die
				m_alive = false;

				// Play the death sound
				m_deathSound.play();

				// Add to pending scpre
				m_pendingScore += m_scoreValue;


			}

		} // end event clicked
	}
}

int Critter::GetPendingScore()
{
	return m_pendingScore;
}

void Critter::ClearPendingScore()
{
	m_pendingScore = 0;
}

void Critter::Setup(std::string _textureFile, int _pointValue)
{
	// Set up the sprite 
	m_texture.loadFromFile(_textureFile);
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(rand() % sf::VideoMode::getDesktopMode().width,
		rand() % sf::VideoMode::getDesktopMode().height);

	m_scoreValue = _pointValue;

}