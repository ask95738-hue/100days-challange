#include <stdio.h>
#include <ctype.h>

typedef struct {
    char question[200];
    char options[4][50];
    char correctOption;
} QuizQuestion;

void runQuiz(QuizQuestion quiz[], int totalQuestions);

int main() {
    QuizQuestion library[] = {
        {
            "Which programming language is known as the 'Mother of all languages'?",
            {"A. Python", "B. C Language", "C. Java", "D. C++"},
            'B'
        },
        {
            "What is the correct format specifier for an integer in C?",
            {"A. %f", "B. %c", "C. %d", "D. %s"},
            'C'
        },
        {
            "Which keyword is used to return a value from a function?",
            {"A. break", "B. return", "C. continue", "D. void"},
            'B'
        },
        {
            "What is the index number of the very first element in a C array?",
            {"A. 1", "B. -1", "C. 0", "D. Depends on array size"},
            'C'
        }
    };
    int totalQuestions = sizeof(library) / sizeof(library[0]);
    printf("     WELCOME TO THE C PROGRAMMING QUIZ!     \n");
    runQuiz(library, totalQuestions);
    return 0;
}
void runQuiz(QuizQuestion quiz[], int totalQuestions) {
    int score = 0;
    char userAnswer;

    for (int i = 0; i < totalQuestions; i++) {
        printf("Question %d: %s\n", i + 1, quiz[i].question);
        for (int j = 0; j < 4; j++) {
            printf("  %s\n", quiz[i].options[j]);
        }
        do {
            printf("Your Answer (A, B, C, or D): ");
            scanf(" %c", &userAnswer);
            userAnswer = toupper(userAnswer); 
        } while (userAnswer != 'A' && userAnswer != 'B' && userAnswer != 'C' && userAnswer != 'D');
        if (userAnswer == quiz[i].correctOption) {
            printf("\n   Correct!  \n");
            score++;
        } else {
            printf("\n  Wrong! The correct answer was %c. \n", quiz[i].correctOption);
        }
    }
    float percentage = ((float)score / totalQuestions) * 100;
    
    printf("\n                    RESULTS                     \n");
    printf(" Final Score: %d out of %d\n", score, totalQuestions);
    printf(" Percentage: %.2f%%\n", percentage);
    
    if (percentage >= 75.0) {
        printf(" Status: Excellent! You passed! \n");
    } else {
        printf(" Status: Keep practicing! Try again.\n");
    }
}
