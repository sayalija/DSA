#include "testUtils.h"
#include "hashMap.h"

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

void test_putting_first_element_in_list(){
    HashMap map = createHashMap(getHashCode,compareInt,10);
	ASSERT(1 == put(&map, &emp1.id, &emp1.name));    
}