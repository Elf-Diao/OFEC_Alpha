#include "MOEA_F5.h"

namespace OFEC {
	MOEA_F5::MOEA_F5(param_map & v) : problem(v[param_proName], v[param_numDim], 2), \
		MOEA_FBase(v[param_proName], v[param_numDim], 2) {
		global::ms_arg[param_numObj] = 2;
		std::vector<std::pair<real, real>> range(m_variable_size, std::make_pair(-1, 1));
		range[0].first = 0;
		set_range(range);
		m_dtype = 1;
		m_ptype = 21;
		m_ltype = 26;
		LoadPF();
	}
}