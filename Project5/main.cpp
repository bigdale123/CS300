#include <iostream>
#include <string>
#include <vector>
#include <curl/curl.h>
#include <cassert>
#include "wikiLadder.h"

//Testing for wikiLadder class
int main() {
    
    // Test case 1: University of Alabama at Birmingham to NASA, no direct link.
    wikiLadder wl = wikiLadder();
    std::vector<std::string> ladder = wl.findLadder("https://en.wikipedia.org/wiki/University_of_Alabama_at_Birmingham", "https://en.wikipedia.org/wiki/NASA", 0);
    for(int i = 0; i < ladder.size(); i++) {
        std::cout << ladder[i] << std::endl;
    }
    std::cout << std::endl;
    // wikiLadder longer than 2 elements, since the source does not link directly to the destination
    assert(ladder.size() > 2);
    // first element in wikiLadder is the source
    assert(ladder[0] == "https://en.wikipedia.org/wiki/University_of_Alabama_at_Birmingham");
    // last element in wikiLadder is the destination
    assert(ladder[ladder.size()-1] == "https://en.wikipedia.org/wiki/NASA");
    // source is not repeated in the wikiLadder
    for (int i = 1; i < ladder.size(); i++) {
        assert(ladder[i] != "https://en.wikipedia.org/wiki/University_of_Alabama_at_Birmingham");
    }
    // destination is not repeated in the wikiLadder
    for (int i = 0; i < ladder.size()-1; i++) {
        assert(ladder[i] != "https://en.wikipedia.org/wiki/NASA");
    }

    // Test case 2: Second from last rung in first ladder to Nasa, direct link.
    std::vector<std::string> finalRung = wl.findLadder(ladder[ladder.size()-2], "https://en.wikipedia.org/wiki/NASA", 0);
    for(int i = 0; i < finalRung.size(); i++) {
        std::cout << finalRung[i] << std::endl;
    }
    std::cout << std::endl;
    // wikiLadder contains two elements, as the source links directly to the destination
    assert(finalRung.size() == 2);
    // first element in wikiLadder is the source
    assert(finalRung[0] == ladder[ladder.size()-2]);
    // last element in wikiLadder in the destination
    assert(finalRung[1] == "https://en.wikipedia.org/wiki/NASA");

    // Test case 3: Divergent boundary to NASA, one link in between source and destination.
    wikiLadder wl2 = wikiLadder();
    std::vector<std::string> ladderFewRungs = wl2.findLadder("https://en.wikipedia.org/wiki/Divergent_boundary","https://en.wikipedia.org/wiki/NASA", 0);
    for(int i = 0; i < ladderFewRungs.size(); i++) {
        std::cout << ladderFewRungs[i] << std::endl;
    }
    std::cout << std::endl;
    // wikiLadder contains three elements: the source, destination, and a common link between them
    assert(ladderFewRungs.size() == 3);
    // first element of wikiLadder is the source
    assert(ladderFewRungs[0] == "https://en.wikipedia.org/wiki/Divergent_boundary");
    // last element of wikiLadder is the destination
    assert(ladderFewRungs[ladderFewRungs.size()-1] == "https://en.wikipedia.org/wiki/NASA");

    // Test case 4: William Shakespeare to Anne Hathaway (wife of Shakespeare), direct link
    wikiLadder wl3 = wikiLadder();
    std::vector<std::string> ladderOneRung = wl3.findLadder("https://en.wikipedia.org/wiki/William_Shakespeare","https://en.wikipedia.org/wiki/Anne_Hathaway_(wife_of_Shakespeare)", 0);
    for(int i = 0; i < ladderOneRung.size(); i++) {
        std::cout << ladderOneRung[i] << std::endl;
    }
    std::cout << std::endl;
    // direct link, two elements in wikiLadder
    assert(ladderOneRung.size() == 2);
    assert(ladderOneRung[0] == "https://en.wikipedia.org/wiki/William_Shakespeare");
    assert(ladderOneRung[ladderOneRung.size()-1] == "https://en.wikipedia.org/wiki/Anne_Hathaway_(wife_of_Shakespeare)");

    // Test case 5: Beetlejuice to Coraline, no direct link
    wikiLadder wl4 = wikiLadder();
    std::vector<std::string> ladderManyRungs = wl4.findLadder("https://en.wikipedia.org/wiki/Beetlejuice", "https://en.wikipedia.org/wiki/Coraline_(film)", 0);
    for(int i = 0; i < ladderManyRungs.size(); i++) {
        std::cout << ladderManyRungs[i] << std::endl;
    }
    std::cout << std::endl;
    // no direct link, wikiLadder longer than two elements
    assert(ladderManyRungs.size() > 2);
    assert(ladderManyRungs[0] == "https://en.wikipedia.org/wiki/Beetlejuice");
    assert(ladderManyRungs[ladderManyRungs.size()-1] == "https://en.wikipedia.org/wiki/Coraline_(film)");
    for (int i = 1; i < ladderManyRungs.size(); i++) {
        assert(ladderManyRungs[i] != "https://en.wikipedia.org/wiki/Beetlejuice");
    }
    for (int i = 0; i < ladderManyRungs.size()-1; i++) {
        assert(ladderManyRungs[i] != "https://en.wikipedia.org/wiki/Coraline_(film)");
    }

    // Test case 6: Knitting to Folklore, no direct link
    wikiLadder wl5 = wikiLadder();
    std::vector<std::string> ladderManyRungs2 = wl5.findLadder("https://en.wikipedia.org/wiki/Knitting", "https://en.wikipedia.org/wiki/Folklore", 0);
    for(int i = 0; i < ladderManyRungs2.size(); i++) {
        std::cout << ladderManyRungs2[i] << std::endl;
    }
    std::cout << std::endl;
    // no direct link, wikiLadder longer than two elements
    assert(ladderManyRungs2.size() > 2);
    assert(ladderManyRungs2[0] == "https://en.wikipedia.org/wiki/Knitting");
    assert(ladderManyRungs2[ladderManyRungs2.size()-1] == "https://en.wikipedia.org/wiki/Folklore");
    for (int i = 1; i < ladderManyRungs2.size(); i++) {
        assert(ladderManyRungs2[i] != "https://en.wikipedia.org/wiki/Knitting");
    }
    for (int i = 0; i < ladderManyRungs2.size()-1; i++) {
        assert(ladderManyRungs2[i] != "https://en.wikipedia.org/wiki/Folklore");
    }
}