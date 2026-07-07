//
// Created by Vijay Kumar Hans on 7/7/26.
//

#ifndef GRAPHICS_PROJECT_MATERIAL_H
#define GRAPHICS_PROJECT_MATERIAL_H

#include "hittable.h"

class material {
public:
    virtual ~material() = default;

    virtual bool scatter(
        const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const {
        return false;
    }
};

class lambertian : public material {
    // Matte material
private:
    color albedo;
public:
    lambertian(const color& albedo): albedo(albedo) {}

    bool scatter(const ray &r_in, const hit_record &rec,
        color &attenuation, ray& scattered) const override {
        auto scatter_direction = rec.normal + random_unit_vector();

        if (scatter_direction.near_zero()) {
            scatter_direction = rec.normal;
        }

        scattered = ray(rec.p, scatter_direction);

        attenuation = albedo;
        return true;
    }
};

class metal : public material {
private:
    color albedo;
public:
    metal(const color& albedo): albedo(albedo) {}

    bool scatter(const ray& r_in, const hit_record& rec,
        color& attenuation, ray& scattered) const override {
        auto scatter_direction = reflect(r_in.direction(), rec.normal);
        scattered = ray(rec.p, scatter_direction);
        attenuation = albedo;
        return true;
    }

};


#endif //GRAPHICS_PROJECT_MATERIAL_H
