#include "Nivel.h"

/*
Nivel::Nivel()
{
}
*/
Nivel::Nivel(int ancho, int alto, int soles, std::vector<VampiroEnEspera>& spawninglist) {
    _ancho = ancho;
    _alto = alto;
    _soles = soles;
    _spawning = spawninglist;
    _turno = 0;
    _vampiros.clear();
    _flores.clear();
}

int Nivel::anchoN()
{
    return this->_ancho;
}

int Nivel::altoN()
{
    return this->_alto;
}

int Nivel::turnoN()
{
    return this->_turno;
}

int Nivel::solesN()
{
    return this->_soles;
}

std::vector<FlorEnJuego>& Nivel::floresN()
{
    return this->_flores;
}

std::vector<VampiroEnJuego>& Nivel::vampirosN()
{
    return this->_vampiros;
}

std::vector<VampiroEnEspera>& Nivel::spawningN()
{
    return this->_spawning;
}

void Nivel::agregarFlor(Flor f, Posicion p) {
    std::vector<FlorEnJuego> fEnJuego = floresN();
    fEnJuego.push_back(FlorEnJuego(f,p,f.vidaF()));
    _flores = fEnJuego;
    double cantH = f.habilidadesF().size();
    _soles = solesN() - pow(2.0, cantH);
}

void Nivel::pasarTurno()
{
}

bool Nivel::terminado()
{
    if ((this->_vampiros.size() == 0 && this->_spawning.size() == 0) /*|| vampirosEnCasa*/) {
        return true;
    } else {
        return false;
    }
}

bool Nivel::obsesivoCompulsivo()
{
}

void Nivel::comprarSoles(int n){
}

void Nivel::Mostrar(std::ostream& os)
{
    os << *this;
}

void Nivel::Guardar(std::ostream& os)
{
    os << *this;
}

void Nivel::Cargar(std::istream& is)
{
}

std::ostream& operator<<(std::ostream& out, Nivel& n) {
    out << "{ N " << n.anchoN() << " " << n.altoN() << " " << n.turnoN() << " "
        << n.solesN() << " ";
    // Flores
    out << "[ ";
    int i = 0;
    while (i < n.floresN().size()) {
        out << "( ";
        out << n.floresN()[i].flor << " ";
        out << "( " << n.floresN()[i].pos.x << " " << n.floresN()[i].pos.y << " ) ";
        out << n.floresN()[i].vida << " ";
        out << ") ";
        i++;
    }
    out << "] ";
    // Vampiros
    out << "[ ";
    i = 0;
    while (i < n.vampirosN().size()) {
        out << "( ";
        out << n.vampirosN()[i].vampiro << " ";
        out << "( " << n.vampirosN()[i].pos.x << " " << n.vampirosN()[i].pos.y << " ) ";
        out << n.vampirosN()[i].vida << " ";
        out << ") ";
        i++;
    }
    out << "] ";
    // Spawnings
    out << "[ ";
    i = 0;
    while (i < n.spawningN().size()) {
        out << "( ";
        out << n.spawningN()[i].vampiro << " ";
        out << n.spawningN()[i].fila << " ";
        out << n.spawningN()[i].turno << " ";
        out << ") ";
        i++;
    }
    out << "] ";
    out << "}";
    return out;
}
