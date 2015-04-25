/*
 * nld_74279.c
 *
 */

#include "nld_74279.h"

nld_74279A::truthtable_t nld_74279A::m_ttbl;

const char *nld_74279A::m_desc[] = {
		"S,R,PQ,PS,PR|Q",
		"0,0,X,X,X|1|22",
		"0,1,X,X,X|1|22",
		"1,0,X,X,X|0|15",
		"1,1,0,X,X|0|15",
		"1,1,1,X,X|1|22",
		""
};

nld_74279B::truthtable_t nld_74279B::m_ttbl;

const char *nld_74279B::m_desc[] = {
		"S1,S2,R,PQ,PS1,PS2,PR|Q",
		"0,X,0,X,X,X,X|1|22",
		"X,0,0,X,X,X,X|1|22",
		"0,X,1,X,X,X,X|1|22",
		"X,0,1,X,X,X,X|1|22",
		"1,1,0,X,X,X,X|0|15",
		"1,1,1,0,X,X,X|0|15",
		"1,1,1,1,X,X,X|1|22",
		""
};

NETLIB_START(74279_dip)
{
	register_sub(m_1, "1");
	register_sub(m_2, "2");
	register_sub(m_3, "3");
	register_sub(m_4, "4");

	register_subalias("1", m_1.m_i[2]);  //R
	register_subalias("2", m_1.m_i[0]);
	register_subalias("3", m_1.m_i[1]);
	register_subalias("4", m_1.m_Q[0]);

	register_subalias("5", m_2.m_i[1]);  //R
	register_subalias("6", m_2.m_i[0]);
	register_subalias("7", m_2.m_Q[0]);

	register_subalias("9", m_3.m_Q[0]);
	register_subalias("10", m_3.m_i[2]); //R
	register_subalias("11", m_3.m_i[0]);
	register_subalias("12", m_3.m_i[1]);

	register_subalias("13", m_2.m_Q[0]);
	register_subalias("14", m_2.m_i[1]); //R
	register_subalias("15", m_2.m_i[0]);
}

NETLIB_UPDATE(74279_dip)
{
	/* only called during startup */
	m_1.update_dev();
	m_2.update_dev();
	m_3.update_dev();
	m_4.update_dev();
}

NETLIB_RESET(74279_dip)
{
	m_1.do_reset();
	m_2.do_reset();
	m_3.do_reset();
	m_4.do_reset();
}