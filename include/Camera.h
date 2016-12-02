#ifndef CAMERA_H
#define CAMERA_H

#include <glm.h>

namespace Rendering {
  class Camera {
  public:
    glm::mat4 getProjectionMatrix();
    glm::mat4 getViewMatrix();

    void move();
    void rotate();
  private:

  };
}

#endif /* end of include guard: CAMERA_H */
