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
        cout << first << " + " << second << " = " << answer;
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
        cout << first << " - " << second << " = " << answer;
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
        int answer = GetAnswer(first, second);
        cout << first << " * " << second << " = " << answer;
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
class CintHandler
{
};

int main()
{
    // Assign seed.
    srand(time(0));

    // Create example problem.
    AdditionProblem addprob;
    SubtractionProblem subprob;
    MultiplicationProblem multiprob;

    // Display example problem.
    addprob.DisplayProblem();
    cout << "\n";
    subprob.DisplayProblem();
    cout << "\n";
    multiprob.DisplayProblem();
    return 0;
};