#include <iostream>
#include <fstream>
using namespace std;
class Login
{
    string username, password, usernamex, passwordx;

public:
    void loginusers()
    {
        cout << "LOGIN" << endl;
        cout << "enter user name " << endl;
        cin >> username;
        cout << "enter password " << endl;
        cin >> password;
        ifstream file(username + ".txt");
        file >> usernamex;
        file >> passwordx;
        if (username == usernamex && password == passwordx)
        {
            cout << "login sucessfully" << endl;
        }
        else
        {
            if (username != usernamex)
            {
                cout << "wrong username";
            }
        
                else if (password != passwordx)
                {
                    cout << "wrong password";
                }
        }
    }
};
class Signup
{
    string username, password;

public:
    void signupusers(Login &login)
    {
        cout << "enter user name " << endl;
        cin >> username;
        cout << "enter password " << endl;
        cin >> password;
        ofstream file(username + ".txt");
        file << username << endl;
        file << password << endl;
        cout << "NOW YOU CAN LOG IN" << endl;
        login.loginusers();
    }
};

class Check
{
    string ans;

public:
    void check(Login &login, Signup &signup)
    {
        cout << "are you new" << endl;
        cin >> ans;
        if (ans == "yes")
        {
            signup.signupusers(login);
        }
        else if (ans == "no")
        {
            login.loginusers();
        }
    }
};
int main()
{
    Login login;
    Signup signup;
    Check id;
    id.check(login, signup);
    return 0;
}
