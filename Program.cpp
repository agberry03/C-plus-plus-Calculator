#include <iostream>  // Read and write to input/output streams.
#include <cstdlib>   // Use rand and srand.
using namespace std; // Use strings.

// Functions to declare before the classes.
// Get a random integer from 1 to maxNum.
static int GetRandomNum(int maxNum)
{
    return (rand() % maxNum) + 1;
}
// Get an integer inputed by the user.
static int EnterAnswer()
{
    int answer;
    cin >> answer;
    return answer;
}

// Classes
// The generic MathProblem class.
// Attributes: firstNum, secondNum, values are randomly determined integers from 1-9.
class MathProblem
{
private:
    int firstNum;
    int secondNum;

public:
    MathProblem()
    {
        int maxNum = 9;
        firstNum = GetRandomNum(maxNum);
        secondNum = GetRandomNum(maxNum);
    }
    // Return the firstNum's value.
    int GetFirstNum()
    {
        return firstNum;
    }
    // Return the secondNum's value.
    int GetSecondNum()
    {
        return secondNum;
    }
    // If the answer == firstNum +/-/* secondNum, return true bool. Otherwise return false.
    bool IsAnswerCorrect(int answer)
    {
        int first = GetFirstNum();
        int second = GetSecondNum();
        return answer == GetAnswer(first, second);
    }

    // Display "firstNum +/-/* secondNum = " to the user.
    virtual void DisplayProblem(){};
    // Return the value of firstNum and secondNum when operated on together.
    virtual int GetAnswer(int firstNum, int secondNum){};
};

// Child of MathProblem, used for addition problems.
class AdditionProblem : public MathProblem
{
public:
    using MathProblem ::MathProblem;

    void DisplayProblem()
    {
        int first = GetFirstNum();
        int second = GetSecondNum();
        int answer = GetAnswer(first, second);
        cout << first << " + " << second << " = ";
    }
    int GetAnswer(int firstNum, int secondNum) override
    {
        return firstNum + secondNum;
    }
};
// Child of MathProblem, used for subtraction problems.
class SubtractionProblem : public MathProblem
{
public:
    void DisplayProblem()
    {
        int first = GetFirstNum();
        int second = GetSecondNum();
        int answer = GetAnswer(first, second);
        cout << first << " - " << second << " = ";
    }
    int GetAnswer(int firstNum, int secondNum) override
    {
        return firstNum - secondNum;
    }
};
// Child of MathProblem, used for multiplication problems.
class MultiplicationProblem : public MathProblem
{
public:
    void DisplayProblem()
    {
        int first = GetFirstNum();
        int second = GetSecondNum();
        cout << first << " * " << second << " = ";
    }
    int GetAnswer(int firstNum, int secondNum) override
    {
        return firstNum * secondNum;
    }
};

// Functions to declare after the classes.
static void DisplayMathProblems(MathProblem problems[50])
{
    for (int i = 0; i < sizeof(problems); i++)
    {
        problems[i].DisplayProblem();
        int answer = EnterAnswer();
        if (problems[i].IsAnswerCorrect(answer))
        {
            cout << "correct!\n";
        }
        else
        {
            cout << "incorrect.\n";
        }
    }
}

// Main
int main()
{
    // Assign seed. Ensures that math problems are random every time, instead of being the same for each build.
    srand(time(0));

    // Input for number of problems to complete.
    cout << "How many problems would you like to solve? ";
    int numberProblems = EnterAnswer();

    // Input for type of problems. 1=Addition, 2=Subtraction, 3=Multiplication
    cout << "What type of problems will you solve? (1-Addition, 2-Subtraction, 3-Multiplication) ";
    int problemType = EnterAnswer();

    // Display Addition Problems.
    if (problemType == 1)
    {
        // Initialize addition problem list.
        AdditionProblem problems[numberProblems];
        DisplayMathProblems(problems);
    }
    // Display Subtraction Problems.
    else if (problemType == 2)
    {
        // Initialize subtraction problem list.
        SubtractionProblem problems[numberProblems];
        DisplayMathProblems(problems);
    }
    // Display Multiplication Problems.
    else if (problemType == 3)
    {
        // Initialize multiplication problem list.
        MultiplicationProblem problems[numberProblems];
        DisplayMathProblems(problems);
    }
    // Otherwise display invalid message.
    else
    {
        cout << "invalid number!";
    }

    return 0;
};