//
// Created by Vijay Kumar Hans on 7/4/26.
//

#ifndef GRAPHICS_PROJECT_SPHERE_H
#define GRAPHICS_PROJECT_SPHERE_H

#include "hittable.h"
#include "vec3.h"

class sphere : public hittable {
private:
    point3 center;
    double radius;
public:
    sphere(const point3& center, double radius):
        center(center), radius(std::fmax(0, radius))
        {};

    bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const override {
        vec3 oc = center - r.origin();
        auto a = r.direction().length_squared();
        auto h = dot(r.direction(), oc);
        auto c = oc.length_squared() - radius*radius;

        auto discriminant = h*h - a*c;
        if (discriminant < 0) {
            return false;
        }
        auto sqrtd = std::sqrt(discriminant);

        // nearest root that exists in the acceptable range
        auto root = (h - sqrtd) / a;
        if (root <= ray_tmin || root >= ray_tmax) {
            root = (h + sqrtd) / a;
            if (root <= ray_tmin || root >= ray_tmax) {
                return false;
            }
        }

        rec.t = root;
        rec.p = r.at(root);
        rec.normal = (rec.p - center) / radius;

        return true;
    }

};


#endif //GRAPHICS_PROJECT_SPHERE_H
