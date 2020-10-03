#include <Windows.h>
#include <iostream>
using namespace std;

class Player {

public:
	void LevelUp();

	void TakeDamage(int dmg);

	void MoveLeft();

	void MoveRight();

	void MoveUp();

	void MoveDown();

	void Attack();
};

