#include "ZDT4.h"

namespace OFEC {
	ZDT4::ZDT4(param_map & v) : problem(v[param_proName], v[param_numDim], 2), ZDT(v) {
		generateAdLoadPF();
	}
	void ZDT4::evaluate__(double * x, std::vector<double>& obj) {
		double g = 0;
		for (size_t n = 1; n<m_variable_size; n++)
			g = g + (pow(x[n], 2) - 10 * cos(4 * OFEC_PI*x[n]));
		g = 1 + 10 * (m_variable_size - 1) + g;
		obj[0] = x[0];
		obj[1] = g*(1 - sqrt(x[0] / g));
	}
}