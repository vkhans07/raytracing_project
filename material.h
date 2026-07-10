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
    double fuzz;
public:
    metal(const color& albedo): albedo(albedo) { fuzz = 0; }

    metal(const color& albedo, double fuzz): albedo(albedo), fuzz(fuzz < 1 ? fuzz : 1) {}

    bool scatter(const ray& r_in, const hit_record& rec,
        color& attenuation, ray& scattered) const override {
        auto reflected = reflect(r_in.direction(), rec.normal);
        reflected = unit_vector(reflected) + fuzz * (random_unit_vector());
        scattered = ray(rec.p, reflected);
        attenuation = albedo;
        return (dot(scattered.direction(), rec.normal) > 0);
    }

};

class dielectric : public material {
private:
    double refraction_index;
public:
    dielectric(double refraction_index): refraction_index(refraction_index) {}

    bool scatter(const ray &r_in, const hit_record &rec, color &attenuation,
        ray &scattered) const override {
        attenuation = color(1.0, 1.0, 1.0);
        // internal or external refraction
        double ri = rec.front_face ? (1.0/refraction_index) : refraction_index;

        vec3 unit_direction = unit_vector(r_in.direction());
        vec3 refracted = refract(unit_direction, rec.normal, ri);

        scattered = ray(rec.p, refracted);

        return true;
    }

};


#endif //GRAPHICS_PROJECT_MATERIAL_H
