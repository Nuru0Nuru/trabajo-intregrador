#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/system.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "principal.h"
#include "fondo.h"
#include "npc.h"
#include "mira.h"
#include "hud.h"
using namespace sf;
using namespace std;

int main() {
	Texture TnpcB; 
	TnpcB.loadFromFile("humano2.png");
	Texture TnpcM; 
	TnpcM.loadFromFile("robot2.png");
	
	Texture Tback;
	Tback.loadFromFile("ventana.png");
	fondo back;
	back.colocarTextura(Tback);

	npc personaje; 

	Texture Tmira;
	Tmira.loadFromFile("mira2.png"); 
	mira Smira;  
	Smira.colocarTextura(Tmira); 
	Smira.setPosition(400, 300);
	
	int estado = 1;
	int vidas = 0;
	int tipo = 0;
	int posNPC = 0;
	bool jugando = false;
	int bajasMalos = 0;
	int bajasBuenos = 0;
	int puntos;
	float tiempoEspera = 1500;
	clock_t tiempoInicial = clock();  
	int nada;
	sf::Sprite Menu;
	sf::Texture MenuT;
	hud interface;

	sf::RenderWindow Ventana(sf::VideoMode(1050, 600, 32),"KEEP OUT"); 
	Ventana.setFramerateLimit(30);
	while (Ventana.isOpen()) {  
		switch (estado)
		{
		case 1:
			MenuT.loadFromFile("fondo2.png");
			Menu.setTexture(MenuT);
			Menu.setPosition(0, 0);
			Ventana.clear();
			Ventana.draw(Menu); 
			Ventana.display();
			sf::Event evento; 
			while (Ventana.pollEvent(evento)) {
				if (evento.type == sf::Event::Closed) {
					Ventana.close();
				}
				if (evento.type == sf::Event::MouseButtonPressed && evento.mouseButton.button == sf::Mouse::Left) {
					int posX = sf::Mouse::getPosition(Ventana).x; 
					int posY = sf::Mouse::getPosition(Ventana).y;
					if (posX > 422 && posX< 611 && posY> 180 && posY < 240) {
						estado = 2;
						break;
					}
					if (posX > 869 && posX < 1035 && posY> 530 && posY < 600) {
						Ventana.close();
						break;
					}
				}
			}
			break;
		case 2:
			vidas = 3; 
			puntos = 0;
			bajasBuenos = 0;
			bajasMalos = 0;
			while (vidas > 0) {
				bool colision = false;
				if (!jugando) {
					tipo = rand() % 2 + 1;
					posNPC = rand() % 3 + 1;
					tiempoInicial = clock();  
					jugando = true;
					if (posNPC == 1) {
						personaje.setPosition(157, 163);
					}
					if (posNPC == 2) {
						personaje.setPosition(471, 163); 
					}
					if (posNPC == 3) { 
						personaje.setPosition(803, 163); 
					}
					if (tipo == 1) { 
						personaje.colocarTextura(TnpcB);  
					} else{
						personaje.colocarTextura(TnpcM); 
					}

					interface.actualizar(puntos, vidas);
				}
				sf::Event evento;
				while (Ventana.pollEvent(evento)) {
					if (evento.type == sf::Event::Closed)
						Ventana.close();
					if (evento.type == sf::Event::MouseButtonPressed && evento.mouseButton.button == sf::Mouse::Left) {
						if(personaje.pegar(Ventana)){
							if (tipo == 2) {
								bajasMalos++;
								puntos = bajasMalos - bajasBuenos * 2;
								jugando = false;
								std::cout << "Puntos: " << bajasMalos << endl; 
								interface.actualizar(puntos, vidas);
							}
							else {
								bajasBuenos++;
								vidas--;
								puntos = bajasMalos - bajasBuenos * 2; 
								jugando = false;
								std::cout << "Bajas Buenos: " << bajasBuenos << endl;
								interface.actualizar(puntos, vidas);
							}
						}
					}
				
				}
				Smira.actualizar(Ventana); 
				Ventana.clear();
				personaje.dibujar(Ventana);
				back.dibujar(Ventana); 
				Smira.dibujar(Ventana); 
				interface.dibujar(Ventana);
				Ventana.display(); 
				if ((clock() - tiempoInicial) > (tiempoEspera * CLOCKS_PER_SEC / 1000)) {
					if (tipo == 2) {
						vidas--;
						std::cout << "Vidas: " << vidas << endl;
					}
					jugando = false;
					interface.actualizar(puntos, vidas);
				}
			}
			estado = 3;
		case 3:
			MenuT.loadFromFile("final.png");
			Menu.setTexture(MenuT);
			Menu.setPosition(0, 0);
			Ventana.clear();
			Ventana.draw(Menu);
			interface.dibujarPuntos(Ventana);
			Ventana.display();
			while (Ventana.pollEvent(evento)) {
				if (evento.type == sf::Event::Closed) {
					Ventana.close();
				}
				if (evento.type == sf::Event::MouseButtonPressed && evento.mouseButton.button == sf::Mouse::Left) {
						estado = 1;
						break;
					}
				}
			
			break;
		}
		
	}
	return 0;
}



