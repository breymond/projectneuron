#include <iostream>
#include "neuron2.hpp"
#include "constante.hpp"

using namespace std;

int main()
{
	cout <<"COUCOU\n";
	
	Neuron n1,n2;
	//connection();
	
	int tfin = 1200;
	
	for(int t(0); t<tfin; t++)
	{
		bool spike1 = n1.update(1);
		bool spike2 = n2.update(1);
		if(spike1)
		{
			n2.receive_spike(t);
			cout<<"Spike à t1 = "<< t <<"\n";
		}
		if(spike2)
		{
			cout<<"Spike à t2 = "<< t <<"\n";
		}
	}
	
	return 0;
}
