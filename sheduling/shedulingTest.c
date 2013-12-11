#include "testUtils.h"
#include "sheduling.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_1_add_one_process(){
	int result;
	List* l = create();
	Process p = {1,20};
	result = insert(l, 1, &p); 
	ASSERT(result == 1);
	ASSERT(l->head->data == &p);
	ASSERT(l->numberOfElements == 1);
}


void test_1_add_two_process_and_get_time(){
	int result;
	List* l = create();
	Process p1 = {1,20};
	Process p2 = {2,40};
	result = insert(l, 1, &p1); 
	result = insert(l, 1, &p2); 
	ASSERT(result == 1);
	ASSERT(l->head->data == &p2);
	ASSERT(l->numberOfElements == 2);
	ASSERT(getTime((Process*)l->head->data) == 40);
}

