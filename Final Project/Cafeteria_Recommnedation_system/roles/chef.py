# roles/chef.py
from roles.role import Role
from functionalities.view_menu import ViewMenu
from functionalities.roll_out_menu import RollOutMenu
from functionalities.finalize_menu import FinalizeMenu
from functionalities.generate_report import GenerateReport
from functionalities.update_availability import UpdateAvailability


class Chef(Role):
    def __init__(self, name, db_handler):
        super().__init__(name)
        self.functionalities = {
            1: ViewMenu(db_handler),
            2: RollOutMenu(),
            3: FinalizeMenu(),
            4: GenerateReport(),
            5: UpdateAvailability(),
        }
