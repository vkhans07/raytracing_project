//
// Created by Vijay Kumar Hans on 7/4/26.
//

#ifndef GRAPHICS_PROJECT_HITTABLE_LIST_H
#define GRAPHICS_PROJECT_HITTABLE_LIST_H

#include "rtweekend.h"
#include <vector>
#include "hittable.h"



class hittable_list : public hittable {
public:
    std::vector<shared_ptr<hittable>> objects;

    hittable_list() {};

    hittable_list(shared_ptr<hittable> object) {
        add(object);
    }

    void clear() { objects.clear(); }

    void add(shared_ptr<hittable> object) {
        objects.push_back(object);
    }

    bool hit(const ray &r, interval ray_t, hit_record &rec) const override {
        hit_record temp_rec;
        bool hit_anything = false;
        double nearest_hit = ray_t.max;

        for (const auto& object : objects) {
            if (object->hit(r, interval(ray_t.min, nearest_hit), temp_rec)) {
                hit_anything = true;
                nearest_hit = temp_rec.t;
                rec = temp_rec;
            }
        }

        return hit_anything;
    }
};

#endif //GRAPHICS_PROJECT_HITTABLE_LIST_H
