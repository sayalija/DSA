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

	testStarted("test_1_for_creating_a_stack_and_push_one_element");
	setup();
		test_1_for_creating_a_stack_and_push_one_element();
	tearDown();
	testEnded();
	testStarted("test_2_for_push_3_elements");
	setup();
		test_2_for_push_3_elements();
	tearDown();
	testEnded();
	testStarted("test_3_for_testing_peek_functionality");
	setup();
		test_3_for_testing_peek_functionality();
	tearDown();
	testEnded();
	testStarted("test_4_for_testing_push_peek_create_using_float_type");
	setup();
		test_4_for_testing_push_peek_create_using_float_type();
	tearDown();
	testEnded();
	testStarted("test_5_for_pushing_element_in_stack_more_than_maxSize");
	setup();
		test_5_for_pushing_element_in_stack_more_than_maxSize();
	tearDown();
	testEnded();
	testStarted("test_6_for_push_and_pop_a_element_from_stack");
	setup();
		test_6_for_push_and_pop_a_element_from_stack();
	tearDown();
	testEnded();
	testStarted("test_7_for_push_and_pop_2_float_elements_from_stack");
	setup();
		test_7_for_push_and_pop_2_float_elements_from_stack();
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
