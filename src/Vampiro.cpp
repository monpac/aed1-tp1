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
    os << *this;
}

void Vampiro::Guardar(std::ostream& os) {
    os << *this;
}

void Vampiro::Cargar(std::istream& is) {
    std::string s = "";
    int i = 0;
    while (!is.eof() && s != "}") {
        is >> s;
        if(s == "V") {
            i = 1;
        }
        if (i == 2) {
            if (s == "Caminante") {
                this->_clase = Caminante;
            } else if (s == "Desviado") {
                this->_clase = Desviado;
            }
        } else if (i == 3) {
            int vida = atoi(s.c_str());
            this->_vida = vida;
        } else if (i == 4) {
            int cP = atoi(s.c_str());
            this->_cuantoPega = cP;
        }
        i++;
    }
}

std::ostream& operator<<(std::ostream& out, Vampiro& v) {
    std::string clase = "";
    if (v.claseV() == Caminante) {
        clase = "Caminante";
    } else if (v.claseV() == Desviado) {
        clase = "Desviado";
    }
    out << "{ V " << clase << " " << v.vidaV() << " " << v.cuantoPegaV() << " }";
    return out;
}
