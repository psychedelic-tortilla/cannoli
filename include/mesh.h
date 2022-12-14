#ifndef CANNOLI_SRC_MESH_H_
#define CANNOLI_SRC_MESH_H_

#include "obj_file_loader.h"
#include "utils.h"
#include "light_ray.h"
#include "hit_record.h"
#include "vec3f.h"
#include "material.h"
#include "object.h"
#include "aabb.h"

#include <string>
#include <memory>

namespace cannoli {
class Mesh {
 public:
  explicit Mesh(objl::Mesh &mesh, std::shared_ptr<Material> &material);

  [[nodiscard]] std::vector<Vec3f> GetVertices() const {
	return m_vertices;
  }

  [[nodiscard]] std::vector<uint> GetIndices() const {
	return m_indices;
  }

  [[nodiscard]] int GetFaceCount() const {
	return m_faceCount;
  }

  [[nodiscard]] std::shared_ptr<Material> GetMaterial() const {
	return m_meshMaterial;
  }

  [[nodiscard]] std::shared_ptr<AABB> GetAABB() const {
	return std::make_shared<AABB>(m_aabb);
  }

  bool RayTriangleIntersect(LightRay &ray,
							const float &t_min,
							const float &t_max,
							HitRecord &hit_record,
							int triangle_nr);

  LightRay ComputeSurfaceInteraction(const LightRay &ray, const HitRecord &hit_record);
  void ComputeAABB();

 private:
  std::vector<cannoli::Vec3f> m_vertices;
  std::vector<uint> m_indices;
  std::string m_name;
  std::shared_ptr<Material> m_meshMaterial;

 private:
  int m_faceCount = 0;
  AABB m_aabb;

};
} // namespace cannoli
#endif //CANNOLI_SRC_MESH_H_
