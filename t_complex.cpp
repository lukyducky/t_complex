#include "t_complex.h"

template <class T>
complex<T>::complex(T a, T b) //CTOR
{
	//setting our data members to a and b
	R = a; 
	Im = b;
}

template <class T>
complex<T>::complex(const complex<T>& c) //copy CTOR
{
	//copying from existing complex number c and getting its values he-yo
	R = c.R;
	Im = c.Im;
}

//operator overloaders
template <class T>
complex<T>& complex<T>::operator +(const complex<T>& c)
{
	complex<T> *out = new complex<T>; //ptr to space of new complex
	//adding compnent-wise
	out->R = this->R + c.R;
	out->Im = this->Im + c.Im;
	return *out; //returning data at out
}

template <class T>
complex<T>& complex<T>::operator -(const complex<T>& c)
{
	complex<T> *out = new complex<T>;//ptr to space of new complex
	//subtracting component-wise
	out->R = this->R - c.R;
	out->Im = this->Im - c.Im;
	return *out; //returning data at out
}

template <class T>
complex<T>& complex<T>::operator *(const complex<T>& c)
{
	//using (a + bi)*(c + di) = (ac - bd) + i(ad + bc)

	complex<T>*out = new complex<T>;//ptr to space of new complex
	out->R = (this->R * c.R) - (this->Im * c.Im);
	out->Im = (this->R*c.Im) + (this->Im * c.R);
	return *out; //returning data at out

}

template <class T>
complex<T>& complex<T>::operator /(const complex<T>& c)
{
	//using  x = (a + bi) / (c + di)
	//= (ac + bd) + i(bc - ad)) / (c ^ 2 + d ^ 2)

	complex<T> *out = new complex<T>; //ptr to space of new complex
	T d = (c.R * c.R) + (c.Im * c.Im); //saving the denominator so we don't have to type as much
	out->R = ((this->R * c.R) + (this->Im * c.Im)) / d; 
	out->Im = ((this->Im * c.R) - (this->R * c.Im)) / d;
	return *out; //returning data at out
}

template <class T>
complex<T>& complex<T>::operator = (const complex<T>& c)
{
	this->R = c.R;
	this->Im = c.Im;
	return *this;  //return lhs
}

template <class T>
bool complex<T>::operator == (const complex& c)
{
	return ((this->R == c.R) && (this->Im == c.Im)) ? true : false; //if the Real parts and Imaginary parts are the same return true.  if not, false
}

template <class T>
complex<T>& complex<T>::operator +=(const complex<T>& c)
{
	this->R += c.R; //this Real equals sum of this real and c real
	this->Im += c.Im; //this Im equal sum of this imag and c imag
	return *this;  //return lhs
}

template <class T>
complex<T>& complex<T>::operator -=(const complex<T>& c)
{
	this->R -= c.R;//this Real equals difference of this real and c real
	this->Im -= c.Im;//this Im equal difference of this imag and c imag
	return *this; //return lhs
}

template <class T>
complex<T>& complex<T>::operator *=(const complex<T>& c)
{
	T tR = this->R; //save the this->real data into tR
	//using the earlier equation
	this->R = (tR * c.R) - (this->Im * c.Im); 
	this->Im = (tR*c.Im) + (this->Im * c.R); 
	return *this; //return lhs
}

template <class T>
complex<T>& complex<T>::operator /=(const complex<T>& c)
{
	//using previously listed equation
	T d = (c.R * c.R) + (c.Im * c.Im);//saving denominator
	T tR = this->R; //saving this->real data into tR
	this->R = ((tR*c.R) + (this->Im * c.Im)) / d;
	this->Im = ((this->Im*c.R) - (tR*c.Im)) / d;
	return *this; //return lhs
}

//explicit instantiation

template class complex<int>;
template class complex<float>;
template class complex<double>;

