//Program: Rational Numbers Processing
//Name: Mr.Lad
//Date 4/23/2026
//Description:
// Reads rational numbers from a file, stores them in an array of structs,
// computes their sum and average using rational arithmetic functions,
// and writes the results to an output file.
//
//Algorithm:
// 1. Open input and output files
// 2. Read number of rationals
// 3. Read numerator/denominator pairs into array
// 4. Compute sum using add_rationals
// 5. Compute average using divide_rationals
// 6. Write results to output file
// 7. Close files

#include <stdio.h>
#include <stdlib.h>

//Declares the rational struct 
//containing numerator and denominator
typedef struct rational {int num; int denom;} rational;


//Name: read_rationals_amount
//Input: 
// FILE *fptr - pointer to input file
// int *amount - pointer to integer where amount will be stored
//Output: none
//Description: 
// Reads the number of rational numbers from the file
// and stores it in the variable pointed to by amount.
void read_rationals_amount(FILE *fptr,int* amount){
    fscanf(fptr,"%d",amount);
    printf("amount is: %d\n\n",*amount);
}


//Name: print_rational_data
//Input: 
// rational data[] - array of rational numbers
// int size - number of elements in the array
//Output: none
//Description: 
// Prints all rational numbers in the array,
// displaying their numerators and denominators.
void print_rational_data(rational data[], int size){
    int i;
    for(i = 0 ; i < size; i++){
        printf("Rational Number %d:\n",i+1);
        printf("Numerator is %d\n",data[i].num);
        printf("Denominator is %d\n",data[i].denom);
        printf("\n\n");
    }
}


//Name: read_rationals_data
//Input: 
// FILE *fptr - pointer to input file
// int size - number of rational numbers to read
// rational data[] - array to store the rationals
//Output: none
//Description:
// Reads pairs of integers from the file and stores them
// as rational numbers in the data array.
void read_rationals_data(FILE *fptr,int size,rational data[]){
    int i;
    for (i = 0; i<size; i++){
        fscanf(fptr,"%d",&data[i].num);
        fscanf(fptr,"%d",&data[i].denom);
    }
    print_rational_data(data,size);
}


//Name: add_rationals
//Input: 
// rational a - first rational number
// rational b - second rational number
//Output: rational result of a + b
//Description: 
// Adds two rational numbers using the formula
// (a/b) + (c/d) = (ad + bc) / bd
rational add_rationals(rational a,rational b){
    rational result = {0,0};
    result.num = (a.num*b.denom + b.num*a.denom);
    result.denom = (a.denom*b.denom);
    return result;
}


//Name: multiply_rationals
//Input: 
// rational a - first rational number
// rational b - second rational number
//Output: 
// rational result of a * b
//Description: 
// Multiplies two rational numbers using the formula
// (a/b) * (c/d) = (ac) / (bd)
rational multiply_rationals(rational a, rational b){
    rational result = {0,0};
    result.num = (a.num*b.num);
    result.denom = (a.denom*b.denom);
    return result;
}


//Name: divide_rationals
//Input: 
// rational a - first rational number
// rational b - second rational number
//Output: rational result of a / b
//Description: 
// Divides two rational numbers using the formula
// (a/b) / (c/d) = (a * d) / (b * c)
rational divide_rationals(rational a, rational b){
    rational result = {0,0};
    result.num = (a.num*b.denom);
    result.denom = (b.num*a.denom);
    return result;
}


//Name: subtract_rationals
//Input: 
// rational a - first rational number
// rational b - second rational number
//Output: rational result of a - b
//Description: 
// Subtracts two rational numbers using the formula
// (a/b) - (c/d) = (ad - bc) / bd
rational subtract_rationals(rational a,rational b){
    rational result = {0,0};
    result.num = (a.num*b.denom - b.num*a.denom);
    result.denom = (a.denom*b.denom);
    return result;
}


//Name: sum_rationals
//Input: 
// rational data[] - array of rational numbers
// int size - number of elements in the array
// FILE *out_fptr - pointer to output file
//Output: none
//Description: 
// Computes the sum of all rational numbers in the array,
// calculates the average, and writes both results to the output file.
void sum_rationals(rational data[],int size,FILE *out_fptr){
    rational result = {0,1};
    int i;
    for (i = 0; i < size; i++){
        result = add_rationals(result,data[i]);
    }
    rational rationals_size = {size,1};
    printf("sum is %d/%d\n\n",result.num,result.denom);
    rational avg = divide_rationals(result,rationals_size);
    printf("average is %d/%d\n\n",avg.num,avg.denom);

    fprintf(out_fptr,"SUM: %d/%d\n",result.num,result.denom);
    fprintf(out_fptr,"AVERAGE: %d/%d\n",avg.num,avg.denom);
}


//Name: test_operations
//Input: rational data[] - array of rational numbers
//Output: none
//Description: 
// Demonstrates the use of arithmetic functions (add, subtract,
// multiply, divide) on the first two elements of the array.
void test_operations(rational data[]){
    rational add = add_rationals(data[0],data[1]);
    printf("additon is %d/%d\n\n",add.num,add.denom);

    rational mult = multiply_rationals(data[0],data[1]);
    printf("multipication is %d/%d\n\n",mult.num,mult.denom);

    rational divide = divide_rationals(data[0],data[1]);
    printf("division is %d/%d\n\n",divide.num,divide.denom);

    rational sub = subtract_rationals(data[0],data[1]);
    printf("subtraction is %d/%d\n\n",sub.num,sub.denom);
}


//Name: main
//Input: none
//Output: returns 0
//Description: 
// Opens input and output files, reads rational numbers from the file,
// processes them, computes sum and average, writes results to file,
// and closes all files.
int main(){
    FILE *in_fptr;
    in_fptr = fopen("rational_input.txt","r");

    FILE *out_fptr;
    out_fptr = fopen("rational_output.txt","w");

    int amount;
    read_rationals_amount(in_fptr,&amount);

    rational data[amount];
    read_rationals_data(in_fptr,amount,data);

    sum_rationals(data,amount,out_fptr);

    test_operations(data);

    fclose(in_fptr);
    fclose(out_fptr);

    return 0;
}