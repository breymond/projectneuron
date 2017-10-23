#ifndef NEURON_H
#define NEURON_H

#include <cassert>
#include <vector>

using namespace std;

const double R_=20.0;
const double tau_m_=20.0;
const double v_th_=20.0;
const double t_ref=2.0;
const double h_=0.1;
const long delay_steps = 15;	
	
class Neuron
{
	
	
	long refractory_steps;
	
	double c1;
	double c2;
	
	double v_m;
	double i_ext;
	double delay;
	long t_spike;
	long n_spikes;
	long clock;
	
	
	std::vector <int> spike_buffer;
	
	
	public:	
		void setc1andc2(double h_, double tau_m, double R_);
		
		void seti_ext(double x);
		
		double getv_m();
		double geti_ext();
		double gett_spike();
		long getn_spikes();
		
		void receive_spike(unsigned long arrival, double j);
		bool update(unsigned long steps);
};

#endif
