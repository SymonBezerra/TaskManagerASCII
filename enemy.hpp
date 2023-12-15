#ifndef ENEMY_H
#define ENEMY_H

#include <memory>
#include <vector>
#include "entity.hpp"
#include "projectile.hpp"
#include "ascii/Sprite.hpp"

using std::shared_ptr;
using std::make_shared;
using std::vector;

class Enemy : public Entity {
	private:
		const bool shooter;
		int shoot_frames;
	public:
		Enemy(int posL, int posC, Sprite& sprite, const bool shooter);
		int getShootFrames() const;
		bool getShooter() const;
		void update();
};

#endif
