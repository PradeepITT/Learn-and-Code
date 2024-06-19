# roles/role.py
class Role:
    def __init__(self, name):
        self.name = name
        self.functionalities = {}

    def get_functionalities(self):
        return self.functionalities
