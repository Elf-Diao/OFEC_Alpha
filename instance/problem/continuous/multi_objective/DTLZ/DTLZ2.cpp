#include "DTLZ2.h"

namespace OFEC {
	DTLZ2::DTLZ2(param_map & v) : problem(v[param_proName], (v[param_numObj] + v[param_interTest1] - 1), v[param_numObj]), \
		DTLZ(v[param_proName], (v[param_numObj] + v[param_interTest1] - 1), v[param_numObj]) {
	}

	void DTLZ2::evaluate__(double * x, std::vector<double>& obj) {
		double g = 0;
		for (size_t i = m_objective_size - 1; i < m_variable_size; i += 1)
			g += pow((x[i] - 0.5), 2);
		for (size_t m = 0; m < m_objective_size; m += 1)
		{
			double product = (1 + g);
			size_t i = 0;
			for (; i + m <= m_objective_size - 2; i += 1)
				product *= cos(x[i] * OFEC_PI / 2);
			if (m > 0)
				product *= sin(x[i] * OFEC_PI / 2);
			obj[m] = product;
		}
	}
}