#include<stdio.h>
#include <stdbool.h>
#include<string.h>

bool isPalindrome(char * s) {
    int newSize =0;
    char nS[strlen(s)+1];
        for(int i=0;s[i]!='\0';i++) {
            if(s[i]>=65 && s[i]<=90){
                nS[newSize] = s[i] + 32;
                newSize++;
            }
            else if(s[i]>=97 && s[i]<=122){
                nS[newSize] = s[i];
                newSize++;
            }
        }
        nS[newSize] = '\0';
        for(int i=0;nS[i]!='\0';i++) {
            if(nS[i]!=nS[newSize -i -1])
                return false;
        }
        return true;
}
int main(){
    char s[] = "0P";
    if(isPalindrome(s))
        printf("true\n");
    else printf("false\n");
    return 0;
}