#include "Collision.h"

bool Collision::testSphereSphere(const Sphere& sphere1, const Sphere& sphere2) {
	XMFLOAT3 vec; 
	vec.x = sphere1.position.x - sphere2.position.x;
	vec.y = sphere1.position.y - sphere2.position.y;
	vec.z = sphere1.position.z - sphere2.position.z;
	float sqLength = (vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z);
	float r = sphere1.radius + sphere2.radius;

	return sqLength <= r * r;
}

bool Collision::testSphereBox(const Sphere& sphere, const Box& box) {
	float sqDistance = 0.0f;
	float pos;

	pos = sphere.position.x;
	if (pos < box.minPosition.x) {
		sqDistance += (pos - box.minPosition.x) * (pos - box.minPosition.x);
	}
	else if (pos > box.maxPosition.x) {
		sqDistance += (pos - box.maxPosition.x) * (pos - box.maxPosition.x);
	}

	pos = sphere.position.y;
	if (pos < box.minPosition.y) {
		sqDistance += (pos - box.minPosition.y) * (pos - box.minPosition.y);
	}
	else if (pos > box.maxPosition.y) {
		sqDistance += (pos - box.maxPosition.y) * (pos - box.maxPosition.y);
	}

	pos = sphere.position.z;
	if (pos < box.minPosition.z) {
		sqDistance += (pos - box.minPosition.z) * (pos - box.minPosition.z);
	}
	else if (pos > box.maxPosition.z) {
		sqDistance += (pos - box.maxPosition.z) * (pos - box.maxPosition.z);
	}

	return sqDistance <= sphere.radius * sphere.radius;
}