#pragma once
#include <tuple>
#include <vector>
#include <iostream>
#include <string>
#include <math.h>

#include "Flor.h"
#include "Vampiro.h"

struct FlorEnJuego
{
	FlorEnJuego(Flor f, Posicion p, Vida v)
	{
		flor = f;
		pos = p;
		vida = v;
	}

	Flor flor;
	Posicion pos;
	Vida vida;
};

struct VampiroEnJuego
{
	VampiroEnJuego(Vampiro v, Posicion p, Vida vd)
	{
		vampiro = v;
		pos = p;
		vida = vd;
	}
	Vampiro vampiro;
	Posicion pos;
	Vida vida;
};

struct VampiroEnEspera
{
	Vampiro vampiro;
	int fila;
	int turno;

	VampiroEnEspera(Vampiro v, int f, int t)
	{
		vampiro = v;
		fila = f;
		turno = t;
	}

};

class Nivel
{
private:
	int _ancho;
	int _alto;
	int _turno;
	int _soles;

	std::vector<FlorEnJuego> _flores;
	std::vector<VampiroEnJuego> _vampiros;
	std::vector<VampiroEnEspera> _spawning;


    friend std::ostream& operator<<(std::ostream& out, Nivel& n);

public:
	Nivel();
	Nivel(int ancho, int alto, int soles, std::vector<VampiroEnEspera>& spawninglist);
	int anchoN();
	int altoN();
	int turnoN();
	int solesN();
	std::vector<FlorEnJuego>& floresN();
	std::vector<VampiroEnJuego>& vampirosN();
	std::vector<VampiroEnEspera>& spawningN();
	void agregarFlor(Flor f, Posicion p);
	void pasarTurno();
	bool terminado();
	bool obsesivoCompulsivo();
  void comprarSoles(int n);

	void Mostrar(std::ostream& os);
	void Guardar(std::ostream& os);
	void Cargar(std::istream& is);


};
