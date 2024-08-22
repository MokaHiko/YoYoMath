#pragma once

#include "Defines.h"

namespace yoyo
{
    typedef double real;

    union YAPI Vec2
    {
        Vec2() : x(0), y(0) { elements[0] = x; elements[1] = y; }
        Vec2(real val) : x(val), y(val) { elements[0] = x; elements[1] = y; }
        Vec2(real _x, real _y) : x(_x), y(_y) { elements[0] = x; elements[1] = y; }
        
        real elements[2];

        struct
        {
            union
            {
                real x, r, s, u;
            };
            union
            {
                real y, g, t, v;
            };
        };

        Vec2& operator*=(const Vec2& other);
    };

    union YAPI IVec2
    {
        int elements[2];

        struct
        {
            union
            {
                int x, r, s, u;
            };
            union
            {
                int y, g, t, v;
            };
        };
    };

    union YAPI Vec3
    {
        Vec3() : x(0), y(0), z(0) { elements[0] = x; elements[1] = y; elements[2] = z; }
        Vec3(real val) : x(val), y(val), z(val) { elements[0] = x; elements[1] = y; elements[2] = z; }
        Vec3(real _x, real _y, real _z) : x(_x), y(_y), z(_z) { elements[0] = x; elements[1] = y; elements[2] = z; }

        real elements[3];

        struct
        {
            union
            {
                real x, r, s, u;
            };
            union
            {
                real y, g, t, v;
            };
            union
            {
                real z, b, p, w;
            };
        };

        Vec3& operator+=(real scalar);
        Vec3& operator-=(real scalar);
        Vec3& operator*=(real scalar);
        Vec3& operator/=(real scalar);

        Vec3& operator+=(const Vec3& other);
        Vec3& operator-=(const Vec3& other);
        Vec3& operator*=(const Vec3& other);

        bool operator==(const Vec3& other) const;
        bool operator!=(const Vec3& other) const;
    };

    union YAPI IVec3
    {
        int elements[3];

        struct
        {
            union
            {
                int x, r, s, u;
            };
            union
            {
                int y, g, t, v;
            };
            union
            {
                int z, b, p, w;
            };
        };

        bool operator==(const IVec3& other) const;
        bool operator!=(const IVec3& other) const;
    };

    union YAPI Vec4
    {
#ifdef YUSESIMD
        alignas(16) _m128 data;
#endif
        alignas(16) real elements[4];

        Vec4() : x(0), y(0), z(0), w(0) { elements[0] = x; elements[1] = y; elements[2] = z; elements[3] = w;}
        Vec4(real _x, real _y, real _z, real _w) : x(_x), y(_y), z(_z), w(_w) { elements[0] = x; elements[1] = y; elements[2] = z; elements[3] = w;}

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

        Vec4& operator*=(real scalar);
        Vec4& operator+=(const Vec4& other);

        operator Vec3() const { return { x, y, z }; }
    };

    union YAPI IVec4
    {
#ifdef YUSESIMD
        alignas(16) _m128 data;
#endif
        alignas(16) int elements[4];

        struct
        {
            union
            {
                int x, r, s;
            };
            union
            {
                int y, g, t;
            };
            union
            {
                int z, b, p;
            };
            union
            {
                int w, a, q;
            };
        };
    };

    union YAPI Mat4x4
    {
        Mat4x4();
        ~Mat4x4();

        Mat4x4(real val);

        alignas(16) real data[16];
#ifdef YUSESIMD
        alignas(16) Vec4 rows[4];
#endif
        Mat4x4& operator*=(const Mat4x4& other);
        Mat4x4& operator*=(real scalar);
        real& operator[](int index);
    };

    // Definitions for Vec3 and IVec3 comparison operators
    inline bool Vec3::operator==(const Vec3& other) const {
        return x == other.x && y == other.y && z == other.z;
    }

    inline bool Vec3::operator!=(const Vec3& other) const {
        return !(*this == other);
    }

    inline bool IVec3::operator==(const IVec3& other) const {
        return x == other.x && y == other.y && z == other.z;
    }

    inline bool IVec3::operator!=(const IVec3& other) const {
        return !(*this == other);
    }
}

