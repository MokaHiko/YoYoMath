#pragma once

#include "Math.h"

namespace yoyo
{
    union YAPI Quat
    {
        Quat() : elements{0.0, 0.0, 0.0, 1.0} {} // Initialize elements in the default constructor
        ~Quat() = default;

        Quat(real x, real y, real z, real scalar)
            : elements{x, y, z, scalar} {} // Initialize elements in the parameterized constructor

        Quat(const Vec3 &v, real scalar)
            : elements{v.x, v.y, v.z, scalar} {}
#ifdef YUSESIMD
        // Use SIMD
        alignas(16) _m128 data;
#endif
        alignas(16) real elements[4];
        struct
        {
            union
            {
                real x, r, s;
            };
            union
            {
                real y, g, t;
            };
            union
            {
                real z, b, p;
            };
            union
            {
                real w, a, q;
            };
        };

        operator Vec4() const { return {x, y, z, w}; }
        Quat &operator*=(const Quat &other);
    };

    // Returns the normal of the quaternion.
    YAPI real NormalQuat(const Quat &q);

    // Returns a normalized version of the quaternion.
    YAPI Quat NormalizeQuat(const Quat &q);

    // Returns a quaternion from the given axis and angle normalized by deafult.
    YAPI Quat QuatFromAxisAngle(const Vec3 &axis, real angle, bool normalize = true);

    // Returns the euler angles of the quaternion.
    YAPI Vec3 EulerAnglesFromQuat(const Quat &q);

    YAPI const Quat operator*(const Quat &q1, const Quat &q2);

    YAPI const Quat Slerp(const Quat &q1, const Quat &q2, real t);
    YAPI const Quat operator*(const Quat &q, real scalar);
    YAPI const Quat operator+(const Quat &q1, const Quat &q2);
    YAPI const Quat operator-(const Quat &q1, const Quat &q2);
}
