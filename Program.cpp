#include <iostream>
#include <cstdlib>
using namespace std;

// Functions
static int GetRandomNum(int maxNum)
{
    return (rand() % maxNum) + 1;
}

// Classes
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
    int GetFirstNum()
    {
        return firstNum;
    }
    int GetSecondNum()
    {
        return secondNum;
    }
    bool IsAnswerCorrect(int answer)
    {
        int first = GetFirstNum();
        int second = GetSecondNum();
        return answer == GetAnswer(first, second);
    }
    virtual void DisplayProblem(){};
    virtual int GetAnswer(int firstNum, int secondNum){};
};

class AdditionProblem : public MathProblem
{
public:
    using MathProblem ::MathProblem;
    int GetAnswer(int firstNum, int secondNum) override
    {
        return firstNum + secondNum;
    }

    void DisplayProblem()
    {
        int first = GetFirstNum();
        int second = GetSecondNum();
        int answer = GetAnswer(first, second);
        cout << first << " + " << second << " = ";
    }
};

class SubtractionProblem : public MathProblem
{
public:
    int GetAnswer(int firstNum, int secondNum) override
    {
        return firstNum - secondNum;
    }
    void DisplayProblem()
    {
        int first = GetFirstNum();
        int second = GetSecondNum();
        int answer = GetAnswer(first, second);
        cout << first << " - " << second << " = ";
    }
};

class MultiplicationProblem : public MathProblem
{
public:
    int GetAnswer(int firstNum, int secondNum) override
    {
        return firstNum * secondNum;
    }
    void DisplayProblem()
    {
        int first = GetFirstNum();
        int second = GetSecondNum();
        cout << first << " * " << second << " = ";
    }
};
// Input handler.
class CinHandler
{
public:
    static int EnterAnswer()
    {
        int answer;
        cin >> answer;
        return answer;
    }
};
// Output handler.
class CoutHandler
{
public:
    void DisplayAdditionProblems(int problemNum)
    {
        CinHandler cinhandler;
        AdditionProblem problems[problemNum];
        for (int i = 0; i < problemNum; i++)
        {
            problems[i].DisplayProblem();
            int answer = cinhandler.EnterAnswer();
            if (problems[i].IsAnswerCorrect(answer))
            {
                cout << "correct!\n";
            }
            else
            {
                cout << "incorrect\n";
            }
        }
    }
    void DisplaySubtractionProblems(int problemNum)
    {
        CinHandler cinhandler;
        SubtractionProblem problems[problemNum];
        for (int i = 0; i < problemNum; i++)
        {
            problems[i].DisplayProblem();
            int answer = cinhandler.EnterAnswer();
            if (problems[i].IsAnswerCorrect(answer))
            {
                cout << "correct!\n";
            }
            else
            {
                cout << "incorrect\n";
            }
        }
    }
    void DisplayMultiplicationProblems(int problemNum)
    {
        CinHandler cinhandler;
        MultiplicationProblem problems[problemNum];
        for (int i = 0; i < problemNum; i++)
        {
            problems[i].DisplayProblem();
            int answer = cinhandler.EnterAnswer();
            if (problems[i].IsAnswerCorrect(answer))
            {
                cout << "correct!\n";
            }
            else
            {
                cout << "incorrect\n";
            }
        }
    }
};

// Main
int main()
{
    // Assign seed.
    srand(time(0));

    // cin handler
    CinHandler cinhandler;
    // cout handler
    CoutHandler couthandler;

    // Input for number of problems
    cout << "How many problems would you like to solve? ";
    int numberProblems = cinhandler.EnterAnswer();

    // Input for type of problems
    cout << "What type of problems will you solve? (1-Addition, 2-Subtraction, 3-Multiplication) ";
    int problemType = cinhandler.EnterAnswer();

    switch (problemType)
    {
    case 1:
        couthandler.DisplayAdditionProblems(numberProblems);
        break;
    case 2:
        couthandler.DisplaySubtractionProblems(numberProblems);
        break;
    case 3:
        couthandler.DisplayMultiplicationProblems(numberProblems);
        break;
    default:
        cout << "invalid number!";
    }

    return 0;
};