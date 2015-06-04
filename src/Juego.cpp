#include "Juego.h"

Juego::Juego()
{
}

Juego::Juego(std::vector<Flor>& flores, std::vector<Vampiro>& vamps)
{
    _flores = flores;
    _vampiros = vamps;
}

int Juego::nivelActual()
{
    return this->_nivelActual;
}

void Juego::pasarNivel()
{
    _nivelActual = nivelActual() + 1;
}

std::vector<Flor>& Juego::floresJ()
{
    return this->_flores;
}

std::vector<Vampiro>& Juego::vampirosJ()
{
    return this->_vampiros;
}

std::vector<Nivel>& Juego::nivelesJ()
{
    return this->_niveles;
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

std::ostream& operator<<(std::ostream& out, Juego& j) {
    out << "{ J ";
    // Flores
    out << "[ ";
    int i = 0;
    while (i < j.floresJ().size()) {
        out << j.floresJ()[i] << " ";
        i++;
    }
    out << "] ";
    // Vampiros
    out << "[ ";
    i = 0;
    while (i < j.vampirosJ().size()) {
        out << j.vampirosJ()[i] << " ";
        i++;
    }
    out << "] ";
    // Niveles
    out << "[ ";
    i = 0;
    while (i < j.nivelesJ().size()) {
        out << j.nivelesJ()[i] << " ";
        i++;
    }
    out << "] ";
    out << "}";
    return out;
}
