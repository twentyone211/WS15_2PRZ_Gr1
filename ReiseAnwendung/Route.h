#pragma once
#include "Graph.h"

class Route :
	public Edge
{
	double m_entfernung;
	int m_istBaustelle;
	double m_geschwindigkeit;

public:

	virtual double getWeight() ;
	virtual double getDistance() ;
	void setistBaustelle() { m_istBaustelle = 1; }
	void setkeinBaustelle() { m_istBaustelle = 0; }
	bool istbaustele()
	{
		if (m_istBaustelle == 1)
		{
			return true;
		}
		return false;
	}


	Route(Node& rSrc, Node& rDst,double,double);
	~Route();
};

