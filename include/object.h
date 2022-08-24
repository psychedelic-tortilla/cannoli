#ifndef CANNOLI_INCLUDE_OBJECT_H_
#define CANNOLI_INCLUDE_OBJECT_H_

#include "vec3f.h"
#include "light_ray.h"
#include "material.h"
#include "object_type.h"

namespace cannoli {
  class Object {
   public:
	Object() = default;

	void SetType(ObjectType type) {
	  m_type = type;
	}

	ObjectType GetType() {
	  return m_type;
	}

	virtual bool Hit(const LightRay& ray) = 0;

   protected:
	ObjectType m_type{ObjectType::DEFAULT};
	Material m_material;
  };
}  // namespace cannoli
#endif //CANNOLI_INCLUDE_OBJECT_H_