#include "Math.h"

#include <cassert>
#include <math.h>

namespace yoyo
{
    const Vec2 operator*(const Vec2 &v1, const Vec2 &v2)
    {
        Vec2 product = {};
        product.x = v1.x * v2.x;
        product.y = v1.y * v2.y;

        return product;
    }

    const Vec3 operator*(const Vec3 &v1, const Vec3 &v2)
    {
        Vec3 product = {};
        product.x = v1.x * v2.x;
        product.y = v1.y * v2.y;
        product.z = v1.z * v2.z;

        return product;
    }

    const Vec2 operator+(const Vec2 &v1, const Vec2 &v2)
    {
        Vec2 sum = {};
        sum.x = v1.x + v2.x;
        sum.y = v1.y + v2.y;

        return sum;
    }

    const Vec3 operator+(const Vec3 &v1, const Vec3 &v2)
    {
        Vec3 sum = {};
        sum.x = v1.x + v2.x;
        sum.y = v1.y + v2.y;
        sum.z = v1.z + v2.z;

        return sum;
    }

    const IVec2 operator+(const IVec2 &v1, const IVec2 &v2)
    {
        IVec2 sum = {};
        sum.x = v1.x + v2.x;
        sum.y = v1.y + v2.y;

        return sum;
    }

    const Vec2 operator-(const Vec2 &v1, const Vec2 &v2)
    {
        Vec2 dif = {};
        dif.x = v1.x - v2.x;
        dif.y = v1.y - v2.y;

        return dif;
    }

    const Vec3 operator-(const Vec3 &v1, const Vec3 &v2)
    {
        Vec3 dif = {};
        dif.x = v1.x - v2.x;
        dif.y = v1.y - v2.y;
        dif.z = v1.z - v2.z;

        return dif;
    }

    const IVec2 operator-(const IVec2 &v1, const IVec2 &v2)
    {
        IVec2 dif = {};
        dif.x = v1.x - v2.x;
        dif.y = v1.y - v2.y;

        return dif;
    }

    const IVec2 operator*(const IVec2 &v1, int scalar)
    {
        IVec2 out = {};
        out.x = v1.x * scalar;
        out.y = v1.y * scalar;

        return out;
    }

    const IVec3 operator*(const IVec3 &v1, int scalar)
    {
        IVec3 out = {};
        out.x = v1.x * scalar;
        out.y = v1.y * scalar;
        out.z = v1.z * scalar;

        return out;
    }

    const Vec3 operator*(const Vec3 &v1, real scalar)
    {
        Vec3 out = {};
        out.x = v1.x * scalar;
        out.y = v1.y * scalar;
        out.z = v1.z * scalar;

        return out;
    }

    const Vec4 operator*(const Vec4 &v1, real scalar)
    {
        Vec4 out = {};
        out.x = v1.x * scalar;
        out.y = v1.y * scalar;
        out.z = v1.z * scalar;
        out.w = v1.w * scalar;

        return out;
    }

    const Vec2 operator/(const Vec2 &v1, real scalar)
    {
        assert(scalar != 0 && "Cannot divide by 0!");
        return {v1.x / scalar, v1.y / scalar};
    }

    const Vec3 operator/(const Vec3 &v1, real scalar)
    {
        assert(scalar != 0 && "Cannot divide by 0!");
        return {v1.x / scalar, v1.y / scalar, v1.z / scalar};
    }

    const Vec4 operator/(const Vec4 &v1, real scalar)
    {
        assert(scalar != 0 && "Cannot divide by 0!");
        return {v1.x / scalar, v1.y / scalar, v1.z / scalar, v1.w / scalar};
    }

    Vec3 operator*(const Mat4x4 &m, const Vec3 &v)
    {
        return {
            v.x * m.data[0] + v.y * m.data[4] + v.z * m.data[8],
            v.x * m.data[1] + v.y * m.data[5] + v.z * m.data[9],
            v.x * m.data[2] + v.y * m.data[6] + v.z * m.data[10]};
    }

    const Vec4 operator*(const Mat4x4 &m, const Vec4 &v)
    {
        return {
            v.x * m.data[0] + v.y * m.data[4] + v.z * m.data[8] + v.w * m.data[12],
            v.x * m.data[1] + v.y * m.data[5] + v.z * m.data[9] + v.w * m.data[13],
            v.x * m.data[2] + v.y * m.data[6] + v.z * m.data[10] + v.w * m.data[14],
            v.x * m.data[3] + v.y * m.data[7] + v.z * m.data[11] + v.w * m.data[15]};
    }

