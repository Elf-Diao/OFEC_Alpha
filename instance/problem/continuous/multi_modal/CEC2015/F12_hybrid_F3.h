
/*************************************************************************
* Project:Open Frameworks for Evolutionary Computation (OFEC)
*************************************************************************
* Author: Changhe Li and Li Zhou
* Email: changhe.lw@gmail.com, 441837060@qq.com
* Language: C++
*************************************************************************
*  This file is part of OFEC. This library is free software;
*  you can redistribute it and/or modify it under the terms of the
*  GNU General Public License as published by the Free Software
*  Foundation; either version 2, or (at your option) any later version.
*************************************************************************/


#ifndef OFEC_F12_HYBRID_F3_H
#define OFEC_F12_HYBRID_F3_H

#include "../../../../../core/problem/continuous/function.h"

namespace OFEC {
	namespace CEC2015 {
		class F12_hybrid_F3 : public function
		{
		public:
			F12_hybrid_F3(param_map &v);
			F12_hybrid_F3(const std::string &name, size_t size_var, size_t size_obj);
			virtual ~F12_hybrid_F3();
		protected:
			void initialize();
			void evaluate__(real *x, std::vector<real>& obj);
		private:
			size_t m_num_function;
			std::vector<function*> m_function;    // the functions
			std::vector<size_t> m_start, m_dim;
		};
	}
}
#endif // ! OFEC_F12_HYBRID_F3_H




