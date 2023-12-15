#ifndef MEMORY_H
#define MEMORY_H
#include "entity.hpp"
#include "ascii/Sprite.hpp"

class Memory : public Entity {
	public:
		Memory(int posL, int posC, Sprite& sprite);
};

#endif
