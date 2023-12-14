#ifndef _wikiLadder_h
#define _wikiLadder_h

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

/**
 * @class wikiLadder
 * @brief Class for finding the Wikipedia ladder between two pages.
 */
class wikiLadder {
    private:
        /**
        * @brief The maximum amount of recursion allowed.
        * @details A static variable indicating the recursion limit for the findLadder function. 15 is chosen to 
        * force the finding of a shorter path if one exists. The longest chain between links is eight-degrees, according to 
        * https://en.wikipedia.org/wiki/Wikipedia:Six_degrees_of_Wikipedia. A recursion limit of 15 allows for a few extra steps
        * than the shortest possible route.
        * 
        */
        static const int recursion_limit = 15;

        /**
        * @brief Unordered set used during findLadder to keep track of pages visited to avoid cycles.
        * @details We also use a set to eliminate duplicate values. We don't care if we have visited a page twice,
        * and ideally, we shouldn't visit a page twice.
        */
        std::unordered_set<std::string> visited;

        /**
        * @brief Callback function for the curl operation done in getLinks().
        * @param ptr A pointer to the received data.
        * @param size The size of each element.
        * @param nmemb The number of elements.
        * @param output A pointer to a std::string where the data will be written.
        * @return The total number of bytes written.
        */
        static size_t curlDataWriteCallback(void *ptr, size_t size, size_t nmemb, std::string* output);


        /**
        * @brief Finds every link within a wiki page using libcurl.
        * @param wikiPage A std::string representing the current wiki page being searched for links.
        * @return A vector of strings with each element representing one link within the current wiki page.
        */
        std::vector<std::string> getLinks(std::string wikiPage);
    
    public:
        /**
        * @brief Default constructor for the wikiLadder class.
        */
        wikiLadder();

        /**
        * @brief Recursive function that finds the wiki ladder between the source and destination wiki pages.
        * @details The wiki ladder is a list of every Wikipedia link visited in order to get from the source page to the destination page.
        * @param source A std::string representing the starting page, which must be the first rung in the wiki ladder.
        * @param destination A std::string representing the wiki page being searched for.
        * @param depth The current recursion depth to avoid exceeding the recursion limit.
        * @return A vector of strings representing the wiki ladder.
        * If one exists, each element represents one rung (link) in the wiki ladder.
        * Else, the vector is empty.
        */
        std::vector<std::string> findLadder(std::string source, std::string destination, int depth);

};

#endif