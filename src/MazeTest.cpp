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
#include <iterator>

class PosType {
private:
	int x;
	int y;
	int type; //0-通道 1-墙
public:
	PosType(int x, int y, int type = 1) :
			x(x), y(y), type(type) {

	}
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
	friend std::ostream & operator<<(std::ostream & os, const PosType & pos) {
		os << "x:" << pos.getX() << " y:" << pos.getY() << " type:" << pos.getType() << std::endl;
		return os;
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
	Maze(int width, int height);
	virtual ~Maze() {
	}
	void show() const;
};

Maze::Maze(int width, int height) {
	std::srand(std::time(0));
	for (int i = 0; i < width; ++i) {
		for (int j = 0; j < height; ++j) {
			PosType p(i, j);
			if (i != 0 && i != width - 1 && j != 0 && j != height - 1) {
				p.setType(std::rand() % 2);
			}
			poss.push_back(p);
		}
	}
}

void Maze::show() const {
	std::ostream_iterator<PosType, char> ost(std::cout, "");
	std::copy(poss.begin(), poss.end(), ost);
}

void MazeTest() {
	Maze maze(10, 10);
	maze.show();
}

