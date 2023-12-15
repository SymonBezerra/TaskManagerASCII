#include "projectile.hpp"
#include "entity.hpp"
#include "ascii/Sprite.hpp"

Projectile::Projectile(int posL, int posC, const Sprite& sprite, bool shooter) :
Entity("Projectile", sprite, posL, posC), shooter(shooter) {}

bool Projectile::getShooter() const { return this->shooter; }

bool Projectile::collide_rect(const shared_ptr<Entity>& entity) const {
		for (int i = -5; i <= 5 ? getPosC() >= 12 : 0; i++) {
			if ((entity->getPosL() <= getPosL() + sprite->getAltura() &&
			 entity->getPosL() + entity->getSprite()->getAltura() >= getPosL()) &&
			(entity->getPosC() <= getPosC() + i + sprite->getLargura() &&
			 entity->getPosC() + entity->getSprite()->getLargura() >= getPosC() + i)) return true;
		 };
		 return false;
}
