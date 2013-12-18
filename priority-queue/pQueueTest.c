#include "testUtils.h"
#include "pQueue.h"
#include "../linkedList/linkedList.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_1_for_create_priority_queue(){
	void* queue = createQueue();
	int item = 3;
	int res = enqueue(queue, &item, 2);
	ASSERT(res == 1);
	ASSERT(*(int*)dequeue(queue) == item);
}
