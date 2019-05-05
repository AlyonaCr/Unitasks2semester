#include "MyData.h"

const char* e_sex[] = { "UNDEF", "MALE", "FEMALE" };

MyData::MyData(const char* job, Sex s, size_t age, float sal) : m_job(job) {
	sex = s;
	m_age = age;
	m_salary = sal;
}

ostream& operator<<(ostream& os, const MyData& d) {
	os << " sex: " << e_sex[d.sex] << " , age: " << d.m_age << " ,job: " << d.m_job << " , salary: " << d.m_salary;
	return os;
}