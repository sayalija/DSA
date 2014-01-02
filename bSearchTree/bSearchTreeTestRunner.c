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

	testStarted("test_to_insert_rootNode_in_tree");
	setup();
		test_to_insert_rootNode_in_tree();
	tearDown();
	testEnded();
	testStarted("test_to_inserting_same_value_as_of_root_should_fail");
	setup();
		test_to_inserting_same_value_as_of_root_should_fail();
	tearDown();
	testEnded();
	testStarted("test_to_insert_two_nodes_in_tree");
	setup();
		test_to_insert_two_nodes_in_tree();
	tearDown();
	testEnded();
	testStarted("test_to_insert_four_nodes_in_tree");
	setup();
		test_to_insert_four_nodes_in_tree();
	tearDown();
	testEnded();
	testStarted("test_to_get_the_children_nodes_of_root");
	setup();
		test_to_get_the_children_nodes_of_root();
	tearDown();
	testEnded();
	testStarted("test_to_get_the_children_of_every_node_inserted");
	setup();
		test_to_get_the_children_of_every_node_inserted();
	tearDown();
	testEnded();
	testStarted("test_to_get_no_children_when_no_node_is_present");
	setup();
		test_to_get_no_children_when_no_node_is_present();
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
