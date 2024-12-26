#include "principal.h"
principal:: principal() {
	x = 0,
	y = 0;
}
void principal::setPosition(float _x, float _y) {
	x = _x;
	y = _y;
	sprite.setPosition(x, y);
}
float principal::verX(){
	return x;
}
float principal::verY(){
	return y;
}

	