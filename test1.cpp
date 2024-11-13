#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using namespace std;

/* Define the exception here */
class BadLengthException: public std::exception
{
private:
    int saved;
public:
    BadLengthException(int n) : saved(n) {}
    
    const char* what() const noexcept {
        std::ostringstream ss;
        ss << saved;
        std::string temp = ss.str();
        std::string s = std::to_string(saved);
        return temp.c_str();
    }
    
};

bool checkUsername(string username) {
	bool isValid = true;
	int n = username.length();
	if(n < 5) {
		throw BadLengthException(n);
	}
	for(int i = 0; i < n-1; i++) {
		if(username[i] == 'w' && username[i+1] == 'w') {
			isValid = false;
		}
	}
	return isValid;
}

int main() {
	int T; cin >> T;
	while(T--) {
		string username;
		cin >> username;
		try {
			bool isValid = checkUsername(username);
			if(isValid) {
				cout << "Valid" << '\n';
			} else {
				cout << "Invalid" << '\n';
			}
		} catch (BadLengthException e) {
			cout << "Too short: " << e.what() << '\n';
		}
	}
	return 0;
}
