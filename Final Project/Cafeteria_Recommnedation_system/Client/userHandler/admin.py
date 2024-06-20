from userHandler.user import User

class Admin(User):
    def __init__(self, id, name, role, client_socket):
        super().__init__(id, name, role, client_socket)

    def user_menu(self):
        print(f"\nWelcome {self.name}!")
        print("\n1. View Menu Item\n2. Add Menu Item\n3. Update Menu Item\n4. Delete Menu Item\n5. Exit")
        choice = int(input("Enter a choice : "))
        if(choice == 1):
            print("Food Selection")
        elif(choice == 2):
            print("See Feeback")
        elif(choice == 5):
            print("\nEXITING...Bye")
            self.client_socket.close()
            exit


