#pragma once
#include <iostream>

class Kunde
{
	std::string name;
	std::string ort;
	double fahrtkosten;
	double einnahmen;
public:

	std::string getName() { return name; }
	std::string getort() { return ort; }
	double getFahrtkosten() { return fahrtkosten; }
	double geteinnahmen() { return einnahmen; }

	Kunde();
	Kunde(std::string name, std::string ort, double fahrtkosten, double einnahmen) : name(name), ort(ort), fahrtkosten(fahrtkosten), einnahmen(einnahmen) {};
	~Kunde();
};

