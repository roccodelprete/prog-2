#ifndef OVERLOAD_DI_OPERATORI_LIB_HPP
#define OVERLOAD_DI_OPERATORI_LIB_HPP

#include <iostream>
using namespace std;

class vettore2D {
	float Vx,Vy; // attributi privati che verranno utilizzati come componenti di un vettore2D
public: // metodi pubblici che verranno implementati nel file "vettore2D.cpp"
	void set_component(float,float);
	float *get_component();
	vettore2D operator+(vettore2D);
	float operator*(vettore2D);
};

#endif //OVERLOAD_DI_OPERATORI_LIB_HPP
