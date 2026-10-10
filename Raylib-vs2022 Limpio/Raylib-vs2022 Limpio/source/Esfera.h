#ifndef ESFERA_H
#define ESFERA_H

#include "raylib.h"

class Esfera
{
    private:
            //Pos y vel
            Vector2 posicion;
            Vector2 velocidad;

            //Caracteristicas
            float radio;
            Color color;

            //Contador de rebotes
            int cantidadRebotes;

            //Cambia el color de la esfera
            void CambiarColor();

    public:
            Esfera();

            void Actualizar(float deltaTime);
            void Dibujar();
};

#endif