#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

class UserAgentGenerator {
public:
    UserAgentGenerator();

    std::string generateRandomUserAgent();

private:
    std::vector<std::string> browsers;
    std::vector<std::string> platforms;
    std::vector<std::string> extras;
    std::vector<std::string> usedUserAgents;
};

UserAgentGenerator::UserAgentGenerator() {
    browsers = {"Mozilla/5.0", "Chrome/94.0.4606.81", "Firefox/93.0"};
    platforms = {"Windows NT 10.0; Win64; x64", "Linux x86_64", "Macintosh; Intel Mac OS X 10.15"};
    extras = {"KHTML, like Gecko", "AppleWebKit/537.36", "Gecko/20100101 Firefox/93.0"};
}

std::string UserAgentGenerator::generateRandomUserAgent() {
    srand(static_cast<unsigned>(time(nullptr)));

    std::string userAgent;
    do {
        std::string randomBrowser = browsers[rand() % browsers.size()];
        std::string randomPlatform = platforms[rand() % platforms.size()];
        std::string randomExtra = extras[rand() % extras.size()];

        userAgent = randomBrowser + " (" + randomPlatform + ") " + randomExtra;
    } while (std::find(usedUserAgents.begin(), usedUserAgents.end(), userAgent) != usedUserAgents.end());

    usedUserAgents.push_back(userAgent);

    return userAgent;
}

int main() {
    UserAgentGenerator userAgentGenerator;

    for (int i = 0; i < 15; ++i) {
        std::string userAgent = userAgentGenerator.generateRandomUserAgent();
        std::cout << "Oluşturulan User-Agent " << (i + 1) << ": " << userAgent << std::endl;
    }

    return 0;
}