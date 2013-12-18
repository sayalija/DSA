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
	testStarted("test_2_for_creating_a_stack_and_push_multiple_elements");
	setup();
		test_2_for_creating_a_stack_and_push_multiple_elements();
	tearDown();
	testEnded();
	testStarted("test_3_for_pop_an_element");
	setup();
		test_3_for_pop_an_element();
	tearDown();
	testEnded();
	testStarted("test_4_for_push_pop_on_multiple_doubleType_elements");
	setup();
		test_4_for_push_pop_on_multiple_doubleType_elements();
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
