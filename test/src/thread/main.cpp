# include <iostream>
# include <future>
# include <vector>
# include <ctime>
# include <unistd.h>
# include <cstdio>

void randomPrint(char c)
{
    int r = 10;
    while(r--)
    {
        std::cout << c;
        usleep(random()%1000);
    }
}

int test_future()
{
    std::cout << "Hello World" << std::endl;
    auto res1(std::async([](){randomPrint('+');}));
    auto res2(std::async([](){randomPrint('-');}));
    res1.get();
    res2.get();
    std::cout << std::endl << "Finish";
    return 0;
}

int test_future_deffer()
{
    std::cout << "Hello World" << std::endl;
    auto res1(std::async(std::launch::deferred,[](){randomPrint('+');}));
    auto res2(std::async(std::launch::deferred,[](){randomPrint('-');}));
    res1.get();
    res2.get();
    std::cout << std::endl << "Finish";
    return 0;
}

int test_memory_header()
{
    // test_future();
    // test_future_deffer();
    uint64_t last = 0;
    for(int i=0;i < 10;i++)
    {
        void * p = malloc(1024);
        printf("%d : %p, size :%u seg_info:%d magic:%d\n",
            i+1,p,((uint64_t)p)-last,*((int*)(((uint64_t)p)-8)),*((int*)(((uint64_t)p)-4)));
        last = (uint64_t)p;
    }
    return 0;
}

int main()
{
    
    return 0;
}