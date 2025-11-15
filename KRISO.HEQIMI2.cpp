#include <iostream>
#include <fstream>
#include <json/json.h>

std::string hash_pass(const std::string& p) {
    return "HASH_" + p;
}

int main() {
    Json::Value db;
    std::ifstream("users.json") >> db;
    if (!db.isMember("users")) return 1;

    std::string u, p;
    std::cin >> u >> p;

    for (const auto& user : db["users"]) {
        if (user["username"].asString() == u) {
            if (user["password_hash"].asString() == hash_pass(p)) {
                std::cout << "Logged in as " << u << " (" << user["role"].asString() << ")";
                return 0;
            }
            else {
                std::cout << "Incorrect password";
                return 1;
            }
        }
    }
    std::cout << "User not found";
    return 1;
}
