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

	testStarted("test_1_create_linledList_object");
	setup();
		test_1_create_linledList_object();
	tearDown();
	testEnded();
	testStarted("test_2_insert_a_node_of_integer_type_at_first");
	setup();
		test_2_insert_a_node_of_integer_type_at_first();
	tearDown();
	testEnded();
	testStarted("test_3_insert_a_node_of_integer_type_at_last");
	setup();
		test_3_insert_a_node_of_integer_type_at_last();
	tearDown();
	testEnded();
	testStarted("test_4_insert_a_node_of_float_type_at_first");
	setup();
		test_4_insert_a_node_of_float_type_at_first();
	tearDown();
	testEnded();
	testStarted("test_5_insert_a_node_of_float_type_at_last");
	setup();
		test_5_insert_a_node_of_float_type_at_last();
	tearDown();
	testEnded();
	testStarted("test_6_insert_a_node_of_double_type_at_first");
	setup();
		test_6_insert_a_node_of_double_type_at_first();
	tearDown();
	testEnded();
	testStarted("test_7_insert_a_node_of_double_type_at_last");
	setup();
		test_7_insert_a_node_of_double_type_at_last();
	tearDown();
	testEnded();
	testStarted("test_8_insert_a_node_of_char_type_at_first");
	setup();
		test_8_insert_a_node_of_char_type_at_first();
	tearDown();
	testEnded();
	testStarted("test_9_to_insert_in_middle");
	setup();
		test_9_to_insert_in_middle();
	tearDown();
	testEnded();
	testStarted("test_10_to_delete_first_node");
	setup();
		test_10_to_delete_first_node();
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
