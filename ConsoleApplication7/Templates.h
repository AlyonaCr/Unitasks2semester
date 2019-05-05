#pragma once

template  <typename T> void Swap (T & one, T& other)
{
	T tmp = std::move(one);
	one = std::move(other);
	other = std::move(tmp);
}

