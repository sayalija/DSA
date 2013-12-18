#include "testUtils.h"
#include "stack.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_1_for_creating_a_stack_and_push_one_element(){
	int element;
	Stack* s = createStack();
	push(s, &element);
	ASSERT(*(int*)(peek(s)) == element);
	disposeStack(s);
}

void test_2_for_creating_a_stack_and_push_multiple_elements(){
	float first = 3.3f, second = 4.4f, third = 5.5f;
	Stack* s = createStack();
	push(s, &first);
	push(s, &second);
	push(s, &third);
	ASSERT(*(float*)(peek(s)) == 5.5f);
	disposeStack(s);
}

void test_3_for_pop_an_element(){
	int element;
	Stack* s = createStack();
	push(s, &element);
	ASSERT(*(int*)(pop(s)) == element);
	disposeStack(s);
}

void test_4_for_push_pop_on_multiple_doubleType_elements(){
	float first = 3.3f, second = 4.4f, third = 5.5f;
	Stack* s = createStack();
	push(s, &first);
	ASSERT(*(float*)(pop(s)) == first);
	push(s, &second);
	ASSERT(*(float*)(pop(s)) == second);
	push(s, &third);
	ASSERT(*(float*)(pop(s)) == third);
	disposeStack(s);
}