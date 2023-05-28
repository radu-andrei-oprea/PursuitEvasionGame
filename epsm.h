#pragma once

#include "components/simple_scene.h"


namespace m1
{
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

    protected:
        float cx, cy;
        glm::mat3 modelMatrix, headMatrix;
        float translateX, translateY;
        float scaleX, scaleY;
        float angularStep;

        //border variables
        float side;
        float limX, limY;
        float width;


        
    };
}   // namespace m1