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

	testStarted("test_1_insert_element");
	setup();
		test_1_insert_element();
	tearDown();
	testEnded();
	testStarted("test_2_insert_multiple_elements");
	setup();
		test_2_insert_multiple_elements();
	tearDown();
	testEnded();
	testStarted("test_3_interns_grows_beyond_capacity");
	setup();
		test_3_interns_grows_beyond_capacity();
	tearDown();
	testEnded();
	testStarted("test_4_should_not_insert_at_index_beyond_length");
	setup();
		test_4_should_not_insert_at_index_beyond_length();
	tearDown();
	testEnded();
	testStarted("test_5_should_not_insert_at_negative_index");
	setup();
		test_5_should_not_insert_at_negative_index();
	tearDown();
	testEnded();
	testStarted("test_6_insert_at_middle_should_shift_the_elements");
	setup();
		test_6_insert_at_middle_should_shift_the_elements();
	tearDown();
	testEnded();
	testStarted("test_7_should_not_insert_when_list_is_null");
	setup();
		test_7_should_not_insert_when_list_is_null();
	tearDown();
	testEnded();
	testStarted("test_8_add_a_element_to_array");
	setup();
		test_8_add_a_element_to_array();
	tearDown();
	testEnded();
	testStarted("test_9_to_search_a_element");
	setup();
		test_9_to_search_a_element();
	tearDown();
	testEnded();
	testStarted("test_10_to_search_a_element_which_is_not_present");
	setup();
		test_10_to_search_a_element_which_is_not_present();
	tearDown();
	testEnded();
	testStarted("test_11_remove_a_element");
	setup();
		test_11_remove_a_element();
	tearDown();
	testEnded();
	testStarted("test_12_try_to_remove_a_element_which_is_not_present");
	setup();
		test_12_try_to_remove_a_element_which_is_not_present();
	tearDown();
	testEnded();
	testStarted("test_iterator_tells_that_next_data_is_present");
	setup();
		test_iterator_tells_that_next_data_is_present();
	tearDown();
	testEnded();
	testStarted("test_iterator_tells_that_next_data_is_not_present");
	setup();
		test_iterator_tells_that_next_data_is_not_present();
	tearDown();
	testEnded();
	testStarted("test_iterator_gives_the_data_of_next_index");
	setup();
		test_iterator_gives_the_data_of_next_index();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void fixtureSetup(){}

void fixtureTearDown(){}
