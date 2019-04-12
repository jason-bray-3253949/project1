#include<stdio.h>

 
int main()
{
	char message[1000];                                        //array to store message 
	int x, i, key = 1;                                         //x for program option menu, key for key, i for array
	
	
	printf("Enter message: \n");      
	scanf("%[^\n]", message);                                  //reads the message until a new line
	
	printf("Please choose from the following options:\n");
	printf("1. Encrypt with a rotation cipher\n");
	printf("2. Encrypt with substitution cipher\n");
	printf("3. Decrypt a rotation cipher\n");
	printf("4. Decrypt a rotation cipher without key\n");
	printf("5. Decrypt a substitution cipher\n");
	printf("6. Decrypt a substitution cipher without key\n");
	scanf("%d\n", &x);
	
	switch(x){
	    //Rotation cipher encryption with key
	    case 1: 
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

        case 2:
               printf("Enter key between 0 and 26: \n");
	           scanf("%d", &key);
        break;


        //Rotation ciphor decryption with key	     
	    case 3:
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
	       
     //rotation ciphor without key
	    case 4:	
	    while(key < 26){
	       for(i = 0; i < 1000 && message[i] != '\0' ; i++) {       //loops until the message has been read then exits
	            if(message[i] >= 'A' && message[i] <= 'Z'){         //this selects letters between A-Z
	               message[i] = message[i] - key;                //tests the generated key
    	           if(message[i] < 'A'){                         //if a letter moves outside of the data range A-Z
	                   message[i] = message[i] - 'A' + 'Z' + 1;  //returns that letter back to the beginning of A-Z
                   }        
                }
            }            

                 
                 printf("\n\nThe encrypted message may be:\n%s", message);
                 key++;
        }
        break;
	       
	     
	     
	     
        case 5:
            printf("Enter key between 0 and 26: \n");
            scanf("%d", &key);
        
        break;
        
        case 6:
        break;
        
	    default:
	       printf("Error\n");
	}

	
	return 0;
}
