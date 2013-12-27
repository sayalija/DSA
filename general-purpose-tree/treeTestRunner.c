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

	testStarted("test_1_to_create_tree_and_insert_root");
	setup();
		test_1_to_create_tree_and_insert_root();
	tearDown();
	testEnded();
	testStarted("test_2_to_create_tree_and_insert_node_under_root");
	setup();
		test_2_to_create_tree_and_insert_node_under_root();
	tearDown();
	testEnded();
	testStarted("test_3_to_insert_child_node_to_child_of_root");
	setup();
		test_3_to_insert_child_node_to_child_of_root();
	tearDown();
	testEnded();
	testStarted("test_4_to_serach_data_in_tree");
	setup();
		test_4_to_serach_data_in_tree();
	tearDown();
	testEnded();
	testStarted("test_5_to_serach_unavailable_data_in_tree");
	setup();
		test_5_to_serach_unavailable_data_in_tree();
	tearDown();
	testEnded();
	testStarted("test_6_to_delete_data_from_tree");
	setup();
		test_6_to_delete_data_from_tree();
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
