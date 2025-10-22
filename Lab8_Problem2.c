/* =========================================================================
   Program: Temperature Conversion and Weather Advisory
   Description: Converts temperatures between Celsius, Fahrenheit, and Kelvin,
                categorizes the temperature, and provides a weather advisory.
   Inputs: Temperature, Original Scale, and Target Scale
   Output: Converted temperature, Temperature categegory, and the Weather advisory

   ========================================================================= */

#include <stdio.h>

int main() {
    float temp, converted;              // Temperature values
    char originalScale, targetScale;    // Temperature scales: 'C', 'F', 'K'
    char category[99];                  // String for temperature category
    char advisory[99];                  // String for weather advisory

    // Asks user for temperature value
    printf("Enter the temperature value: ");
    scanf("%f", &temp);

    // Asks user for original scale
    printf("Enter the original scale (C, F, or K): ");
    scanf(" %c", &originalScale);  

    // Asks user for target scale
    printf("Enter the scale to convert to (C, F, or K): ");
    scanf(" %c", &targetScale);

    // Converts input temperature to Celsius first
    float tempCelsius;
    if (originalScale == 'C' || originalScale == 'c') {
        tempCelsius = temp;
    } else if (originalScale == 'F' || originalScale == 'f') {
        tempCelsius = (temp - 32) * 5 / 9;
    } else if (originalScale == 'K' || originalScale == 'k') {
        tempCelsius = temp - 273.15;
    } else {
        printf("Invalid choice!\n");
        return 1;
    }

    // Converts from Celsius to target scale
    if (targetScale == 'C' || targetScale == 'c') {
        converted = tempCelsius;
    } else if (targetScale == 'F' || targetScale == 'f') {
        converted = tempCelsius * 9 / 5 + 32;
    } else if (targetScale == 'K' || targetScale == 'k') {
        converted = tempCelsius + 273.15;
    } else {
        printf("Invalid choice!\n");
        return 1;
    }

    // Categorize temperature into ranges based on Celsius value
    if (tempCelsius < 0) {
        sprintf(category, "Freezing");
        sprintf(advisory, "Stay indoors, it's freezing!");
    } else if (tempCelsius >= 0 && tempCelsius < 10) {
        sprintf(category, "Cold");
        sprintf(advisory, "Wear a jacket!");
    } else if (tempCelsius >= 10 && tempCelsius < 25) {
        sprintf(category, "Comfortable");
        sprintf(advisory, "Enjoy the weather!");
    } else if (tempCelsius >= 25 && tempCelsius < 35) {
        sprintf(category, "Hot");
        sprintf(advisory, "Drink lots of water!");
    } else { // tempCelsius >= 35
        sprintf(category, "Extreme Heat");
        sprintf(advisory, "Stay indoors and stay hydrated!");
    }

    // Display the results
    printf("Converted temperature: %.2f %c\n", converted, targetScale);
    printf("Temperature category: %s\n", category);
    printf("Weather advisory: %s\n", advisory);

    return 0;
}
