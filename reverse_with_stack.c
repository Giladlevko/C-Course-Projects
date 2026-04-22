#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_LEN 1000
#define EMPTY -1
#define FULL (MAX_LEN - 1)

typedef struct stack{char s[MAX_LEN]; int top;} stack;

void reset(stack *stk){stk -> top = EMPTY;}

void push(char c, stack *stk){
	stk -> top++;
	stk -> s[stk -> top] = c;
}

char pop(stack *stk){return(stk -> s[stk -> top--]);}
char top(const stack *stk){return(stk -> s[stk -> top]);}

int is_empty(const stack *stk){return(stk -> top == EMPTY);}

int is_full(const stack *stk){return(stk -> top == FULL);}

void reverse(int SIZE,char *str){
	stack stack_of_char;
	char str_back[SIZE];
	int i = 0;
	reset(&stack_of_char);
	printf("original is : %s\n",str);
	while (str[i] != '\0'){
		printf("%c\n",str[i]);
		push(str[i++],&stack_of_char);
	}
	i = 0;
	while(!is_empty(&stack_of_char) && i < SIZE){
		str_back[i++] = pop(&stack_of_char);
	}
	str_back[i] = '\0';
	printf("reverse is : %s\n",str_back);

	printf("\n\n");
}




int main(){
	printf("Enter the amount of characters in your string or more");
	int SIZE;
	scanf("%d",&SIZE);
	getwchar();
	printf("Enter String to have it reversed: ");
	char str[MAX_LEN];
	fgets(str,MAX_LEN,stdin);
	str[strcspn(str,"\n")] = '\0';
	reverse(SIZE,str);
	return 0;
}


