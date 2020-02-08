#include "TiledSprite.h"

TiledSprite::TiledSprite(const sf::Texture & texture, int repeatsInX, int repeatsInY)
{
	// Set texture and get size of texture
	m_sprite.setTexture(texture);
	m_textureSize = texture.getSize();

	// Set int rect size for repeats
	sf::IntRect spriteSize(0.f, 0.f, repeatsInX * m_textureSize.x, repeatsInY * m_textureSize.y);
	m_sprite.setTextureRect(spriteSize);

	// Set origin prior to any translation, scale or rotation
	// Means transformation will happen from centre of the sprite
	m_sprite.setOrigin((float)spriteSize.width * 0.5f, (float)spriteSize.height * 0.5f);
	// (float) casts the integer values such as spriteSize.width to a float, avoiding type coercion
	// Should always do this to avoid perform integer math on floating point number by mistake
	// Remmber 1 / 2 = 0 where as (float)1 / (float)2 = 0.5f, same as writing 1.f / 2.f = 0.5f
}

void TiledSprite::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_sprite);
}

void TiledSprite::setPosition(float x, float y)
{
	m_sprite.setPosition(x, y);
}

void TiledSprite::setScale(float x, float y)
{
	m_sprite.setScale(x, y);
}

void TiledSprite::setRotation(float angle)
{
	m_sprite.setRotation(angle);
}

TiledSprite::TiledSprite(const sf::Texture & texture, sf::Vector2f position, sf::Vector2f scale, sf::Vector2u repeats)
{
	// Set texture and get size of texture
	m_sprite.setTexture(texture);
	m_textureSize = texture.getSize();

	// Set int rect size for repeats
	sf::IntRect spriteSize(0.f, 0.f, repeats.x * m_textureSize.x, repeats.y * m_textureSize.y);
	m_sprite.setTextureRect(spriteSize);

	// Set origin prior to any translation, scale or rotation
	// Means transformation will happen from centre of the sprite
	m_sprite.setOrigin((float)spriteSize.width * 0.5f, (float)spriteSize.height * 0.5f);

	// Set position
	m_sprite.setPosition(position);

	// Set scale
	m_sprite.setScale(scale);
}
