/*!
\file main.cpp
\brief Contains the entry point for the application
*/

#include <SFML/Graphics.hpp>

#include "TiledSprite.h"
int main() /** Entry point for the application */
{
	sf::RenderWindow window(sf::VideoMode(1024, 800), "Sprite Tiling Example"); // Open main window

	float fFrameTime = 1.f / 60.f;

	// Start a clock
	sf::Clock clock;

	sf::Texture tileTexture;
	if (!tileTexture.loadFromFile("tile.png"))
	{
		return 1;
	}
	tileTexture.setRepeated(true); // Must do this is the texture is to be used in a tiled sprite

	// Draw the tile texture as is
	TiledSprite sprite1(tileTexture, 1, 1);
	sprite1.setPosition(40.f, 40.f);

	// Draw the tile texture at half it's original size
	TiledSprite sprite2(tileTexture, 1, 1);
	sprite2.setPosition(100.f, 40.f);
	sprite2.setScale(0.5, 0.5);

	// Draw the tile texture rotated 45 degrees
	TiledSprite sprite3(tileTexture, 1, 1);
	sprite3.setPosition(200.f, 40.f);
	sprite3.setRotation(45.f);

	// Draw the tile texture repeated 3 times in x
	TiledSprite sprite4(tileTexture, 3, 1);
	sprite4.setPosition(360.f, 40.f);

	// Draw the tile texture repeated 6 times in x and 2 times in y
	TiledSprite sprite5(tileTexture, 6, 2);
	sprite5.setPosition(650.f, 65.f);

	// Draw the tile texture repeated 6 times in x and 2 times in y at a quater size
	TiledSprite sprite6(tileTexture, 6, 2);
	sprite6.setPosition(200.f, 200.f);
	sprite6.setScale(0.25f, 0.25f);

	// Draw the tile texture repeated 12 times in x and 2 times in y at a quater size, rotated by -30 degrees
	TiledSprite sprite7(tileTexture, 12, 2);
	sprite7.setPosition(400.f, 200.f);
	sprite7.setScale(0.25f, 0.25f);
	sprite7.setRotation(-30);

	// None squate texture - just to show it works!
	sf::Texture redTileTexture;
	if (!redTileTexture.loadFromFile("redTile.png"))
	{
		return 1;
	}
	redTileTexture.setRepeated(true);

	// Draw the tile texture repeated 12 times in x and 2 times in y scale to 0.5
	TiledSprite sprite8(redTileTexture, 12, 2);
	sprite8.setScale(0.5f, 0.5f);
	sprite8.setPosition(400.f, 400.f);

	// Draw the tile texture repeated 2 times in x and 8 times in y scale to 0.5
	TiledSprite sprite9(redTileTexture, 2, 8);
	sprite9.setScale(0.5f, 0.5f);
	sprite9.setPosition(800.f,350.f);

	// Mini level demo
	// Shows a mini level at a scale suitable for Box2D - press space to toggle views

	// Create mini level at the scale of 10.24 X 8.0 centred at 0.0, 0.0 (top left of the screen)
	sf::View defaultView = window.getView();
	sf::View miniLevelView(sf::Vector2f(0.f, 0.f), sf::Vector2f(10.24f, 8.0f));

	std::vector<TiledSprite> miniLevel;
	bool miniLevelViewEnabled = false;

	// base row
	miniLevel.push_back(TiledSprite(tileTexture,sf::Vector2f(0.f,3.5f),sf::Vector2f(0.01,0.01),sf::Vector2u(40,2)));
	// platforms
	miniLevel.push_back(TiledSprite(tileTexture, sf::Vector2f(-4.f, 1.5f), sf::Vector2f(0.01, 0.01), sf::Vector2u(4, 1)));
	miniLevel.push_back(TiledSprite(tileTexture, sf::Vector2f(-2.f, 0.0f), sf::Vector2f(0.01, 0.01), sf::Vector2u(4, 1)));
	miniLevel.push_back(TiledSprite(tileTexture, sf::Vector2f(0.f, -1.5f), sf::Vector2f(0.01, 0.01), sf::Vector2u(8, 1)));
	miniLevel.push_back(TiledSprite(tileTexture, sf::Vector2f(1.75f, 0.0f), sf::Vector2f(0.01, 0.01), sf::Vector2u(3, 1)));
	miniLevel.push_back(TiledSprite(tileTexture, sf::Vector2f(3.f, 1.5f), sf::Vector2f(0.01, 0.01), sf::Vector2u(2, 1)));
	miniLevel.push_back(TiledSprite(tileTexture, sf::Vector2f(4.25f, -2.0f), sf::Vector2f(0.01, 0.01), sf::Vector2u(1, 6)));
	
	// Run a game loop
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			// window closed button pressed
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Space) miniLevelViewEnabled = !miniLevelViewEnabled;
			}
		}

		// Find out how much time has elapsed

		float m_fElapsedTime = clock.getElapsedTime().asSeconds();
		// If a frame has past the update the physics
		if (m_fElapsedTime > fFrameTime)
		{

			clock.restart();
		}

		if (miniLevelViewEnabled) window.setView(miniLevelView);
		else window.setView(defaultView);

		window.clear(sf::Color(120,120,120));

		window.draw(sprite1);
		window.draw(sprite2);
		window.draw(sprite3);
		window.draw(sprite4);
		window.draw(sprite5);
		window.draw(sprite6);
		window.draw(sprite7);
		window.draw(sprite8);
		window.draw(sprite9);

		for (auto tiledSprite : miniLevel) window.draw(tiledSprite);

		window.display();
	}
}