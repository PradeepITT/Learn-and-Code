from userHandler.user import User

class Chef(User):
    def __init__(self, id, name, role, client_socket):
        super().__init__(id, name, role, client_socket)

    def user_menu(self):
        print(f"\nWelcome {self.name}!")
        print("\n1. View Menu Item\n2. Roll Out Tomorrow's Menu\n3. Finalized Menu\n4. Generate Monthly Report\n5. Update Availability of Menu Item\n6. View Feedback\n7. Exit")
        choice = int(input("Enter a choice : "))
        
        if choice == 1:
            print("View Menu Item")
        elif choice == 2:
            print("Rolling out tomorrow's menu...")
            # Implement logic for rolling out tomorrow's menu
        elif choice == 3:
            print("Displaying finalized menu...")
            # Implement logic for displaying finalized menu
        elif choice == 4:
            print("Generating monthly report...")
            # Implement logic for generating monthly report
        elif choice == 5:
            print("Updating availability of menu item...")
            # Implement logic for updating availability of menu item
        elif choice == 6:
            print("Viewing feedback...")
            # Implement logic for viewing feedback
        elif choice == 7:
            print("\nEXITING...Bye")
            self.client_socket.close()
            exit()
        else:
            print("Invalid choice. Please enter a valid option.")
