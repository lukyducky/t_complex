#ifndef _T_COMPLEX_H
#define _T_COMPLEX_H

#include <iostream>

template <class T>
class complex{
private:
	T R; //real part
	T Im; //imag part
public:
	complex(){ R = Im = 0; } //default CTOR: set real and imag to 0
	complex(T a, T b); //CTOR
	complex(const complex<T>& c); //copy CTOR
	~complex(){}

	//getters and setters
	T getR(){ return R; }
	T getIm(){ return Im; }
	void setR(T a){ R = a; }
	void setIm(T a){ Im = a; }

	//operator overloaders
	complex<T>& operator +(const complex<T>& c);
	complex<T>& operator -(const complex<T>& c);
	complex<T>& operator *(const complex<T>& c);
	complex<T>& operator /(const complex<T>& c);



	complex<T>& operator = (const complex<T>& c);

	bool operator == (const complex& c);

	complex<T>& operator +=(const complex<T>& c);
	complex<T>& operator -=(const complex<T>& c);
	complex<T>& operator *=(const complex<T>& c);
	complex<T>& operator /=(const complex<T>& c);

	//overloading cout to print  in ( a + bi ) format
	friend std::ostream& operator << (std::ostream& o, const complex<T>& c)
	{
		o << "(" << c.R << "+" << c.Im << "i )"; 
		return o;
	}

};




#endif