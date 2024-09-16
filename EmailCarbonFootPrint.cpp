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
