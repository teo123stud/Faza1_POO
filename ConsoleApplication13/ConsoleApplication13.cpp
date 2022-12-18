#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>
#include "Locatie.h"
#include "Eveniment.h"
#include "Bilet.h"
using namespace std;

//prin aceasta functie, am abordat scenariile cerintei, prin care in functie de tipul biletului, utilizatorul poate rezerva doar anumite locuri si randuri, tinand cont de 
//caracteristicile locatiei
//utilizatorul alege evenimentul, tipul biletului si primeste precizari cu privire la ce locuri poate rezerva in functie de tip
//daca introduce corect si lcoul este liber, se ocupa
//in caz contrar, daca nu a introdus corect, i se arata mesajul 
//daca locul este ocupat, i se arata matricea locului ocupata
//la urmatoarea faza va fi facut cu un while, ca sa poate reincerca si se va ocupa si de alte functionalitati pe care le voi implementa ulterior

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


	//teste penru toti constructorii, operatorii si functiile create in cele 3 clase

int main() {

	Locatie l1;
	Locatie l3(3, new int[3] { 5, 6, 7 }, 3, 3);
	Locatie l2(2, new int[2] { 5, 6 }, 0, 0);
	l2.setPaznici(3);
	Locatie l4(l3);
	Locatie l5;
	l5 = l3;
	Eveniment e1("Fotbal", sportiv, "14 decembrie", "12:00", l2, 100);
	Eveniment e4("Teatru", teatru, "14 decembrie", "12:00", l2, 100);
	Eveniment e2(e1);
	Eveniment e3;
	e3 = e1;
	Bilet b1("Popescu Ana", 8, 2, 3, normal, e1);
	Bilet b2(b1);
	Bilet b3;
	b3 = b1;
	cout << b1;
	
	/*bool da;
	da=l2>=(l3);
	if (da == true) {
		cout << "DA";
	}
	else {
		cout << "NU";
	}*/

	/*
	bool ok;
	ok = l4 == (l3);
	if (ok == true) {
		cout << "DA";
	}
	else {
		cout << "NU";
	}
	*/

	/*l2.verificaiesiri(l2);
	l2.verificastingatoare(l2);*/


	/*bool ok;
	ok=!e2;
	if (ok == true) {
		cout << "DA";
	}
	else {
		cout << "NU";
	}
	*/

	/*
	 e1 = e1+(2);
	 cout << e1;*/


	 //Bilet b5("Popescu Ana",11,2, 3, vip, e1);
	 //b5 = b5 - (10);
	 //cout << b5;

	//e1.posibileprelungiri(10);
	//cout << e1;
}