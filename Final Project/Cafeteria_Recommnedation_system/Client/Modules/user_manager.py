import json 

class UserManager:
    def __init__(self, server_communicator, role, user_id):
        self.server_communicator = server_communicator
        self.role = role
        self.user_id = user_id

    def update_user_profile(self):
            endpoint = "/update-user-profile"
            # Diet Preference
            print("Please select one:")
            print("1. Vegetarian")
            print("2. Non Vegetarian")
            print("3. Eggetarian")
            diet_preference_choice = int(input("Enter choice (1/2/3): "))
            if diet_preference_choice == 1:
                new_dietpreference = "Vegetarian"
            elif diet_preference_choice == 2:
                new_dietpreference = "Non Vegetarian"
            elif diet_preference_choice == 3:
                new_dietpreference = "Eggetarian"
            else:
                print("Invalid Input")
                return
            
            # Spice Level
            print("Please select your spice level:")
            print("1. High")
            print("2. Medium")
            print("3. Low")
            spice_level_choice = int(input("Enter choice (1/2/3): "))
            if spice_level_choice == 1:
                new_spicelevel = "High"
            elif spice_level_choice == 2:
                new_spicelevel = "Medium"
            elif spice_level_choice == 3:
                new_spicelevel = "Low"
            else:
                print("Invalid Input")
                return
            
            # Cuisine Preference
            print("What do you prefer most?")
            print("1. North Indian")
            print("2. South Indian")
            print("3. Other")
            cuisine_preference_choice = int(input("Enter choice (1/2/3): "))
            if cuisine_preference_choice == 1:
                new_cuisinepreference = "North Indian"
            elif cuisine_preference_choice == 2:
                new_cuisinepreference = "South Indian"
            elif cuisine_preference_choice == 3:
                new_cuisinepreference = "Other"
            else:
                print("Invalid Input")
                return
            
            # Sweet Tooth
            print("Do you have a sweet tooth?")
            print("1. Yes")
            print("2. No")
            sweet_tooth_choice = int(input("Enter choice (1/2): "))
            if sweet_tooth_choice == 1:
                new_sweettooth = 1
            elif sweet_tooth_choice == 2:
                new_sweettooth = 0
            else:
                print("Invalid Input")
                return

            data = {
                "RoleName": "Employee",
                "UserId": self.user_id,
                "DietPreference": new_dietpreference,
                "SpiceLevel": new_spicelevel,
                "CuisinePreference": new_cuisinepreference,
                "SweetTooth": new_sweettooth
            }
            print(data)
            response = self.server_communicator.send_request(endpoint, data)
            if response["status"] == "success":
                print(response["message"])
            else:
                print(response["message"])