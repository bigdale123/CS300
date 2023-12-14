#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <unordered_set>
#include <curl/curl.h>
#include "wikiLadder.h"

/**
 * @details
 * We don't really need to construct anything, so the constructor is blank.
 */
wikiLadder::wikiLadder() {}

/**
 * @details
 * This callback function is registered with libcurl to write data from the curl.
 * It writes the received data to the value provided at the std::string pointer `content`.
 * The total number of bytes written is returned.
 *
 * @see getLinks
 */
size_t wikiLadder::curlDataWriteCallback(void *ptr, size_t size, size_t nmemb, std::string* content) {
    // https://curl.se/libcurl/c/url2file.html
    content->append((char*)ptr, size*nmemb);
    return size*nmemb;
}



/**
 * @details
 * The function initiates an HTTP request to the specified Wikipedia page using libcurl.
 * Upon successful retrieval of the page content, it extracts links using a regular expression.
 * The regex pattern ensures that only valid Wikipedia article links are considered and excludes certain Wikipedia pages (e.g., Main_Page, Special:).
 * Each extracted link is appended to the 'links' vector after validation.
 * The resulting vector contains URLs pointing to Wikipedia articles on the provided page.
 *
 * @see curlDataWriteCallback
 * @see recursion_limit
 */
std::vector<std::string> wikiLadder::getLinks(std::string wikiPage) {
    // https://stackoverflow.com/questions/389069/programmatically-reading-a-web-page
    // https://curl.se/libcurl/c/url2file.html
    CURL *curl;
    CURLcode res;
    std::vector<std::string> links;

    curl = curl_easy_init();
    if(curl) {
        std::string content;
        curl_easy_setopt(curl, CURLOPT_URL, wikiPage.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curlDataWriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &content);
        res = curl_easy_perform(curl);
        if(res == CURLE_OK){
            std::smatch matches;
            std::regex href_regex("href\\s*=\\s*(?:['\"])(.*?)(?:['\"])");
            while(regex_search(content, matches, href_regex)) {
                std::string href_value = matches[1].str();
                // Regex pattern includes a "blacklist" that avoids many wikipedia pages that aren't articles.
                // Also checks that an anchor actually starts with /wiki, giving us only wiki pages (ideally).
                std::regex valid_pattern(R"~(^(\/wiki(?!\/(?:Wikipedia:|Special:|Main_Page|Portal:|Help:|Category:|File:|Template:|Template_talk:|Talk:))))~");
                if(std::regex_search(href_value, valid_pattern)){
                    // std::cout << "https://en.wikipedia.org"+href_value << std::endl;
                    links.push_back("https://en.wikipedia.org"+href_value);
                }
                content = matches.suffix();
            }
        }
        else {
            std::cout << "curl_easy_perform failed with res=" << res << std::endl;
        }
        curl_easy_cleanup(curl);
    }
    return links;
}

/**
 * @details
 * findLadder uses a depth-first search strategy to explore possible paths in the Wikipedia network.
 * It stops the recursion when the depth reaches the recursion limit.
 * The visited set is used to avoid revisiting pages and forming cycles in the ladder.
 * The link != source condition is added to avoid duplicating the source in the ladder.
 */
std::vector<std::string> wikiLadder::findLadder(std::string source, std::string destination, int depth) {
    visited.insert(source);    //include original source in visited pages
    if(depth == recursion_limit) {
        return {};
    }
    std::string currentPage = source;
    std::vector<std::string> links = getLinks(currentPage);
    if (std::find(links.begin(), links.end(), destination) != links.end()) {
        // Destination link is on source page.
        return {source, destination};
    }
    else {
        for(std::string link : links) {
            if (visited.find(link) == visited.end() && link != source) { // added link != source to avoid duplication in the ladder.
                visited.insert(link);
                std::vector<std::string> ladder = findLadder(link, destination, depth + 1);
                if(!ladder.empty()) {
                    ladder.insert(ladder.begin(), source);
                    return ladder;
                }
            }
        }
    }

    return {}; // No ladder found.
    
}