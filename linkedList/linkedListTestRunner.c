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
	testStarted("test_2_insert_a_node_at_first_of_integer_type");
	setup();
		test_2_insert_a_node_at_first_of_integer_type();
	tearDown();
	testEnded();
	testStarted("test_3_insert_a_node_at_last_of_integer_type");
	setup();
		test_3_insert_a_node_at_last_of_integer_type();
	tearDown();
	testEnded();
	testStarted("test_4_insert_a_node_at_first_of_float_type");
	setup();
		test_4_insert_a_node_at_first_of_float_type();
	tearDown();
	testEnded();
	testStarted("test_5_insert_a_node_at_last_of_float_type");
	setup();
		test_5_insert_a_node_at_last_of_float_type();
	tearDown();
	testEnded();
	testStarted("test_6_insert_a_node_at_first_of_double_type");
	setup();
		test_6_insert_a_node_at_first_of_double_type();
	tearDown();
	testEnded();
	testStarted("test_7_insert_a_node_at_last_of_double_type");
	setup();
		test_7_insert_a_node_at_last_of_double_type();
	tearDown();
	testEnded();
	testStarted("test_8_insert_a_node_at_first_of_char_type");
	setup();
		test_8_insert_a_node_at_first_of_char_type();
	tearDown();
	testEnded();
	testStarted("test_9_to_insert");
	setup();
		test_9_to_insert();
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
