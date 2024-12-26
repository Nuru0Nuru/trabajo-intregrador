#pragma once
#include <SFML/Graphics.hpp>
class principal
{
protected:
	sf::Sprite sprite;
	sf::Texture texture;
	float x, y;

public:
	principal();
	virtual void actualizar(sf::RenderWindow& ventana) = 0;
	virtual void dibujar(sf::RenderWindow& ventana) = 0;
	void setPosition(float _x, float _y);
	float verX();
	float verY();
};


