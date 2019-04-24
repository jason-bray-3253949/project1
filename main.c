#include<stdio.h>

/* LOWER CASE TO UPPER CASE FUNCTION PROTOTYPE */
void lowToUp(char *message);

/* ROTATION CIPHER ENCRYPTION FUNCTION PROTOTYPE */
void rotEncrypt(char *message, int key);

/* ROTATION CIPHER DECRYPTION FUNCTION */
void rotDecrypt(char *message, int key);

/*ROTATION CIPHER BRUTE FORCE ATTACK FUNCTION PROTOTYPE */
void brute(char *message);

/* SUBSTITUTION CIPHER ENCRYPTION FUNCTION PROTOTYPE */ 
void subEncrypt(char *message, char *akey); 
 
/* SUBSTITUTION CIPHER DECRYPTION FUNCTION PROTOTYPE */
void subDecrypt(char *message, char *akey);
 
int main()
{
	char message[1000]; //array to store the message entered 
	char akey[26];      //array to store the substitution cipher key
	int x;              //x is the program option menu variable
	int key = 1;        //rotation cipher key. key = 1 for brute force attack
	
	printf("Enter your message:\n"); //user prompt to enter message   
	scanf("%[^\n]", message); // %[^\n] scans until a new line is read and stores the message in an array	
	lowToUp(message); //lowToUp function converts lower case letters in the message to upper case letters
	
	/* Task Selection Option Menu */
	printf("What would you like to do with the message?\n");
	printf("1  Encrypt with a rotation cipher\n");
	printf("2  Decrypt a rotation cipher\n");
	printf("3  Decrypt a rotation cipher without key\n");
	printf("4  Encrypt with substitution cipher\n");
	printf("5  Decrypt a substitution cipher\n");
	printf("6  Decrypt a substitution cipher without key\n");
	scanf("%d", &x); //stores the option chosen for use later


	switch(x)
	{
	   /* 
        * switch(x) uses the number entered by the user at the option menu to select which task to execute.
        * case 1 = option 1, case 2 = option 2...
        * default = if an option between 1-6 is not selected an error message is printed to the console
        */
	   
	   /* Rotation cipher encryption with key */
	   case 1: 
	       printf("Enter a key between 1 and 25:\n"); //user prompt to enter key
	       scanf("%d", &key); //reads and stores the entered number in key variable
	       rotEncrypt(message, key); //rotation cipher encryption function on message using key variable
	       printf("The encrypted message is:\n%s\n", message); //prints the encrypted message to console
	       break; //exits switch() case to prevent the following cases from running after this case      
	       
	   /* Rotation cipher decryption with key */
	   case 2:	
	       printf("Enter a key between 1 and 25:\n"); //user prompt to enter key
	       scanf("%d", &key); //reads and stores the entered number in key variable
	       rotDecrypt(message, key); //rotation cipher decryption function on message using key variable
	       printf("The decrypted message is:\n%s\n", message); //prints decrypted message to console
	       break; //exits switch() case to prevent the following cases from running after this case   
	       
	   /* Rotation cipher without key: BRUTE FORCE */
	   case 3: 
	   /* 
	    * The function is looped until each key between 1-25 is tested.
	    * key = 1 initially, loop exits once key = 25 is tested.
        * The output from each test is printed to the console with the key used.
	    */
	       while(key < 26) //loops while key is less than 26
	       {
	          brute(message); //brute force function used on message
	          printf("\nThe encrypted message may be (Key = %d):\n%s\n", key, message); //prints the message and key used for the test to console
	          key++; //increments key variable for the next test
	       }
              break; //exits switch() case to prevent the following cases from running after this case   
              
       /* Substitution cipher encryption */       
	   case 4: 
	       printf("Please enter the substitution alphabet key without any spaces:\n"); //user prompt to enter key
	       scanf("%s", akey); //reads and stores the alphabet key as an array
	       subEncrypt(message, akey); //substitution encryption function on message using akey array
	       printf("The encypted message is:\n%s", message); //prints encrypted message to console
	       break; //exits switch() case to prevent the following cases from running after this case      
	       
	   /* Substitution cipher decryption */
       case 5: 
           printf("Please enter the substitution alphabet key without any spaces:\n"); //user prompt to enter key
           scanf("%s", akey); //reads and stores the alphabet key as an array
           subDecrypt(message, akey); //substitution decryption function on message using akey array
           printf("The decrypted message is:\n%s", message); //prints decrypted message to console
           break; //exits switch() case to prevent the following cases from running after this case    
           
       /* Substitution cipher decryption without key */   
       case 6: 
           printf("LOL jk\n"); //I'm an average student
           break; //exits switch() case to prevent default running after this case   
       
       /*notifies user that an incorrect option was selected and gives further instruction */
       default:
	       printf("\nError in task selection\n" //prints error to console
	       printf("Please choose a number between 1 and 6 for task selection\n"); //prints instruction to console
	}
	return 0;
}

/* LOWER CASE TO UPPER CASE FUNCTION DEFINITION
 * Converts all lower case letters in the message entered by the user  
 * into upper case letters
 */
void lowToUp(char *message) //definition
{
    int i; //used as an element variable for the message array in the for loop
    for(i = 0; i < 1000 && message[i] != '\0' ; i++)
    {
        /*
         * The for loop starts at element 0 of the message array (i=0), 
         * increments i to the next element each time the loop runs, until
         * the last element message[999] is read or '\0' is read indicating
         * the end of the string has been reached.
         */   
        if(message[i] >= 'a' && message[i] <= 'z') //if the message is between ASCII characters a-z
	    {
	        message[i] = message[i] - 32; 
	        /* lower case letters are 32 ASCII characters higher than upper case
	         * by subtraction 32 the letters between a-z are now between A-Z.
	         * b becomes B, x becomes X and so on
             */
       }
    }  
}

/* ROTATION CIPHER ENCRYPTION FUNCTION DEFINITION
 * Takes the key and message input from the user and adds the key variable to each 
 * message element. The ASCII character stored in the message element shifts up
 * by the value of the key variable. If the new ASCII character is greater than 
 * ASCII Z, 26 is subtracted to return the ASCII character back to the beginning
 * of the A-Z range.
 * For example,
 * for key = 1: A becomes B, B becomes C, ..., Y becomes Z, Z becomes A
 * for key = 2: A becomes C, B becomes D, ..., Y becomes A, Z becomes B
 * and so on
 */
void rotEncrypt(char *message, int key) //definition
{
    int i; //used as an element variable for the message array in the for loop
    for(i = 0; i < 1000 && message[i] != '\0' ; i++)
    {
        /*
         * The for loop starts at element 0 of the message array (i=0), 
         * increments i to the next element each time the loop runs, until
         * the last element message[999] is read or '\0' is read indicating
         * the end of the string has been reached.
         */   
        if(message[i] >= 'A' && message[i] <= 'Z') //if message[i] is between ASCII A-Z
	    {
	        message[i] = message[i] + key; //message[i] becomes the ASCII character that is message[i] + key
	        if(message[i] > 'Z') //if message[i] becomes greater than ASCII character Z with the addition of the key
	        {
	            message[i] = message[i] - 26; //message[i] - 26 returns to the beginning of the ASCII characters A-Z range
            }    
        }
    }
}

/* ROTATION CIPHER DECRYPTION FUNCTION DEFINITION
 * Takes the key and message input from the user and substracts the key variable 
 * from each message element. The ASCII character stored in the message element 
 * shifts down by the value of the key variable. If the new ASCII character is less 
 * than ASCII Z, 26 is added to return the ASCII character back to the end of the
 * A-Z range.
 * For example,
 * for key = 1: A becomes Z, B becomes A, ..., Y becomes X, Z becomes Y
 * for key = 2: A becomes Y, B becomes Z, ..., Y becomes W, Z becomes X
 * and so on

 */
void rotDecrypt(char *message, int key) //definition
{
    int i; //used as an element variable for the message array in the for loop
    for(i = 0; i < 1000 && message[i] != '\0' ; i++)
    {
        /*
         * The for loop starts at element 0 of the message array (i=0), 
         * increments i to the next element each time the loop runs, until
         * the last element message[999] is read or '\0' is read indicating
         * the end of the string has been reached.
         */      
	    if(message[i] >= 'A' && message[i] <= 'Z') //if message[i] is between ASCII A-Z
	    {
	        message[i] = message[i] - key; //message[i] becomes the ASCII character that is message[i] - key             
	        if(message[i] < 'A') //if message[i] becomes less than ASCII character A with the subtraction of the key
	        {
	            message[i] = message[i] + 26; //message[i] + 26 returns to the end of the ASCII characters A-Z range
	        }
        }
    }
}

/* ROTATION CIPHER BRUTE FORCE ATTACK FUNCTION DEFINITION
 * Takes the message input from the user and substracts 1 each message element. 
 * The ASCII character stored in the message element shifts down by 1. 
 * If the new ASCII character is less than ASCII Z, 26 is added to return the 
 * ASCII character back to the end of the A-Z range.
 *
 * NB: This function needs to be looped to test multiple keys as it subtracts
 * 1 each time it runs.
 */
void brute(char *message) //defintion
{
    int i; //used as an element variable for the message array in the for loop
    for(i = 0; i < 1000 && message[i] != '\0' ; i++)
	{
	    /*
         * The for loop starts at element 0 of the message array (i=0), 
         * increments i to the next element each time the loop runs, until
         * the last element message[999] is read or '\0' is read indicating
         * the end of the string has been reached.
         */   
        
	    if(message[i] >= 'A' && message[i] <= 'Z') //if message[i] is between ASCII A-Z
	    {
	        message[i] = message[i] - 1; //message[i] becomes the ASCII character that is message[i] - 1
	        if(message[i] < 'A') //if message[i] becomes less than ASCII character A with the subtraction of 1
    	    {
    	        message[i] = message[i] + 26; //message[i] + 26 returns to the end of the ASCII characters A-Z range
            }        
        }
    }                       
}

/* SUBSTITUTION CIPHER ENCRYPTION FUNCTION DEFINITION
 * Takes the message and key input from the user, uses the key to encrypt
 * the message, and overwrites the message with the encrypted the message.
 *
 * The function converts every A in the message to the first key letter,
 * every B to the second key letter, ..., every Z to the 26th key letter.
 * For example,
 * if the 1st key letter is X, each A in the message would become X.
 * if the 2nd key letter is A, each B in the message would become A.
 * ...
 * if the 26th key letter is M, each Z in the message becomes M.
 */
void subEncrypt(char *message, char *akey) //definition
{
    int i; //used as an element variable for the message array in the for loop
    for(i = 0; i < 1000 && message[i] != '\0' ; i++)
    {
        /*
         * The for loop starts at element 0 of the message array (i=0), 
         * increments i to the next element each time the loop runs, until
         * the last element message[999] is read or '\0' is read indicating
         * the end of the string has been reached.
         */   
        switch(message[i])
        {
            case 'A': //if message[i] is ASCII A
                message[i] = akey[0]; //message[i] becomes the 1st key letter
                break;
            case 'B': //if message[i] is ASCII B
                message[i] = akey[1]; //message[i] becomes the 2nd key letter
                break;
            case 'C': 
                message[i] = akey[2]; //and so on
                break;
            case 'D': 
                message[i] = akey[3]; 
                break;
            case 'E': 
                message[i] = akey[4]; 
                break;
            case 'F': 
                message[i] = akey[5]; 
                break;
            case 'G': 
                message[i] = akey[6]; 
                break;
            case 'H': 
                message[i] = akey[7]; 
                break;
            case 'I': 
                message[i] = akey[8]; 
                break;
            case 'J': 
                message[i] = akey[9]; 
                break;
            case 'K': 
                message[i] = akey[10]; 
                break;
            case 'L': 
                message[i] = akey[11]; 
                break;
            case 'M': 
                message[i] = akey[12]; 
                break;
            case 'N': 
                message[i] = akey[13]; 
                break;
            case 'O': 
                message[i] = akey[14]; 
                break;
            case 'P': 
                message[i] = akey[15]; 
                break;
            case 'Q': 
                message[i] = akey[16]; 
                break;
            case 'R': 
                message[i] = akey[17]; 
                break;
            case 'S': 
                message[i] = akey[18]; 
                break;
            case 'T': 
                message[i] = akey[19]; 
                break;
            case 'U': 
                message[i] = akey[20]; 
                break;
            case 'V': 
                message[i] = akey[21]; 
                break;
            case 'W': 
                message[i] = akey[22]; 
                break;
            case 'X': 
                message[i] = akey[23]; 
                break;
            case 'Y': 
                message[i] = akey[24]; 
                break;
            case 'Z': 
                message[i] = akey[25]; 
                break;
            default: //if message[i] is an ASCII character outside of A-Z
                //default is probably not needed but included for completeness
                break; 
        }
    }
}

/*SUBSTITUTION CIPHER DECRYPTION FUNCTION 
 * Takes the encrypted message and key input from the user, uses the key to
 * decrypt the message, and overwrites the encrypted message with 
 * the decrypted message.
 * 
 * The function converts the nth letter entered for the key to the corresponding
 * nth letter of the standard alphabet in the message.
 * For example, 
 * if the 1st key letter is P, each P in the message becomes A.
 * if the 2nd key letter is X, each X in the message becomes B. 
 * ...
 * if the 26th key letter is Q, each Q in the message becomes Z.
 */
void subDecrypt(char *message, char *akey) //definition
{
    int i; //used as an element variable for the message array in the for loop
    for(i = 0; i < 1000 && message[i] != '\0' ; i++) 
    {
        /*
         * The for loop starts at element 0 of the message array (i=0), 
         * increments i to the next element each time the loop runs, until
         * the last element message[999] is read or '\0' is read indicating
         * the end of the string has been reached.
         */   
        if(message[i] == akey[0]) //if message[i] equals the first key letter
        {
            message[i] = 'A'; //message[i] becomes A to return to standard alphabet
        }
        else if(message[i] == akey[1]) //if message[i] equals the second key letter
        {
            message[i] = 'B'; //message[i] becomes B to return to standard alphabet
        }
        else if(message[i] == akey[2]) //and so on
        {
            message[i] = 'C';
        }
        else if(message[i] == akey[3])
        {
            message[i] = 'D';
        }
        else if(message[i] == akey[4])
        {
            message[i] = 'E';
        }
        else if(message[i] == akey[5])
        {
            message[i] = 'F';
        }
        else if(message[i] == akey[6])
        {
            message[i] = 'G';
        }
        else if(message[i] == akey[7])
        {
            message[i] = 'H';
        }
        else if(message[i] == akey[8])
        {
            message[i] = 'I';
        }
        else if(message[i] == akey[9])
        {
            message[i] = 'J';
        }
        else if(message[i] == akey[10])
        {
            message[i] = 'K';
        }
        else if(message[i] == akey[11])
        {
            message[i] = 'L';
        }
        else if(message[i] == akey[12])
        {
            message[i] = 'M';
        }
        else if(message[i] == akey[13])
        {
            message[i] = 'N';
        }
        else if(message[i] == akey[14])
        {
            message[i] = 'O';
        }
        else if(message[i] == akey[15])
        {
            message[i] = 'P';
        }
        else if(message[i] == akey[16])
        {
            message[i] = 'Q';
        }
        else if(message[i] == akey[17])
        {
            message[i] = 'R';
        }
        else if(message[i] == akey[18])
        {
            message[i] = 'S';
        }
        else if(message[i] == akey[19])
        {
            message[i] = 'T';
        }
        else if(message[i] == akey[20])
        {
            message[i] = 'U';
        }
        else if(message[i] == akey[21])
        {
            message[i] = 'V';
        }
        else if(message[i] == akey[22])
        {
            message[i] = 'W';
        }
        else if(message[i] == akey[23])
        {
            message[i] = 'X';
        }
        else if(message[i] == akey[24])
        {
            message[i] = 'Y';
        }
        else if(message[i] == akey[25])
        {
            message[i] = 'Z';
        }
    }
}