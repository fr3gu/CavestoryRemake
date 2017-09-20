#ifndef GLOBALS_H
#define GLOBALS_H

namespace globals {
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGTH = 480;

	const float SPRITE_SCALE = 2.0;
}

enum Direction {
	LEFT,
	RIGHT,
	UP,
	DOWN
};

struct RgbHolder {
	int r, g, b;
	bool isSet;
	RgbHolder() : RgbHolder(-1, -1, -1) { this->isSet = false; }
	RgbHolder(int r, int g, int b) : r(r), g(g), b(b) { isSet = true; }

};

struct Vector2 {
	int x, y;
	Vector2() : Vector2(0, 0) { }

	Vector2(int x, int y) : x(x), y(y) {

	}

	static Vector2 zero() {
		return Vector2(0, 0);
	}
};

#endif // !GLOBALS_H

