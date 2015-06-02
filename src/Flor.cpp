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
