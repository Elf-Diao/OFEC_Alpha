#include "F11_shifted_rotated_weierstrass.h"

namespace OFEC {
	namespace CEC2005 {
		F11_shifted_rotated_weierstrass::F11_shifted_rotated_weierstrass(param_map &v) :problem((v[param_proName]), (v[param_numDim]), 1), \
			weierstrass((v[param_proName]), (v[param_numDim]), 1) {
			initialize();
		}
		F11_shifted_rotated_weierstrass::F11_shifted_rotated_weierstrass(const std::string &name, size_t size_var, size_t size_obj) :problem(name, size_var, size_obj), \
			weierstrass(name, size_var, size_obj) {
			initialize();
		}

		void F11_shifted_rotated_weierstrass::initialize() {


			set_condition_number(5);
			set_bias(90);
			m_translation.resize(m_variable_size);
			bool is_load = load_translation("instance/problem/continuous/global/CEC2005/data/");  //data path
			if (!is_load) {
				std::vector<real> temp_var(m_variable_size);
				for (size_t i = 0; i < m_variable_size; ++i)
					temp_var[i] = m_original_optima.variable(0)[i];
				set_translation(temp_var);
				m_translation_flag = true;
			}
			load_rotation("instance/problem/continuous/global/CEC2005/data/");
			m_optima.clear();
			set_global_opt(m_translation.data());
		}
		void F11_shifted_rotated_weierstrass::evaluate__(real *x, vector<real>& obj) {

			weierstrass::evaluate__(x, obj);
		}
	}
}