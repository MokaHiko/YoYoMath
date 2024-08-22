#pragma once


#include "Math/Math.h"

namespace yoyo
{
    struct YAPI Ray
    {
        Ray() = default;
        Ray(const Vec3& ray_origin, const Vec3& ray_dir);

        Vec3 GetPoint(real t) const;
    public:
        Vec3 origin;
        Vec3 direction;
    };
}