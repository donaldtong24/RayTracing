#ifndef MATERIAL_H
#define MATERIAL_H
#include "common.h"
#include "hittable.h"
/*
abstract material class that encapsulates unique behavior. 
For our program the material needs to do two things:

Produce a scattered ray (or say it absorbed the incident ray).
If scattered, say how much the ray should be attenuated.
*/

class material {
  public:
    virtual ~material() = default;

    virtual bool scatter(
        const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered
    ) const {
        return false;
    }
};
//we chose to always scatter lambertian reflectance
class lambertian : public material {
    public:
      lambertian(const color& albedo) : albedo(albedo) {}
  
      bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered)
      const override {
        auto scatter_direction = rec.normal + random_unit_vector();
        
        // Catch degenerate scatter direction
        if (scatter_direction.near_zero())
        scatter_direction = rec.normal;

        scattered = ray(rec.p, scatter_direction);
        attenuation = albedo;
        return true;
      }
  
    private:
      color albedo;
  };

  class metal : public material {
    public:
      metal(const color& albedo, double fuzz) : albedo(albedo), fuzz(fuzz < 1 ? fuzz : 1) {}
  
      bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered)
      const override {
          vec3 reflected = reflect(r_in.direction(), rec.normal);
          reflected = unit_vector(reflected) + (fuzz * random_unit_vector());
          scattered = ray(rec.p, reflected);
          attenuation = albedo;
          return (dot(scattered.direction(), rec.normal) > 0);
      }
  
    private:
      color albedo;
      double fuzz;
  };
  

#endif