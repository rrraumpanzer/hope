#pragma once

enum class Direction { Left = 0, Right = 1, Up = 2, Down = 3 };

class GameModel
{
public:
	static const int SIZE = 4;						
	static const int ARRAY_SIZE = SIZE * SIZE;		
	static const int FIELD_RADIUS = 350;				
	static const int CELL_SIZE = 120;				
protected:
	int elements[ARRAY_SIZE];
	int empty_index;
	bool solved;
public:
	GameModel();
	void Init();
	bool Check();
	void Move(Direction direction);
	bool IsSolved() { return solved; }
	int* Elements() { return elements; }
};