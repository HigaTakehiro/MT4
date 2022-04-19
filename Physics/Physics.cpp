#include "Physics.h"

void Physics::Gravity(XMFLOAT3* pos) {
	if (fallPos.y <= 0.0f) {
		fallPos = *pos;
	}
	time += 0.1;
	fallPos.y -= gravity * time * time / 2.0f;
	pos = &fallPos;
}