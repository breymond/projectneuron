#include <iostream>
#include "neuron.hpp"

using namespace std;

int main(int argc, char*argv[])
{
	cout << "coeur\n";
	Neuron n1,n2;
	
	int i_start = 1000;
	int i_stop = 4000;
	int t_stop = 5000;
	int delay = 15;
	double i_ext = 1.01;
	
	if (argc>1)
	{
		double y;
		cin >> y;
		i_ext = y;
	}
	
	cout << "I_ext = " << i_ext << "\n";
	
	for(int t = 0; t<t_stop; ++t)
	{
		if(t>=i_start and t<i_stop)
		{
		n1.seti_ext(i_ext);
		}
		else
		{
		n1.seti_ext(0.0);	
		}
		bool spike1 = n1.update(1);
		bool spike2 = n2.update(1);
		cout << t*0.1 << "\t" << n2.getv_m() << "\n";
		if(spike1)
		{
			cout << "Spike from 1 at t = " << t*0.1 << "ms\n";
			n2.receive_spike(t+delay, 0.1);
		}
		if(spike2)
		{
			cout << "Spike form 2 at t = " << t*0.1 << "ms\n";
		}
	}
	return 0;
}
