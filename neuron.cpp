#include <iostream>
#include <cmath>
#include <vector>
#include "neuron.hpp"




double Neuron::getv_m()
{
	return v_m;
}

double Neuron::geti_ext()
{
	return i_ext;
}

double Neuron::gett_spike()
{
	return t_spike;
}


long Neuron::getn_spikes()
{
	return n_spikes;
}


void Neuron::setc1andc2(double h_, double tau_m, double R_)
{
	c1 = exp(-h_/tau_m);
	c2 = R_*(1.0-c1);	
}

void Neuron::seti_ext(double x)
{
	i_ext = x;	
}

void Neuron::receive_spike(unsigned long arrival, double j)
{
	const size_t t_out = arrival%(delay_steps + 1);
	spike_buffer[t_out] += j;
}


bool Neuron::update(unsigned long steps)
{
	if(steps == 0) return false;
	
	bool spike = false;
	double t_stop = clock + steps;
	
	while (clock < t_stop)
	{
		int t_in = clock % (delay_steps +1);
		if(v_m > v_th_)
		{
			++n_spikes;
			t_spike = clock;
			spike = true;
		}
		
		if((t_spike > 0) and (clock - t_spike < refractory_steps))
		{
			v_m = 0.0;
		}
		else
		{
			v_m = c1*v_m + c2 *i_ext + spike_buffer[t_in];
		}
		spike_buffer[t_in]=0.0;
		++clock;
	}
	return spike;
}
