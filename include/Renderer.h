#ifndef RENDERER_H
#define RENDERER_H

#include "Model.h"
#include "Shader.h"
#include "Terrain.h"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

namespace Rendering {
  class Renderer {
  public:
    Renderer(const int& width, const int& height);

    void RenderModel(Model& model, Shader& shader, glm::vec3 position);
    void RenderTerrain(Terrain::Terrain& terrain, Shader& shader, glm::vec3 position);
  private:
    int width, height;
  };
}

#endif /* end of include guard: RENDERER_H */
