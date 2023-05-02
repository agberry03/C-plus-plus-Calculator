#include <iostream>
#include <cstdlib>
using namespace std;

class MathProblem
{
private:
    int answer;
    int firstNum;
    int secondNum;

public:
    MathProblem()
    {
        int maxNum = 10;
        firstNum = GetRandomNum(maxNum);
        secondNum = GetRandomNum(maxNum);
        answer = SetAnswer(firstNum, secondNum);
    }
    static int GetRandomNum(int maxNum)
    {
        return rand() % maxNum;
    }
    int GetFirstNum()
    {
        return firstNum;
    }
    int GetSecondNum()
    {
        return secondNum;
    }
    int GetAnswer()
    {
        return answer;
    }
    virtual void DisplayProblem(){};
    virtual int SetAnswer(int firstNum, int secondNum){};
};

class AdditionProblem : public MathProblem
{
public:
    using MathProblem ::MathProblem;
    int SetAnswer(int firstNum, int secondNum) override
    {
        return firstNum + secondNum;
    }
    void DisplayProblem()
    {
        cout << GetFirstNum() << " + " << GetSecondNum() << " = " << GetAnswer();
    }
};

class SubtractionProblem : public MathProblem
{
public:
    int SetAnswer(int firstNum, int secondNum)
    {
        return firstNum - secondNum;
    }
    void DisplayProblem()
    {
        cout << GetFirstNum() << " - " << GetSecondNum() << " = " << GetAnswer();
    }
};

class MultiplicationProblem : public MathProblem
{
public:
    int SetAnswer(int firstNum, int secondNum)
    {
        return firstNum + secondNum;
    }
    void DisplayProblem()
    {
        cout << GetFirstNum() << " * " << GetSecondNum() << " = " << GetAnswer() << "\n";
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

    // Display example problem.
    addprob.DisplayProblem();

    return 0;
};