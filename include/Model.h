#ifndef Model_H
#define Model_H

#include "OpenGL.h"
#include <vector>
#include <glm.hpp>

namespace Rendering {
  class Model {
  public:
    Model(std::vector<glm::vec3> vertecies, std::vector<int> indices);

    int getVertexCount();
    void bind();
    void unbind();
  private:
    GLuint vaoID;
    int vertexCount;

    void storeVectorsInAttributeList(std::vector<glm::vec3> data,
      int attributeList);

    void createIndicesBuffer(std::vector<int> indices);
  };

}
#endif /* end of include guard: Model_H */
