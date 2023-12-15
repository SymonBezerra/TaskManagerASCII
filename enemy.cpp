#include "enemy.hpp"
#include "entity.hpp"
#include "ascii/Sprite.hpp"

Enemy::Enemy(int posL, int posC, Sprite& sprite, const bool shooter) :
Entity("Enemy", sprite, posL, posC), shooter(shooter), shoot_frames(2) {}

int Enemy::getShootFrames() const { return shoot_frames; }

bool Enemy::getShooter() const { return shooter; }

void Enemy::update() {
	ObjetoDeJogo::update();
	if (shoot_frames > 0) shoot_frames -= 1;
	else if(getPosC() >= 100) shoot_frames = 4;
}

