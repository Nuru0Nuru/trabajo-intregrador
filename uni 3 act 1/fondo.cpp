#include "fondo.h"
fondo::fondo() :principal(){}

void fondo::colocarTextura(sf::Texture &textura) {
	sprite.setTexture(textura);
}
void fondo::actualizar(sf::RenderWindow& ventana) {}

void fondo:: dibujar(sf::RenderWindow &ventana){
	ventana.draw(sprite);
}