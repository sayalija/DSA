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

	testStarted("test_for_create_a_new_process");
	setup();
		test_for_create_a_new_process();
	tearDown();
	testEnded();
	testStarted("test_for_adding_front_process");
	setup();
		test_for_adding_front_process();
	tearDown();
	testEnded();
	testStarted("test_for_adding_process_that_have_high_priority_rather_than_first");
	setup();
		test_for_adding_process_that_have_high_priority_rather_than_first();
	tearDown();
	testEnded();
	testStarted("test_remove_first_and_only_process");
	setup();
		test_remove_first_and_only_process();
	tearDown();
	testEnded();
	testStarted("test_remove_processes_in_middle");
	setup();
		test_remove_processes_in_middle();
	tearDown();
	testEnded();
	testStarted("test_remove_last_process");
	setup();
		test_remove_last_process();
	tearDown();
	testEnded();
	testStarted("test_remove_first_in_many");
	setup();
		test_remove_first_in_many();
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
