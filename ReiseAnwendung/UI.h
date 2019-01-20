#pragma once
using namespace std;
#include <iostream>
#include <iomanip>
#include "Graph.h"
#include <deque>
#include <map>
#include "Kunde.h"

class UI
{
	deque<Node*> lastDestination;
	double gesamtKM = 0;
	int ende = 0;
	deque<Kunde*> kunden;

public:
	UI(Node*);
	~UI();
	char showMenue();
	Node* selectDestination(Graph& const);
	void tagBeenden(Graph& const);
	void bookTrip(Graph& const);
	void baustelle(Graph& const);
	map<int, Edge*>  showEdges(Graph& const);
	unsigned int getUInt(unsigned int) const;







};

