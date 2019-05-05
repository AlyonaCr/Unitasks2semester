#pragma once
class MyString
{
    char* m_pStr;	//������-���� ������
public:
	MyString() {
		m_pStr = nullptr;
	}
	
	MyString(const char* m_pStr);
	~MyString();
	// ������
	const char* GetString() const;
	// �����������
	MyString(const MyString & other);
	// ������
	void SetNewString(const char* p_nStr);

};

MyString MyStrConcat(const char* first, ...);
MyString MyStrConcat2(const char* first, ...);