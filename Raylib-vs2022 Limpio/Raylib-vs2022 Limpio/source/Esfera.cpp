#include "Esfera.h"

Esfera::Esfera()
{
    //Pos inicial
    posicion = { 512.0f, 384.0f };

    //Velocidad
    velocidad = { 140.0f, 100.0f };

    radio = 25.0f;

    //Color inicial
    color = { 70, 150, 220, 180 };

    cantidadRebotes = 0;
}

void Esfera::CambiarColor()
{
    //Genera un nuevo color
    color = {(unsigned char)GetRandomValue(50, 255),(unsigned char)GetRandomValue(50, 255),(unsigned char)GetRandomValue(50, 255),180};
}

void Esfera::Actualizar(float deltaTime)
{
    //Actualiza la posicion
    posicion.x += velocidad.x * deltaTime;
    posicion.y += velocidad.y * deltaTime;

    bool reboto = false;

    //Colision con bordes izquierdo y derecho
    if (posicion.x - radio <= 0.0f)
    {
        posicion.x = radio;
        velocidad.x = -velocidad.x;
        reboto = true;
    }

    else if (posicion.x + radio >= (float)GetScreenWidth())
    {
        posicion.x = (float)GetScreenWidth() - radio;
        velocidad.x = -velocidad.x;
        reboto = true;
    }

    //Colision con bordes superior e inferior
    if (posicion.y - radio <= 0.0f)
    {
        posicion.y = radio;
        velocidad.y = -velocidad.y;
        reboto = true;
    }

    else if (posicion.y + radio >= (float)GetScreenHeight())
    {
        posicion.y = (float)GetScreenHeight() - radio;
        velocidad.y = -velocidad.y;
        reboto = true;
    }

    //Si hubo una colision, cuenta el rebote y cambia color
    if (reboto)
    {
        cantidadRebotes++;
        CambiarColor();
    }
}

void Esfera::Dibujar()
{
    //Esfera
    DrawCircleV(posicion, radio, color);

    //Resolucion
    DrawText(
        TextFormat("Resolucion: %d x %d", GetScreenWidth(),GetScreenHeight()),20, 20, 20, WHITE);

    //Pos actual
    DrawText(
        TextFormat("Posicion: X = %.1f | Y = %.1f",posicion.x,posicion.y),20, 50, 20, WHITE);

    //Cantidad de rebotes
    DrawText(TextFormat("Rebotes: %d", cantidadRebotes),20, 80, 20, WHITE);
}