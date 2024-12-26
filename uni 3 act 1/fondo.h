#pragma once
#include "principal.h"
class fondo : public principal
{
public:
	fondo();
	void colocarTextura(sf::Texture& textura); 
	void actualizar(sf::RenderWindow& ventana)override;
	void dibujar(sf::RenderWindow& ventana)override;
};

