#pragma once
#include "principal.h"
class mira :
    public principal
{
public:
	mira();
	void colocarTextura(sf::Texture& textura);
	void actualizar(sf::RenderWindow& ventana)override;
	void dibujar(sf::RenderWindow& ventana)override;
};

