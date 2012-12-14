/*
 * MazeTest.cpp
 *
 *  Created on: 2012-12-14
 *      Author: lzero
 */
#include "Test.h"
#include <iostream>
#include <stack>
#include <list>
#include <cstdlib>
#include <ctime>

class PosType {
private:
	int x;
	int y;
	int type; //0-通道 1-墙
public:
	void setX(int x) {
		this->x = x;
	}
	void setY(int y) {
		this->y = y;
	}

	int getX() const {
		return x;
	}

	int getY() const {
		return y;
	}

	int getType() const {
		return type;
	}

	void setType(int type) {
		this->type = type;
	}
};

class SElemType {
private:
	int ord;
	PosType pos;
	int di;
public:
	int getDi() const {
		return di;
	}

	void setDi(int di) {
		this->di = di;
	}

	int getOrd() const {
		return ord;
	}

	void setOrd(int ord) {
		this->ord = ord;
	}

	const PosType& getPos() const {
		return pos;
	}

	void setPos(const PosType& pos) {
		this->pos = pos;
	}
};

class Maze {
private:
	std::list<PosType> poss;
public:
	Maze(const PosType& start, const PosType& end);
	virtual ~Maze() {
	}
};

Maze::Maze(const PosType& start, const PosType& end){
	std::srand(std::time(0));
}

void MazeTest() {

}

