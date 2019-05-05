#include "Base.h"


Base::Base (size_t p_capacity): pBase(new Pair[p_capacity]), count (0), capacity (p_capacity)
{}

Base::Base(): pBase(nullptr), count(0), capacity(0)
{}

Base::~Base()
{
	delete[] pBase;
}

Base::Base(const Base& bd)
{
	this->operator=(bd);
	//capacity и count меняются в операторе присваивания
}

Base::Base(Base&& bd) 
{
	count = bd.count;
	capacity = bd.capacity;
	this->pBase = bd.pBase;
	bd.pBase = nullptr;
	bd.capacity = 0;
	bd.count = 0;
}

Base& Base::operator=(const Base& bd) 
{
	if (!(*this == bd)) {
		if (capacity < bd.count) {
			delete[] pBase;
			pBase = new Pair[bd.count];
			capacity = bd.count;
		}
		count = bd.count;
		if (bd.pBase != nullptr) {
			for (size_t i = 0; i < count; i++) {
				this->pBase[i].operator=(bd.pBase[i]);
			}
		}
		else {
			//если указатель нулевой
			//pBase = bd.pBase;
			count = 0;
		}
	}
	return *this;
}


Base& Base::operator=(Base&& bd) 
{
	if (!(*this == bd)) {
		this->pBase = bd.pBase;
		bd.pBase = nullptr;
		count = bd.count;
		capacity = bd.capacity;
		bd.count = 0;
		bd.capacity = 0;
	}

	return *this;
}

MyData& Base::operator[](const char * key)
{
	for (size_t i = 0; i < count; i++) {
		if (pBase[i].key.operator==(key)) { return pBase[i].data; }
	}
		if (count == capacity) {
			capacity++;
			Pair* tmp = new Pair[capacity];
			if (count) {
				for (size_t i = 0; i < capacity-1; i++) {
					tmp[i] = std::move(pBase[i]);
				}
			}
			delete[] pBase;
			pBase = std::move(tmp);
		}
		pBase[count].key = key;
		count++;
	
	return pBase[count-1].data;
}

bool Base::operator== (const Base & other) const 
{
	if (count != other.count) {
		return false;

	} else {
		for (size_t i = 0; i < count; i++) {
			if (!(pBase[i].operator==(other.pBase[i]))) {
				return false;
			}
		}
		return true;
	}
	
}

ostream& operator<<(ostream& os, const Base &bd) 
{
	for (size_t i = 0; i < bd.count; i++) {
		os << bd.pBase[i] << std::endl;
	}
	return os;
}

int Base::deletePair(const char* key) 
{
	for (size_t i = 0; i < count; i++) {
		if (pBase[i].key.operator == (key)) {
			pBase[i] = pBase[count-1];
			count--;
			return 1;
		}
	}
	return 0;
}