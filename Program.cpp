#include <stdlib.h>
#include <iostream>
using namespace std;
class Main {

};

class MathProblem
{
private:
    int answer;
    int firstNum;
    int secondNum;

public:
    MathProblem()
    {
        SetNumbers();
    }
    static int GetRandomNum(int maxNum, int initNum = 1)
    {
        return rand() % maxNum + initNum;
    }
    void SetNumbers()
    {
        int maxNum = 9;
        firstNum = GetRandomNum(maxNum);
        secondNum = GetRandomNum(maxNum);
    }
    void SetAdditionAnswer()
    {
        answer = firstNum + secondNum;
    }
    void DisplayAdditionProblem()
    {
       // cout << firstNum << " + " << lastNum << " = ";
    }
    int GetProblemAnswer(int firstNum, int lastNum)
    {
    }
};

class AdditionProblem: public MathProblem {
    
};

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

class CintHandler {

};