#include "mira.h"
mira::mira() :principal() {}

void mira::colocarTextura(sf::Texture& textura) {
	sprite.setTexture(textura);
	sprite.setOrigin(textura.getSize().x / 2, textura.getSize().y / 2);
}
void mira::actualizar(sf::RenderWindow& ventana) {
	x = sf::Mouse::getPosition(ventana).x;
	y = sf::Mouse::getPosition(ventana).y;
	sprite.setPosition(x, y);
}

void mira::dibujar(sf::RenderWindow& ventana) {
	ventana.draw(sprite);
}
