#include "lab_m1/PursuitEvasionGame/epsm.h"

#include <vector>
#include <iostream>

#include "lab_m1/PursuitEvasionGame/transform2D.h"
#include "lab_m1/PursuitEvasionGame/object2D.h"
#include <random>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using namespace std;
using namespace m1;


/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */


Epsm::Epsm()
{
}


Epsm::~Epsm()
{
}


void Epsm::Init()
{
    glm::ivec2 resolution = window->GetResolution();
    auto camera = GetSceneCamera();
    camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
    camera->SetPosition(glm::vec3(0, 0, 50));
    camera->SetRotation(glm::vec3(0, 0, 0));
    camera->Update();
    GetCameraInput()->SetActive(false);

    glm::vec3 corner = glm::vec3(0, 0, 0);
    float squareSide = 100;


    float cx, cy;
    cx = corner.x + squareSide / 2;
    cy = corner.y + squareSide / 2;
    
    // screen limits
    limX = resolution.x;
    limY = resolution.y;

    // barrier width
    width = 0.1f;

    

    // outer walls
    Mesh* bottomWall = object2D::square("bottomWall", corner, resolution.y / 3, glm::vec3(0.3f, 0.8f, 0.3f), true);
    AddMeshToList(bottomWall);

    Mesh* topWall = object2D::square("topWall", corner, resolution.y / 3, glm::vec3(0.3f, 0.8f, 0.3f), true);
    AddMeshToList(topWall);

    Mesh* leftWall = object2D::square("leftWall", corner, resolution.y / 3, glm::vec3(0.3f, 0.8f, 0.3f), true);
    AddMeshToList(leftWall);

    Mesh* rightWall = object2D::square("rightWall", corner, resolution.y / 3, glm::vec3(0.3f, 0.8f, 0.3f), true);
    AddMeshToList(rightWall);

    Mesh* obstacle1 = object2D::triangle("obstacle1", corner, 500, glm::vec3(0.8f, 0.8f, 0.3f), true);
    AddMeshToList(obstacle1);
}


void Epsm::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);

}


void Epsm::Update(float deltaTimeSeconds)
{
    // render walls
    // bottom
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(0, 0);
    modelMatrix *= transform2D::Scale(50, width);
    RenderMesh2D(meshes["bottomWall"], shaders["VertexColor"], modelMatrix);
    // top    
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(0, limY);
    modelMatrix *= transform2D::Scale(50, width);
    RenderMesh2D(meshes["bottomWall"], shaders["VertexColor"], modelMatrix);
    // left
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(0, 0);
    modelMatrix *= transform2D::Scale(width, 50);
    RenderMesh2D(meshes["leftWall"], shaders["VertexColor"], modelMatrix);
    // right
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(limX, 0);
    modelMatrix *= transform2D::Scale(width, 50);
    RenderMesh2D(meshes["rightWall"], shaders["VertexColor"], modelMatrix);


    // obstacles
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(0, 0);
    modelMatrix *= transform2D::Translate(limX / 2, limY / 2);
    RenderMesh2D(meshes["obstacle1"], shaders["VertexColor"], modelMatrix);

}   


void Epsm::FrameEnd()
{
}


/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */


void Epsm::OnInputUpdate(float deltaTime, int mods)
{
}


void Epsm::OnKeyPress(int key, int mods)
{
    // Add key press event
}


void Epsm::OnKeyRelease(int key, int mods)
{
    
}


void Epsm::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    
}


void Epsm::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
   
}


void Epsm::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button release event
}


void Epsm::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void Epsm::OnWindowResize(int width, int height)
{
}
