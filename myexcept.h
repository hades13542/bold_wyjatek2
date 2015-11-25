#pragma once

#include <stdexcept>

class numerical_exception : public std::runtime_error
{
public:
	numerical_exception(std::string tekst):std::runtime_error(tekst),_tekst(tekst){}
	~numerical_exception() throw(){}
private:
	std::string _tekst;
};

class calculation_exception : public numerical_exception
{
public:
	calculation_exception(std::string tekst):numerical_exception(tekst),_tekst(tekst){}
	~calculation_exception() throw(){}
private:
	std::string _tekst;
};

class myexcept
{
public:
	myexcept();
	~myexcept();
	static void handler(std::string tekst){}
	
};

class m
{
public:
	m();
	~m();
	static void moje_obliczenia(int a){}
};