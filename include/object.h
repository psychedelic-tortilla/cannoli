#ifndef CANNOLI_INCLUDE_OBJECT_H_
#define CANNOLI_INCLUDE_OBJECT_H_

#include "vec3f.h"
#include "color.h"
#include "light_ray.h"
#include "lambertian_brdf.h"
#include "object_type.h"
#include "hit_record.h"

#include <memory>

namespace cannoli {

class Object {
 public:
  explicit Object() = default;
  virtual ~Object() = default;

  void SetType(ObjectType type) {
	m_type = type;
  }

  [[nodiscard]] ObjectType GetType() const {
	return m_type;
  }

  [[nodiscard]] std::shared_ptr<Material> GetMaterial() {
	return m_material;
  }

  [[nodiscard]] ColorRGB GetBaseColor() {
	return m_baseColor;
  }

  void SetBaseColor(const ColorRGB &color) {
	m_baseColor = color;
  }

  virtual bool Hit(const LightRay &ray, const float &t_min, const float &t_max, HitRecord &hit_record) = 0;
  virtual cannoli::LightRay ComputeSurfaceInteraction(const LightRay &ray, HitRecord &hit_record) = 0;

 protected:
  ObjectType m_type{ObjectType::DEFAULT};
  std::shared_ptr<Material> m_material = std::make_shared<cannoli::LambertianBRDF>();
  ColorRGB m_baseColor;
};
}  // namespace cannoli
#endif //CANNOLI_INCLUDE_OBJECT_H_
