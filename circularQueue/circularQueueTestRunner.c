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

	testStarted("test_1_for_creating_a_queue_for_integer_type");
	setup();
		test_1_for_creating_a_queue_for_integer_type();
	tearDown();
	testEnded();
	testStarted("test_2_for_creating_a_queue_for_float_type");
	setup();
		test_2_for_creating_a_queue_for_float_type();
	tearDown();
	testEnded();
	testStarted("test_3_for_creating_a_queue_for_double_type");
	setup();
		test_3_for_creating_a_queue_for_double_type();
	tearDown();
	testEnded();
	testStarted("test_4_for_creating_a_queue_for_character_type");
	setup();
		test_4_for_creating_a_queue_for_character_type();
	tearDown();
	testEnded();
	testStarted("test_5_for_creating_a_queue_for_string_type");
	setup();
		test_5_for_creating_a_queue_for_string_type();
	tearDown();
	testEnded();
	testStarted("test_6_for_enqueue_a_integer_element_in_queue");
	setup();
		test_6_for_enqueue_a_integer_element_in_queue();
	tearDown();
	testEnded();
	testStarted("test_7_for_enqueue_two_integer_element_in_queue");
	setup();
		test_7_for_enqueue_two_integer_element_in_queue();
	tearDown();
	testEnded();
	testStarted("test_8_for_queue_a_string_element_in_queue");
	setup();
		test_8_for_queue_a_string_element_in_queue();
	tearDown();
	testEnded();
	testStarted("test_9_for_queue_two_string_element_in_queue");
	setup();
		test_9_for_queue_two_string_element_in_queue();
	tearDown();
	testEnded();
	testStarted("test_10_for_queue_a_float_element_in_queue");
	setup();
		test_10_for_queue_a_float_element_in_queue();
	tearDown();
	testEnded();
	testStarted("test_11_for_queue_two_float_element_in_queue");
	setup();
		test_11_for_queue_two_float_element_in_queue();
	tearDown();
	testEnded();
	testStarted("test_12_for_queue_a_double_element_in_queue");
	setup();
		test_12_for_queue_a_double_element_in_queue();
	tearDown();
	testEnded();
	testStarted("test_13_for_queue_two_double_element_in_queue");
	setup();
		test_13_for_queue_two_double_element_in_queue();
	tearDown();
	testEnded();
	testStarted("test_14_for_queue_a_character_element_in_queue");
	setup();
		test_14_for_queue_a_character_element_in_queue();
	tearDown();
	testEnded();
	testStarted("test_15_for_queue_two_character_element_in_queue");
	setup();
		test_15_for_queue_two_character_element_in_queue();
	tearDown();
	testEnded();
	testStarted("test_16_for_dequeue_a_interger_from_queue");
	setup();
		test_16_for_dequeue_a_interger_from_queue();
	tearDown();
	testEnded();
	testStarted("test_17_for_dequeue_two_interger_in_queue");
	setup();
		test_17_for_dequeue_two_interger_in_queue();
	tearDown();
	testEnded();
	testStarted("test_18_for_dequeue_a_float_in_queue");
	setup();
		test_18_for_dequeue_a_float_in_queue();
	tearDown();
	testEnded();
	testStarted("test_19_for_dequeue_two_float_in_queue");
	setup();
		test_19_for_dequeue_two_float_in_queue();
	tearDown();
	testEnded();
	testStarted("test_20_for_dequeue_a_double_in_queue");
	setup();
		test_20_for_dequeue_a_double_in_queue();
	tearDown();
	testEnded();
	testStarted("test_21_for_dequeue_two_double_in_queue");
	setup();
		test_21_for_dequeue_two_double_in_queue();
	tearDown();
	testEnded();
	testStarted("test_22_for_dequeue_a_character_in_queue");
	setup();
		test_22_for_dequeue_a_character_in_queue();
	tearDown();
	testEnded();
	testStarted("test_23_for_dequeue_two_character_in_queue");
	setup();
		test_23_for_dequeue_two_character_in_queue();
	tearDown();
	testEnded();
	testStarted("test_24_for_dequeue_a_string_in_queue");
	setup();
		test_24_for_dequeue_a_string_in_queue();
	tearDown();
	testEnded();
	testStarted("test_27_for_dequeue_two_string_in_queue");
	setup();
		test_27_for_dequeue_two_string_in_queue();
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
