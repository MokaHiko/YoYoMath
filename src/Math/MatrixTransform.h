#pragma once

#include "Math.h"
#include "Quaternion.h"

namespace yoyo
{
    // Generates an orthographic projection matrix
    YAPI Mat4x4 OrthographicProjectionMat4x4(real left, real right, real bottom, real top, real near, real far);

    // Generates an perspective projection matrix
    YAPI Mat4x4 PerspectiveProjectionMat4x4(real fov_radians, real aspect_ratio, real near, real far);

    // Generates a look at matrix 
    YAPI Mat4x4 LookAtMat4x4(const Vec3& position, const Vec3& target, const Vec3& up);

    // Generates an translation matrix
    YAPI Mat4x4 TranslationMat4x4(const Vec3& position);

    // Generates an scale matrix
    YAPI Mat4x4 ScaleMat4x4(const Vec3& scale);

    // Generates a rotation matrix an angle in radians and a rotation axis
    YAPI Mat4x4 RotateMat4x4(real angle_radians, const Vec3& axis);

    // Generates a rotation matrix given euler angles 
    YAPI Mat4x4 RotateEulerMat4x4(const Vec3& angles);

    YAPI Mat4x4 TransposeMat4x4(const Mat4x4& matrix);

    YAPI real Trace4x4(const Mat4x4& matrix);

    YAPI Mat4x4 QuatToMat4x4(const Quat& q);

    // Returns the inverse of a matrix
    YAPI Mat4x4 InverseMat4x4(const Mat4x4& matrix);

    YAPI Vec3 PositionFromMat4x4(const Mat4x4& matrix);

    YAPI Vec3 ScaleFromMat4x4(const Mat4x4& matrix);

    // Returns a normalized quaternion from the matrix 
    YAPI Quat RotationFromMat4x4(const Mat4x4& matrix);
}