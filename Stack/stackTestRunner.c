#include <stdio.h>

int testCount=-1;
int passCount=0;
void setup();
void tearDown();

void fixtureSetup();
void fixtureTearDown();
void incrementTestCount();
void incrementPassCount();
int currentTestFailed=0;

void testStarted(char* name){
	incrementTestCount();
	currentTestFailed=0;
	printf("\t%s\n",name);
}

void testEnded(){
	if(!currentTestFailed)
		incrementPassCount();
}

void resetTestCount(){
	testCount=0;
	passCount=0;
	printf("********* Starting tests\n\n");
}

void summarizeTestCount(){
	printf("\n********* Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
}

void incrementTestCount(){
	testCount++;
}

void incrementPassCount(){
	passCount++;
}

void testFailed(const char* fileName, int lineNumber, char* expression){
	currentTestFailed = 1;
	printf("\t\t %s : failed at %s:%d\n",expression, fileName,lineNumber);
}

int main(){
	fixtureSetup();
	resetTestCount();

	testStarted("test_1_for_creating_a_stack_for_integer_type");
	setup();
		test_1_for_creating_a_stack_for_integer_type();
	tearDown();
	testEnded();
	testStarted("test_2_for_creating_a_stack_for_float_type");
	setup();
		test_2_for_creating_a_stack_for_float_type();
	tearDown();
	testEnded();
	testStarted("test_3_for_creating_a_stack_for_double_type");
	setup();
		test_3_for_creating_a_stack_for_double_type();
	tearDown();
	testEnded();
	testStarted("test_4_for_creating_a_stack_for_character_type");
	setup();
		test_4_for_creating_a_stack_for_character_type();
	tearDown();
	testEnded();
	testStarted("test_5_for_push_a_integer_element_in_stack");
	setup();
		test_5_for_push_a_integer_element_in_stack();
	tearDown();
	testEnded();
	testStarted("test_6_for_push_two_integer_element_in_stack");
	setup();
		test_6_for_push_two_integer_element_in_stack();
	tearDown();
	testEnded();
	testStarted("test_7_for_push_a_integer_element_in_stack");
	setup();
		test_7_for_push_a_integer_element_in_stack();
	tearDown();
	testEnded();
	testStarted("test_8_for_push_two_integer_element_in_stack");
	setup();
		test_8_for_push_two_integer_element_in_stack();
	tearDown();
	testEnded();
	testStarted("test_9_for_push_a_float_element_in_stack");
	setup();
		test_9_for_push_a_float_element_in_stack();
	tearDown();
	testEnded();
	testStarted("test_10_for_push_two_float_element_in_stack");
	setup();
		test_10_for_push_two_float_element_in_stack();
	tearDown();
	testEnded();
	testStarted("test_11_for_push_a_double_element_in_stack");
	setup();
		test_11_for_push_a_double_element_in_stack();
	tearDown();
	testEnded();
	testStarted("test_12_for_push_two_double_element_in_stack");
	setup();
		test_12_for_push_two_double_element_in_stack();
	tearDown();
	testEnded();
	testStarted("test_13_for_push_a_character_element_in_stack");
	setup();
		test_13_for_push_a_character_element_in_stack();
	tearDown();
	testEnded();
	testStarted("test_14_for_push_two_character_element_in_stack");
	setup();
		test_14_for_push_two_character_element_in_stack();
	tearDown();
	testEnded();
	testStarted("test_15_for_pop_a_interger_in_stack");
	setup();
		test_15_for_pop_a_interger_in_stack();
	tearDown();
	testEnded();
	testStarted("test_16_for_pop_two_interger_in_stack");
	setup();
		test_16_for_pop_two_interger_in_stack();
	tearDown();
	testEnded();
	testStarted("test_17_for_pop_a_float_in_stack");
	setup();
		test_17_for_pop_a_float_in_stack();
	tearDown();
	testEnded();
	testStarted("test_18_for_pop_two_float_in_stack");
	setup();
		test_18_for_pop_two_float_in_stack();
	tearDown();
	testEnded();
	testStarted("test_19_for_pop_a_double_in_stack");
	setup();
		test_19_for_pop_a_double_in_stack();
	tearDown();
	testEnded();
	testStarted("test_20_for_pop_two_double_in_stack");
	setup();
		test_20_for_pop_two_double_in_stack();
	tearDown();
	testEnded();
	testStarted("test_21_for_pop_a_character_in_stack");
	setup();
		test_21_for_pop_a_character_in_stack();
	tearDown();
	testEnded();
	testStarted("test_22_for_pop_two_character_in_stack");
	setup();
		test_22_for_pop_two_character_in_stack();
	tearDown();
	testEnded();
	testStarted("test_23_for_pop_a_character_in_stack");
	setup();
		test_23_for_pop_a_character_in_stack();
	tearDown();
	testEnded();
	testStarted("test_24_for_pop_two_character_in_stack");
	setup();
		test_24_for_pop_two_character_in_stack();
	tearDown();
	testEnded();
	testStarted("test_25_for_pop_a_character_in_stack");
	setup();
		test_25_for_pop_a_character_in_stack();
	tearDown();
	testEnded();
	testStarted("test_26_for_pop_two_character_in_stack");
	setup();
		test_26_for_pop_two_character_in_stack();
	tearDown();
	testEnded();
	testStarted("test_27_for_peek_a_interger_in_stack");
	setup();
		test_27_for_peek_a_interger_in_stack();
	tearDown();
	testEnded();
	testStarted("test_28_for_peek_two_interger_in_stack");
	setup();
		test_28_for_peek_two_interger_in_stack();
	tearDown();
	testEnded();
	testStarted("test_29_for_peek_a_float_in_stack");
	setup();
		test_29_for_peek_a_float_in_stack();
	tearDown();
	testEnded();
	testStarted("test_30_for_peek_two_float_in_stack");
	setup();
		test_30_for_peek_two_float_in_stack();
	tearDown();
	testEnded();
	testStarted("test_31_for_peek_a_double_in_stack");
	setup();
		test_31_for_peek_a_double_in_stack();
	tearDown();
	testEnded();
	testStarted("test_32_for_peek_two_double_in_stack");
	setup();
		test_32_for_peek_two_double_in_stack();
	tearDown();
	testEnded();
	testStarted("test_33_for_peek_a_character_in_stack");
	setup();
		test_33_for_peek_a_character_in_stack();
	tearDown();
	testEnded();
	testStarted("test_34_for_peek_two_character_in_stack");
	setup();
		test_34_for_peek_two_character_in_stack();
	tearDown();
	testEnded();
	testStarted("test_35_for_peek_a_character_in_stack");
	setup();
		test_35_for_peek_a_character_in_stack();
	tearDown();
	testEnded();
	testStarted("test_36_for_peek_two_character_in_stack");
	setup();
		test_36_for_peek_two_character_in_stack();
	tearDown();
	testEnded();
	testStarted("test_37_for_peek_a_character_in_stack");
	setup();
		test_37_for_peek_a_character_in_stack();
	tearDown();
	testEnded();
	testStarted("test_38_for_peek_two_character_in_stack");
	setup();
		test_38_for_peek_two_character_in_stack();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}
