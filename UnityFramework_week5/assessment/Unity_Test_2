#To find leap_year
//main.c
#include "leapyear.h"
#include "stdio.h"
#include "unity.h"

void setUp(){}
void tearDown(){}

void test_leap(){
    TEST_ASSERT_EQUAL(1,is_leapyear(2000));
    }
void test_nonleap(){
  TEST_ASSERT_NOT_EQUAL(1,is_leapyear(1999));
}

int main(){
    UNITY_BEGIN();
    RUN_TEST(test_leap);
    RUN_TEST(test_nonleap);
    return UNITY_END();

    
}

//leapyear.c
#include "leapyear.h"
#include "unity.h"

int is_leapyear(int yy)
{
   if((yy%400==0)||(yy%4==0 && yy%100!=0))
   return 1;
   else 
   return 0;
}

//leapyear.h
#ifndef __LEAPYEAR__H
#define __LEAPYEAR__H
int is_leapyear(int yy);

#endif

//Makefile
object.0: main.c leapyear.c unity.c
	gcc $^ -c
out: main.o leapyear.o unity.o
	gcc $^ -o out.exe
run: out
	./out.exe
clean:
	rm -f *.o*.exe