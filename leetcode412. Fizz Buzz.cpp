/* leetcode412. Fizz Buzz
Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for 
the multiples of five output “Buzz”. For numbers which are multiples of both three 
and five output “FizzBuzz”.

Example:

n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]
 */
// way 1 use %
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> vs;
        for(int i=1;i<=n;++i){
            if(!(i%3) && (i%5)){
                vs.push_back("Fizz");
            }
            else if((i%3) && !(i%5)){
                vs.push_back("Buzz");
            }
            else if(!(i%3) && !(i%5)){
                vs.push_back("FizzBuzz");
            } 
            else
                vs.push_back(to_string(i));      
        }
        return vs;
    }
};

// way 1 NOT use %
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> vs;
        int fizz=0;
        int buzz=0;
        for(int i=1;i<=n;++i){
            fizz++;buzz++;
            if(fizz==3 && buzz==5){
                fizz=0;buzz=0;
                vs.push_back("FizzBuzz");
            }             
            else if(fizz==3){
                fizz=0;
                vs.push_back("Fizz");
            }
            else if(buzz==5){
                buzz=0;
                vs.push_back("Buzz");
            }
            else
                vs.push_back(to_string(i));      
        }
        return vs;
    }
};