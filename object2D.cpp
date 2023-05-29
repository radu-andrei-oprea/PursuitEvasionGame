#include "object2D.h"

#include <vector>
#include <math.h>

#include "core/engine.h"
#include "utils/gl_utils.h"
#include <iostream>

using namespace std;


Mesh* object2D::square(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner + glm::vec3(-length / 2, -length / 2, 0), color),
        VertexFormat(corner + glm::vec3(length / 2, -length / 2, 0), color),
        VertexFormat(corner + glm::vec3(length / 2, length / 2, 0), color),
        VertexFormat(corner + glm::vec3(-length / 2, length / 2, 0), color)
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;
}

Mesh* object2D::triangle(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill
)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(length, length / 2, 0), color),
        VertexFormat(corner + glm::vec3(0, length / 2, 0), color),
    };

    /*std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner + glm::vec3(-length / 2, -length / 4, 0), color),
        VertexFormat(corner + glm::vec3(length / 2, 0, 0), color),
        VertexFormat(corner + glm::vec3(-length / 2, length / 4, 0), color),
    };*/

    Mesh* triangle = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2 };

    triangle->InitFromData(vertices, indices);
    return triangle;
}


Mesh* object2D::circle(
    const std::string& name,
    glm::vec3 center,
    float radius,
    glm::vec3 color
)
{
    std::vector<VertexFormat> vertices;

    GLfloat vertX[360];
    GLfloat vertY[360];

    for (int i = 0; i < 360; i++) {

        vertX[i] = (radius * cos(i * (M_PI) / 180));
        vertY[i] = (radius * sin(i * (M_PI) / 180));
        cout << vertX[i] << " " << vertY[i] << endl;
    }

    for (int i = 0; i < 360; i++) {

        vertices.insert(vertices.begin(), VertexFormat(center + glm::vec3(vertX[i], vertY[i], 0), color));
    }

    Mesh* circle = new Mesh(name);

    std::vector<unsigned int> indices;
    indices.resize(360);

    for (int i = 0; i < 360; i++) {
        indices[i] = i;
    }

    circle->SetDrawMode(GL_TRIANGLE_FAN);

    circle->InitFromData(vertices, indices);
    return circle;
}


