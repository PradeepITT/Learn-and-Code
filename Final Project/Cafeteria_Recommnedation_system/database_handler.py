import mysql.connector

class DatabaseHandler:
    def __init__(self, db_config):
        self.db_config = db_config

    def connect(self):
        return mysql.connector.connect(**self.db_config)

    def get_user_role(self, username, password):
        try:
            connection = self.connect()
            cursor = connection.cursor(dictionary=True)

            query = "SELECT u.Name, r.RoleName FROM User u JOIN Role r ON u.RoleID = r.ID WHERE u.Name = %s AND u.Password = %s"
            cursor.execute(query, (username, password))

            user = cursor.fetchone()
            cursor.close()
            connection.close()

            return user
        except mysql.connector.Error as err:
            print(f"Error: {err}")
            return None

    def get_menu_items(self):
        try:
            connection = self.connect()
            cursor = connection.cursor(dictionary=True)
            query = """
            SELECT m.ID, m.Name, m.Price, m.AvailabilityStatus, mt.MealType
            FROM MenuItem m
            JOIN MealTypes mt ON m.MealTypeID = mt.ID
            """
            cursor.execute(query)
            menu_items = cursor.fetchall()

            cursor.close()
            connection.close()
            return menu_items
        except mysql.connector.Error as err:
            print(f"Error: {err}")
            return None
