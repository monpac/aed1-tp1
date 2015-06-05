#include "Nivel.h"

Nivel::Nivel()
{
}

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

int Nivel::generanSoles(std::vector<FlorEnJuego> flores) {
    int i = 0;
    int j = 0;
    int x = 0;
    int tamanoF = flores.size();
    while(i < tamanoF) {
        while (j < flores.at(i).flor.habilidadesF().size()) {
            if (flores.at(i).flor.habilidadesF().at(j) == Generar) {
                x++;
            }
            j++;
        }
        i++;
    }
    return x;
}

std::vector<FlorEnJuego> Nivel::floresDaniadas(std::vector<FlorEnJuego> flores, std::vector<VampiroEnJuego> vampiros) {
    int i = 0;
    int tamanoF = flores.size();
    int j = 0;
    int tamanoV = vampiros.size();
    std::vector<FlorEnJuego> floresSobrevivientes;
    if(floresSobrevivientes.empty() == false) floresSobrevivientes.clear();

    while (i < tamanoF) {
        while (j < tamanoV) {
            if(flores.at(i).pos.x == vampiros.at(j).pos.x && flores.at(i).pos.y == vampiros.at(j).pos.y) {
                flores.at(i).vida = flores.at(i).vida - vampiros.at(j).vampiro.cuantoPegaV();
            }
            j++;
        }
        if(flores.at(i).vida > 0){
            floresSobrevivientes.push_back(flores.at(i));
        }
        j = 0;
        i++;
    }

    return floresSobrevivientes;
}

bool Nivel::esVampiroDelantero(std::vector<VampiroEnJuego> vampiros, int posYVampiro, int v) {
    int i = 0;
    bool b = true;
    int tamanoV = vampiros.size();
    while(i < tamanoV) {
        if(vampiros.at(i).pos.y <= posYVampiro && i != v) {
            b = false;
        }
        i++;
    }
    return b;
}

bool Nivel::noHayFlor(std::vector<FlorEnJuego> flores, VampiroEnJuego vampiro) {
    int i = 0;
    int tamanoF = flores.size();
    bool choque = false;
    while (i < tamanoF) {
        if(flores.at(i).pos.x == vampiro.pos.x && flores.at(i).pos.y == vampiro.pos.y) {
            choque = true;
        }
        i++;
    }
}

std::vector<VampiroEnJuego> Nivel::vampirosDaniados(std::vector<FlorEnJuego> flores, std::vector<VampiroEnJuego> vampiros) {
    int i = 0;
    int tamanoF = flores.size();
    int j = 0;
    int tamanoV = vampiros.size();
    bool explosiva = false;
    bool ataca = false;
    int k = 0;
    int l = 0;
    std::vector<VampiroEnJuego> vampirosSobrevivientes;
    if(vampirosSobrevivientes.empty() == false) vampirosSobrevivientes.clear();

    while (i < tamanoV) {
        while (j < tamanoF) {
            while (k < flores.at(j).flor.habilidadesF().size()) {
                if (flores.at(j).flor.habilidadesF().at(k) == Atacar) {
                    ataca = true;
                }
            k++;
            }

            while (l < flores.at(j).flor.habilidadesF().size()) {
                if (flores.at(j).flor.habilidadesF().at(l) == explosiva) {
                    explosiva = true;
                }
            l++;
            }

            if(flores.at(j).pos.x == vampiros.at(i).pos.x && flores.at(j).pos.y == vampiros.at(i).pos.y && explosiva) {
                vampiros.at(i).vida = vampiros.at(i).vida - flores.at(j).flor.cuantoPegaF();
                vampiros.at(i).pos.y = vampiros.at(i).pos.y + 2;
            }

            if(flores.at(j).pos.y <= vampiros.at(i).pos.y && ataca && esVampiroDelantero(vampiros, vampiros.at(i).pos.y, i) && !explosiva) {
                vampiros.at(i).vida = vampiros.at(i).vida - flores.at(j).flor.cuantoPegaF();
            }
            k=0;
            explosiva=false;
            ataca=false;
            j++;
        }
        j = 0;
        if(vampiros.at(i).vampiro.claseV() == Caminante && noHayFlor(flores, vampiros.at(i))) {
            vampiros.at(i).pos.x = vampiros.at(i).pos.x - 1;
        } else if(vampiros.at(i).vampiro.claseV() == Desviado && noHayFlor(flores, vampiros.at(i)) && vampiros.at(i).pos.y != this->altoN() - 1) {
            vampiros.at(i).pos.y = vampiros.at(i).pos.y + 1;
            vampiros.at(i).pos.x = vampiros.at(i).pos.x - 1;

        }
        if(vampiros.at(i).vida > 0){
            vampirosSobrevivientes.push_back(vampiros.at(i));
        }
        i++;
    }

    return vampirosSobrevivientes;
}

