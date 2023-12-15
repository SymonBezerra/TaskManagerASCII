#ifndef ENTITY_H
#define ENTITY_H

#include <memory>
#include <string>
#include "ascii/ObjetoDeJogo.hpp"

using std::string;
using std::unique_ptr;
using std::shared_ptr;

class Entity : public ObjetoDeJogo {
	protected:
		const shared_ptr<Sprite> sprite;
	public:
		Entity(string name, const Sprite& sprite, int posL, int posC);
		bool collide_rect(const shared_ptr<Entity>& entity) const;
		shared_ptr<Sprite> getSprite() const;
};

#endif
