#include <iostream>
#include <cstdlib>
using namespace std;

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
    static int GetRandomNum(int maxNum)
    {
        return (rand() % maxNum) + 1;
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

// Output handler.
class CoutHandler
{

public:
    void DisplayProblems(int problemNum)
    {
        for (int i = 0; i < problemNum; i++)
        {
        }
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

int main()
{
    // Assign seed.
    srand(time(0));

    // Create example problem.
    AdditionProblem addprob;
    SubtractionProblem subprob;
    MultiplicationProblem multiprob;
    CinHandler cinhandler;

    // Display example problems.
    addprob.DisplayProblem();
    int answer = cinhandler.EnterAnswer();
    if (addprob.IsAnswerCorrect(answer))
    {
        cout << "correct!\n";
    }
    else
    {
        cout << "incorrect\n";
    }

    subprob.DisplayProblem();
    answer = cinhandler.EnterAnswer();
    if (subprob.IsAnswerCorrect(answer))
    {
        cout << "correct!\n";
    }
    else
    {
        cout << "incorrect\n";
    }

    multiprob.DisplayProblem();
    answer = cinhandler.EnterAnswer();
    if (multiprob.IsAnswerCorrect(answer))
    {
        cout << "correct!\n";
    }
    else
    {
        cout << "incorrect\n";
    }

    return 0;
};