#include "Model.h"

namespace Rendering {
  Model::Model(std::vector<glm::vec3> vertecies, std::vector<int> indices) {
    vertexCount = indices.size();

    glGenVertexArrays(1, &vaoID);
    glBindVertexArray(vaoID);

    createIndicesBuffer(indices);
    storeVectorsInAttributeList(vertecies, 0);

    glBindVertexArray(0);
  }

  void Model::storeVectorsInAttributeList(std::vector<glm::vec3> data,
    int attributeList) {
    GLuint vboID;
    glGenBuffers(1, &vboID);
    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * data.size(), data.data(),
      GL_STATIC_DRAW);
    glVertexAttribPointer(attributeList, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
  }

  void Model::createIndicesBuffer(std::vector<int> indices) {
    GLuint indicesBuffer;
  	glGenBuffers(1, &indicesBuffer);
  	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indicesBuffer);
  	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(int),
      indices.data(), GL_STATIC_DRAW);
  }
  void Model::bind() {
    glBindVertexArray(vaoID);
    glEnableVertexAttribArray(0);
  }

  void Model::unbind() {
    glDisableVertexAttribArray(0);
    glBindVertexArray(0);
  }

  int Model::getVertexCount() {
    return vertexCount;
  }
}
