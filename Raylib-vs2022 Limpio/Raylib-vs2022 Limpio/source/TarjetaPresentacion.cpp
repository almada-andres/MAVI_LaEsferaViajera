#include "TarjetaPresentacion.h"


TarjetaPresentacion::TarjetaPresentacion(const char* nombreCompleto, Color colorFondo, Color colorNombrePersonalizado, Color colorMensajePersonalizado, Color colorFiguraPersonalizado)
{
    nombre = nombreCompleto;

    fondo = colorFondo;
    colorNombre = colorNombrePersonalizado;
    colorMensaje = colorMensajePersonalizado;
    colorFigura = colorFiguraPersonalizado;

    transicionActiva = false;
    simulacionLista = false;
    tiempoTranscurrido = 0.0f;
}

void TarjetaPresentacion::Actualizar(float deltaTime)
{
    //Inicia la transicion
    if (!transicionActiva && IsKeyPressed(KEY_SPACE))
    {
        transicionActiva = true;
    }

    //Cuenta el tiempo de la transicion
    if (transicionActiva && !simulacionLista)
    {
        tiempoTranscurrido += deltaTime;

        if (tiempoTranscurrido >= 2.5f)
        {
            simulacionLista = true;
        }
    }
}

void TarjetaPresentacion::DibujarTextoCentrado(const char* texto, int y, int tamanio, Color color)
{
    //Calcula el ancho del texto
    int anchoTexto = MeasureText(texto, tamanio);

    //Calcula la posicion X para centrarlo
    int x = (GetScreenWidth() - anchoTexto) / 2;

    DrawText(texto, x, y, tamanio, color);
}

void TarjetaPresentacion::Dibujar()
{
    //Fondo
    ClearBackground(fondo);

    //Nombre principal
    DibujarTextoCentrado(nombre,80,40, colorNombre);

    //Texto descriptivo
    DibujarTextoCentrado("Andres Horacio Almada",135,20,LIGHTGRAY);

    //Simulacion
    DibujarTextoCentrado("SIMULACION", 155, 22, colorMensaje);

    //Rectangulo
    if (transicionActiva)
    {
        DrawRectangle(250, 190, 300, 60, GREEN);
    }

    else
    {
        DrawRectangle(250, 190, 300, 60, colorFigura);
    }

    //Instruccion
    if (transicionActiva)
    {
        DibujarTextoCentrado("Preparando simulacion...", 280, 18, LIGHTGRAY);
    }

    else
    {
        DibujarTextoCentrado(
            "Presione ESPACIO para iniciar la simulacion",
            280,
            18,
            LIGHTGRAY
        );
    }
}

bool TarjetaPresentacion::SimulacionLista() const
{
    return simulacionLista;
}