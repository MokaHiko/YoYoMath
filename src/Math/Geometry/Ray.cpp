#include "Ray.h"

#include <assert.h>

namespace yoyo
{
    Ray::Ray(const Vec3 &ray_origin, const Vec3 &ray_dir)
        : origin(ray_origin), direction(ray_dir)
    {
    }

    Vec3 Ray::GetPoint(real t) const
    {
        assert(t > 0.0 && "Ray cannot be evaluated at negative time");
        return origin + direction * t;
    }
}