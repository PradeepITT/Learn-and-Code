from roles.role import Role
from functionalities.view_menu import ViewMenu
from functionalities.view_notifications import ViewNotifications
from functionalities.give_feedback import GiveFeedback
from functionalities.finalize_menu import FinalizeMenu
from functionalities.update_availability import UpdateAvailability

class Employee(Role):
    def __init__(self, name, db_handler):
        super().__init__(name)
        self.functionalities = {
            1: ViewMenu(db_handler),
            2: ViewNotifications(),
            3: GiveFeedback(),
            4: FinalizeMenu(),
            5: UpdateAvailability()
        }
