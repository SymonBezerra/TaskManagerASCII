#include "entity.hpp"
#include "player.hpp"
#include "ascii/Sprite.hpp"

Player::Player(int posL, int posC, Sprite& sprite) :
Entity("Player", sprite, posL, posC) {}
