#ifndef ARGPARSE_HPP
#define ARGPARSE_HPP

#include <iostream>
#include <vector>
#include <string>

void debug()
{
    static int index;
    std::cout << index << std::endl;
    index++;
}

namespace ap
{
    
    /*

    splits
    parses
    handle error


    */



    std::vector<std::string> split(std::string input)
    {
        std::vector<std::string> result;

        char delimiter = ' ';
        std::string buffer;
        size_t index = 0;

        while((index = input.find(delimiter)) != std::string::npos)
        {
            buffer = input.substr(0, index);
            result.push_back(buffer);

            input.erase(0, index+1);
        }
        result.push_back(input); // last element

        return result;
    }

    std::string combine(std::vector<std::string> vector)
    {
        std::string result;

        vector.erase(vector.begin());
        for (auto i : vector)
        {
            static int it;

            result += i;

            it++;
            if (it < vector.size())
                result += " ";
        }

        return result;
    }

} // namespace ap

#endif