/*************************************************************************
* Project:Open Frameworks for Evolutionary Computation (OFEC)
*************************************************************************
* Author: Changhe Li
* Email: changhe.lw@gmail.com
* Language: C++
*************************************************************************
*  This file is part of OFEC. This library is free software;
*  you can redistribute it and/or modify it under the terms of the
*  GNU General Public License as published by the Free Software
*  Foundation; either version 2, or (at your option) any later version.
*************************************************************************/

#ifndef OFEC_F17_HYBRID_COMPOSITION_NOISY_H
#define OFEC_F17_HYBRID_COMPOSITION_NOISY_H

#include "composition.h"

namespace OFEC {
	namespace CEC2005 {
		class F17_hybrid_composition_noisy final: public composition
		{
		public:
			F17_hybrid_composition_noisy(param_map &v);
			F17_hybrid_composition_noisy(const std::string &name, size_t size_var, size_t size_obj);
		protected:
			void initialize();
			void evaluate__(real *x, std::vector<real>& obj);
			void set_function();
			
			double noise();
		private:

		};
	}
}
#endif // !OFEC_F17_HYBRID_COMPOSITION_NOISY_H
