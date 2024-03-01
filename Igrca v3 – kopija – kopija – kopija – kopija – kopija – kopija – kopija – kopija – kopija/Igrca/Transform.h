#pragma once
#include "Vector2D.h"

class Transform {

public:
	float X, Y;
	Transform(float x=0, float y=0):X(x), Y(y) {}
	void Log(std::string mag = "") {
		std::cout << mag << X << " " << Y << std::endl;
	}

	void TranslateX(float x) { X += x; }
	void TranslateY(float y) { Y += y; }
	void TranslateX(Vector2D v) { X += v.X; Y += v.Y; }
};
