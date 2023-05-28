#pragma once

#include <string>

#include "core/gpu/mesh.h"
#include "utils/glm_utils.h"


namespace object2D
{

    // Create square with given bottom left corner, length and color
    Mesh* square(const std::string& name, glm::vec3 leftBottomCorner,
        float length, glm::vec3 color, bool fill = false);

    // Create circle
    Mesh* circle(const std::string& name, glm::vec3 center,
        float radius, glm::vec3 color);

    // Create triangle
    Mesh* triangle(const std::string& name, glm::vec3 leftBottomCorner,
        float length, glm::vec3 color, bool fill = false);
}
