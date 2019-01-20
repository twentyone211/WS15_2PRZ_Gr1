#include "UI.h"



UI::UI(Node* startnode)
{
	lastDestination.push_back(startnode);

}


UI::~UI()
{
}

char UI::showMenue()
{
	char auswahl;
	deque<Node*>::iterator deIt;
	deIt = lastDestination.begin();
	Node* tempnode = *deIt;

	
	cout << "Aktueller Aufenthaltsort: " 
		<< tempnode->getID() << "\n" << endl;
			
	cout << "| " << setw(2) << left << "1" << right << "|"
		<< setw(25) << left << " Naechster Kunde" << endl;

	cout << "| " << setw(2) << left << "2" << right << "|"
		<< setw(25) << left << " Baustellen markieren / Entfernen" << endl;

	cout << "| " << setw(2) << left << "3" << right << "|"
		<< setw(25) << left << " Arbeitstag beenden\n" << endl;
		
	cout << "\nSelect : ";

	cin >> auswahl;

	return auswahl;
}


Node* UI::selectDestination(Graph &orte)
{
	list<Node*> templist;
	list<Node*>::iterator ItNodes;
	map<int, Node*> destinations;
	Node* tempnode;
	unsigned int select;
	unsigned int i = 0;
	
	templist = orte.getNodes();

	cout << "\n";
	for (ItNodes = templist.begin(); ItNodes != templist.end(); ItNodes++)
	{
		i++;
		tempnode = *ItNodes;
		destinations[i] = tempnode;
		cout << "| " << setw(2) << left << i << right << "|"
			<< setw(25) << left << tempnode->getID() << endl;
		

	}
	cout << "\nZeilort angeben : ";
	select = getUInt(i);

	 

	return destinations[select];
}

void UI::tagBeenden(Graph &graph)
{
	ende = 1;
	bookTrip(graph);
	deque<Kunde*>::iterator kundenIt;
	Kunde* tempkunde;
	int zaehler = 0 ;;
	double gesamteinnahmen = 0;
	double gesamtfahrtkosten = 0;

	cout << "\nTagesbericht:\n " << endl;
	for (kundenIt = kunden.begin(); kundenIt != kunden.end(); kundenIt++)
	{
		zaehler++;
		tempkunde = *kundenIt;
		cout << "Kunde : " << zaehler << ". " << tempkunde->getName() << endl;
		cout << "Fahrtkosten : " << tempkunde->getFahrtkosten() << "Euro"<< endl;
		cout << "Einahmen : "  << tempkunde->geteinnahmen() << "Euro\n" << endl;
		gesamteinnahmen += tempkunde->geteinnahmen();
		gesamtfahrtkosten += tempkunde->getFahrtkosten();		

	}

	cout << "\nGesamteinnahmen: " << gesamteinnahmen << " Euro" << endl;
	cout << "Gesamtfahrtkosten: " << gesamtfahrtkosten << " Euro" << endl;


	
	



}

unsigned int UI::getUInt(unsigned int max) const {
	unsigned int i;
	while (!(cin >> i) || i <= 0 || i > max) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Wrong input ! Please select a number beetween 1 and " << max << endl;
	}
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	return i;
}

void UI::bookTrip(Graph &graph)
{
	string Kundenname;
	Node* zielort; // = selectDestination(graph);
	deque<Node*>::iterator deIt;
	deque<Edge*> path;
	deque<Edge*>::iterator deIt2;
	Edge* tempedge;
	
	double fahrtkosten;
	int i = 0;

	if (ende == 1) // haette besser geoest werden können
	{
		deIt = lastDestination.end();
		deIt--;
		zielort = *deIt;
		lastDestination.pop_back();
		Kundenname = "Daheim";
	}
	else
	{
		zielort = selectDestination(graph);
		cout << "Kundenname : ";
		cin >> Kundenname;
	}

	deIt = lastDestination.begin();	
	Node* startort = *deIt;
	graph.findShortestPathDijkstra(path, startort, zielort);
	int entfernung = 0;
		
	cout << "\nKuerzeste Route von : " << startort->getID() << " nach " << zielort->getID() << "\n" << endl;

	for (deIt2 = path.begin(); deIt2 != path.end(); deIt2++)
	{
		
		tempedge = *deIt2;
		cout << tempedge->toString() << endl;

		entfernung += tempedge->getDistance(); // streckenkm
		gesamtKM += tempedge->getDistance(); //tageskm
		
	
	}
	fahrtkosten = 0.3 * entfernung;
	cout << "\nEntfernung : " << entfernung << "KM" << "\nFahrtkosten : " << fahrtkosten << " Euro " << endl;
	
	if (ende == 0)
	{
		kunden.push_back(new Kunde(Kundenname, zielort->getID(), fahrtkosten, fahrtkosten + 50));
	}
	else
	{
		kunden.push_back(new Kunde(Kundenname, zielort->getID(), fahrtkosten, 0));
	}
	lastDestination.push_front(zielort);


	cout << "Fahrt verbucht !\n" << endl;
}




void UI::baustelle(Graph& const raph)
{
	unsigned int auswahl;
	Edge* tempedge;
	string markiert;
	
	cout << "Streckenabschnitte : \n" << endl;
	map<int, Edge*>edges = showEdges(raph);

	cout << "\nStreckenabschnitt waehlen: ";

	auswahl = getUInt(raph.getEdges().size());
	tempedge = edges[auswahl];
	
	if (!tempedge->istbaustele())
	{
		tempedge->setistBaustelle();
		markiert = " markiert\n";

	}
	else
	{
		tempedge->setkeinBaustelle();
		markiert = "Markierung entfernt\n";
	}


	cout << "\nStreckenabschnitt :" << tempedge->toString() << " " << markiert << endl;
	







}

map<int,Edge*> UI::showEdges(Graph & const graph)
{
	Edge* tempedge;
	string markierung;
	map<int, Edge*> edges;
	list<Edge*> templist = graph.getEdges();
	list<Edge*>::iterator EdgeIt;
	EdgeIt = templist.begin();
	int i = 0;

	for (EdgeIt = templist.begin(); EdgeIt != templist.end(); EdgeIt++)
	{
		i++;
		tempedge = *EdgeIt;
		edges[i] = tempedge;
		if (tempedge->istbaustele() == 1)
		{
			markierung = "Ja";
		}
		else
		{
			markierung = "Nein";
		}
		cout <<  "| " << setw(2) << left << i << right << "|" << setw(40) << left << tempedge->toString() << " Baustelle :" << markierung << endl;
	}

	
	return edges;
}









