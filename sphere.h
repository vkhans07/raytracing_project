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
    shared_ptr<material> mat;
public:
    sphere(const point3& center, double radius, shared_ptr<material> mat):
        center(center), radius(std::fmax(0, radius)), mat(mat)
        {};

    bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
        rec.mat = mat;

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
        if (!ray_t.surrounds(root)) {
            root = (h + sqrtd) / a;
            if (!ray_t.surrounds(root)) {
                return false;
            }
        }

        rec.t = root;
        rec.p = r.at(root);
        vec3 outward_normal = (rec.p - center) / radius;
        rec.set_face_normal(r, outward_normal);
        rec.normal = (rec.p - center) / radius;

        return true;
    }

};


#endif //GRAPHICS_PROJECT_SPHERE_H
