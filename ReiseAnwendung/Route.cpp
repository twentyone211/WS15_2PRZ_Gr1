#include "Route.h"



double Route::getWeight()
{
	if (!istbaustele())
	{
		double weight;
		weight = m_entfernung / m_geschwindigkeit;
		return weight;
	}
	return 1000000;
}

double Route::getDistance()
{
	return m_entfernung;
}

Route::Route(Node& rSrc, Node& rDst , double entfernung , double geschwindigkeit): Edge(rSrc,rDst), m_entfernung(entfernung) , m_geschwindigkeit(geschwindigkeit)
{
	
}


Route::~Route()
{
}
