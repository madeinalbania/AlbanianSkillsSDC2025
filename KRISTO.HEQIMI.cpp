#include <iostream>
#include <fstream>
#include <json/json.h>

int main() {
    Json::Value db;
    std::ifstream("users.json") >> db;
    if (!db.isMember("users")) db["users"] = Json::arrayValue;

    std::string u, p, r;
    std::cin >> u >> p >> r;

    Json::Value user;
    user["username"] = u;
    user["password_hash"] = "HASH_" + p;
    user["role"] = r;

    db["users"].append(user);

    std::ofstream("users.json") << db.toStyledString();
}
