#ifndef NEURON_H
#define NEURON_H

#include <cassert>


class Neuron
{
	public:
		double R_=20.0 const ;
		const double tau_m_=20.0;
		const double v_th_=20.0;
		const double t_ref=2.0;
		const double h_=0.1;
		const long refractory_steps_;
		
		double c1;
		double c2;
		
		double v_m;
		double i_ext;
		long t_spike;
		long n_spikes;
		long clock;
		
		void Neuron::setc1andc2(double h_, double tau_m, double R_);
		
		double getv_m();
		double geti_ext();
		double gett_spike();
		long n_spikes();
		long clock();
};

#endif
