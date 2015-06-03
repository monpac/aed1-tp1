#include "Juego.h"

/*
Juego::Juego()
{
}

Juego::Juego(std::vector<Flor>& flores, std::vector<Vampiro>& vamps)
{
}
*/
int Juego::nivelActual()
{
    return this->_nivelActual;
}

void Juego::pasarNivel()
{
    _nivelActual = nivelActual() + 1;
}
/*
std::vector<Flor>& Juego::floresJ()
{
}

std::vector<Vampiro>& Juego::vampirosJ()
{
}

std::vector<Nivel>& Juego::nivelesJ()
{
}

void Juego::agregarNivel(Nivel& n,int i)
{
}

void Juego::jugarNivel(Nivel& n, int i){
}

std::vector<Nivel> Juego::estosSaleFacil()
{
}

void Juego::altoCheat(int n)
{
}

bool Juego::muyDeExactas()
{
}

void Juego::Mostrar(std::ostream& os)
{
}

void Juego::Guardar(std::ostream& os)
{
}

void Juego::Cargar(std::iostream& is)
{
}
*/
