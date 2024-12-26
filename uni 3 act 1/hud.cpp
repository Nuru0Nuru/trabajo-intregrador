#include "hud.h"
hud::hud() {
	textoPuntosT.loadFromFile("PUNTOS.png");
	textoVidasT.loadFromFile("VIDAS.png");
	textoPuntos.setTexture(textoPuntosT);
	textoVidas.setTexture(textoVidasT);
}

void hud::actualizar(int _puntos,int _vidas) {
	std::string nombreArchivo = "" + std::to_string(_vidas) + ".png";
	valorVidasT.loadFromFile(nombreArchivo);
	if (_puntos < 0) {
		nombreArchivo = "0.png";
	}
	else {
		nombreArchivo = "" + std::to_string(_puntos) + ".png";
	}
	valorPuntosT.loadFromFile(nombreArchivo);
	valorPuntos.setTexture(valorPuntosT);
	valorPuntos.setTextureRect(sf::IntRect(0, 0, valorPuntosT.getSize().x, valorPuntosT.getSize().y));
	valorVidas.setTexture(valorVidasT);
}

void hud::dibujar(sf::RenderWindow& ventana) {
	textoPuntos.setPosition(550,10);
	valorPuntos.setPosition(800,10);
	textoVidas.setPosition(200,10);
	valorVidas.setPosition(400,10);
	ventana.draw(textoPuntos);
	ventana.draw(valorPuntos);
	ventana.draw(textoVidas);
	ventana.draw(valorVidas);
}

void hud::dibujarPuntos(sf::RenderWindow& ventana) {
	valorPuntos.setPosition(525, 350);
	ventana.draw(valorPuntos);
}

