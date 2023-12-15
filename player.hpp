#include "ascii/Sprite.hpp"
#ifndef PLAYER_H
#define PLAYER_H
#include "entity.hpp"

class Player : public Entity {
	public:
		Player(int posL, int posC, Sprite& sprite);
};

#endif
