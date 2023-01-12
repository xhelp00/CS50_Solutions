#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //nested for loops to iterate all rows and columns
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE px = image[i][j];
            int avg = round((px.rgbtRed + px.rgbtGreen + px.rgbtBlue) / 3.0);
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //nested for loops to iterate all rows and columns
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //nested for loops to iterate all rows and columns
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //nested for loops to iterate all rows and columns
    return;
}
