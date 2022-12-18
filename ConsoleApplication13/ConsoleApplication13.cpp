#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>
#include "Locatie.h"
#include "Eveniment.h"
#include "Bilet.h"
using namespace std;


void afisaretip(Eveniment& e, Locatie& l) {
	cout << "Bine ai venit! Selecteaza tip eveniment!" << endl;
	cout << "Alege tip eveniment:" << endl;
	cout << "1. Film" << endl;
	cout << "2. Teatru" << endl;
	cout << "3. Sport" << endl;
	int a;
	cin >> a;
	switch (a) {
	case 1:
		cout << "Tip bilet:" << endl;
		cout << "1. Normal" << endl;
		cout << "2. VIP" << endl;
		int b;
		cin >> b;
		switch (b) {

		case 1:
			cout << "De la randul 2 pana la randul " << l.getNrRanduri() << endl;
			for (int i = 1; i < l.getNrRanduri(); i++) {
				cout << "Randul " << i + 1 << "are " << l.getNrLocuriPeRand()[i] << "locuri ";
				cout << endl;
			}
			cout << endl;
			int r, s;
			cout << "Rand: ";
			cin >> r;
			cout << "Loc";
			cin >> s;
			if (r != 1 && s >= 1 ) {
				if (r <= l.getNrRanduri() && s <= l.getNrLocuriPeRand()[r-1]) {
					e.OcupaLoc(l, r, s);
					
				}
				else {
					cout << "Locul nu exista!" << endl;
				}
			}
			else {
				cout << "Ai introdus loc VIP.Reincearca!";
				cout << endl;
			}
			break;
		case 2:
			cout << "Randul 1, locurile de la 1 la " << l.getNrLocuriPeRand()[0] << endl;
			cout << endl;
			int m, n;
			cout << "Rand: ";
			cin >> m;
			cout << "Loc";
			cin >> n;
			if (m == 1 && n >= 1 && n <= l.getNrLocuriPeRand()[m-1]) {
				e.OcupaLoc(l, m, n);
			}
			else {
				cout << "Nu ai introdus loc VIP";
				cout << endl;
			}

			break;
		}
		break;
	case 2:

		cout << "Tip bilet:" << endl;
		cout << "1. Categoria 1" << endl;
		cout << "2. Categoria 2" << endl;
		cout << "3. Loja" << endl;
		int c;
		cin >> c;
		switch (c) {
		case 1:
			cout << "Randurile 1,2 fara locul 1, unde exista: " << l.getNrRanduri() << " randuri" << endl;
			cout << endl;
			int f, t;
			cout << "Rand: ";
			cin >> t;
			cout << "Loc: ";
			cin >> f;
			if (t == 1 || t == 2 && f != 1 && f < l.getNrLocuriPeRand()[t - 1]) {
				e.OcupaLoc(l, t, f);
			}
			else {
				cout << "Nu ai introdus loc Categoria 1";
				cout << endl;
			}
			break;
		case 2:
			cout << "Toate locurile, fara randurile 1 si 2 si locul 1 de pe toate randurile, unde exista: " << l.getNrRanduri() << " randuri" << endl;
			cout << endl;
			int u, p;
			cout << "Rand: ";
			cin >> u;
			cout << "Loc: ";
			cin >> p;
			if (p > 1 && p < l.getNrLocuriPeRand()[u - 1] && u>2 && u < l.getNrRanduri()) {
				e.OcupaLoc(l, u, p);
			}
			else {
				cout << "Nu ai introdus loc Categoria 2";
				cout << endl;
			}
			break;
		case 3:
			cout << "Locul 1 de pe fiecare rand, unde exista: " << l.getNrRanduri() << " randuri" << endl;
			cout << endl;
			int k, j;
			cout << "Rand: ";
			cin >> k;
			cout << "Loc: ";
			cin >> j;
			if (j == 1 && k >= 1 && k<= l.getNrRanduri()) {
				e.OcupaLoc(l, k, j);
			}
			else {
				cout << "Nu ai introdus loc Loja";
				cout << endl;
			}
			break;
		}
		break;
	case 3:
		cout << "Tip bilet:" << endl;
		cout << "1. Peluza" << endl;
		cout << "2. Tribuna 1" << endl;
		cout << "3. Tribuna 2" << endl;
		int d;
		cin >> d;
		switch (d) {
		case 1:
			cout << "Primul si ultimul loc de pe fiecare rand unde exista: " << endl;
			for (int i= 0; i < l.getNrRanduri(); i++) {
				cout << "Randul " << i+1 << "are" << l.getNrLocuriPeRand()[i] << "locuri ";
				cout << endl;
			}
			int v, o;
			cout << "Rand: ";
			cin >> v;
			cout << "Loc: ";
			cin >> o;
			if (o == 1 && o == l.getNrLocuriPeRand()[v - 1] && v >= 1 && v <= l.getNrRanduri()) {
				e.OcupaLoc(l, v, o);
			}
			else {
				cout << "Nu ai introdus loc Peluza";
				cout << endl;
			}
			break;
		case 2:
			for (int i = 0; i < l.getNrRanduri()-1; i++) {
				cout << "Randul " << i + 1 << " locurile 2-" << l.getNrLocuriPeRand()[i] - 1;
				cout << endl;
			}
			int q, w;
			cout << "Rand: ";
			cin >> q;
			cout << "Loc: ";
			cin >> w;
			if (q>=1 && q<=l.getNrRanduri()-1 && w>1 && w< l.getNrLocuriPeRand()[q-1]){
				e.OcupaLoc(l, q, w);
			}
			else {
				cout << "Nu ai introdus loc Tribuna1";
				cout << endl;
			}
			break;
		case 3:
			int f = l.getNrRanduri();
			cout << "Randul " << f << " locurile de la 2 la " << l.getNrLocuriPeRand()[f-1]-1;
				cout << endl;
				int ab, cd;
				cout << "Rand: ";
				cin >> ab;
				cout << "Loc: ";
				cin >> cd;
				if (ab == l.getNrRanduri() && cd > 1 && cd <= l.getNrLocuriPeRand()[ab - 1] - 1) {
					e.OcupaLoc(l, ab, cd);
				}
				else {
					cout << "Nu ai introdus loc Tribuna1";
					cout << endl;
				}
			}
			break;
		default:
			cout << "Optiune invalida";
			break;
		}
	}




int main() {

	Locatie l3(3, new int[3] { 5, 6, 7 }, 3, 3);
	Eveniment e2("Meci Galati", "13 dec", "14:00", l3, 40);
	Bilet b3("Anap", 2, 3, vip, e2);
	Bilet b4("Anap", 2, 3, vip, e2);
	Bilet b5("Anap", 2, 3, vip, e2);
	afisaretip(e2,l3);

	
	
	
	return 0;
}