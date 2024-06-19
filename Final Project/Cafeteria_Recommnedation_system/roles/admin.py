# roles/admin.py
from roles.role import Role
from functionalities.view_menu import ViewMenu
from functionalities.add_user import AddUser
from functionalities.delete_user import DeleteUser
from functionalities.add_menu_item import AddMenuItem
from functionalities.update_menu_item import UpdateMenuItem
from functionalities.delete_menu_item import DeleteMenuItem


class Admin(Role):
    def __init__(self, name, db_handler):
        super().__init__(name)
        self.functionalities = {
            1: ViewMenu(db_handler),
            2: AddUser(),
            3: DeleteUser(),
            4: AddMenuItem(),
            5: UpdateMenuItem(),
            6: DeleteMenuItem(),
        }
