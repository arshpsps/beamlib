#include <raylib.h>

const float DRAW_FPS = 60;
const float NORMAL_FPS = 30;
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 650;

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "beamlib");
    Rectangle box = {400, 280, 40, 40};

    Camera2D camera = {0};
    camera.target = (Vector2){box.x + 20.0f, box.y + 20.0f};
    camera.offset = (Vector2){SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    SetTargetFPS(DRAW_FPS);
    Vector2 pos = {800.0 / 2, 450.0 / 2};
    int moveDirection = 1;
    int speed = 100;

    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();
        if (pos.x >= SCREEN_WIDTH) {
            moveDirection = -1;
            speed *= 1.5;
        } else if (pos.x <= 0) {
            moveDirection = 1;
            speed *= 1.5;
        }
        BeginDrawing();
        {
            ClearBackground(BLACK);
            const char *textToWrite = "UwU, idk why there's space up there";
            DrawText(textToWrite,
                     (GetScreenWidth() / 2) -
                         (MeasureText(textToWrite, 20) / 2),
                     (GetScreenHeight() / 2), 20, LIGHTGRAY);

            pos = {pos.x + (speed * moveDirection) * deltaTime, pos.y};

            DrawPoly(pos, 4, 10.0, 45, LIGHTGRAY);
            DrawFPS(5, 5);
        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
