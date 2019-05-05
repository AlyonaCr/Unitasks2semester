#pragma once
class Burrel
{
	double m_capacity;
	double m_concentrate;

public:
	Burrel(double capacity = 100, double concentrate = 100);
	double GetCapacity() const;
	double GetConcentrate() const;
	void Pour(Burrel & burrel);
};

