#include "Player.h"

	int level = 1;
	int health = 10;
	int damage = 0;
	float x_pos = 0;
	float y_pos = 0;
	int speed = 5;

	void LevelUp() {
		level++;
		//std::cout << "Level is now " << level;
	}

	void TakeDamage(int dmg) {
		health -= dmg;
	}

	void Attack(bool hasBuff) {
		if (hasBuff) {
			damage = 2;

		}

		else {
			damage = 1;
		}
	}



