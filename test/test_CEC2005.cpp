#define BOOST_TEST_MODULE CEC2005
#include <boost/test/unit_test.hpp>

#include "../instance/problem/continuous/global/classical/six_hump_camel_back.h"
#include "../instance/problem/continuous/global/classical/branin_rcos.h"
#include "../instance/problem/continuous/global/classical/sphere.h"
#include "../instance/problem/continuous/global/classical/CEC2005/F25_rotated_hybrid_no_bound.h"
//#include "../instance/problem/continuous/global/classical/schwefel_2_13.h"
using namespace OFEC;

BOOST_AUTO_TEST_SUITE(CEC2005_test)


BOOST_AUTO_TEST_CASE(test_case1) {
	global::ms_global = unique_ptr<global>(new global(0.5, 0.5));
	vector<real> data = { -0.089842, 0.712656 };
	vector<real> data2 = { 0, 0 };

	solution<variable<real>> sol(1, data);
	solution<variable<real>> sol2(1, data2);

	six_hump_camel_back a("", data.size(), 1);

	a.evaluate(sol, caller::Problem);
	a.evaluate(sol2, caller::Problem);
	BOOST_CHECK_EQUAL(a.get_optima().single_objective(0), sol.get_objective()[0]);
	//BOOST_CHECK_EQUAL(a.get_optima().single_objective(0), sol2.get_objective()[0]);
	
	//std::cout << a.get_optima().single_objective(0) << std::endl;
	//for (auto &i : sol.get_objective())
		//std::cout << i << std::endl;
	//for (auto &i : sol2.get_objective())
		//std::cout << i << std::endl;

}
BOOST_AUTO_TEST_CASE(test_case2) {
	global::ms_global = unique_ptr<global>(new global(0.5, 0.5));
	vector<real> data = { -OFEC_PI, 12.275 };
	vector<real> data2 = { 0, 1 };

	solution<variable<real>> sol(1, data);
	solution<variable<real>> sol2(1, data2);

	branin_rcos a("", data.size(), 1);

	a.evaluate(sol, caller::Problem);
	a.evaluate(sol2, caller::Problem);
	BOOST_CHECK_EQUAL(a.get_optima().single_objective(0), sol.get_objective()[0]);
	//BOOST_CHECK_EQUAL(a.get_optima().single_objective(0), sol2.get_objective()[0]);

	//std::cout << a.get_optima().single_objective(0) << std::endl;
	//for (auto &i : sol.get_objective())
	//std::cout << i << std::endl;
	//for (auto &i : sol2.get_objective())
	//std::cout << i << std::endl;

}
BOOST_AUTO_TEST_CASE(test_case3) {
	global::ms_global = unique_ptr<global>(new global(0.5, 0.5));

	F25_rotated_hybrid_no_bound a("F25_rotated_hybrid_no_bound", 2, 1);

	vector<real> data = { 0, 0 };
	vector<real> data2 = { -1, 1 };
	
	//for (size_t i = 0; i < data.size(); ++i) {
		//data[i] += a.translation()[i];
	//}
	for (size_t i = 0; i < data.size(); ++i) {
		data[i] += a.get_function(0)->translation()[i];
	}
	solution<variable<real>> sol(1, data);
	solution<variable<real>> sol2(1, data2);

	
	//sphere a("", data.size(), 1);
	
	
	a.evaluate(sol, caller::Problem);
	a.evaluate(sol2, caller::Problem);
	BOOST_CHECK_EQUAL(a.get_optima().single_objective(0), sol.get_objective()[0]);
	//BOOST_CHECK_EQUAL(a.get_optima().single_objective(0), sol2.get_objective()[0]);

	std::cout << a.get_optima().single_objective(0) << std::endl;
	//for (auto &i : sol.get_objective())
	//std::cout << i << std::endl;
	//for (auto &i : sol2.get_objective())
	//std::cout << i << std::endl;

}

BOOST_AUTO_TEST_SUITE_END()