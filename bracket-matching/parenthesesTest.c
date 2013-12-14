#include "testUtils.h"
#include "parentheses.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_1_for_match_parantheses_of_simple_round_brackets(){
	char* data = "()";
	int result = matchParantheses(data);
	ASSERT(result == 1);
}

void test_2_for_match_parantheses_of_simple_round_brackets_with_extra_opening_bracket(){
	char* data = "())";
	int result = matchParantheses(data);
	ASSERT(result == 0);
}

void test_3_for_match_parantheses_of_simple_round_brackets_with_some_text(){
	char* data = "sdf(dfrth)eedsf)";
	int result = matchParantheses(data);
	ASSERT(result == 0);
}

void test_4_for_match_parantheses_of_couple_of_brackets_with_some_text(){
	char* data = "sd{f(dfrth)eed}sf[dc]";
	int result = matchParantheses(data);
	ASSERT(result == 1);
}

void test_5_for_match_parantheses_of_one_closing_bracket(){
	char* data = "]";
	int result = matchParantheses(data);
	ASSERT(result == 0);
}

void test_6_for_match_parantheses_of_no_brackets(){
	char* data = "dfdvjbdfknsvef";
	int result = matchParantheses(data);
	ASSERT(result == 1);
}

void test_7_for_match_parantheses_of_empty_string(){
	char* data = "";
	int result = matchParantheses(data);
	ASSERT(result == 1);
}


