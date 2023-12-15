#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <string>
#include <memory>
#include "entity.hpp"
#include "ascii/Sprite.hpp"

using std::shared_ptr;

class Projectile : public Entity {
	private:
		const bool shooter;
	public:
		Projectile(int posL, int posC, const Sprite& sprite, bool shooter);
		bool getShooter() const;
		bool collide_rect(const shared_ptr<Entity>& entity) const;
};

#endif
