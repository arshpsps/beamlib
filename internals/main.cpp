#include <raylib.h>

const float DRAW_FPS = 120;
const float NORMAL_FPS = 30;

int normalizeByFPS(int val) { return val / NORMAL_FPS * DRAW_FPS; }

int main() {
    InitWindow(800, 450, "beamlib");

    SetTargetFPS(DRAW_FPS);
    float ticks = 1;
    Vector2 pos = {800.0 / 2, 450.0 / 2};

    while (!WindowShouldClose()) {
        BeginDrawing();
        {
            ClearBackground(BLACK);
            DrawText("This is beamlib", 190, 200, 20, LIGHTGRAY);
            if (DRAW_FPS / ticks == NORMAL_FPS) {
                ticks = 0;
                pos = {pos.x + 2, pos.y};
            }
            DrawPoly(pos, 4, 10.0, 45, LIGHTGRAY);
            ticks++;
            DrawFPS(5, 5);
        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
