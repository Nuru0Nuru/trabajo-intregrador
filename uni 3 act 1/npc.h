#pragma once
#include "principal.h"
class npc :
    public principal
{
	int ancho, alto;
public:
	npc();
	void colocarTextura(sf::Texture& textura);
	void actualizar(sf::RenderWindow& ventana)override;
	void dibujar(sf::RenderWindow& ventana)override;
	bool pegar(sf::RenderWindow& ventana);
};

