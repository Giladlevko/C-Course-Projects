#include <stdio.h>
// Merge Sorting when the array size is a power of two

void print_array(int how_many,int data[],char *str){
	int i;
	printf("%s",str);

	for (i = 0; i < how_many; i++){
		printf("%d\t",data[i]);
	}
}


void merge(int a[],int b[],int c[],int a_size, int b_size){
	int indx_a = 0, indx_b = 0 , indx_c = 0;
	while (indx_a < a_size && indx_b < b_size){
		if (a[indx_a] < b[indx_b]){
			c[indx_c++] = a[indx_a++];
		}
		else{
			c[indx_c++] = b[indx_b++];
		}
	}
	while (indx_a < a_size){
		c[indx_c++] = a[indx_a++];
	}
	while (indx_b < b_size){
		c[indx_c++] = b[indx_b++];
	}
}

// a power of two
void merge_sort( int key[], int how_many){
	int indx,num_keys;
	int new_arr[how_many];

	for (num_keys = 1; num_keys < how_many; num_keys *= 2){
		for(indx = 0; indx < how_many - num_keys; indx += 2*num_keys){
			merge(key+indx, key+indx + num_keys, new_arr+indx, num_keys,num_keys);// the arr + x means it will start reading it at index x 
											      // and also remember that it will read it until the size it was passed with
											      // because of how merge is set up 
		}

		for (indx = 0; indx < how_many; indx++){
			key[indx] = new_arr[indx];
		}
	
		print_array(how_many,new_arr,"\n");
	}
	
}

int main(){
	const int SIZE = 8;
	int grades[8] = {98,95,97,76,48,43,24,100};
	print_array(SIZE,grades,"my grades\n");
	merge_sort(grades,SIZE);
	print_array(SIZE,grades,"sorted\n");
	return 0;
}

