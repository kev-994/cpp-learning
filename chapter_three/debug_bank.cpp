#include <iostream>
#include <iomanip>
#include <string>

double applyDeposit(double balance, double deposit)
{
    return balance + deposit;
}

double applyWithdrawal(double balance, double withdrawal)
{
    return balance - withdrawal;
}

bool canWithdraw(double balance, double withdrawal)
{
    return withdrawal <= balance;
}

void printBalance(std::string accountName, double balance)
{
    std::cout << std::fixed << std::setprecision(2);
    std::cout << accountName << " balance: £" << balance << '\n';
}

int main()
{
    std::string accountName{};
    double balance{};
    double deposit{};
    double withdrawal{};

    std::cout << "Enter account name: ";
    std::cin >> accountName;

    std::cout << "Enter starting balance: ";
    std::cin >> balance;

    std::cout << "Enter deposit amount: ";
    std::cin >> deposit;

    std::cout << "Enter withdrawal amount: ";
    std::cin >> withdrawal;

    balance = applyDeposit(balance, deposit);

    if (withdrawal == 0)
    {
    
    }
    else if (canWithdraw(balance, withdrawal))
    {
        balance = applyWithdrawal(balance, withdrawal);
        std::cout << "Withdrawal approved.\n";
    }
    else
    {
        std::cout << "Withdrawal denied.\n";
    }

    printBalance(accountName, balance);

    return 0;
}
