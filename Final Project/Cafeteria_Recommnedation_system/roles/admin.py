# roles/admin.py
from roles.role import Role
from menu_function import MenuFunction

class Admin(Role):
    def __init__(self, name, db_handler):
        super().__init__(name)
        self.menu_function = MenuFunction(db_handler)
        self.functionalities = {
            1: ("View Menu", self.menu_function.view_menu),
            2: ("Add Menu Item", self.menu_function.add_menu_item),
            # Add more functionalities as needed
        }



# roles/employee.py
from roles.role import Role
from menu_function import MenuFunction

class Employee(Role):
    def __init__(self, name, db_handler):
        super().__init__(name)
        self.menu_function = MenuFunction(db_handler)
        self.functionalities = {
            1: ("View Menu", self.menu_function.view_menu),
            # Add more functionalities as needed
        }
