#include "memory.hpp"
#include "entity.hpp"
#include "ascii/Sprite.hpp"

Memory::Memory(int posL, int posC, Sprite& sprite) :
Entity("Memory", sprite, posL, posC) {}
