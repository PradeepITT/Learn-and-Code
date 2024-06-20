from userHandler.user import User

class Employee(User):
    def __init__(self, id, name, role, client_socket):
        super().__init__(id, name, role, client_socket)

    def user_menu(self):
        print(f"\nWelcome {self.name}!")
        print("\n1. View Menu Item\n2. View Notification\n3. Food Recommendation for Tomorrow\n4. Give Feedback\n5. Exit")
        choice = int(input("Enter a choice : "))
        
        if choice == 1:
            print("View Menu Item")
            # Implement logic for viewing menu items
        elif choice == 2:
            print("View Notification")
            # Implement logic for viewing notifications
        elif choice == 3:
            print("Food Recommendation for Tomorrow")
            # Implement logic for providing food recommendations for tomorrow
        elif choice == 4:
            print("Give Feedback")
            # Implement logic for allowing the employee to give feedback
        elif choice == 5:
            print("\nEXITING...Bye")
            self.client_socket.close()
            exit()
        else:
            print("Invalid choice. Please enter a valid option.")
