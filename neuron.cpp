#include <iostream>
#include "neuron.hpp"




double getv_m()
{
	return v_m;
}

double geti_ext()
{
	return i_ext;
}

double gett_spike()
{
	return t_spike;
}


long getn_spikes()
{
	return n_spikes;
}

long getclock()
{
	return clock;
}

void Neuron::setc1andc2(double h_, double tau_m, double R_)
{
	c1 = std::exp(-h_/tau_m);
	c2 = R_*(1.0-c1);	
}
