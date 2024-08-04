#include <iostream>
#include <vector>
#include <map>

using namespace std;

// variables to change
static int lookBehind = 4;
int textCharacterLength = 100000;
int storyOutputLength = 2000;


vector<char> text;
map<string, map<char, int>> nextCharacters;
map<string, int> totalCount;
string story;

void solve() {
    srand(time(nullptr));
    // Reading the input
    for (int i = 0; i < textCharacterLength; i++) {
        char read = getchar();
        text.push_back(read);
    }
    // Creating start string
    string currentString = "";
    for (int i = 0; i < lookBehind; i++) {
        currentString += text[i];
    }
    // Set up of maps
    for (int i = lookBehind; i < textCharacterLength; i++) {
        char next = text[i];
        nextCharacters[currentString][next]++;
        totalCount[currentString]++;
        currentString.erase(0, 1);
        currentString += next;
    }
    // Making the story
    currentString = "That";
    story += currentString;
    for (int i = 0; i < storyOutputLength; i++) {
        int total = totalCount[currentString];
        if (total > 0) {
            int randomNumber = 1 + (rand() % total);
            int sum = 0;
            auto point = nextCharacters[currentString].begin();
            int counter = 0;
            while (counter < nextCharacters[currentString].size()) {
                sum += point -> second;
                counter++;
                if (randomNumber <= sum) {
                    story += point -> first;
                    currentString.erase(0, 1);
                    currentString += point -> first;
                    break;
                }
                advance(point, 1);
            }
        } else {
            break;
        }
    }
    cout << story;


}




int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    solve();

    return 0;
}
