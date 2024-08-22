#pragma once

#include "Defines.h"
#include "MathTypes.h"

#define Y_PI 3.14159265897932

namespace yoyo
{
    YAPI real Sqrt(real val);

    YAPI real Cos(real rad);
    YAPI real Sin(real rad);
    YAPI real Tan(real rad);

    YAPI real ACos(real rad);

    YAPI real DegToRad(real deg);
    YAPI real RadToDeg(real rad);

    YAPI const real Lerp(real a, real b, real t);
    YAPI const real Clamp(real value, real min, real max);

    YAPI bool FloatCompare(real x, real y, real epsilon = 0.01f);

    YAPI const real SquaredLength(const Vec3& v1);
    YAPI const real Length(const Vec2& v1);
    YAPI const real Length(const Vec3& v1);
    YAPI const real Length(const Vec4& v1);
    YAPI const Vec2 Normalize(const Vec2& v1);
    YAPI const Vec3 Normalize(const Vec3& v1);
    YAPI const Vec4 Normalize(const Vec4& v1);
    YAPI const Vec2 NormalizeOrZero(const Vec2& v1);

    YAPI const Vec3 Reflect(const Vec3& v1, const Vec3& n);

    YAPI const real Dot(const Vec3& v1, const Vec3& v2);
    YAPI const real Dot(const Vec4& v1, const Vec4& v2);

    YAPI const Vec3 Cross(const Vec3& v1, const Vec3& v2);

    YAPI const Vec3 Lerp(const Vec3& v1, const Vec3& v2, real t);
    YAPI const Vec4 Lerp(const Vec4& v1, const Vec4& v2, real t);

    YAPI const Vec2 operator*(const Vec2& v1, const Vec2& v2);
    YAPI const Vec3 operator*(const Vec3& v1, const Vec3& v2);

    YAPI const Vec2 operator+(const Vec2& v1, const Vec2& v2);
    YAPI const Vec3 operator+(const Vec3& v1, const Vec3& v2);
    YAPI const IVec2 operator+(const IVec2& v1, const IVec2& v2);

    YAPI const Vec2 operator-(const Vec2& v1, const Vec2& v2);
    YAPI const Vec3 operator-(const Vec3& v1, const Vec3& v2);
    YAPI const IVec2 operator-(const IVec2& v1, const IVec2& v2);

    YAPI const IVec2 operator*(const IVec2& v1, int scalar);
    YAPI const IVec3 operator*(const IVec3& v1, int scalar);
    YAPI const Vec3 operator*(const Vec3& v1, real scalar);
    YAPI const Vec4 operator*(const Vec4& v1, real scalar);

    YAPI const Vec2 operator/(const Vec2& v1, real scalar);
    YAPI const Vec3 operator/(const Vec3& v1, real scalar);
    YAPI const Vec4 operator/(const Vec4& v1, real scalar);

    YAPI const Mat4x4 operator*(const Mat4x4& v1, real scalar);
    YAPI const Mat4x4 operator*(const Mat4x4& m1, const Mat4x4& m2);

    YAPI Vec3 operator*(const Mat4x4& m, const Vec3& v);
    YAPI const Vec4 operator*(const Mat4x4& m, const Vec4& v);
}