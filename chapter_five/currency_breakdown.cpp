#include <iostream>

int main()
{
    std::cout << "Enter amount in pence: ";
    int totalPence{};
    std::cin >> totalPence;

    if (totalPence < 0)
    {
        std::cout << "Amount cannot be negative.\n";
        return 1;
    }
    else if (totalPence == 0)
    {
        std::cout << "No money entered.\n";
        return 0;
    }
    else if (totalPence >= 1000)
    {
        std::cout << "Large amount entered.\n";
    }
    
    constexpr int poundsPerPence{100};
    constexpr int fiftyPence{50};
    constexpr int twentyPence{20};
    constexpr int tenPence{10};
    constexpr int fivePence{5};
    constexpr int twoPence{2};
    

    int remaining{ totalPence };

    int pounds{ remaining / poundsPerPence };
    remaining = remaining % poundsPerPence;

    int fiftyPs{ remaining / fiftyPence };
    remaining = remaining % fiftyPence;

    int twentyPs{ remaining / twentyPence };
    remaining = remaining % twentyPence;

    int tenPs{ remaining / tenPence };
    remaining = remaining % tenPence;

    int fivePs{ remaining / fivePence };
    remaining = remaining % fivePence;

    int twoPs{ remaining / twoPence };
    remaining = remaining % twoPence;

    int onePs{ remaining };
    
    
    std::cout << totalPence << "p is:\n";
    std::cout << "£" << pounds << "\n"; 
    std::cout << "50p coins: " << fiftyPs << "\n"; 
    std::cout << "20p coins: " << twentyPs << "\n"; 
    std::cout << "10p coins: " << tenPs << "\n"; 
    std::cout << "5p coins: " << fivePs << "\n"; 
    std::cout << "2p coins: " << twoPs << "\n"; 
    std::cout << "1p coins: " << onePs << "\n"; 
    
    
    return 0;
}