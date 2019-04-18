#include<stdio.h>

/*  SUBSTITUTION CIPHER ENCRYPTION FUNCTION  */ 
void subencrypt(char *message, char *akey); 
 
 
 
 
int main()
{
	char message[1000], akey[26];                                        //array to store message 
	int x, i, key = 1;                                         //x for program option menu, key for key, i for array
	
	
	printf("Enter message: \n");      
	scanf("%[^\n]", message);                                  //reads the message until a new line
	
	printf("Please choose from the following options:\n");
	printf("1. Encrypt with a rotation cipher\n");
	printf("2. Decrypt a rotation cipher\n");
	printf("3. Decrypt a rotation cipher without key\n");
	printf("4. Encrypt with substitution cipher\n");
	printf("5. Decrypt a substitution cipher\n");
	printf("6. Decrypt a substitution cipher without key\n");
	scanf("%d", &x);
	
	switch(x){
	    //Rotation cipher encryption with key
	    case 1: 
	       printf("Enter message: \n");      
	       scanf("%[^\n]", message); 
	       printf("Enter key between 0 and 26: \n");
	       scanf("%d", &key);
	       for(i = 0; i < 1000 && message[i] != '\0' ; i++)     //loops until the message has been read then exits
	           if(message[i] >= 'A' && message[i] <= 'Z'){      //this selects letters between A-Z
	               message[i] = message[i] + key;               //performs the encryption with key
	               if(message[i] > 'Z'){                        //if a letter moves outside of the data range A-Z
	                    message[i] = message[i] - 'Z' + 'A' - 1; //returns that letter back to the beginning of A-Z
                   }    
                }
	       printf("The encrypted message is: %s\n", message);
	       break;

  

        //Rotation ciphor decryption with key	     
	    case 2:
	       printf("Enter message: \n");      
	       scanf("%[^\n]", message); 
	       printf("Enter key between 0 and 26: \n");
	       scanf("%d", &key);
	       for(i = 0; i < 1000 && message[i] != '\0' ; i++)     //loops until message has been read then exits
	           if(message[i] >= 'A' && message[i] <= 'Z'){      //this selects letters between A-Z
	               message[i] = message[i] - key;               //performs the decryption with key
	                   if(message[i] < 'A'){                        //if a letters moves out of the A-Z range
	                       message[i] = message[i] - 'A' + 'Z' + 1;      //returns letter back to the end of A-Z
	                   }
               }
	       printf("The decrypted message is: %s\n", message);
	       break; 
	       
     //rotation ciphor without key: BRUTE FORCE
	    case 3:	
	    printf("Enter message: \n");      
	    scanf("%[^\n]", message); 
	    while(key < 26){
	       for(i = 0; i < 1000 && message[i] != '\0' ; i++) {       //loops until the message has been read then exits
	            if(message[i] >= 'A' && message[i] <= 'Z'){         //this selects letters between A-Z
	               message[i] = message[i] - 1;                //tests the generated key
    	           if(message[i] < 'A'){                         //if a letter moves outside of the data range A-Z
	                   message[i] = message[i] - 'A' + 'Z' + 1;  //returns that letter back to the beginning of A-Z
                   }        
                }
            }            

                 
            printf("\n\nThe encrypted message may be:\n%s\n", message);
            key++;
        }
        break;
	       
	    //Substitution cipher encryption   
	    case 4:
	    printf("Enter message: \n");      
	    scanf("%[^\n]", message); 
        printf("Please enter the key alphabet without any spaces: \n");
	    scanf("%s", akey);
	    subencrypt(message, akey);
	    printf("The encypted message is:\n%s", message);
        break;
	     
	     
        case 5:
        printf("Enter message: \n");      
	    scanf("%[^\n]", message); 
        printf("Enter key between 0 and 26: \n");
        scanf("%s", akey);
        
        break;
        
        case 6:
        printf("LOL jk\n.");
        break;
        
	    default:
	       printf("Error\n");
	}

	
	return 0;
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
}
