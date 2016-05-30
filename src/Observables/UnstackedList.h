/*
 * UnstackedList.h
 *
 *  Created on: May 16, 2016
 *      Author: Ferdinando Randisi
 */

/**
 * @brief Prints a list of pairs involved in all order parameters that are hydrogen-bonded
 * if an order parameter file with particle pairs is provided, only those particle pairs
 * will be considered, otherwise all pairs in the system are considered.
 * @brief Prints the indices of all the particles that are NOT stacked with the particles with 
 * the following index. For example, if particle 1 is not stacked with 2, 2 is stacked with 3, 
 * 3 is not stacked with 4, it will print 1, 3.
 *
 * Based on the HBList observable, that has a better selection of which particles are to be
 * considered (can even read from order parameter files).
 * 
 * To use this observable, use type = unstacked_list
 * threshold_fraction = <double> the nucleotides will be counted as stacked if their
 *                      stacking energy is at least this fraction of the maximum stacking energy
 */

#ifndef UNSTACKEDLIST_H_
#define UNSTACKEDLIST_H_

#include "BaseObservable.h"
#include "../Utilities/OrderParameters.h"
#include "../Interactions/DNAInteraction.h"
#include "../Interactions/RNAInteraction.h"
#include "../Interactions/rna_model.h"

template<typename number>
class UnstackedList  : public BaseObservable<number>  {
	double _threshold_fraction;
	double _threshold_energy;
  std::string _interaction_type;
	Model *model;
	//char _order_parameters_file[512];
	//OrderParameters _op;
	//bool _read_op;

public:
	UnstackedList();
	virtual ~UnstackedList();

	virtual void get_settings (input_file &my_inp, input_file &sim_inp);
	std::string get_output_string(llint curr_step);
	virtual void init(ConfigInfo<number> &config_info);
	//bool is_hbond(int p, int q);
};

#endif /* UNSTACKEDLIST_H_ */
