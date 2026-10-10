#ifndef NDEBUG
#include <vld.h> // Visual Leak Detector, útil en modo Debug para detectar fugas de memoria
#endif

#include "raylib.h"

#include "TarjetaPresentacion.h"
#include "Esfera.h"

int main(void)
{
    //Inicializa una ventana de 800x450 píxeles (como en el primer proyecto)
    InitWindow(800, 450, "Tarjeta de presentacion - Andres Almada");

    // Configuramos el framerate deseado (opcional, pero recomendado)
    SetTargetFPS(60);

    //Creacion de objetos
    TarjetaPresentacion tarjeta("ANDRES ALMADA",{ 30, 40, 80, 255 }, WHITE, YELLOW, { 70, 150, 220, 255 });

    Esfera esfera;

    //Estado del programa
    bool simulacionIniciada = false;

    // Bucle principal del juego (se repite hasta que se cierre la ventana)
    while (!WindowShouldClose())
    {
        //Tiempo desde el frame anterior
        float deltaTime = GetFrameTime();

        //Actualiza la tarjeta mientras la simulacion no haya comenzado
        if (!simulacionIniciada)
        {
            tarjeta.Actualizar(deltaTime);

            //Comprueba si termino la transicion
            if (tarjeta.SimulacionLista())
            {
                //Cambia las dimensiones de la ventana
                SetWindowSize(1024, 768);

                //Actualiza el titulo
                SetWindowTitle("MAVI - La esfera viajera");

                //Activa la simulacion
                simulacionIniciada = true;
            }
        }

        else
        {
            //Actualiza el movimiento de la esfera
            esfera.Actualizar(deltaTime);
        }

        //Comienza el dibujo
        BeginDrawing();

        if (!simulacionIniciada)
        {
            //Dibuja la tarjeta de presentacion
            tarjeta.Dibujar();
        }

        else
        {
            //Dibuja el fondo de la simulacion
            ClearBackground({ 30, 40, 80, 255 });

            //Dibuja la esfera y sus datos
            esfera.Dibujar();
        }

        // Finalizamos el dibujo
        EndDrawing();
    }

    // Cerramos la ventana y liberamos recursos
    CloseWindow();

    return 0;
}

