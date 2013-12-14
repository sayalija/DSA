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

	testStarted("test_1_for_match_parantheses_of_simple_round_brackets");
	setup();
		test_1_for_match_parantheses_of_simple_round_brackets();
	tearDown();
	testEnded();
	testStarted("test_2_for_match_parantheses_of_simple_round_brackets_with_extra_opening_bracket");
	setup();
		test_2_for_match_parantheses_of_simple_round_brackets_with_extra_opening_bracket();
	tearDown();
	testEnded();
	testStarted("test_3_for_match_parantheses_of_simple_round_brackets_with_some_text");
	setup();
		test_3_for_match_parantheses_of_simple_round_brackets_with_some_text();
	tearDown();
	testEnded();
	testStarted("test_4_for_match_parantheses_of_couple_of_brackets_with_some_text");
	setup();
		test_4_for_match_parantheses_of_couple_of_brackets_with_some_text();
	tearDown();
	testEnded();
	testStarted("test_5_for_match_parantheses_of_one_closing_bracket");
	setup();
		test_5_for_match_parantheses_of_one_closing_bracket();
	tearDown();
	testEnded();
	testStarted("test_6_for_match_parantheses_of_no_brackets");
	setup();
		test_6_for_match_parantheses_of_no_brackets();
	tearDown();
	testEnded();
	testStarted("test_7_for_match_parantheses_of_empty_string");
	setup();
		test_7_for_match_parantheses_of_empty_string();
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
