#include <memory>
#include <string>
#include <memory>
#include "entity.hpp"
#include "ascii/ObjetoDeJogo.hpp"

using std::string;
using std::unique_ptr;
using std::shared_ptr;
using std::make_shared;

Entity::Entity(string name, const Sprite& sprite, int posL, int posC) :
ObjetoDeJogo(name, sprite, posL, posC), sprite(make_shared<Sprite>(sprite)) {
}

bool Entity::collide_rect(const shared_ptr<Entity>& entity) const {
		return (entity->getPosL() <= getPosL() + sprite->getAltura() &&
		 entity->getPosL() + entity->getSprite()->getAltura() >= getPosL()) &&
		(entity->getPosC() <= getPosC() + sprite->getLargura() &&
		 entity->getPosC() + entity->getSprite()->getLargura() >= getPosC());
}

shared_ptr<Sprite> Entity::getSprite() const { return this->sprite; }
