/*
 * CGM Lab Assignment - 2
 * Question: Write a C/C++ program using a graphics library/tool to implement 
 *           the DDA (Digital Differential Analyzer) Line Drawing Algorithm.
 * 
 * The program should:
 * 1. Accept the starting point (x1, y1) and ending point (x2, y2).
 * 2. Calculate the required steps using the DDA algorithm.
 * 3. Plot the line pixel-by-pixel.
 * 4. Display the output graphically.
 *
 * Student Name : Sanskriti Madrele
 * Roll No      : IC-2K24-85
 * Subject      : Computer Graphics & Multimedia (CGM) Lab
 */

#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

// ============================================================================
// DDA Line Drawing Algorithm Implementation
// ============================================================================
void drawDDA(int x1, int y1, int x2, int y2, int color, bool bold = true)
{
    // Step 1: Calculate coordinate differences
    int dx = x2 - x1;
    int dy = y2 - y1;

    // Step 2: Determine number of steps
    int steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

    // Step 3: Calculate increment in x and y for each step
    float x_inc = (float)dx / (float)steps;
    float y_inc = (float)dy / (float)steps;

    // Step 4: Initialize starting point
    float x = (float)x1;
    float y = (float)y1;

    // Step 5: Plot pixels step by step
    for (int i = 0; i <= steps; i++)
    {
        int px = (int)floor(x + 0.5f);
        int py = (int)floor(y + 0.5f);

        // Core DDA pixel plotting
        putpixel(px, py, color);

        // Optional 2x2 footprint for enhanced visibility on high-resolution displays
        if (bold)
        {
            putpixel(px + 1, py, color);
            putpixel(px, py + 1, color);
            putpixel(px + 1, py + 1, color);
        }

        x += x_inc;
        y += y_inc;
    }
}

