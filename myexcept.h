#ifndef EXCEOT
#define EXCEOT

#include <iostream>
#include <stdexcept>

class numerical_exception : public std::runtime_error
{
public:
	numerical_exception(std::string tekst):std::runtime_error(tekst),_tekst(tekst){}
	numerical_exception(std::string tekst,std::string file ,int line):runtime_error(tekst),_tekst(tekst),_plik(file),_line(line){}
	~numerical_exception() throw(){}
	int getLine(){return _line;}
	std::string getFile(){return _plik;}
	std::string getTekst(){return _tekst;}
protected:
	std::string _tekst;
	std::string _plik;
	int _line;

};

class calculation_exception : public numerical_exception
{
public:
	calculation_exception(std::string tekst):numerical_exception(tekst){}
	calculation_exception(std::string tekst,std::string file ,int line):numerical_exception(tekst,file,line){
		//std::cout<<"Plik: "<<_plik;
	}
	~calculation_exception() throw(){}
};

class myexcept
{
public:
	myexcept();
	~myexcept();
	static void handler(std::string tekst){
		try{
			throw;
		}
		catch(calculation_exception& exe){
			std::cout<<"plik: "<<exe.getFile()<<" linia: "<<exe.getLine()<<" kontekst: (obliczenia z arg. 4) calculation exception: "<<exe.getTekst()<<"\n";
		}
		catch(numerical_exception& exe){
			std::cout<<"plik: "<<exe.getFile()<<" linia: "<<exe.getLine()<<" kontekst: (oblicznia z zrg. 1) numerical exception: "<<exe.getTekst()<<"\n";
		}
		catch(std::runtime_error exe){
			std::cout<<"kontekst: (obliczenia z arg. 7) runtime_error: "<<exe.what()<<"\n";
		}
	}
	
};

#endif