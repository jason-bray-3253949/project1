#include <stdio.h>


/* Caeser Cipher*/
/* Encryption Function required*/
//int encrypt(?arguments); k(key), ?string

int main(){
    
    char msg[26];  //?increase array size
    
    
    int key;
    
    printf("Enter a message to encrypt: ");
    
    // ?scanf("%s", msg);
    
    printf("Enter key: ")
    scanf("%d", &key);
    
    /* if to ensure key is not a negative number when used with the modulus operator, %, as
       the operator is not defined for a negative number */
    if(key < 0){           
        key = key + 26;
    }
    
    
    //loop: ?for, while
    //?switch or if needed
    
    //end loop
    
    printf("The encrypted message is: "); // ?output encoded message
    
    return 0;
}
