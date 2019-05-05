#include "Pair.h"

Pair::Pair(const char *k, const MyData& d): key(k), data(d)
{}

bool Pair::operator == (const Pair& other) const 
{

	return (strcmp(this->key.GetString(), other.key.GetString())== 0);

}

ostream& operator<<(ostream& os, const Pair& pair)
{
	os << "Last name: " << pair.key.GetString() << pair.data;
	return os;
}

Pair& Pair::operator=(const Pair& other) {
	if (this != &other) {
		this->data.operator=(other.data);
		this->key.operator=(other.key);
	}
	return *this;
}
