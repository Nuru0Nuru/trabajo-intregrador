#pragma once
#include <SFML/Graphics.hpp>
class hud
{
private:
	sf::Sprite textoVidas, textoPuntos, valorVidas, valorPuntos;
	sf::Texture textoVidasT, textoPuntosT, valorVidasT, valorPuntosT;
public:
	hud();
	void actualizar(int _puntos, int _vidas); 
	void dibujar(sf::RenderWindow& ventana);
	void dibujarPuntos(sf::RenderWindow& ventana); 
};

