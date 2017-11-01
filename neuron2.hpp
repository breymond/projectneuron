#ifndef NEURON2_H
#define NEURON2_H


#include <iostream>
#include <cassert>
#include <vector>

class Neuron
{
	private:
		double vm;
		int clock;
		int numberspikes;
		double timespike;
		
		std::vector<double> buffer;
		std::vector<int> source;
	
	public:
		Neuron();
		double getvm();
		void receive_spike(int t_interne);
		bool update(int steps);
		
		void connection();
		void connect(int n);	
};


#endif
