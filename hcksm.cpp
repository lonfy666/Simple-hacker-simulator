#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <cstdlib>
#include <string>
#include <ctime>
#include <sstream>
#include <locale>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

using namespace std;
using namespace std::chrono_literals;

void printWithDelay(const string& text, const string& color = RESET, int delay_ms = 500, bool animateDots = false) {
    if (animateDots) {
        for (int i = 0; i < 3; ++i) {
            cout << "\r" << color << text;
            for (int j = 0; j <= i; ++j)
                cout << ".";
            cout << RESET << flush;
            this_thread::sleep_for(chrono::milliseconds(delay_ms / 3));
        }
        cout << endl;
    }
    else {
        cout << color << text << RESET << endl;
        this_thread::sleep_for(chrono::milliseconds(delay_ms));
    }
}

int main()
{
    srand(time(nullptr));

    printWithDelay("Checking your saved IP's", YELLOW, 600, true);

    vector<string> deviceAliases = {
        "Office Printer", "Workstation-PC-7", "SQL Database",
        "Smart Fridge", "CCTV-Camera-12", "NAS-Storage", "VPN Gateway",
        "IoT-Lamp", "Router", "Smart TV", "VALVE Database",
        "Wargaming storage", "ICBC-ATM", "Nova-Post Parcel Machine"
    };
    vector<string> geoLocations = {
        "Tokyo, Japan", "Berlin, Germany", "Kyiv, Ukraine",
        "New York, USA", "Moscow, Russia", "Paris, France",
        "Toronto, Canada", "Seoul, South Korea", "London, UK",
        "Novosibirsk, Russia", "Chernivtsi, Ukraine", "Minsk, Belarus",
        "Orsha, Belarus", "Lvov, Ukraine", "Cologne, Germany",
        "Cluj-Napoca, Romania", "Prague, Czech", "Belgrad, Serbia"
    };

    vector<string> ipList;
    vector<string> aliasList;
    for (int i = 0; i < 5; ++i) {
        int a = rand() % 256;
        int b = rand() % 256;
        int c = rand() % 256;
        int d = rand() % 256;
        int port = rand() % (65535 - 1024 + 1) + 1024;
        string ip = to_string(a) + "." + to_string(b) + "." + to_string(c) + "." + to_string(d) + " : " + to_string(port);
        string alias = deviceAliases[rand() % deviceAliases.size()];
        ipList.push_back(ip);
        aliasList.push_back(alias);
    }

    cout << CYAN << "\nFound IP addresses:\n" << RESET;
    for (int i = 0; i < ipList.size(); ++i) {
        cout << "[" << i + 1 << "] " << ipList[i] << " | Target: \"" << aliasList[i] << "\"" << endl;
    }

    int choice = 0;
    do {
        cout << YELLOW << "\nSelect IP (1-" << ipList.size() << "): " << RESET;
        cin >> choice;
    } while (choice < 1 || choice > ipList.size());

    string targetIP = ipList[choice - 1];
    string location = geoLocations[rand() % geoLocations.size()];

    printWithDelay("Scanning nearby hosts", YELLOW, 500, true);
    printWithDelay("Sniffing open ports", YELLOW, 500, true);
    printWithDelay("Decrypting MAC addresses", YELLOW, 500, true);
    printWithDelay("Matching IPs with device aliases", YELLOW, 500, true);

    vector<string> randomInterrupts = {
        "Firewall detected unusual traffic. Retrying...",
        "Connection lost. Reconnecting...",
        "Access denied. Brute-forcing password...",
        "Proxy tunnel unstable. Stabilizing...",
        "Routing through backup node...",
        "VPN interference detected. Switching channel..."
    };

    if (rand() % 100 < 30) {
        string interrupt = randomInterrupts[rand() % randomInterrupts.size()];
        printWithDelay(interrupt, RED, 800, true);
    }
    
    printWithDelay("\nAnalyzing IP " + targetIP + "...", GREEN, 900, true);
    printWithDelay("Location: " + location, CYAN, 500, false);

    vector<string> actions = {
        "Connecting to target...",
        "Bypassing firewall...",
        "Accessing root...",
        "Root access: success",
        "Downloading secret data...",
        "Decrypting files...",
        "Uploading malware...",
        "Cleaning logs...",
        "Disconnecting...",
        "Hack complete."
    };

    for (const string& action : actions) {
        string color;
        bool animate = action.find("...") != string::npos;
        if (action.find("success") != string::npos || action.find("complete") != string::npos)
            color = GREEN;
        else if (action.find("error") != string::npos)
            color = RED;
        else if (action.find("Downloading") != string::npos || action.find("Uploading") != string::npos)
            color = CYAN;
        else
            color = YELLOW;

        printWithDelay(action, color, rand() % 600 + 200, animate);
    }

    return 0;
}