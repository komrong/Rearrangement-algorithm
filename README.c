//Rearrangement-algorithm -- Designed to rearrange the numbers is a specified order


/*
Let n ≥ 2 be a natural number. Find a way to assign natural
numbers to the vertices of a regular 2^n-gon such that the following
conditions are satisfied:
(1) only digits 1 and 2 are used;
(2) each number consists of exactly n digits;
(3) different numbers are assigned to different vertices;
(4) the numbers assigned to two neighboring vertices differ at exactly one
digit.
*/

/*
The algorithm is not efficient though. Randomly order numbers to match above conditions.
*/

#include <stdio.h>
#include <math.h>
#include <time.h>

int check_num(int num);
int adj(int a, int b);
int factorial(int a);
int count_dig(int a);


int main(void){
	int n = 3;
	int SIZE = pow(2,n);
    int pol[SIZE];
    int numbers[SIZE];
    int i, j, k = 0;
    int start = 0;
    
    
    for(i = n-1; i >=0; i--){
    	start += 1*pow(10, i);
    }
    
    for(i = start; i <= 2*start; i++){
    	if(check_num(i) == 1){
    		numbers[k] = i;
    		k++;
    	}
    }
     
    int copy[SIZE];
    for(i = 0; i < SIZE; i++){
   		copy[i] = numbers[i];
    }
    
    int ran;
    int test = 0;
    int count1 = 0;
    
    while(1 > 0){
    
    	srand(time(NULL));
    
    	for(i = 0; i < SIZE; i++){
    		do{
    			ran = rand()%SIZE;
    		}while(copy[ran] == 0);
    		pol[i] = copy[ran];
    		copy[ran] = 0;
    	}
    	
    	count1++;
    	
    	for(i = 0; i < SIZE; i++){
    		printf("%d ", pol[i]);
    	}
    	printf("\n");
    	
    	for(i = 0; i < SIZE; i++){
    		if(i == SIZE - 1){
    			if(adj(pol[i], pol[0]) == -1){
    				test++;
    			}
    		}
    		else{
    			if(adj(pol[i], pol[i+1]) == -1){
    				test++;
    			}
    		}
    	}
    
    	if(test == 0){
    		break;
    	}
    	
    	for(i = 0; i < SIZE; i++){
   			copy[i] = numbers[i];
    	}
    	
    	test = 0;
    }
    
    printf("%d ", count1);
    
	return 0;
}

int adj(int a, int b){
	int t = abs(a-b);
	int num_dig = count_dig(t);
	int temp;
	int ones = 0;
	int zeros = 0;
	int total;
	
	while(t != 0){
		temp = t % 10;
		if(temp == 1){
			ones++;
		}
		else if(temp == 0){
			zeros++;
		}
		t = t / 10;
	}
	
	total = ones + zeros;
	if(ones == 1 && total == num_dig){
		return 1;
	}
	else{
		return -1;
	}
}

int factorial(int a){
	int temp = 1;
	int i;
	
	for(i = 1; i <= a; i++){
		temp = temp * i;
	}
	return temp;
}

int check_num(int num){
	int t;
	while(num != 0){
		t = num % 10;
		if(t == 1 || t == 2){
			num = num / 10;
		}
		else{
			return -1;
		}
	}
	
	return 1;
}

int count_dig(int a){
	int count = 0;
	while(a != 0){
		count++;
		a = a / 10;
	}
	return count;
}
