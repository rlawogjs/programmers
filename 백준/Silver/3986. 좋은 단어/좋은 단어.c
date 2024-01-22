#include<stdio.h>

#include<string.h>

 

char Stack[100002];  

char input[100002];  

int top = -1;          

int sum = 0;        

void Push(char data){

    Stack[++top] = data;  

}

 

void Pop(){

    Stack[top] = '0';  

    top = top -1;

}

 

int main(void){

    

    

     int n;

    scanf("%d",&n); 

    for(int i = 0;i<n;i++){

     scanf("%s",input);   

        int len = strlen(input);   

        for(int q = 0;q<len;q++){   

            if(q == 0){           

                Push(input[q]);  

            }

            else{

            if(input[q] == Stack[top]){    

                Pop();

            }

            else if(input[q] !=Stack[top]){

                Push(input[q]);    

            }

        }

        

        

    }

        if(top == -1){    

            sum = sum + 1;

        }

        top = -1; 

        for(int h = 0;h<len;h++){   

            Stack[h] = '0';    

        }

        

        

    }

    printf("%d",sum);   

 

}