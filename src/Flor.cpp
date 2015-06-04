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
/*
void Flor::Mostrar(std::ostream& os)
{
}

void Flor::Guardar(std::ostream& os)
{
}

void Flor::Cargar(std::istream& is)
{
}
*/

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
