#include <iostream>

void countOps(int &operationCount)
{
    operationCount++;
}

int main(){
    char op;
    char exit;
    int num1, num2;

    int count=0;
    while(true)
    {   
        do
        {
        std::cout<<"Exit? y/n"<<std::endl;
        std::cin>>exit;
        }
        while(exit != 'y' && exit != 'n');
        if(exit == 'y') {break;}

        countOps(count);

        std::cout<<"Enter the first number"<<std::endl;
        std::cin>>num1;
        
        std::cout<<"Choose an operation between: +, -, *, /, ^"<<std::endl;
        std::cin>>op;

        std::cout<<"Enter the second number"<<std::endl;
        std::cin>>num2;

        switch(op)
        {
            case '+':
                std::cout<<num1+num2<<std::endl;
                break;
            case '-':
                std::cout<<num1-num2<<std::endl;
                break;
            case '*':
                std::cout<<num1*num2<<std::endl;
                break;
            case '/':
                if(num2 == 0)
                {
                    std::cout<<"Error"<<std::endl;
                    break;
                }
                std::cout<<num1/num2<<std::endl;
                break;
            case '^':
                int res = 1;
                for(int _ = 0; _ < num2; _++) res *= num1;
                std::cout<<res<<std::endl;
                break;
            default:
                std::cout<<"Enter a valid operator"<<std::endl;
        }
    }
}