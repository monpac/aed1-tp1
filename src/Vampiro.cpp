#include "Vampiro.h"


Vampiro::Vampiro()
{
}

Vampiro::Vampiro(ClaseVampiro cv, Vida v, int cP)
{
    _clase = cv;
    _vida = v;
    _cuantoPega = cP;
}

Vida Vampiro::vidaV()
{
    return this->_vida;
}

ClaseVampiro Vampiro::claseV()
{
    return this->_clase;
}

int Vampiro::cuantoPegaV()
{
    return this->_cuantoPega;
}

void Vampiro::Mostrar(std::ostream& os) {
  os << this;
}

void Vampiro::Guardar(std::ostream& os) {
    //{ V Desviado 50 8 }
    //"{ V ", su clase de vampiro, " ", su vida, " ", su cuanto pega y " }"
    os << "{ V ";
    os << claseV() << " ";
    os << vidaV() << " ";
    os << cuantoPegaV() << " }";
}
/*
void Vampiro::Cargar(std::istream& is) {

}
*/

std::ostream& operator<<(std::ostream& out, Vampiro& v) {
    std::string clase = "";
    if (v.claseV() == Caminante) {
        clase = "Caminante ";
    } else if (v.claseV() == Desviado) {
        clase = "Desviado ";
    }
    out << "{ V " << clase << " " << v.vidaV() << " " << v.cuantoPegaV() << " }";
    return out;
}
