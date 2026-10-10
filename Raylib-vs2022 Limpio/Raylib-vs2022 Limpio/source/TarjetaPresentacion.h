#ifndef TARJETA_PRESENTACION_H
#define TARJETA_PRESENTACION_H

#include "raylib.h"

class TarjetaPresentacion
{
    private:
            //Datos de la tarjeta
            const char* nombre;
            const char* mensajeInicial;
            const char* mensajeAlternativo;

            //Colores
            Color fondo;
            Color colorNombre;
            Color colorMensaje;
            Color colorFigura;

            //Estado de la transicion
            bool transicionActiva;
            bool simulacionLista;
            float tiempoTranscurrido;

            //Para centrar textos
            void DibujarTextoCentrado(const char* texto, int y, int tamanio, Color color);

    public:
            //Constructor
            TarjetaPresentacion(const char* nombreCompleto, Color colorFondo, Color colorNombrePersonalizado, Color colorMensajePersonalizado, Color colorFiguraPersonalizado);

            void Actualizar(float deltaTime);
            void Dibujar();

            bool SimulacionLista() const;
};

#endif