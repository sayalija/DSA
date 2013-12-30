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

	testStarted("test_1_get_element_from_hashmap");
	setup();
		test_1_get_element_from_hashmap();
	tearDown();
	testEnded();
	testStarted("test_2_for_put_first_element_in_list");
	setup();
		test_2_for_put_first_element_in_list();
	tearDown();
	testEnded();
	testStarted("test_3_for_put_two_elements_in_the_list");
	setup();
		test_3_for_put_two_elements_in_the_list();
	tearDown();
	testEnded();
	testStarted("test_4_putting_same_key_two_times_will_overwrite_value");
	setup();
		test_4_putting_same_key_two_times_will_overwrite_value();
	tearDown();
	testEnded();
	testStarted("test_5_to_put_value_in_NULL_hashmap");
	setup();
		test_5_to_put_value_in_NULL_hashmap();
	tearDown();
	testEnded();
	testStarted("test_6_to_put_value_in_hashmap_with_NULL_key");
	setup();
		test_6_to_put_value_in_hashmap_with_NULL_key();
	tearDown();
	testEnded();
	testStarted("test_7_to_put_value_in_hashmap_with_NULL_value");
	setup();
		test_7_to_put_value_in_hashmap_with_NULL_value();
	tearDown();
	testEnded();
	testStarted("test_8_to_trying_to_get_value_from_NULL_hashmap");
	setup();
		test_8_to_trying_to_get_value_from_NULL_hashmap();
	tearDown();
	testEnded();
	testStarted("test_9_to_trying_to_get_value_from_hashmap_with_NULL_key");
	setup();
		test_9_to_trying_to_get_value_from_hashmap_with_NULL_key();
	tearDown();
	testEnded();
	testStarted("test_2_for_removing_element_from_map");
	setup();
		test_2_for_removing_element_from_map();
	tearDown();
	testEnded();
	testStarted("test_11_to_remove_element_from_NULL_map");
	setup();
		test_11_to_remove_element_from_NULL_map();
	tearDown();
	testEnded();
	testStarted("test_12_to_remove_NULL_element_from_map");
	setup();
		test_12_to_remove_NULL_element_from_map();
	tearDown();
	testEnded();
	testStarted("test_13_for_removing_element_from_map_which_have_two_elements");
	setup();
		test_13_for_removing_element_from_map_which_have_two_elements();
	tearDown();
	testEnded();
	testStarted("test_14_get_all_keys_from_hash");
	setup();
		test_14_get_all_keys_from_hash();
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
