# menu_function.py
from database_handler import DatabaseHandler
from functionalities.view_menu import ViewMenu

class MenuFunction:
    def __init__(self, db_handler: DatabaseHandler):
        self.db_handler = db_handler
        self.view_menu_function = ViewMenu(db_handler)

    def view_menu(self):
        return self.view_menu_function.execute()

    def add_menu_item(self):
        return "Adding a menu item..."

    def delete_user(self):
        return "Deleting a user..."

    def delete_menu_item(self):
        return "Deleting a menu item..."
    
    # Add more methods for other functionalities as needed
