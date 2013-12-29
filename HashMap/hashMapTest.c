#include "testUtils.h"
#include "hashMap.h"
#include <string.h>
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

typedef struct{
	int id;
	char* name;
} Emp;

Emp emp1 = {1,"Sayali"};
Emp emp2 = {2,"Gauri"};
Emp emp3 = {3,"Aarti"};


int getHashCode(void* key){
	return *(int*)key;
}

int compareInt(void* element1, void* element2){
	return *(int*)element1 == *(int*)element2;
}

void test_get_element_from_hashmap(){
    HashMap map = createHashMap(getHashCode,compareInt,10);
	ASSERT(NULL == get(&map,&emp1.id));
}

void test_for_put_first_element_in_list(){
	HashMap map = createHashMap(getHashCode,compareInt,10);
	ASSERT(1 == put(&map, &emp1.id,emp1.name));  
	ASSERT(0 == strcmp(emp1.name,get(&map,&emp1.id)));
}

void test_for_put_two_elements_in_the_list(){
    HashMap map = createHashMap(getHashCode,compareInt,10);
    put(&map,&emp1.id,emp1.name);
    put(&map,&emp2.id,emp2.name);
    ASSERT(0 == strcmp(emp1.name,get(&map,&emp1.id)));
    ASSERT(0 == strcmp(emp2.name,get(&map,&emp2.id)));
};

void test_putting_same_key_two_times_will_overwrite_value(){
    HashMap map = createHashMap(getHashCode,compareInt,10);
    put(&map,&emp3.id,emp2.name);
    put(&map,&emp3.id,emp3.name);
    ASSERT(0 == strcmp(emp3.name,get(&map,&emp3.id)));
    ASSERT(0 != strcmp(emp2.name,get(&map,&emp3.id)));
};

void test_to_put_value_in_NULL_hashmap(){
    ASSERT(0 == put(NULL,&emp3.id,emp3.name));
};

void test_to_put_value_in_hashmap_with_NULL_key(){
    HashMap map = createHashMap(getHashCode,compareInt,10);
    ASSERT(0 == put(&map,NULL,emp3.name));
};

void test_to_put_value_in_hashmap_with_NULL_value(){
    HashMap map = createHashMap(getHashCode,compareInt,10);
    ASSERT(0 == put(&map,&emp3.id,NULL));
};

void test_to_trying_to_get_value_from_NULL_hashmap(){
    HashMap map = createHashMap(getHashCode,compareInt,10);
    ASSERT(0 == get(NULL,&emp3.id));
};

void test_to_trying_to_get_value_from_hashmap_with_NULL_key(){
    HashMap map = createHashMap(getHashCode,compareInt,10);
    ASSERT(0 == get(&map,NULL));
};

void test_for_removing_element_from_map(){
    HashMap map = createHashMap(getHashCode,compareInt,10);
    put(&map,&emp1.id,emp1.name);
    ASSERT(1 == removeHashElement(&map,&emp1.id));
    ASSERT(NULL == get(&map,&emp1.id));
};