/*
 * CGM Lab Assignment - 1
 * Question: Write a C/C++ program using a graphics library/tool to draw 
 *           the following basic graphics primitives in a single program:
 *           1. A straight line
 *           2. A circle
 *           3. A rectangle
 *           4. A triangle
 *
 * Student Name : Sanskriti Madrele
 * Roll No      : IC-2K24-85
 */

#include <graphics.h>
#include <conio.h>
#include <cstring>

int main(int argc, char* argv[])
{
    // Initialize graphics window (Width: 800, Height: 600)
    initwindow(800, 600, (char*)"CGM Lab Assignment 1 - Basic Graphics Primitives");

    // Title & Header Information
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    setcolor(WHITE);
    outtextxy(220, 25, (char*)"CGM LAB ASSIGNMENT - 1");

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    setcolor(LIGHTGRAY);
    outtextxy(280, 55, (char*)"Basic Graphics Primitives");
    outtextxy(230, 80, (char*)"Name: Sanskriti Madrele  |  Roll No: IC-2K24-85");

    // Divider Borders for the 4 Sections
    setcolor(DARKGRAY);
    rectangle(40, 110, 760, 530); // Outer border
    line(400, 110, 400, 530);     // Vertical divider
    line(40, 315, 760, 315);      // Horizontal divider

    // ==========================================
    // 1. A STRAIGHT LINE (Top-Left Quadrant)
    // ==========================================
    setcolor(LIGHTCYAN);
    outtextxy(80, 135, (char*)"1. Straight Line");
    line(100, 210, 320, 210);

    // ==========================================
    // 2. A CIRCLE (Top-Right Quadrant)
    // ==========================================
    setcolor(YELLOW);
    outtextxy(450, 135, (char*)"2. Circle");
    circle(580, 210, 55);

    // ==========================================
    // 3. A RECTANGLE (Bottom-Left Quadrant)
    // ==========================================
    setcolor(LIGHTGREEN);
    outtextxy(80, 340, (char*)"3. Rectangle");
    rectangle(110, 380, 310, 480);

    // ==========================================
    // 4. A TRIANGLE (Bottom-Right Quadrant)
    // ==========================================
    setcolor(LIGHTMAGENTA);
    outtextxy(450, 340, (char*)"4. Triangle");
    // Draw triangle using 3 lines connecting (x1,y1) -> (x2,y2) -> (x3,y3) -> (x1,y1)
    int x1 = 580, y1 = 370; // Top vertex
    int x2 = 500, y2 = 480; // Bottom-left vertex
    int x3 = 660, y3 = 480; // Bottom-right vertex
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    // Footer
    setcolor(WHITE);
    outtextxy(255, 555, (char*)"Press any key to close the window...");

    // Automatically save a screenshot of the output window
    writeimagefile("output_screenshot.bmp", 0, 0, 800, 600);

    // If passed "--save-only", exit immediately (for automated screenshot generation)
    if (argc > 1 && strcmp(argv[1], "--save-only") == 0) {
        closegraph();
        return 0;
    }

    // Wait for user input before exiting
    getch();

    // Close the graphics window
    closegraph();

    return 0;
}