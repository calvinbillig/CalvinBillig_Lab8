/* =========================================================================
   Description: Determines all possible ways a team could have scored their points
            
   Inputs:
       n = the team's score
   Output:
       Prints all possible outputs on how the team could have scored their points
   ========================================================================= */

#include <stdio.h>

int main() {
    int score;

    // Loop until the user enters 1
    while (1) {
        printf("Enter the NFL score (Enter 1 to stop): ");
        scanf("%d", &score);

        // Stop if user enters 1
        if (score == 1)
            break;

        printf("Possible combinations of scoring plays if a team’s score is %d:\n", score);

        // Iterate through all possible numbers of TD+2pt (8 points)
        for (int td2 = 0; td2 <= score / 8; td2++) {
            // Iterate through all possible numbers of TD+1pt (7 points)
            for (int td1 = 0; td1 <= score / 7; td1++) {
                // Iterate through all possible numbers of TD only (6 points)
                for (int td = 0; td <= score / 6; td++) {
                    // Iterate through all possible numbers of FG (3 points)
                    for (int fg = 0; fg <= score / 3; fg++) {
                        // Iterate through all possible numbers of Safeties (2 points)
                        for (int safety = 0; safety <= score / 2; safety++) {

                            // Compute total points for this combination
                            int total = td2 * 8 + td1 * 7 + td * 6 + fg * 3 + safety * 2;

                            // If total equals the score, print the combination
                            if (total == score) {
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                                        td2, td1, td, fg, safety);
                            }
                        }
                    }
                }
            }
        }

        printf("\n");  // Blank line for readability before next input
    }
    return 0;
}
