#include <iostream>
#include <string>
#include "EmailCarbonFootprint.cpp"

void InputEmailData(int& spam_Emails, int& standard_Emails, int& attachment_Emails) {
    cout << "Enter the number of spam emails received: ";
    cin >> spam_Emails;

    cout << "Enter the number of standard emails received: ";
    cin >> standard_Emails;

    cout << "Enter the number of emails with attachments received: ";
    cin >> attachment_Emails;
}

bool ValidateEmailData(int spam_Emails, int standard_Emails, int attachment_Emails) {
   if (spam_Emails < 0 || standard_Emails < 0 || attachment_Emails < 0) {
       return false;
   }

   return true;
}

int main() {
   cout << "Email Carbon Footprint Calculator" << endl;
       string email_Id;
       cout << "Enter the Email Id : ";
       cin>>email_Id;
       int spam_Emails, standard_Emails, attachment_Emails;
       PromptEmailData(spam_Emails, standard_Emails, attachment_Emails);

   if (!ValidateEmailData(spam_Emails, standard_Emails, attachment_Emails)) {
       cout << "Invalid input. Please enter positive integers for the number of emails." << endl;
       return 1;
   }

   EmailCarbonFootprint emailFootprint(spam_Emails, standard_Emails, attachment_Emails);
   emailFootprint.DisplayDayTotal();
   return 0;
}