#include <iostream>
#include "Graph.h"
#include "UI.h"
#include "Orte.h"
#include "Node.h"
#include "Graph.h"
#include "Route.h"



int main()
{
	Graph gebiet;
	Graph &refgebiet= gebiet;
	
	Orte* Ludwigsfelde = new Orte("Ludwigsfelde");
	Orte* Trebbin= new Orte("Trebbin");
	Orte* Zossen = new Orte("Zossen");
	Orte* Mittenwalde = new Orte("Mittenwalde");
	Orte* Luckenwalde = new Orte("Luckenwalde");
	Orte* Teupitz = new Orte("Teupitz");

	Route* LT = new Route(*Ludwigsfelde, *Trebbin, 12, 65);
	Route* TL = new Route(*Trebbin, *Ludwigsfelde, 12, 65);
	Route* TZ = new Route(*Trebbin, *Zossen, 40, 80);
	Route* TRL = new Route(*Trebbin, *Luckenwalde, 18, 85);
	Route* LTR = new Route(*Luckenwalde, *Trebbin, 18, 85);
	Route* ZT = new Route(*Zossen, *Trebbin, 40, 80);
	Route* ZM = new Route(*Zossen, *Mittenwalde, 10, 60);
	Route* MZ = new Route(*Mittenwalde, *Zossen, 10, 60);
	Route* ZTE = new Route(*Zossen, *Teupitz, 20, 80);
	Route* TEZ = new Route(*Teupitz, *Zossen, 20, 80);
	Route* TEL = new Route(*Teupitz, *Luckenwalde, 45, 90);
	Route* LTE = new Route(*Luckenwalde, *Teupitz, 45, 90);

		 
	gebiet.addNode(Ludwigsfelde);
	gebiet.addNode(Trebbin);
	gebiet.addNode(Zossen);
	gebiet.addNode(Mittenwalde);
	gebiet.addNode(Luckenwalde);
	gebiet.addNode(Teupitz);

	gebiet.addEdge(LT);
	gebiet.addEdge(TL);
	gebiet.addEdge(TZ);
	gebiet.addEdge(ZT);
	gebiet.addEdge(TRL);
	gebiet.addEdge(LTR);
	gebiet.addEdge(ZM);
	gebiet.addEdge(MZ);
	gebiet.addEdge(ZTE);
	gebiet.addEdge(TEZ);
	gebiet.addEdge(TEL);
	gebiet.addEdge(LTE);
	

	
	
	char auswahl;
	UI userinteferace(Mittenwalde);

	do
	{
		auswahl = userinteferace.showMenue();

		switch (auswahl)
		{
		case '1':

			userinteferace.bookTrip(refgebiet);
			break;

		case '2':
			userinteferace.baustelle(refgebiet);
			break;
		case'3':
			userinteferace.tagBeenden(refgebiet);
			cout << "Programm wird beendet." << endl;
			break;
		}
	} while (auswahl != '3');

	system("pause");
    return 0;
}