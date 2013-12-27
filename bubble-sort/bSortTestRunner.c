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

	testStarted("test_1_for_sorting_sorted_integer_values");
	setup();
		test_1_for_sorting_sorted_integer_values();
	tearDown();
	testEnded();
	testStarted("test_2_for_sorting_unsorted_integer_values");
	setup();
		test_2_for_sorting_unsorted_integer_values();
	tearDown();
	testEnded();
	testStarted("test_3_for_sorting_unsorted_float_values");
	setup();
		test_3_for_sorting_unsorted_float_values();
	tearDown();
	testEnded();
	testStarted("test_4_for_sorting_sorted_float_values");
	setup();
		test_4_for_sorting_sorted_float_values();
	tearDown();
	testEnded();
	testStarted("test_5_for_sorting_unsorted_double_values");
	setup();
		test_5_for_sorting_unsorted_double_values();
	tearDown();
	testEnded();
	testStarted("test_6_for_sorting_sorted_double_values");
	setup();
		test_6_for_sorting_sorted_double_values();
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
