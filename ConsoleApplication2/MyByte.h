#pragma once
#include "Hex.h"
#include "Bin.h"
#include "Oct.h"

	union MyByte
	{
	private:
		char c;
		Bin b;
		Hex h;
		Oct o;

	public:

		MyByte(char _c) { c = _c; };
		void ShowBin() const { b.ShowBin(); }
		void ShowHex() const { h.ShowHex(); }
		void ShowOct() const { o.ShowOct(); }
		void ShowChar() const { std::cout << c << std::endl; }

	};

