/******************************************************************************
* Project:Open Frameworks for Evolutionary Computation (OFEC)
*******************************************************************************
* Author: Changhe Li
* Email: changhe.lw@gmail.com
* Language: C++
*-------------------------------------------------------------------------------
*  This file is part of OFEC. This library is free software;
*  you can redistribute it and/or modify it under the terms of the
*  GNU General Public License as published by the Free Software
*  Foundation; either version 2, or (at your option) any later version.
*
*  see https://github.com/Changhe160/OFEC for more information
*
*-------------------------------------------------------------------------------
* class dynamic defines dynamic optimization problems
*
*********************************************************************************/
#ifndef OFEC_DYNAMIC_H
#define OFEC_DYNAMIC_H

#include"../problem.h"
#include"../../global.h"

enum class change_type { CT_small_step = 0, CT_large_step, CT_random, CT_recurrent, CT_chaotic, CT_recurrent_noisy };

namespace OFEC {
	class dynamic : virtual public problem {

		struct s_change_type {
			change_type type;
			int counter;
			s_change_type & operator=(const s_change_type & change_type) {
				if (this == &change_type)  return *this;
				type = change_type.type;
				counter = change_type.counter;
				return *this;
			};
		};

	protected:
		int m_change_interval;
		s_change_type m_change_type;

		int m_period;				           // definite period for values repeating
		int m_change_counter;			       // counter of number of changes
		double m_noisy_severity;		       // deviation serverity from the trajactory of recurrent change
		bool m_flag_variable_change;	       // flag=true, the number of variables change, otherwise no change,  default value is false
		bool m_dir_variable_change;	           // direction of change, dir=true means increasing the variable, otherwise decrease it
		bool m_synchronize;                    // default=true all variables change at the same time

		int m_variable_size_temp;                 //a temporal variable for variable change only
		int m_num_peaks;
		bool m_flag_num_peaks_change;          // flag of the change of the number of peaks
		bool m_dir_num_peaks_change;           // true for increasing the number of peaks, otherwise decreasing the number of peaks
		int m_num_peaks_temp;                  // temporal varibal for number of peaks change only

		static const unsigned msc_max_variable_size = 15;
		static const unsigned msc_min_variable_size = 2;     //should be greater than 1
		static const int msc_max_num_peaks = 100;
		static const int msc_min_num_peaks = 10;

		static thread_local unique_ptr<int> ms_init_num_peaks, ms_init_variable_size, ms_num_instance;
		double m_alpha, m_max_alpha;              // to control step severity
		double m_chaotic_constant;

		int m_num_peaks_change_mode;	// for the number of peaks change; 1: periodic with fixed step, 2: periodic with random step, 3: chaotic change
		bool m_noise_flag;		        // objective evaluation with noise in descision space
		bool m_time_linkage_flag;	    // optima move to a random posotion if they are beging tracked 

		double m_noise_severity_, m_time_linkage_severity; // severity of noise and time-linkage added in noisy and time-linkage enviroment

		void set_variable_change(const bool flag);
		void set_change_dirction(const bool flag);

		bool m_flag_trigger_time_linkage;
	public:
		static const int msc_num_change_types = 12;

		dynamic(const int size_var, const int num_peaks, const unsigned size_obj = 1);
		virtual ~dynamic() = 0;

		dynamic & operator=(const dynamic & dynamic);

		void set_change_interval(const int change_interval);
		virtual bool set_period(const int period);
		void set_change_type(const s_change_type &change_type);
		void set_change_type(const change_type type);
		void set_num_peaks_change(const bool peaks_change);
		bool flag_num_peaks_change() {
			return m_flag_num_peaks_change;
		}
		void set_synchronize(const bool flag);
		void set_noisy_severity(const double severity);

		void set_alpha(const double alpha) {
			m_alpha = alpha;
		};
		void set_max_alpha(const double max_alpha) {
			m_max_alpha = max_alpha;
		};
		void set_choatic_constant(const double value) {
			m_chaotic_constant = value;
		}

		int change_interval()const {
			return m_change_interval;
		};
		int change_counter()const {
			return m_change_counter;
		};
		int period()const {
			return m_period;
		}
		change_type get_change_type() const {
			return m_change_type.type;
		};
		bool flag_variable_change() const {
			return m_flag_variable_change;
		};
		bool dir_variable_change() const {
			return m_dir_variable_change;
		};
		bool flag_synchronize_change()const {
			return m_synchronize;
		};

		void set_num_peak_change_mode(const int mode) {
			m_num_peaks_change_mode = mode;
		}
		int num_peak_change_mode() {
			return m_num_peaks_change_mode;
		}
		void set_noise_flag(const bool flag);
		int number_of_peak()const {
			return m_num_peaks;
		}
		void set_time_linkage_flag(const bool flag);
		bool flag_time_linkage() {
			return m_time_linkage_flag;
		}
		void change();
		double sin_value_noisy(const int x, const double min, const double max, const double amplitude, const double angle, const double noisy_severity = 1.);
		double chaotic_step(const double x, const double min, const double max, const double scale = 1.0);
		bool predict_change(const int evals_more);
		void set_noise_severity_(double value);
		void set_time_linkage_severity(double value);
		bool &trigger_timelinkage() { //TODO:Why a bool return value should add a "&" suffix?
			return m_flag_trigger_time_linkage;
		}
		static int initial_num_peaks();
	protected:
		virtual void random_change() {};
		virtual void small_step_change() {};
		virtual void large_step_change() {};
		virtual void recurrent_change() {};
		virtual void chaotic_change() {};
		virtual void recurrent_noisy_change() {};

		virtual void change_variable() {}; //TODO: change is change, resize is resize. But what is the difference?
		virtual void change_num_peaks() {};


		void copy(const problem * dynamic_problem); // copy parameter values of a problem when it changes
		virtual void  free_memory() {};
	};
}

#endif // !OFEC_DYNAMIC_H
