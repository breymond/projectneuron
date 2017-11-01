#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <random>

#include "neuron2.hpp"
#include "constante.hpp"


using namespace std;

Neuron::Neuron(): vm(0),clock(0), numberspikes(0), buffer(delay+1), source(cext+cinhib)
{};

double Neuron::getvm()
{
	return vm;
}

void Neuron::receive_spike(int t)
{
	buffer[t%delay+1] = 1;
	//modifier pour ji et je
}

bool Neuron::update(int steps)
{
	if(steps == 0)return false;
	
	bool spike;
	int t_interne = clock%delay+1;
	
	if(vm > vth)
	{
		++numberspikes;
		timespike = clock;
		spike = true;
		vm = 0;
	}
	else
	{
		vm = exp(-h/tau)*vm + R*(1.0-exp(-h/tau))*iext + buffer[t_interne];
		if(buffer[t_interne]!=0)
		{
			buffer[t_interne] = 0;
		}
		spike = false;
	}
	++clock;
	
	return spike;	
}

void Neuron::connection()
{
	
	vector<Neuron> connections(numberNeuron);
	
	
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> nbrinhibitory(0, inNeuron-1);
	uniform_int_distribution<int> nbrexcitatory(inNeuron, numberNeuron-1);

	for(int n(0); n<numberNeuron; n++)
	{
		for(int icon(0); icon<cinhib; icon++)
		{
			int target = 0;
			target = nbrinhibitory(gen);
			
			connections[target].connect(n);
		}
		for(int econ(0); econ<cext; econ++)
		{
			int target = 0;
			target = nbrexcitatory(gen);
			
			connections[target].connect(n);
		}
	}
}

void Neuron::connect(int n)
{
	source.push_back(n);
}
