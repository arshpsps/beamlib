#include <raylib.h>

int main() {
    InitWindow(800, 450, "beamlib");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        {
            ClearBackground(BLACK);
            DrawText("This is beamlib", 190, 200, 20, LIGHTGRAY);
        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
