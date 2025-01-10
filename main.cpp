#include <iostream>
#include <regex>
#include <vector>
#include <string>

class EmailHandler {
private:
    std::vector<std::string> emailAddresses;

    // Regular expression for validating an email address
    bool isValidEmail(const std::string& email) {
        const std::regex emailPattern(
            R"((^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+$))"
        );
        return std::regex_match(email, emailPattern);
    }

public:
    // Add an email to the list
    void addEmail(const std::string& email) {
        emailAddresses.push_back(email);
    }

    // Validate all emails and return the valid ones
    std::vector<std::string> getValidEmails() {
        std::vector<std::string> validEmails;
        for (const auto& email : emailAddresses) {
            if (isValidEmail(email)) {
                validEmails.push_back(email);
            } else {
                std::cerr << "Invalid email detected: " << email << std::endl;
            }
        }
        return validEmails;
    }

    // Print all stored emails
    void printEmails() const {
        std::cout << "Stored Emails:" << std::endl;
        for (const auto& email : emailAddresses) {
            std::cout << " - " << email << std::endl;
        }
    }

    // Clear all stored emails
    void clearEmails() {
        emailAddresses.clear();
        std::cout << "Email list cleared." << std::endl;
    }
};

int main() {
    EmailHandler handler;

    // Add some emails
    handler.addEmail("user@example.com");
    handler.addEmail("invalid-email@");
    handler.addEmail("another.valid@example.org");
    handler.addEmail("kb@bellmann-engineering.com");

    // Print all emails
    handler.printEmails();

    // Validate and get valid emails
    std::cout << "\nValid Emails:" << std::endl;
    for (const auto& email : handler.getValidEmails()) {
        std::cout << " - " << email << std::endl;
    }

    // Clear emails
    handler.clearEmails();

    return 0;
}
