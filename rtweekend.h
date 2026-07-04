//
// Created by Vijay Kumar Hans on 7/4/26.
//

#ifndef GRAPHICS_PROJECT_RTWEEKEND_H
#define GRAPHICS_PROJECT_RTWEEKEND_H

#include <cmath>
#include <iostream>
#include <limits>
#include <memory>

// usings from standard library
using std::make_shared;
using std::shared_ptr;

// constants
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

// common headers
#include "color.h"
#include "ray.h"
#include "vec3.h"
#include "interval.h"
#include "camera.h"

#endif //GRAPHICS_PROJECT_RTWEEKEND_H
