#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// ------------------------------
// Structure for a quiz question
// ------------------------------
typedef struct Question {
    char question[256];
    char optionA[100];
    char optionB[100];
    char optionC[100];
    char optionD[100];
    char correctOption;
    struct Question* next;
} Question;

// ------------------------------
// Create a new question node
// ------------------------------
Question* createQuestion(const char* q, const char* a, const char* b, const char* c, const char* d, char correct) {
    Question* newQ = (Question*)malloc(sizeof(Question));
    strcpy(newQ->question, q);
    strcpy(newQ->optionA, a);
    strcpy(newQ->optionB, b);
    strcpy(newQ->optionC, c);
    strcpy(newQ->optionD, d);
    newQ->correctOption = toupper(correct);  // Store as uppercase for easy comparison
    newQ->next = NULL;
    return newQ;
}

// ------------------------------
// Add question to linked list
// ------------------------------
Question* addQuestion(Question* head, Question* newQ) {
    if (head == NULL)
        return newQ;
    Question* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newQ;
    return head;
}

// ------------------------------
// Start the quiz
// ------------------------------
void startQuiz(Question* head) {
    if (head == NULL) {
        printf("\nNo questions available!\n");
        return;
    }

    int score = 0, total = 0;
    char answer;
    Question* temp = head;

    printf("\n===== QUIZ START =====\n");

    while (temp != NULL) {
        printf("\nQ%d: %s\n", total + 1, temp->question);
        printf("A. %s\nB. %s\nC. %s\nD. %s\n",
               temp->optionA, temp->optionB, temp->optionC, temp->optionD);

        // Input validation loop
        while (1) {
            printf("Enter your answer (A/B/C/D): ");
            scanf(" %c", &answer);
            answer = toupper(answer); // Convert lowercase to uppercase

            if (answer == 'A' || answer == 'B' || answer == 'C' || answer == 'D')
                break;
            else
                printf("⚠️ Invalid option! Please enter A, B, C, or D.\n");
        }

        // Check answer correctness (case-insensitive)
        if (answer == temp->correctOption) {
            printf("✅ Correct!\n");
            score++;
        } else {
            printf("❌ Wrong! Correct answer: %c\n", temp->correctOption);
        }

        total++;
        temp = temp->next;
    }

    // Calculate score percentage
    float percentage = ((float)score / total) * 100;

    printf("\n===== QUIZ COMPLETED =====\n");
    printf("Your Score: %d / %d (%.2f%%)\n", score, total, percentage);

    // Feedback message
    if (percentage == 100)
        printf("🏆 Excellent! Perfect score!\n");
    else if (percentage >= 75)
        printf("🎯 Great job! You really know your stuff.\n");
    else if (percentage >= 50)
        printf("🙂 Not bad! Keep practicing.\n");
    else
        printf("😅 You need more practice. Try again!\n");

    printf("🎉 Thank you for playing!\n");
}

// ------------------------------
// Main function
// ------------------------------
int main() {
    Question* quiz = NULL;

    // Predefined questions
    quiz = addQuestion(quiz, createQuestion("What is the capital of France?",
                                            "Berlin", "Paris", "London", "Rome", 'B'));

    quiz = addQuestion(quiz, createQuestion("Which data structure uses FIFO?",
                                            "Stack", "Queue", "Tree", "Graph", 'B'));

    quiz = addQuestion(quiz, createQuestion("Who developed the C programming language?",
                                            "Dennis Ritchie", "James Gosling", "Bjarne Stroustrup", "Guido van Rossum", 'A'));

    quiz = addQuestion(quiz, createQuestion("Which symbol is used to comment a single line in C?",
                                            "//", "#", "/* */", "--", 'A'));

    quiz = addQuestion(quiz, createQuestion("Which of these is not a data type in C?",
                                            "int", "float", "real", "char", 'C'));
                                                quiz = addQuestion(quiz, createQuestion("What is the size of an int in most 32-bit compilers?",
                                            "2 bytes", "4 bytes", "8 bytes", "Depends on compiler", 'B'));

    quiz = addQuestion(quiz, createQuestion("Which of the following is a linear data structure?",
                                            "Array", "Tree", "Graph", "Hash Table", 'A'));

    quiz = addQuestion(quiz, createQuestion("What will be the output of printf(\"%d\", 5 + 2 * 3)?",
                                            "21", "11", "7", "9", 'D'));

    quiz = addQuestion(quiz, createQuestion("Which operator is used to access a structure member using a pointer?",
                                            ".", "->", "&", "*", 'B'));

    quiz = addQuestion(quiz, createQuestion("Which sorting algorithm has the best average time complexity?",
                                            "Bubble Sort", "Insertion Sort", "Quick Sort", "Selection Sort", 'C'));

    quiz = addQuestion(quiz, createQuestion("In C, what is the index of the first element in an array?",
                                            "0", "1", "-1", "Depends on compiler", 'A'));

    quiz = addQuestion(quiz, createQuestion("Which of the following is not a valid loop in C?",
                                            "for", "while", "do-while", "foreach", 'D'));

    quiz = addQuestion(quiz, createQuestion("Which keyword is used to allocate memory dynamically in C?",
                                            "alloc", "malloc", "new", "create", 'B'));

    quiz = addQuestion(quiz, createQuestion("Which of these data structures is used in recursion?",
                                            "Queue", "Array", "Stack", "Linked List", 'C'));

    quiz = addQuestion(quiz, createQuestion("What is the purpose of the 'return' statement in a C function?",
                                            "To exit from the program", "To return control to main()", "To exit from the function and optionally send a value", "To pause function execution", 'C'));
                                                quiz = addQuestion(quiz, createQuestion("Which header file is required for using printf() and scanf() functions?",
                                            "stdlib.h", "stdio.h", "conio.h", "string.h", 'B'));

    quiz = addQuestion(quiz, createQuestion("What will be the output of sizeof(char)?",
                                            "1", "2", "4", "Depends on compiler", 'A'));

    quiz = addQuestion(quiz, createQuestion("Which of the following is used to prevent a function from being called recursively?",
                                            "static variable", "global variable", "register variable", "local variable", 'A'));

    quiz = addQuestion(quiz, createQuestion("Which of the following is not a storage class in C?",
                                            "auto", "static", "volatile", "extern", 'C'));

    quiz = addQuestion(quiz, createQuestion("Which data structure is best suited for implementing recursion?",
                                            "Queue", "Stack", "Array", "Linked List", 'B'));

    quiz = addQuestion(quiz, createQuestion("What is the output of 10 % 3 in C?",
                                            "1", "2", "3", "0", 'B'));

    quiz = addQuestion(quiz, createQuestion("Which function is used to find the length of a string in C?",
                                            "strlen()", "strlength()", "len()", "length()", 'A'));

    quiz = addQuestion(quiz, createQuestion("Which data structure is used to implement function call stacks?",
                                            "Queue", "Tree", "Stack", "Graph", 'C'));

    quiz = addQuestion(quiz, createQuestion("Which of the following statements is true about arrays in C?",
                                            "Array elements can be of different types", 
                                            "Array index starts from 1", 
                                            "Array size must be a constant", 
                                            "Array stores values randomly", 'C'));

    quiz = addQuestion(quiz, createQuestion("Which keyword is used to define a constant in C?",
                                            "static", "const", "define", "final", 'B'));



    // Start the quiz directly
    startQuiz(quiz);

    return 0;
}
