/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert all of the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
#include <vector>
struct T
{
    T(int v, const char* namee)  : //1
        value(v),
        name(namee)
        {}
    int value ;
    std::string name;
};

struct ComparingMachine                              //4
{
    T* compare(T& a, T& b) //5
    {
        if( a.value < b.value ) return &a;
        if( a.value > b.value ) return &b;
        return nullptr;
    }
};

struct U
{
    float bing { 4.3f }, boom { 5.6f };
    float poodlyDoodly(const float& updatedVal)     //12
    {
        std::cout << "U's bing value: " << this->bing << std::endl;
        this->bing = updatedVal;
        std::cout << "U's bing updated value: " << this->bing << std::endl;
        while( std::abs(this->boom - this->bing) > 0.001f )
        {
            /*
            write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
            */
            this->boom = (this->boom - this->bing)/2;
        }
        std::cout << "U's boom updated value: " << this->boom << std::endl;
        return this->boom * this->bing;
    }
};

struct DiddlyItaly
{
    static float noodlyOodly(U& that, const float& updatedVal )        //10
    {
        std::cout << "U's bing value: " << that.bing << std::endl;
        that.bing = updatedVal;
        std::cout << "U's bing updated value: " << that.bing << std::endl;
        while( std::abs(that.boom - that.bing) > 0.001f )
        {
        /*
             write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
        */
            that.boom = (that.boom - that.bing)/2;
        }
        std::cout << "U's boom updated value: " << that.boom << std::endl;
        return that.boom * that.bing;
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T badaBing( 4, "@");                                             //6
    T badaBoom( 5, "!");                                             //6
    
    ComparingMachine f;                                            //7
    auto* smaller = f.compare(badaBing, badaBoom); 
    
    if (smaller != nullptr)
    {
        std::cout << "the smaller one is << " << smaller->name << std::endl;
    }            
    else
    {
        std::cout << badaBing.value << " is equal to " <<  badaBoom.value << "\n";  
    }
    
    
    U waddleDee;
    float updatedValue = 5.f;
    std::cout << "[static func] waddleDee's multiplied values: " << DiddlyItaly::noodlyOodly( waddleDee, updatedValue) << std::endl;                  //11
    
    U scrabbleTabble;
    std::cout << "[member func] scrabbleTabble's multiplied values: " << scrabbleTabble.poodlyDoodly( updatedValue ) << std::endl;
}
