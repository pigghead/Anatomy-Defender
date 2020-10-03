#include "Player.h"

class Player {

private:
	int level = 1;
	int health = 10;
	int damage = 1;
	float x_pos = 0;
	float y_pos = 0;
	int speed = 5;

public:
	void LevelUp() {
		level++;
		//cout << "Level is now " << level;
	}

	void TakeDamage(int dmg) {
		health -= dmg;
	}

	void MoveLeft() {
		if (GetKeyState('A') & 0x8000) {
			x_pos -= speed;
		}
	}

	void MoveRight() {
		if (GetKeyState('D') & 0x8000) {
			x_pos += speed;
		}
	}

	void MoveUp() {
		if (GetKeyState('W') & 0x8000) {
			y_pos += speed;
		}
	}

	void MoveDown() {
		if (GetKeyState('S') & 0x8000) {
			y_pos -= speed;
		}
	}


	//void Attack() {

	//}
};

