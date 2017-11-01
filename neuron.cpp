#include <iostream>
#include <cmath>
#include <vector>
#include "neuron.hpp"


Neuron::Neuron() : clock(0), spike_buffer(delay_steps+1)
{};

double Neuron::getv_m()
{
	return v_m;
}


double Neuron::gett_spike()
{
	return t_spike;
}


long Neuron::getn_spikes()
{
	return n_spikes;
}


void Neuron::receive_spike(unsigned long arrival, double j)
{
	const size_t t_out = arrival%(delay_steps + 1);
	spike_buffer[t_out] += j;
}


bool Neuron::update(unsigned long steps)
{
	if(steps == 0)return false;
	
	bool spike = false;
	double t_stop = clock + steps;
	while (clock < t_stop)
	{
		int t_in = clock % (delay_steps +1);
		//cout <<"v_m = " << v_m <<"\t" << "v_th_ = " << v_th_ <<"\n";
		
		
		
		
		if(v_m > v_th_)
		{
			++n_spikes;
			t_spike = clock;
			spike = true;
		}
		else
		{
			cout <<"v_m = " <<v_m <<"\n";
			v_m += exp(-h_/tau_m)*v_m + R_*(1.0-exp(-h_/tau_m)) *i_ext + spike_buffer[t_in];
			//cout <<"nouveau v_m = " << v_m <<"\n";
		}
		if((t_spike > 0) and (clock - t_spike < refractory_steps))
		{
			v_m = 0.0;
		}
		spike_buffer[t_in]=0.0;
		++clock;
	}
	return spike;
}
