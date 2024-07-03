from userHandler.user import User
from menuItems.food_menu import FoodMenu

class Employee(User):
    def __init__(self, id, name, role, server_communicator):
        super().__init__(id, name, role, server_communicator)
        self.food_menu = FoodMenu(server_communicator, self.role, self.id)

    def user_menu(self):
        print(f"\nWelcome {self.name}({self.role})!")
        while True:
            print("\n1. View Menu Item\n2. View Notification\n3. Food Recommendation for Tomorrow\n4. Give Feedback\n5. View Feedback\n6. Exit")
            choice = int(input("Enter a choice : "))
            if(choice == 1):
                self.food_menu.view_menu()
            elif choice == 2:
                print("View Notification")
            # Implement logic for viewing notifications
            elif choice == 3:
                self.food_menu.vote_for_menu()
            elif choice == 4:
                self.food_menu.give_feedback()
            elif choice == 5:
                self.food_menu.view_feedback()
            elif(choice == 6):
                print("\nEXITING...Bye")
                self.server_communicator.close_connection()
                exit()
            else:
                print("Invalid choice. Please enter a valid option.")


