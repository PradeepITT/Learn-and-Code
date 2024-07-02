from userHandler.user import User
from menuItems.food_menu import FoodMenu

class Chef(User):
    def __init__(self, id, name, role, server_communicator):
        super().__init__(id, name, role, server_communicator)
        self.food_menu = FoodMenu(server_communicator, self.role)

    def user_menu(self):
        print(f"\nWelcome {self.name}({self.role})!")
        while True:
            print("\n1. View Menu Item\n2. Roll Out Tomorrow's Menu\n3. Finalized Menu\n4. Generate Monthly Report\n5. Update Availability of Menu Item\n6. View Feedback\n7. Exit")
            choice = int(input("Enter a choice : "))
            if(choice == 1):
                self.food_menu.view_menu()
            elif(choice == 2):
                self.food_menu.roll_out_menu()
            elif choice == 3:
                print("Displaying finalized menu...")
            # Implement logic for displaying finalized menu
            elif choice == 4:
                print("Generating monthly report...")
            # Implement logic for generating monthly report
            elif choice == 5:
                print("hiii")
                self.food_menu.update_availabilty()
            elif choice == 6:
                self.food_menu.view_feedback()
            elif choice == 7:
                print("\nEXITING...Bye")
                self.server_communicator.close_connection()
                exit()
            else:
                print("Invalid choice. Please enter a valid option.")


