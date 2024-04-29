#include <raylib.h>

const float DRAW_FPS = 60;
const float NORMAL_FPS = 30;

int main() {
    InitWindow(800, 450, "beamlib");

    SetTargetFPS(DRAW_FPS);
    Vector2 pos = {800.0 / 2, 450.0 / 2};

    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();
        BeginDrawing();
        {
            ClearBackground(BLACK);
            DrawText("This is beamlib", 190, 200, 20, LIGHTGRAY);

            pos = {pos.x + 100 * deltaTime, pos.y};

            DrawPoly(pos, 4, 10.0, 45, LIGHTGRAY);
            DrawFPS(5, 5);
        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
