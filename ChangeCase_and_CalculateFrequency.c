#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CAPACITY 100

//Function to calculate Frequency of each number
void calculateFrequency(char input[], int size)
{
    int frequency[26] = {0}; //Array to store number of occurrance of each character

    for (int i = 0; i < size; i++)
    {
        if (input[i] >= 'A' && input[i] <= 'Z')//if character is an upper case character
        {                                   
            frequency[input[i] - 'A'] += 1; // input[i] -'a' = index of that character, if character is found than it will increment 1 in frequency array at the position of that character
        }
        else if (input[i] >= 'a' && input[i] <= 'z') //if character is a lower case character
        {
            frequency[input[i] - 'a'] += 1; // input[i] -'a' = index of that character, if character is found than it will increment 1 in frequency array at the position of that character
        }
    }

    //loop to print the frequencies of each character which are stored in array
    for (int i = 0; i < 26; i++)
    {
        if (frequency[i] > 0)
            printf("Frequency of %c or %c: %d times\n", (char)(i + 'A'), (char)(i + 'a'), frequency[i]);
    }
}


void changeCase(char input[], int size)
{
    int ch; //temporary variable to store case changed character

    //Loop to change the case of each character
    for (int i = 0; i < size; i++)
    {
        if (input[i] >= 'a' && input[i] <= 'z')
        {                        //if character is Lower case
            ch = input[i] - 32;  //If we subtract 32 from ASCII value of any character than we get it's Uppper case
            input[i] = (char)ch; //Assigning the changed case character
        }
        else if (input[i] >= 'A' && input[i] <= 'Z')
        {                        //if character is Upper case
            ch = input[i] + 32;  //If we add 32 to ASCII value of any character than we get it's Lower case
            input[i] = (char)ch; //Assigning the changed case character
        }
    }
}


int main()
{
    char inputString[CAPACITY]; //declaring character array of size 100 to store the input string
    int choice;
    printf("Enter the string : ");
    fgets(inputString, CAPACITY, stdin); //taking string input

    int size = strlen(inputString) - 1; //calculating the size of string excluding '\0' at the end

    do
    {
        printf("\tEnter 1 to find Frequency \n\tEnter 2 to Change the Case of characters \n\tEnter 0 to exit\n\tChoice :  ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            calculateFrequency(inputString, size); //Function call to calculate frequency
            break;
        }
        case 2:
        {
            changeCase(inputString, size); //function call to change the case
            printf("String after case Changed : ");

            //loop to print the Changed Case Array
            for (int i = 0; i < size; i++)
            {
                printf("%c", inputString[i]);
            }
            printf("\n");

            break;
        }
        case 0:
        {
            exit(0); //to exit the program
            break;
        }
        default:
        {
            printf("\nInvalid Input !!!\n");
            break;
        }
        }
    } while (choice != 0);

    return 0;
}