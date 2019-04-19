#include<stdio.h>
/* ROTATION CIPHER ENCRYPTION FUNCTION */
void rotencrypt(char *message, int key);

/* ROTATION CIPHER DECRYPTION FUNCTION */
void rotdecrypt(char *message, int key);

/*ROTATION CIPHER BRUTE FORCE ATTACK FUNCTION */
void brute(char *message);

/* SUBSTITUTION CIPHER ENCRYPTION FUNCTION */ 
void subencrypt(char *message, char *akey); 
 
/* SUBSTITUTION CIPHER DECRYPTION FUNCTION */
void subdecrypt(char *message, char *akey);
 
int main()
{
	char message[1000], akey[26];                                        //array to store message 
	int x, key;                     //x for program option menu, key for key, i for array
	
	printf("Enter a message: \n");      
	scanf("%[^\n]", message); 
	printf("What would you like to do with the message?\n");
	printf("1  Encrypt with a rotation cipher\n");
	printf("2  Decrypt a rotation cipher\n");
	printf("3  Decrypt a rotation cipher without key\n");
	printf("4  Encrypt with substitution cipher\n");
	printf("5  Decrypt a substitution cipher\n");
	printf("6  Decrypt a substitution cipher without key\n");
	scanf("%d", &x); 
	
	switch(x){
	    case 1: //Rotation cipher encryption with key 
	       printf("Enter key between 0 and 26: \n");
	       scanf("%d", &key);
	       rotencrypt(message, key);
	       break;
              
	    case 2://Rotation cipher decryption with key	
	       printf("Enter key between 0 and 26: \n");
	       scanf("%d", &key);
	       rotdecrypt(message, key);
	       break; 
	         
	    case 3: //rotation cipher without key: BRUTE FORCE
	    brute(message);
        break;
	    	       
	    case 4: //Substitution cipher encryption
        printf("Please enter the key alphabet without any spaces: \n");
	    scanf("%s", akey);
	    subencrypt(message, akey);
	    break;
	     
        case 5: //Substitution cipher decryption
        printf("Please enter the key alphabet without any spaces: \n");
        scanf("%s", akey);
        subdecrypt(message, akey);
        break;
        
        case 6: //Substitution cipher decryption without key
        printf("LOL jk\n.");
        break;

        default:
	    printf("\nError in task selection\nPlease choose a number between 1 and 6 for task selection");
	}
	return 0;
}


/* ROTATION CIPHER ENCRYPTION FUNCTION */
void rotencrypt(char *message, int key){
    int i;
    for(i = 0; i < 1000 && message[i] != '\0' ; i++){     //loops until the message has been read then exits
	   if(message[i] >= 'A' && message[i] <= 'Z'){      //this selects letters between A-Z
	       message[i] = message[i] + key;               //performs the encryption with key
	       if(message[i] > 'Z'){                        //if a letter moves outside of the data range A-Z
	           message[i] = message[i] - 'Z' + 'A' - 1; //returns that letter back to the beginning of A-Z
           }    
        }
    }
    printf("The encrypted message is: %s\n", message);
}


/* ROTATION CIPHER DECRYPTION FUNCTION */
void rotdecrypt(char *message, int key){
    int i;
    for(i = 0; i < 1000 && message[i] != '\0' ; i++){     //loops until message has been read then exits
	   if(message[i] >= 'A' && message[i] <= 'Z'){      //this selects letters between A-Z
	       message[i] = message[i] - key;               //performs the decryption with key
	       if(message[i] < 'A'){                        //if a letters moves out of the A-Z range
	           message[i] = message[i] - 'A' + 'Z' + 1;      //returns letter back to the end of A-Z
	       }
        }
    }
    printf("The decrypted message is: %s\n", message);
}


/* ROTATION CIPHER BRUTE FORCE ATTACK FUNCTION */
void brute(char *message){
int i, count = 1;
	    while(count < 26){
	       for(i = 0; i < 1000 && message[i] != '\0' ; i++) {       //loops until the message has been read then exits
	            if(message[i] >= 'A' && message[i] <= 'Z'){         //this selects letters between A-Z
	               message[i] = message[i] - 1;                //tests the generated key
    	           if(message[i] < 'A'){                         //if a letter moves outside of the data range A-Z
	                   message[i] = message[i] - 'A' + 'Z' + 1;  //returns that letter back to the beginning of A-Z
                   }        
                }
            }                       
            printf("\n\nThe encrypted message may be:\n%s\n", message);
            count++;
        }
    }


