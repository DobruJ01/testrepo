//============================================================================
// Name        : benchmark.cpp
// Author      : jdobrusk
// Version     : 1
// Description : benches ternary, if chain, case, and function pointers
//============================================================================

#include <iostream>
#include <cstdio>
#include <ctime>
#include <cmath>
#define TESTLEN 100000000

void calc();
void testCase();
void testIfChain();
void testTernary();
void testPointers();

int main() {
	for(int i=9;i<12;++i);
	std::string names[5] = {""," Thousand"," Million"," Billion"," Trillion"};
	int num = TESTLEN;
	int name = 0;
	while(num/1000){
		++name;
		num/=1000;
	}

	std::clock_t start;
	double duration;

	start = clock();

	if(name <= 4)
		std::cout << "Testing " << num << names[name] << " Iterations.."<< std::endl;
	else
		std::cout << "Testing too many iterations\n" << std::endl;
	//Case statement
	start = clock();
	testCase();
	duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
	printf("Case Statement: %2.20lf\n",duration);

	//if chain
	start = clock();
	testIfChain();
	duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
	printf("If Chain: %2.20lf\n",duration);

	//ternary
	start = clock();
	testTernary();
	duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
	printf("Ternary: %2.20lf\n",duration);

	//direct with pointers
	start = clock();
	testPointers();
	duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
	printf("Function pointers: %2.20lf\n",duration);

	return 0;
}
void testCase(){
	for(int i=0;i<TESTLEN;++i){
		switch(i%10){
		case 0:
			calc();
			break;
		case 1:
			calc();
			break;
		case 2:
			calc();
			break;
		case 3:
			calc();
			break;
		case 4:
			calc();
			break;
		case 5:
			calc();
			break;
		case 6:
			calc();
			break;
		case 7:
			calc();
			break;
		case 8:
			calc();
			break;
		case 9:
			calc();
			break;
		default:
			calc();
			break;
		}
	}
}
void testIfChain(){
	for(int i=0;i<TESTLEN;++i){
		int test = i%10;
		if(test == 0){
			calc();
		}else if(test == 1){
			calc();
		}else if(test == 2){
			calc();
		}else if (test == 3){
			calc();
		}else if (test == 4){
			calc();
		}else if (test == 5){
			calc();
		}else if (test == 6){
			calc();
		}else if (test == 7){
			calc();
		}else if (test == 8){
			calc();
		}else if (test == 9){
			calc();
		}else{
			calc();
		}
	}
}
void testTernary(){
	for(int i=0;i<TESTLEN;++i){
		int test = i%10;
		test == 0 ? calc() :
		test == 1 ? calc() :
		test == 2 ? calc() :
		test == 3 ? calc() :
		test == 4 ? calc() :
		test == 5 ? calc() :
		test == 6 ? calc() :
		test == 7 ? calc() :
		test == 8 ? calc() :
		test == 9 ? calc() :
		calc();
	}
}
void testPointers(){
	static void (*options[10])() = {&calc,&calc,&calc,&calc,&calc,&calc,&calc,&calc,&calc,&calc};

	/*Redirect call to appropriate function*/
	for(unsigned int i=0;i<TESTLEN;++i)
		options[i%10]();
}
void calc(){
	for(int i=0;i<5;++i){
		int sum = i;
	}
}
