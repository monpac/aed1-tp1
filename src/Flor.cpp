#include "Flor.h"

Flor::Flor(){
}

Flor::Flor(Vida v, int cP, std::vector<Habilidad> hs)
{
    _vida = v;
    _habilidades = hs;
    _cuantoPega = cP;
}

Vida Flor::vidaF()
{
    return this->_vida;
}

int Flor::cuantoPegaF()
{
    return this->_cuantoPega;
}

std::vector<Habilidad>& Flor::habilidadesF()
{
    return this->_habilidades;
}

void Flor::Mostrar(std::ostream& os)
{
    os << *this;
}

void Flor::Guardar(std::ostream& os)
{
    os << *this;
}

void Flor::Cargar(std::istream& is)
{
    std::string s = "";
    int i = 0;
    std::vector<Habilidad> hab;
    while (s != "}" && !is.eof()) {
        is >> s;
        if(s == "F") {
            i = 1;
        }
        if (i == 2) {
            int vida = atoi(s.c_str());
            this->_vida = vida;
        } else if (i == 3) {
            int cP = atoi(s.c_str());
            this->_cuantoPega = cP;
        } else if (s == "Generar") {
            hab.push_back(Generar);
        } else if (s == "Atacar") {
            hab.push_back(Atacar);
        } else if (s == "Explotar") {
            hab.push_back(Explotar);
        }
        i++;
    }
    this->_habilidades = hab;
}


std::ostream& operator<<(std::ostream& out, Flor& f) {
    std::string hs = "[ ";
    int i = 0;
    while (i < f.habilidadesF().size()) {
        if (f.habilidadesF()[i] == Generar) {
            hs += "Generar ";
        } else if (f.habilidadesF()[i] == Atacar) {
            hs += "Atacar ";
        } else if (f.habilidadesF()[i] == Explotar) {
            hs += "Explotar ";
        }
        i++;
    }
    hs += "]";
    out << "{ F " << f.vidaF() << " " << f.cuantoPegaF() << " " << hs << " }";
    return out;
}
