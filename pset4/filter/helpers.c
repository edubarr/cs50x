#include <math.h>
#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width]) // OK - Tested
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);

            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width]) // OK - Tested
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sred, sgreen, sblue; // Sepia Bytes;

            sred = round((0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) + (0.189 * image[i][j].rgbtBlue));
            sgreen = round((0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue));
            sblue = round((0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue));

            if (sred > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = sred;
            }
            if (sgreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = sgreen;
            }
            if (sblue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = sblue;
            }
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width]) // OK - Tested
{

    RGBTRIPLE original[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            original[i][j].rgbtRed = image[i][j].rgbtRed;
            original[i][j].rgbtGreen = image[i][j].rgbtGreen;
            original[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0, c = width - 1; j < width; j++, c--)
        {

            image[i][c].rgbtRed = original[i][j].rgbtRed;
            image[i][c].rgbtGreen = original[i][j].rgbtGreen;
            image[i][c].rgbtBlue = original[i][j].rgbtBlue;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width]) // OK -Tested
{
    RGBTRIPLE original[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            original[i][j].rgbtRed = image[i][j].rgbtRed;
            original[i][j].rgbtGreen = image[i][j].rgbtGreen;
            original[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int count = 0, sumred = 0, sumgreen = 0, sumblue = 0;

            // 1
            if ((i - 1) >= 0 && (j - 1) >= 0)
            {
                sumred += original[i - 1][j - 1].rgbtRed;
                sumgreen += original[i - 1][j - 1].rgbtGreen;
                sumblue += original[i - 1][j - 1].rgbtBlue;
                count++;
            }

            // 2
            if ((i - 1) >= 0)
            {
                sumred += original[i - 1][j].rgbtRed;
                sumgreen += original[i - 1][j].rgbtGreen;
                sumblue += original[i - 1][j].rgbtBlue;
                count++;
            }

            // 3
            if ((i - 1) >= 0 && (j + 1) < width)
            {
                sumred += original[i - 1][j + 1].rgbtRed;
                sumgreen += original[i - 1][j + 1].rgbtGreen;
                sumblue += original[i - 1][j + 1].rgbtBlue;
                count++;
            }

            // 4
            if ((j - 1) >= 0)
            {
                sumred += original[i][j - 1].rgbtRed;
                sumgreen += original[i][j - 1].rgbtGreen;
                sumblue += original[i][j - 1].rgbtBlue;
                count++;
            }

            // 5
            sumred += original[i][j].rgbtRed;
            sumgreen += original[i][j].rgbtGreen;
            sumblue += original[i][j].rgbtBlue;
            count++;

            // 6
            if ((j + 1) < width)
            {
                sumred += original[i][j + 1].rgbtRed;
                sumgreen += original[i][j + 1].rgbtGreen;
                sumblue += original[i][j + 1].rgbtBlue;
                count++;
            }

            // 7
            if ((i + 1) < height && (j - 1) >= 0)
            {
                sumred += original[i + 1][j - 1].rgbtRed;
                sumgreen += original[i + 1][j - 1].rgbtGreen;
                sumblue += original[i + 1][j - 1].rgbtBlue;
                count++;
            }

            // 8
            if ((i + 1) < height)
            {
                sumred += original[i + 1][j].rgbtRed;
                sumgreen += original[i + 1][j].rgbtGreen;
                sumblue += original[i + 1][j].rgbtBlue;
                count++;
            }

            // 8
            if ((i + 1) < height && (j + 1) < width)
            {
                sumred += original[i + 1][j + 1].rgbtRed;
                sumgreen += original[i + 1][j + 1].rgbtGreen;
                sumblue += original[i + 1][j + 1].rgbtBlue;
                count++;
            }

            image[i][j].rgbtRed = round((float)sumred / count);
            image[i][j].rgbtGreen = round((float)sumgreen / count);
            image[i][j].rgbtBlue = round((float)sumblue / count);
        }
    }

    return;
}
