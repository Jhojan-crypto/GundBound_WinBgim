#include <winbgim.h>
#include <cmath>

void explosion(int x, int y, int maxRadius, int numFrames, int delayTime)
{
    for (int frame = 1; frame <= numFrames; frame++)
    {
        cleardevice();
        for (int radius = 1; radius <= maxRadius; radius += 10)
        {
            int alpha = 255 * (maxRadius - radius) / maxRadius; // Ajustar el brillo del color
            int color = COLOR(255, 255 - alpha, 0); // Color amarillo brillante

            setcolor(color);
            setfillstyle(SOLID_FILL, color);
            circle(x, y, radius);
            floodfill(x, y, color);

            delay(delayTime);
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x = 300; // Coordenada x del centro de la explosión
    int y = 300; // Coordenada y del centro de la explosión
    int maxRadius = 30; // Radio máximo del círculo de la explosión
    int numFrames = 2; // Número de frames de la animación
    int delayTime = 200; // Tiempo de espera entre cada frame (milisegundos)

    explosion(x, y, maxRadius, numFrames, delayTime);

    getch();
    closegraph();
    return 0;
}
