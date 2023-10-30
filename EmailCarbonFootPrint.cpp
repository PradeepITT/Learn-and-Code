#include <iostream>
#include <string>

using namespace std;

class EmailCarbonFootprint {
public:
    double Inbox_CarbonFootprint;
    double Sent_CarbonFootprint;
    double Spam_CarbonFootprint;
    double Total_CarbonFootprint;

    EmailCarbonFootprint(int spam_Emails, int standard_Emails, int with_attachment_Emails) {
        Inbox_CarbonFootprint = spam_Emails * 0.3 + standard_Emails * 4;
        Sent_CarbonFootprint = standard_Emails * 4;
        Spam_CarbonFootprint = spam_Emails * 0.3;
        Total_CarbonFootprint = Inbox_CarbonFootprint + Sent_CarbonFootprint + with_attachment_Emails * 50;
    }

    void DisplayDayTotal() {
        cout << "Carbon Footprint of Emails in a day" << endl;
        cout << "Inbox: " << Inbox_CarbonFootprint << " g CO2e" << endl;
        cout << "Sent: " << Sent_CarbonFootprint << " g CO2e" << endl;
        cout << "Spam: " << Spam_CarbonFootprint << " g CO2e" << endl;
        cout << "Total: " << Total_CarbonFootprint << " g CO2e" << endl;
    }
};

// Function to input email data
void InputEmailData(int& spam_Emails, int& standard_Emails, int& attachment_Emails) {
    cout << "Enter the number of spam emails received: ";
    cin >> spam_Emails;

    cout << "Enter the number of standard emails received: ";
    cin >> standard_Emails;

    cout << "Enter the number of emails with attachments received: ";
    cin >> attachment_Emails;
}

int main() {
    cout << "Email Carbon Footprint Calculator" << endl;
        string email_Id;
        cout << "Enter the Email Id : ";
        cin>>email_Id;
        int spam_Emails, standard_Emails, attachment_Emails;
        InputEmailData(spam_Emails, standard_Emails, attachment_Emails);
        EmailCarbonFootprint emailFootprint(spam_Emails, standard_Emails, attachment_Emails);
        emailFootprint.DisplayDayTotal();
    return 0;
}
