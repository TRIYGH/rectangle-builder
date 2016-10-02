// T. Robert Ward
// June 10, 2013
// FINAL Version

#include <iostream>
#include <cstring>

using namespace std;

void goToOtherHalf();
void getBorder();
void getMessage();
void getDimensions();
void drawIt();

void drawFirstLine();
void drawMiddleLines();
void drawMiddleLineWithMessage();

    bool answer = true;
    int rows, columns, numOfCharsInMSG, calcNumCenteredSpaces;
    char hORf, charToPrint, holdingCell, custom;
    string messageToPrint;
//    charToPrint = 'X';
    int calcNumMiddleRows, lowerMiddle, upperMiddle, hollowSpace;

int main()
{
    cout << "*****  RECTANGLE BUILDER  *****\n\n" << endl;

    cout << "Are looking for a custom rectangle ( personalized message ) ? (y/n) ";
    cin >> custom;

    if ( custom == 'y' | custom == 'Y')
        goToOtherHalf();
    else
    {
        while ( answer )
        {
            cout << "\nHow many rows tall? ";
            cin >> rows;
            cout << "\nHow many columns wide? ";
            cin >> columns;

            if ( rows < 3 || columns < 5 )
                {answer = true;
                cout << "\nYour rows/columns are invalid - please reenter - >3 & >5, respectively.\n\n\n";
                }
                else
                    answer = false;
        }

        answer = true;
        while ( answer )
        {
            cout << "\nDo you want it (H)ollow or (F)illed? ";
            cin >> hORf;
            cout << "\nWhat charater do you want to print? ";
            cin >> charToPrint;


            if ( hORf == 'f' || hORf == 'F' ||hORf == 'H' ||hORf == 'h' )
                answer = false;
                else
                    {answer = true;
                    cout << "\nPlease enter an F/f or an H/h.";
                    }
        }

    if ( hORf == 'f' || hORf == 'F')
    {
        for ( int x = 0; x < rows; x++)
        {
            for ( int y = 0; y < columns; y++)
            {
                cout << charToPrint;
            }
            cout << endl;
        }
    }

        else
        {
            for ( int x = 0; x < rows; x++)
            {
                for ( int y = 0; y < columns; y++)
                {
                  if ( x == 0 || x == rows - 1)
                    cout << charToPrint;
                  else if ( y == 0 || y == columns - 1)
                  {
                      cout << charToPrint;
                  }
                  else
                    {
                        holdingCell = charToPrint;
                        charToPrint = ' ';
                        cout << charToPrint;
                        charToPrint = holdingCell;
                    }
                }
                cout << endl;
            }

        }
    }
    return 0;
}

void goToOtherHalf()
{
    getBorder();
    getMessage();
    getDimensions();
    drawIt();

}

void getBorder()
            {cout << "\nWhat charater do you want as your border? ";
            cin >> charToPrint;}

void getMessage()
            {
            cout << "\nWhat message do you want in your rectangle? ";
            getline(cin, messageToPrint);
            getline(cin, messageToPrint);
            }

void getDimensions()
            {
                bool goodanswer = true;
                do
                {
            cout << "\nHow many rows tall? ";
            cin >> rows;

            numOfCharsInMSG = messageToPrint.length();
            cout << "\n\n     *** FYI - You need at least " << numOfCharsInMSG + 9 << " columns wide. ***";
            cout << "\nHow many columns wide? ";
            cin >> columns;

            if ( (numOfCharsInMSG + 8) < columns)
                goodanswer = false;
            else
                cout << "\nYour message does not fit inside your rectangle; please try again.\n";
            if ( columns > 4 )
                goodanswer = false;
            else
                cout << "\nYour message does not fit inside your rectangle; please try again.\n";

                }while(goodanswer);
            }
void drawIt()
        {
    cout << endl;
    //cout << rows << columns << numOfCharsInMSG;
    calcNumMiddleRows = rows - 3;
    upperMiddle = calcNumMiddleRows / 2;
    lowerMiddle = calcNumMiddleRows - upperMiddle;

    calcNumCenteredSpaces = columns - 2 - numOfCharsInMSG;  //

    drawFirstLine();

    for ( int a = 0; a < upperMiddle; a++)
        drawMiddleLines();

    hollowSpace = calcNumCenteredSpaces / 2;
    drawMiddleLineWithMessage();

   for ( int b = 0; b < lowerMiddle; b++)
        drawMiddleLines();

    drawFirstLine();  // *** This is really the LAST line ... but SAME code.

        }

    void drawFirstLine()
    {
    for ( int x = 0; x < columns; x++)
        {
        cout << charToPrint;
        }
        cout << endl;
    }

    void drawMiddleLines()
    {
        for ( int c = 0; c < columns; c++)
        {
            if ( c == 0 | c == (columns - 1))
                cout << charToPrint;
            else
                cout << " ";
        }
        cout << endl;
    }

    void drawMiddleLineWithMessage()
    {
        cout << charToPrint;
        for ( int d = 0; d < hollowSpace; d++ )
            cout << " ";
        cout << messageToPrint;
        int theRest = calcNumCenteredSpaces - hollowSpace;
        for ( int d = 0; d < theRest; d++ )
            cout << " ";
        cout << charToPrint << endl;
    }
