//
// Created by Vijay Kumar Hans on 6/28/26.
//

#ifndef GRAPHICS_PROJECT_RAY_H
#define GRAPHICS_PROJECT_RAY_H

#include "vec3.h"

class ray {
private:
    point3 orig;
    vec3 dir;
public:
    ray() {};

    ray(const point3& location, const vec3& direction) : orig(location), dir(direction) {};

    const point3& origin() const { return orig; }
    const vec3& direction() const { return dir; }

    point3 at(double t) const {
        return point3(orig + t*dir);
    }
};

#endif //GRAPHICS_PROJECT_RAY_H
