#include "npc.h"
npc::npc() :principal() {
	alto = 0;
	ancho = 0;
}

void npc::colocarTextura(sf::Texture& textura) {
	sprite.setTexture(textura);
	ancho = textura.getSize().x;
	alto = textura.getSize().y; 
}
void npc::actualizar(sf::RenderWindow& ventana) {}

void npc::dibujar(sf::RenderWindow& ventana) {
	ventana.draw(sprite);
}

bool npc::pegar(sf::RenderWindow& ventana){
	x = sprite.getPosition().x;
	y = sprite.getPosition().y;

	int posX = sf::Mouse::getPosition(ventana).x; 
	int posY = sf::Mouse::getPosition(ventana).y;  
	if (posX > x && posX< (x + ancho) && posY> y && posY < (y + alto)) {
		return true;
	}
	else {
		return false;
	}
}