    const Mat4x4 operator*(const Mat4x4 &v1, real scalar)
    {
        Mat4x4 out = v1;
        out *= scalar;

        return out;
    }

    const Mat4x4 operator*(const Mat4x4 &m1, const Mat4x4 &m2)
    {
        Mat4x4 out_matrix = {};
        real *dst = out_matrix.data;

        Mat4x4 temp = m2;
        real *temp_data_ptr = temp.data;

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                *dst =
                    temp_data_ptr[0] * m1.data[0 + j] +
                    temp_data_ptr[1] * m1.data[4 + j] +
                    temp_data_ptr[2] * m1.data[8 + j] +
                    temp_data_ptr[3] * m1.data[12 + j];

                dst++;
            }
            temp_data_ptr += 4;
        }

        return out_matrix;
    }

    const real SquaredLength(const Vec3 &v1)
    {
        return v1.x * v1.x + v1.y * v1.y + v1.z * v1.z;
    }

    const real Length(const Vec3 &v1)
    {
        return sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z);
    }

    const real Length(const Vec4 &v1)
    {
        return sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z + v1.w * v1.w);
    }

    const real Length(const Vec2 &v1)
    {
        return sqrt(v1.x * v1.x + v1.y * v1.y);
    }

    const Vec2 Normalize(const Vec2 &v1)
    {
        real l = Length(v1);

        if (l <= 0)
        {
            assert(0 && "Cannot normalize a vector with 0 length");
            return {0.0f, 0.0f};
        }

        return v1 / l;
    }

    const Vec3 Normalize(const Vec3 &v1)
    {
        real l = Length(v1);

        if (l <= 0)
        {
            assert(0 && "Cannot normalize a vector with 0 length");
            return {0.0f, 0.0f, 0.0f};
        }

        return v1 / l;
    }

    const Vec4 Normalize(const Vec4 &v1)
    {
        real l = Length(v1);

        if (l <= 0)
        {
            assert(0 && "Cannot normalize a vector with 0 length");
            return {0.0f, 0.0f, 0.0f, 0.0f};
        }

        return v1 / l;
    }

    const Vec2 NormalizeOrZero(const Vec2 &v1)
    {
        real l = Length(v1);

        if (l <= 0)
        {
            return {0.0f, 0.0f};
        }

        return v1 / l;
    }

    const Vec3 Reflect(const Vec3 &v1, const Vec3 &n)
    {
        return v1 - (n * 2.0 * Dot(v1, n));
    }

    const Vec3 Cross(const Vec3 &v1, const Vec3 &v2)
    {
        return {v1.y * v2.z - v1.z * v2.y,
                v1.z * v2.x - v1.x * v2.z,
                v1.x * v2.y - v1.y * v2.x};
    }

    const Vec3 Lerp(const Vec3 &v1, const Vec3 &v2, real t)
    {
        return {
            Lerp(v1.x, v2.x, t),
            Lerp(v1.y, v2.y, t),
            Lerp(v1.z, v2.z, t),
        };
    }

    const Vec4 Lerp(const Vec4 &v1, const Vec4 &v2, real t)
    {
        return {
            Lerp(v1.x, v2.x, t),
            Lerp(v1.y, v2.y, t),
            Lerp(v1.z, v2.z, t),
            Lerp(v1.w, v2.w, t),
        };
    }

    const real Dot(const Vec3 &v1, const Vec3 &v2)
    {
        return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
    }

    const real Dot(const Vec4 &v1, const Vec4 &v2)
    {
        return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
    }

    real Sqrt(real val)
    {
        assert(val > 0.0 && "Cannot take sqrt of number <= 0!");
        return sqrt(val);
    }

    real Cos(real rad)
    {
        return cos(rad);
    }

    real Sin(real rad)
    {
        return sin(rad);
    }

    real Tan(real rad)
    {
        return tan(rad);
    }

    real ACos(real rad)
    {
        return acos(rad);
    }

    real DegToRad(real deg)
    {
        return deg * (Y_PI / 180.0f);
    }

    real RadToDeg(real rad)
    {
        return (rad * 180.0f) / Y_PI;
    }

    const real Lerp(real a, real b, real t)
    {
        return (a * (1 - t)) + (b * t);
    }

    const real Clamp(real value, real min, real max)
    {
        if (value < min)
        {
            return min;
        }

        if (value > max)
        {
            return max;
        }

        return value;
    }

    bool FloatCompare(real x, real y, real epsilon)
    {
        return (fabs(x - y) < epsilon);
    }
}