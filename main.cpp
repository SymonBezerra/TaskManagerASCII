#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <utility>
#include <cstdlib>
#include <ctime>
#include "ascii/SpriteAnimado.hpp"
#include "ascii/Sprite.hpp"
#include "ascii/SpriteBuffer.hpp"
#include "player.hpp"
#include "memory.hpp"
#include "enemy.hpp"
#include "projectile.hpp"

using std::vector;
using std::shared_ptr;
using std::make_shared;

int main() {
	system("clear");

	SpriteBuffer screen(220, 33);
	Sprite playerSprite("gfx/player.txt");
	Sprite runnerSprite("gfx/enemy2.txt");
	Sprite shooterSprite("gfx/enemy.txt");

	int spawn_frames = 1;
	int spawn_rate = 10;
	int player_score = 0;
	int enemy_move = 10;
	int projectile_move = 10;

	vector<shared_ptr<Memory>> memories;
	vector<shared_ptr<Enemy>> enemies;
	vector<shared_ptr<Projectile>> projectiles;
	vector<shared_ptr<Projectile>> enemy_projectiles;

	for (int i = 0; i < 5; i++) {
		Sprite s("gfx/ram.txt");
		memories.push_back(make_shared<Memory>(Memory(1 + (6 * i), 0, s)));
	}

	shared_ptr<Player> player = make_shared<Player>(1, 12, playerSprite);
	bool running = true;
	// TODO: game menu and reset
	bool game = false;
	char input;
	while(running) {
		system("clear");
		screen.clear();
		bool collide;

		if (player_score % 2000 == 0 && spawn_rate > 5) spawn_rate -= 1;

		if (spawn_frames > 0) { spawn_frames = spawn_frames - 1; }
		else {
			spawn_frames = spawn_rate;
			srand(time(0));
			int shooter_spawn = (rand() % 11) % 5;
			int lane = rand() % 5;
			if (shooter_spawn == 0)
				enemies.push_back(make_shared<Enemy>(1 + (6 * lane), 200, runnerSprite, false));
			else enemies.push_back(make_shared<Enemy>(1 + (6 * lane), 200, shooterSprite, true));
		}
		player->draw(screen, player->getPosL(), player->getPosC());
		for (int i = 0; i < memories.size(); i++) {
			memories[i]->draw(screen, memories[i]->getPosL(), memories[i]->getPosC());
		}
		for (int k = enemies.size() - 1; k >= 0; k--) {
			bool collide = false;
			if (enemies[k]->getShootFrames() >= 0) enemies[k]->update();
			if (enemies[k]->getShooter() && enemies[k]->getShootFrames() == 0) {
				enemy_projectiles.push_back(make_shared<Projectile>(
					enemies[k]->getPosL(), enemies[k]->getPosC() - 5,
					Sprite("gfx/enemy_projectile.txt"), true));
			}
			for (int m = memories.size() - 1; m >= 0; m--) {
				if (memories[m]->collide_rect(enemies[k])) {
					memories.erase(memories.begin() + m);
					collide = true;
					break;
				}
			}
			if (player->collide_rect(enemies[k])) {
				running = false;
			 	break;
			}
			if (collide) {
				enemies.erase(enemies.begin() + k);
				continue;
			} else if (enemies[k]->getPosC() > 2) {
				enemies[k]->moveLeft(enemy_move);
			} else {
				running = false;
				break;
			}
			enemies[k]->draw(screen, enemies[k]->getPosL(), enemies[k]->getPosC());
		}
		for (int j = projectiles.size() - 1; j >= 0; j--) {
			bool collide = false;
			projectiles[j]->draw(screen, projectiles[j]->getPosL(), projectiles[j]->getPosC());
			if (projectiles[j]->getShooter()) projectiles[j]->moveLeft(projectile_move);
			else projectiles[j]->moveRight(projectile_move);
			if (projectiles[j]->getPosC() > 180 || projectiles[j]->getPosC() < 0) {
			        projectiles.erase(projectiles.begin() + (projectiles.size() - j));
		        	continue;
			} else {
				for (int e = enemies.size() - 1; e >= 0; e--) {
					if (projectiles[j]->collide_rect(enemies[e])) {
						enemies.erase(enemies.begin() + e);
						collide = true;
						player_score += 100;
						break;
					}
				}
				if (collide) projectiles.erase(projectiles.begin() + j);
			}
		}

		for (int l = enemy_projectiles.size() - 1; l >= 0; l--) {
			if (enemy_projectiles[l]->collide_rect(player)) {
				enemy_projectiles.erase(enemy_projectiles.begin() + l);
				running = false;
				break;
			} else if (enemy_projectiles[l]->getPosC() >= 12) {
				enemy_projectiles[l]->moveLeft(enemy_move + projectile_move);
			} else {
				enemy_projectiles.erase(enemy_projectiles.begin() + l);
				break;
			}
			enemy_projectiles[l]->draw(screen, enemy_projectiles[l]->getPosL(),
				enemy_projectiles[l]->getPosC());
		}

		std::cout << screen << std::endl;
		std::cout << "Score: " << player_score << std::endl;
		std::cin >> input;
		if (input == 's' && player->getPosL() < 25) player->moveDown(6);
		else if (input == 'w' && player->getPosL() > 1) player->moveUp(6);
		else if (input == 'q' && projectiles.size() < 5) {
			projectiles.push_back(make_shared<Projectile>(player->getPosL() + 2,
				10, Sprite("gfx/projectile.txt"), false));
		}
		else if (input == 'x') running = false;
	}
	return 0;
}

