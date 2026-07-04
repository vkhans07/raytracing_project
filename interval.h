//
// Created by Vijay Kumar Hans on 7/4/26.
//

#ifndef GRAPHICS_PROJECT_INTERVAL_H
#define GRAPHICS_PROJECT_INTERVAL_H
#include "rtweekend.h"

class interval {
public:
    double min, max;

    interval(): min(+infinity), max(-infinity) {};
    interval(double min, double max): min(min), max(max) {};

    double size() const {
        return max - min;
    }

    bool contains(double x) const {
        return min <= x && max >= x;
    }

    bool surrounds(double x) const {
        return min < x && max > x;
    }

    static const interval empty, universe;
};

const interval interval::empty = interval(+infinity, -infinity);
const interval interval::universe = interval(-infinity, +infinity);

#endif //GRAPHICS_PROJECT_INTERVAL_H
