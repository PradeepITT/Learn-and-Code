import json
class FeedbackHandler:
    def __init__(self, server_communicator, user_id):
        self.server_communicator = server_communicator
        self.user_id = user_id

    def give_feedback(self):
        menu_item_id = input("Enter the Menu Item ID: ")
        rating = input("Enter your Rating (e.g., 4.5): ")
        comment = input("Enter your Comment: ")

        endpoint = "/give-feedback"
        data = {
            "UserID": self.user_id,
            "MenuItemID": int(menu_item_id),
            "Rating": float(rating),
            "Comment": comment,
            "RoleName": "Employee"
        }

        response = self.server_communicator.send_request(endpoint, data)
        if response["status"] == "success":
            print(response["message"])
        else:
            print(response["message"])
