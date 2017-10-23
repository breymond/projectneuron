#include <iostream>
#include <cmath>
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


/*long getn_spikes()
{
	return n_spikes;
}

long getclock()
{
	return clock;
}*/

void Neuron::setc1andc2(double h_, double tau_m, double R_)
{
	c1 = exp(-h_/tau_m);
	c2 = R_*(1.0-c1);	
}

void Neuron::seti_ext(double x)
{
	i_ext = x;	
}


bool Neuron::update(unsigned long steps)
{
	if(steps == 0) return false;
	
	bool spike = false;
	const auto t_stop = CLOCK + steps;
	
	while (clock < t_stop)
	{
		const auto t_in = clock % (delay_steps +1);
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
		v_m = c1*v_m + c2 *i_ext + spike_buffer(t_in);
		}
		spike_buffer(t_in)=0.0;
		++clock;
	}
	return spike;
}
