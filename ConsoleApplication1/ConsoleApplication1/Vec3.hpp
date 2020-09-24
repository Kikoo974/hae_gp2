#pragma once

class Vec3 {
public:
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
    Vec3() {}
    Vec3(float x, float y, float z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    Vec3 add(Vec3 v) {
        Vec3 xyz;
        xyz.x = this->x + v.x;
        xyz.y = this->y + v.y;
        xyz.z = this->z + v.z;
        return xyz;
    }
    Vec3 sub(Vec3 v) {
        Vec3 xyz;
        xyz.x = this->x - v.x;
        xyz.y = this->y - v.y;
        xyz.z = this->z - v.z;
        return xyz;
    }
    Vec3 mul(Vec3 v) {
        Vec3 xyz;
        xyz.x = this->x * v.x;
        xyz.y = this->y * v.y;
        xyz.z = this->z * v.z;
        return xyz;
    }
    Vec3 div(Vec3 v) {
        Vec3 xyz;
        xyz.x = this->x / v.x;
        xyz.y = this->y / v.y;
        xyz.z = this->z / v.z;
        return xyz;
    }

};