/* SUBSTITUTION CIPHER ENCRYPTION FUNCTION */
void subencrypt(char *message, char *akey){
    int i;
    for(i = 0; i < 1000 && message[i] != '\0' ; i++) {      
        switch(message[i]){
            case 'A': message[i] = akey[0]; break;
            case 'B': message[i] = akey[1]; break;
            case 'C': message[i] = akey[2]; break;
            case 'D': message[i] = akey[3]; break;
            case 'E': message[i] = akey[4]; break;
            case 'F': message[i] = akey[5]; break;
            case 'G': message[i] = akey[6]; break;
            case 'H': message[i] = akey[7]; break;
            case 'I': message[i] = akey[8]; break;
            case 'J': message[i] = akey[9]; break;
            case 'K': message[i] = akey[10]; break;
            case 'L': message[i] = akey[11]; break;
            case 'M': message[i] = akey[12]; break;
            case 'N': message[i] = akey[13]; break;
            case 'O': message[i] = akey[14]; break;
            case 'P': message[i] = akey[15]; break;
            case 'Q': message[i] = akey[16]; break;
            case 'R': message[i] = akey[17]; break;
            case 'S': message[i] = akey[18]; break;
            case 'T': message[i] = akey[19]; break;
            case 'U': message[i] = akey[20]; break;
            case 'V': message[i] = akey[21]; break;
            case 'W': message[i] = akey[22]; break;
            case 'X': message[i] = akey[23]; break;
            case 'Y': message[i] = akey[24]; break;
            case 'Z': message[i] = akey[25]; break;
            default: break;
        }
    }
    printf("The encypted message is:\n%s", message);
}


/*SUBSTITUTION CIPHER DECRYPTION FUNCTION */
void subdecrypt(char *message, char *akey){
    int i;
    for(i = 0; i < 1000 && message[i] != '\0' ; i++){      
        if(message[i] == akey[0]){
            message[i] = 'A';
        }
        else if(message[i] == akey[1]){
            message[i] = 'B';
        }
        else if(message[i] == akey[2]){
            message[i] = 'C';
        }
        else if(message[i] == akey[3]){
            message[i] = 'D';
        }
        else if(message[i] == akey[4]){
            message[i] = 'E';
        }
        else if(message[i] == akey[5]){
            message[i] = 'F';
        }
        else if(message[i] == akey[6]){
            message[i] = 'G';
        }
        else if(message[i] == akey[7]){
            message[i] = 'H';
        }
        else if(message[i] == akey[8]){
            message[i] = 'I';
        }
        else if(message[i] == akey[9]){
            message[i] = 'J';
        }
        else if(message[i] == akey[10]){
            message[i] = 'K';
        }
        else if(message[i] == akey[11]){
            message[i] = 'L';
        }
        else if(message[i] == akey[12]){
            message[i] = 'M';
        }
        else if(message[i] == akey[13]){
            message[i] = 'N';
        }
        else if(message[i] == akey[14]){
            message[i] = 'O';
        }
        else if(message[i] == akey[15]){
            message[i] = 'P';
        }
        else if(message[i] == akey[16]){
            message[i] = 'Q';
        }
        else if(message[i] == akey[17]){
            message[i] = 'R';
        }
        else if(message[i] == akey[18]){
            message[i] = 'S';
        }
        else if(message[i] == akey[19]){
            message[i] = 'T';
        }
        else if(message[i] == akey[20]){
            message[i] = 'U';
        }
        else if(message[i] == akey[21]){
            message[i] = 'V';
        }
        else if(message[i] == akey[22]){
            message[i] = 'W';
        }
        else if(message[i] == akey[23]){
            message[i] = 'X';
        }
        else if(message[i] == akey[24]){
            message[i] = 'Y';
        }
        else if(message[i] == akey[25]){
            message[i] = 'Z';
        }
    }
    printf("The decrypted message is:\n%s", message);
}