int main(int argc, char* argv[])
{
    // Default demonstration coordinates
    int x1 = 120, y1 = 160;
    int x2 = 680, y2 = 420;
    bool saveOnly = false;

    // Check for command-line arguments
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "--save-only") == 0)
        {
            saveOnly = true;
        }
    }

    if (argc >= 5 && strcmp(argv[1], "--save-only") != 0)
    {
        x1 = atoi(argv[1]);
        y1 = atoi(argv[2]);
        x2 = atoi(argv[3]);
        y2 = atoi(argv[4]);
    }
    else if (!saveOnly)
    {
        cout << "==============================================================\n";
        cout << "      CGM LAB ASSIGNMENT - 2: DDA LINE DRAWING ALGORITHM      \n";
        cout << "      Name: Anshul Singh Chauhan  |  Roll No: IC-2K24-18         \n";
        cout << "==============================================================\n\n";

        cout << "Enter Starting Point (x1 y1) [Press ENTER for default 120 160]: ";
        string line1;
        getline(cin, line1);
        if (!line1.empty())
        {
            stringstream ss(line1);
            ss >> x1 >> y1;
        }

        cout << "Enter Ending Point (x2 y2)   [Press ENTER for default 680 420]: ";
        string line2;
        getline(cin, line2);
        if (!line2.empty())
        {
            stringstream ss(line2);
            ss >> x2 >> y2;
        }
    }

    // Step 1: Calculate parameters for DDA
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);
    float x_inc = (steps != 0) ? ((float)dx / (float)steps) : 0.0f;
    float y_inc = (steps != 0) ? ((float)dy / (float)steps) : 0.0f;
    float slope = (dx != 0) ? ((float)dy / (float)dx) : 9999.0f;

    // Display calculations in console
    cout << "\n--------------------------------------------------------------\n";
    cout << "                    DDA ALGORITHM CALCULATIONS                 \n";
    cout << "--------------------------------------------------------------\n";
    cout << " Starting Point (x1, y1) : (" << x1 << ", " << y1 << ")\n";
    cout << " Ending Point   (x2, y2) : (" << x2 << ", " << y2 << ")\n";
    cout << " dx = x2 - x1            : " << dx << "\n";
    cout << " dy = y2 - y1            : " << dy << "\n";
    if (dx != 0)
    {
        cout << " Slope (m = dy / dx)     : " << fixed << setprecision(4) << slope << "\n";
    }
    else
    {
        cout << " Slope (m)               : Undefined (Vertical Line)\n";
    }
    cout << " Steps = max(|dx|, |dy|) : " << steps << "\n";
    cout << " X-Increment (dx / steps): " << fixed << setprecision(4) << x_inc << "\n";
    cout << " Y-Increment (dy / steps): " << fixed << setprecision(4) << y_inc << "\n";
    cout << "--------------------------------------------------------------\n";
    cout << " Step-by-Step Rasterization Table (First 10 steps):\n";
    cout << "   Step |   X_calc  |   Y_calc  | Plotted (X, Y)\n";
    cout << "  ------------------------------------------------\n";

    float curX = (float)x1;
    float curY = (float)y1;
    int previewCount = (steps > 10) ? 10 : steps;
    for (int i = 0; i <= previewCount; i++)
    {
        int px = (int)floor(curX + 0.5f);
        int py = (int)floor(curY + 0.5f);
        cout << "    " << setw(3) << i << " | "
             << setw(9) << fixed << setprecision(2) << curX << " | "
             << setw(9) << fixed << setprecision(2) << curY << " | ("
             << setw(4) << px << ", " << setw(4) << py << ")\n";
        curX += x_inc;
        curY += y_inc;
    }
    if (steps > 10)
    {
        cout << "    ... (total " << steps << " steps computed)\n";
        cout << "    " << setw(3) << steps << " | "
             << setw(9) << fixed << setprecision(2) << (float)x2 << " | "
             << setw(9) << fixed << setprecision(2) << (float)y2 << " | ("
             << setw(4) << x2 << ", " << setw(4) << y2 << ")\n";
    }
    cout << "--------------------------------------------------------------\n";
    cout << " Displaying output graphically in window...\n\n";

    // ========================================================================
    // Initialize Graphics Window (Width: 800, Height: 600)
    // ========================================================================
    initwindow(800, 600, (char*)"CGM Lab Assignment 2 - DDA Line Drawing Algorithm");

    // Title & Header Information
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    setcolor(WHITE);
    outtextxy(220, 20, (char*)"CGM LAB ASSIGNMENT - 2");

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    setcolor(LIGHTGRAY);
    outtextxy(245, 48, (char*)"DDA (Digital Differential Analyzer) Line Drawing");
    outtextxy(230, 70, (char*)"Name: Sanskriti Madrele  |  Roll No: IC-2K24-85");

    // Drawing Canvas Border (40, 95, 760, 485)
    setcolor(DARKGRAY);
    rectangle(40, 95, 760, 485);

    // Subtle coordinate grid inside canvas
    setcolor(COLOR(35, 40, 50));
    for (int gx = 80; gx < 760; gx += 40)
    {
        line(gx, 96, gx, 484);
    }
    for (int gy = 135; gy < 485; gy += 40)
    {
        line(41, gy, 759, gy);
    }

    // Canvas Label
    setcolor(DARKGRAY);
    outtextxy(50, 102, (char*)"Graphics Canvas (Pixel Grid)");

    // Plot the Line using DDA Algorithm
    drawDDA(x1, y1, x2, y2, LIGHTCYAN, true);

    // Draw Endpoints and Labels
    // Start Point Marker
    setcolor(LIGHTGREEN);
    circle(x1, y1, 5);
    circle(x1, y1, 2);
    char startLabel[64];
    sprintf(startLabel, "Start Point (%d, %d)", x1, y1);
    outtextxy(x1 + 10, (y1 - 18 > 100) ? (y1 - 18) : (y1 + 10), startLabel);

    // End Point Marker
    setcolor(LIGHTRED);
    circle(x2, y2, 5);
    circle(x2, y2, 2);
    char endLabel[64];
    sprintf(endLabel, "End Point (%d, %d)", x2, y2);
    outtextxy(x2 - 130, (y2 + 10 < 480) ? (y2 + 10) : (y2 - 18), endLabel);

    // Calculation & Parameter Info Dashboard (Bottom Panel)
    setcolor(DARKGRAY);
    rectangle(40, 495, 760, 580);

    // Dashboard Row 1: Coordinates and Differences
    setcolor(LIGHTGRAY);
    char infoRow1[128];
    if (dx != 0)
    {
        sprintf(infoRow1, "Start: (%d, %d)   End: (%d, %d)   dx: %d   dy: %d   Slope (m): %.4f",
                x1, y1, x2, y2, dx, dy, slope);
    }
    else
    {
        sprintf(infoRow1, "Start: (%d, %d)   End: (%d, %d)   dx: %d   dy: %d   Slope (m): Undefined",
                x1, y1, x2, y2, dx, dy);
    }
    outtextxy(52, 506, infoRow1);

    // Dashboard Row 2: Steps and Increments
    char infoRow2[128];
    sprintf(infoRow2, "Steps: %d [max(|dx|, |dy|)]   X-Inc: %.4f   Y-Inc: %.4f   Total Pixels: %d",
            steps, x_inc, y_inc, steps + 1);
    outtextxy(52, 528, infoRow2);

    // Dashboard Row 3: Status & Navigation Prompt
    setcolor(YELLOW);
    outtextxy(52, 552, (char*)"DDA Rule: x_next = x + dx/steps, y_next = y + dy/steps");

    setcolor(WHITE);
    outtextxy(560, 552, (char*)"Press any key to close...");

    // Allow graphics window to refresh and render all primitives
    delay(500);

    // Automatically save a screenshot of the output window
    writeimagefile("output_screenshot.bmp", 0, 0, 800, 600);

    // If passed "--save-only", exit immediately (for automated screenshot generation)
    if (saveOnly)
    {
        delay(200);
        closegraph();
        return 0;
    }

    // Wait for user input before exiting
    getch();

    // Close the graphics window
    closegraph();

    return 0;
}
