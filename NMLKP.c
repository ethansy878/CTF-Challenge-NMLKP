//{MichaelStephanieAmyDennisJennifer}
//https://www.ssa.gov/oact/babynames/decades/century.html

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 15
#define PEOPLE_AT_PARTY 101
#define MAX_ENCODE_LENGTH 300
#define PEOPLE_TARGETED 6

#define RETURN 10
#define QUESTION_MARK_ASCII 63

#define INPUT_MAX 6

char nameList[PEOPLE_AT_PARTY][MAX_NAME_LENGTH] = 
{"James", "Mary", "Robert", "Patricia", "John", "Jennifer", "Michael",
 "Linda", "David", "Elizabeth", "William", "Barbara", "Richard", "Susan",
 "Joseph", "Jessica", "Thomas", "Sarah", "Charles", "Karen",
 "Christopher", "Lisa", "Daniel", "Nancy", "Matthew", "Betty",
 "Anthony", "Margaret", "Mark", "Sandra", "Donald", "Ashley", "Steven",
 "Kimberly", "Paul", "Emily", "Andrew", "Donna", "Joshua", "Michelle",
 "Kenneth", "Carol", "Kevin", "Amanda", "Brian", "Dorothy", "George",
 "Melissa", "Timothy", "Deborah", "Ronald", "Stephanie", "Edward",
 "Rebecca", "Jason", "Sharon", "Jeffrey", "Laura", "Ryan", "Cynthia",
 "Jacob", "Kathleen", "Gary", "Amy", "Nicholas", "Angela", "Eric",
 "Shirley", "Jonathan", "Anna", "Stephen", "Brenda", "Larry", "Pamela",
 "Justin", "Emma", "Scott", "Nicole", "Brandon", "Helen", "Benjamin",
 "Samantha", "Samuel", "Katherine", "Gregory", "Christine", "Alexander",
 "Debra", "Frank", "Rachel", "Patrick", "Carolyn", "Raymond", "Janet",
 "Jack", "Catherine", "Dennis", "Maria", "Jerry", "Heather", "NMLKP"};

char targetList[PEOPLE_TARGETED][MAX_NAME_LENGTH] = 
{"NMLKP", "Michael", "Stephanie", "Amy", "Dennis", "Jennifer"};

char encodeList[PEOPLE_TARGETED][MAX_ENCODE_LENGTH] =
{"[INCOMING TRANSMISSION] VGhlcmUgYXJlIGEgaHVuZHJlZCBwZW9wbGUgaGVyZSBhbmQgdGhlaXIgbmFtZXMgYWxsIGxvb2sgZmFtaWxpYXIuIFJlbWluZHMgbWUgb2YgYUhSMGNITTZMeTkzZDNjdWMzTmhMbWR2ZGk5dllXTjBMMkpoWW5sdVlXMWxjeTlrWldOaFpHVnpMMk5sYm5SMWNua3VhSFJ0YkE= [END TRANSMISSION]", "SGUncyBteSBmaXJzdCB0YXJnZXQ", "SSdtIGFmdGVyIGhlciBzZWNvbmQ", "VGhpcmQgaW4gbGluZQ", "Rm91cnRoIG9uIHRoZSBsaXN0", "RmlmdGggYW5kIGZpbmFsbHk"};

void flush(){
    int c;
    while ((c = getchar()) != '\n'); // do nothing
}

int checkFlush(char input[]){
    for (int i = 0; i < 6; i++){
        if (input[i] == RETURN){
            return 0;
        }
    }
    return 1;
}

int strindex(char person[], char pattern[]){
    /* return index of pattern in string, -1 if none */
    
    int i, j, k;

    // NO IDEA WHATS GOING ON HERE
    for (i = 0; person[i] != '\0'; i++){
        for (j=i, k=0; pattern[k] != '\0' && tolower(person[j]) == pattern[k];
             j++, k++)
                ;
        if (k > 0 && pattern[k] == '\0')
            return i;
    }
    return -1;
}

void printPerson(char person[]){
    /* print person's name unless... */

    for (int i=0; i<6; i++){
        if (strcmp(person, targetList[i]) == 0){
            printf("%s\n", encodeList[i]);
            return;
        }
    }
    printf("%s is at the party.\n", person);
}

void grepModified(char person[], char pattern[]) {
    /* holder function for string search logic */

    int index = strindex(person, pattern);
    if (index >= 0) {
        printPerson(person);
    }
}

int main(){
    puts("I am NameLookup, or NMLKP for short.");
    puts("I will find people at the party that match your search query.");
    printf("I can only handle up to %d characters at once.\n", 
    (INPUT_MAX-1));
    
    char input[INPUT_MAX] = "\0\0\0\0\0";
    int running = 1;

    while (running) {
        printf("\n[NMLKP]: ");
        fgets(input, INPUT_MAX, stdin);

        // to lowercase & padding
        for (int i = 0; i < 6; i++){
            if (input[i] == RETURN || input[i] == '\0')
                break;
            input[i] = tolower(input[i]);
        }

        if (checkFlush(input)){
            flush();
        }
        else {    
            // newline remover   
            for (int i = 0; i < 6; i++){
                if (input[i] == RETURN){
                    input[i] = '\0';
                    break;
                }
            }
        }

        printf("Searching \"%s\"\n", input);
        for (int i=0; i < PEOPLE_AT_PARTY; i++){
            grepModified(nameList[i], input);
        }
    }
}