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
    int k = 0;
    std::vector<Nivel> nuevosNiveles;
    if (this->nivelesJ().size() == 0){
        this->nivelesJ().push_back(n);
    } else {
        while (k <= this->nivelesJ().size()){
            if (k<i){
                nuevosNiveles.push_back(this->nivelesJ()[k]);
            }else{
                if (k==i){
                    nuevosNiveles.push_back(n);
                }else{
                    nuevosNiveles.push_back(this->nivelesJ()[k-1]);
                }
            }
            k++;
        }
    }
}

void Juego::jugarNivel(Nivel& n, int i){
    nivelesJ()[i] = n;
}

bool esFacil(int i){
    int k = i;
    Juego j;
    int posMax = i;
    while (k < j.nivelesJ().size()){
        if ((j.nivelesJ()[k].solesN() > j.nivelesJ()[posMax].solesN()) ||
            (j.nivelesJ()[k].solesN() == j.nivelesJ()[posMax].solesN() &&
             j.nivelesJ()[k].floresN().size() > j.nivelesJ()[posMax].floresN().size()))
             posMax = k;
        k++;
    }
    return (posMax == i);
}

std::vector<Nivel> Juego::estosSaleFacil() {
    std::vector<Nivel> resultado;
    int i = 0;
    while (i < this->nivelesJ().size()){
        if (esFacil(i)) resultado.push_back(this->nivelesJ()[i]);
        i++;
    }
    return resultado;
}

void Juego::altoCheat(int n) {
    int i = 0;
    while(i < this->nivelesJ()[n].vampirosN().size()){
        if (this->nivelesJ()[n].vampirosN()[i].vida / 2 > 0)
                this->nivelesJ()[n].vampirosN()[i].vida = this->nivelesJ()[n].vampirosN()[i].vida / 2;
        i++;
    }
}

std::vector<int> nivelesGanados(){
    std::vector<int> resultado;
    Juego j;
    int i = 0;
    while (i < j.nivelesJ().size()){
        if (j.nivelesJ()[i].vampirosN().size()== 0 && j.nivelesJ()[i].spawningN().size()== 0) resultado.push_back(i);
        i++;
    }
    return resultado;
}

bool Juego::muyDeExactas() {
    bool result = false;
    std::vector<int> nivelesG = nivelesGanados();
    if (nivelesG.size()== 0 || (nivelesG.size()==1 && nivelesG[0]==1) || (nivelesG.size()==2 && nivelesG[0]==1 && nivelesG[1]==2)) result = true;
    else {
        int i = 0;
        while (i < nivelesG.size()-2) {
            if (nivelesG[i+2] != nivelesG[i+1]+nivelesG[i]){
                i = nivelesG.size();
            }else{
                i++;
                result = true;
            }
        }
    }
    return result;
}

/*
void Juego::Mostrar(std::ostream& os)
{
    os << *this;
}

void Juego::Guardar(std::ostream& os)
{
    os << *this;
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
*/
