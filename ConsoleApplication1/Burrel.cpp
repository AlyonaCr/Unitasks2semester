#include "Burrel.h"

Burrel::Burrel(double capacity, double concentrate) {
	m_capacity = capacity;
	m_concentrate = concentrate;
}

double Burrel::GetCapacity() const {
	return m_capacity;
}
double Burrel::GetConcentrate() const {
	return m_concentrate;
}
void Burrel::Pour(Burrel & burrel) {
	double one_liter_conc = m_concentrate/m_capacity;
	m_capacity -= 1;
	burrel.m_concentrate -= ((one_liter_conc / burrel.m_capacity)*100);
	burrel.m_capacity += 1;
}