std::vector<VampiroEnJuego> Nivel::vampirosSpawneados(std::vector<VampiroEnEspera> vSpaw) {
    int i = 0;
    int tamanoV = vSpaw.size();
    std::vector<VampiroEnJuego> nuevosVampiros;
    if(nuevosVampiros.empty() == false) nuevosVampiros.clear();

    while (i < tamanoV) {
        if(vSpaw.at(i).turno == this->turnoN() + 1) {
            nuevosVampiros.push_back(VampiroEnJuego(vSpaw.at(i).vampiro,Posicion(this->anchoN()-1,vSpaw.at(i).fila),vSpaw.at(i).vampiro.vidaV()));
        }
        i++;
    }
    return nuevosVampiros;
}

std::vector<VampiroEnJuego> Nivel::vampirosCambiados(std::vector<VampiroEnJuego> danados, std::vector<VampiroEnJuego> spawneados) {
    int i = 0;
    int tamanoS = spawneados.size();
    while (i < tamanoS) {
        danados.push_back(spawneados.at(i));
        i++;
    }
    return danados;
}

std::vector<VampiroEnEspera> Nivel::nuevoSpawning(std::vector<VampiroEnEspera> vS) {
    int i = 0;
    int tamanoS = vS.size();
    std::vector<VampiroEnEspera> nuevosSpawn;
    if(nuevosSpawn.empty() == false) nuevosSpawn.clear();

    while (i < tamanoS) {
        if(vS.at(i).turno /= this->turnoN() + 1) {
            nuevosSpawn.push_back(vS.at(i));
        }
        i++;
    }
    return nuevosSpawn;
}

void Nivel::pasarTurno() {
    _turno = turnoN() + 1;
    _soles = solesN() + 1 + generanSoles(floresN());
    _flores = floresDaniadas(floresN(), vampirosN());
    _vampiros = vampirosCambiados(vampirosDaniados(floresN(), vampirosN()), vampirosSpawneados(spawningN()));
    _spawning = nuevoSpawning(spawningN());

}

bool Nivel::vampirosEnCasa(std::vector<VampiroEnJuego> vs) {
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

bool Nivel::yaSaliDeLaLista(int j, std::vector<int> posiciones) {
    int i = 0;
    bool b = false;
    int tamanoP = posiciones.size();
    while (i < tamanoP) {
        if(j == posiciones.at(i)) {
            b = true;
        }
        i++;
    }
    return b;
}

bool Nivel::obsesivoCompulsivo() {
    int j = 0;
    int menor = 0;
    int tamanoF = floresN().size();
    std::vector<FlorEnJuego> floresOrdenadas;
    std::vector<int> posiciones;
    int tamanoFOrd = floresOrdenadas.size();
    while(tamanoFOrd < tamanoF) {
        while(j < tamanoF) {
            if(floresN().at(j).pos.y <= floresN().at(menor).pos.y && !yaSaliDeLaLista(j,posiciones)) {
                if(floresN().at(j).pos.y != floresN().at(menor).pos.y) {
                    menor = j;
                } else {
                    if(floresN().at(j).pos.x <= floresN().at(menor).pos.x) {
                        menor = j;
                    }
                }
            }
            if(yaSaliDeLaLista(menor,posiciones)) menor++;
            j++;
        }
        posiciones.push_back(menor);
        floresOrdenadas.push_back(floresN().at(menor));
        j = 0;
        menor = 0;
    }
    int i = 0;
    int k = 0;
    int l = 0;
    int b = true;
    while(i < tamanoFOrd-1) {
         while (k < floresOrdenadas.at(i).flor.habilidadesF().size()) {
            if (floresOrdenadas.at(i).flor.habilidadesF().at(k) == Atacar) {
                while(l < floresOrdenadas.at(i+1).flor.habilidadesF().size()) {
                    if (floresOrdenadas.at(i+1).flor.habilidadesF().at(l) == Atacar) {
                        b = false;
                    }
                    l++;
                }
            } else {
                while(l < floresOrdenadas.at(i+1).flor.habilidadesF().size()) {
                    if (floresOrdenadas.at(i+1).flor.habilidadesF().at(l) != Atacar) {
                        b = false;
                    }
                    l++;
                }
            }
            l=0;
            k++;
        }
        k=0;
        i++;
    }
    return b;
}

void Nivel::comprarSoles(int n) {
    _soles = solesN() + n;
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
