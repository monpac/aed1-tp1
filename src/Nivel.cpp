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
/*
void Nivel::pasarTurno()
{
}
*/
bool vampirosEnCasa(std::vector<VampiroEnJuego> vs) {
    int i = 0;
    int tamano = vs.size();
    bool b = false;
    while(i < tamano && b == false) {
        if(vs.at(i).pos.y == 0) {
            b = true;
        } else {
            b = false;
        }
        i++;
    }
    return b;
}

bool Nivel::terminado() {
    bool b;
    if ((vampirosN().size() == 0 && spawningN().size() == 0) || vampirosEnCasa(vampirosN())) {
        b = true;
    } else {
        b = false;
    }
    return b;
}

/*
bool Nivel::obsesivoCompulsivo()
{
}

void Nivel::comprarSoles(int n){
}

void Nivel::Mostrar(std::ostream& os)
{
}

void Nivel::Guardar(std::ostream& os)
{
}

void Nivel::Cargar(std::istream& is)
{
}
*/

std::ostream& operator<<(std::ostream& out, Nivel& n) {
    out << "{ N " << n.anchoN() << " " << n.altoN() << " " << n.turnoN() << " "
        << n.solesN() << " " << n.fsToString() << " " << n.vsToString() << " "
        << n.spsToString() << " }";
    return out;
}

std::string Nivel::fsToString() {
    return "[]";
}

std::string Nivel::vsToString() {
    return "[]";
}

std::string Nivel::spsToString() {
    return "[]";
}
