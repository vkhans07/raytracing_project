//
// Created by Vijay Kumar Hans on 7/4/26.
//

#ifndef GRAPHICS_PROJECT_HITTABLE_H
#define GRAPHICS_PROJECT_HITTABLE_H

#include "ray.h"

class hit_record {
public:
    point3 p;
    vec3 normal;
    double t;
};

class hittable {
public:
    virtual ~hittable() = default;

    virtual bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const = 0;
};


#endif //GRAPHICS_PROJECT_HITTABLE_H
