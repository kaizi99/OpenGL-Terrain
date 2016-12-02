#include "Renderer.h"

namespace Rendering {
  Renderer::Renderer(const int& width, const int& height) {
    this->width = width;
    this->height = height;
  }

  void Renderer::RenderModel(Model& model, Shader& shader, glm::vec3 position) {
    glm::mat4 modelMatrix = glm::mat4(1.0f);
    modelMatrix = glm::translate(modelMatrix, position);

    glm::mat4 viewMatrix = glm::lookAt(glm::vec3(8.0f, 8.0f, 8.0f),
      glm::vec3(16.0f, 0.0f, 16.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 projectionMatrix = glm::perspectiveFov(90.0f,
      (float)width, (float)height, 0.01f, 100.0f);

    shader.useShader();
    shader.sendMatreciesToShader(projectionMatrix, viewMatrix, modelMatrix);

    model.bind();
    glDrawElements(GL_TRIANGLES, model.getVertexCount(), GL_UNSIGNED_INT, 0);
    //glDrawArrays(GL_TRIANGLES, 0, 3);
    model.unbind();

    shader.disableShader();
  }

  void Renderer::RenderTerrain(Terrain::Terrain& terrain, Shader& shader,
    glm::vec3 position) {

    const std::vector<Terrain::Chunk> chunks = terrain.getChunks();
    for (auto chunk : chunks) {
      glm::vec3 pos = chunk.getWorldPosition();
      Model m = chunk.getModel();
      RenderModel(m, shader, pos);
    }
  }
}
