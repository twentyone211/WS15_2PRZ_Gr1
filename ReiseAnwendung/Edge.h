#ifndef EDGE_H
#define EDGE_H

#include "Node.h"

class Edge
{
public:

	Edge(Node& rSrc, Node& rDst)
		: m_rSrc(rSrc), m_rDst(rDst)
	{ }


	Node& getSrcNode() { return m_rSrc; }
	Node& getDstNode() { return m_rDst; }

	std::string toString() const;

	virtual double getWeight() { return 1; }
	virtual double getDistance() { return 1; }
	virtual void setistBaustelle() = 0;
	virtual void setkeinBaustelle() = 0;
	virtual bool istbaustele() { return true; }


private:

	Node& m_rSrc;
	Node& m_rDst;

};

#endif