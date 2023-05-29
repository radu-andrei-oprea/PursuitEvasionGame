#pragma once

#include "components/simple_scene.h"


namespace m1
{
    struct coordPair {
        float x;
        float y;
    };

    // obstacle vertices structure
    struct obtacleVerts {
        coordPair bottomLeft;
        coordPair bottomRight;
        coordPair topLeft;
        coordPair topRight;
    };

    class Epsm : public gfxc::SimpleScene
    {
    public:
        Epsm();
        ~Epsm();

        void Init() override;

    private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;

        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;

        bool isCoordinateValid(float x, float y)

    protected:
        float cx, cy;
        glm::mat3 modelMatrix, headMatrix;
        float translateX, translateY;

        //border variables
        /*float side;*/
        float limX, limY;
        float width;

        //character coords
        float pX, pY;
        float eX, eY;

        // obstacle coords
        float oTopX, oTopY;
        float oBottomX, oBottomY;
        float oLeftX, oLeftY;
        float oRightX, oRightY;

        // obstacle vertices
        obtacleVerts arenaV;
        obtacleVerts oTopV;
        obtacleVerts oBottomV;
        obtacleVerts oLeftV;
        obtacleVerts oRightV;


        // variable if evader is seen by pursuer
        int seen;
        // variable for positions;
        int position;
        float posX, posY;
    };
}   // namespace m1
