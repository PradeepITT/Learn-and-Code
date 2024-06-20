class LoginHandler:
    def __init__(self, db_handler):
        self.db_handler = db_handler

    def login(self, username, password):
        return self.db_handler.check_login(username, password)
