#include <stdio.h>
int main() {
    int numSubjects;
    printf("Enter the number of subjects: ");
    scanf("%d", &numSubjects);
    if (numSubjects <= 0) {
        printf("Number of subjects must be greater than zero.\n");
        return 1; 
    }
    float totalGradePoints = 0.0;
    int totalCredits = 0;

    for (int i = 1; i <= numSubjects; ++i) {
        float grade;
        int credit;

        printf("Enter the grade (GPA) for subject %d (0.0 to 10.0): ", i);
        scanf("%f", &grade);

        if (grade < 0.0 || grade > 10.0) {
            printf("Invalid grade. Please enter a value between 0.0 and 10.0.\n");
            i--; 
            continue; 
        }
        printf("Enter the credit hours for subject %d (positive integer): ", i);
        scanf("%d", &credit);

        if (credit <= 0) {
            printf("Invalid credit hours. Please enter a positive integer.\n");
            i--; 
            continue; 
        }

        totalGradePoints += grade * credit;
        totalCredits += credit;
    }

    if (totalCredits > 0) {
        float cgpa = totalGradePoints / totalCredits;
        printf("Your CGPA is: %.2f\n", cgpa);
    } else {
        printf("Total credits cannot be zero.\n");
    }

    return 0;
}