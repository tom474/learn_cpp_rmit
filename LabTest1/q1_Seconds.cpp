/*
    RMIT University Vietnam
    Course: EEET2482/COSC2082
    Semester: 2023-3
    Lab Assessment: 1
    Author: Tran Manh Cuong
    ID: 3974735
    Compiler used: g++ 8.1.0
    Created  date: 02/12/2023
    Acknowledgement: Canvas, GeeksforGeeks
*/

#include <iostream>

using std::cin;
using std::cout;

int main() {
    int totalSecs, hours, mins, secs; 

    // Prompt user for input total seconds 
    printf("Input total amount of seconds: ");
    scanf("%d", &totalSecs);
	
    // Calculate hours, minutes, and remaining seconds
    hours = totalSecs / 3600; 
    mins = (totalSecs - (3600*hours)) / 60;
    secs =  totalSecs - (3600*hours) - (mins*60);
    printf("It is %d hour(s), %d minute(s) and %d second(s)", hours, mins, secs);
	
    return 0;
}