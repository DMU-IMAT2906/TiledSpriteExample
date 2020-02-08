#pragma once

#include <SFML/Graphics.hpp>

/** \class TiledSprite Class which draws tiled sprite with textures
*/

class TiledSprite : public sf::Drawable
{
private:
	sf::Sprite m_sprite; //!< Sprite which is drawn
	sf::Vector2u m_textureSize; //!< Size of the texture the sprite has been set with
public:
	TiledSprite(const sf::Texture& texture, int repeatsInX, int repeatsInY); //!< Basic constructor
	TiledSprite(const sf::Texture& texture, sf::Vector2f position, sf::Vector2f scale, sf::Vector2u repeats); //!< Constructore with all parameters
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override; //!< Draw function overriden from sf::Drawable
	void setPosition(float x, float y); //!< Set the position of the tiled sprite - origin is in the centre of the sprite
	void setScale(float x, float y); //!< Set the scale of the tiled sprite - origin is in the centre of the sprite
	void setRotation(float angle); //!< Set the rotation of the tiled sprite - origin is in the centre of the sprite
};