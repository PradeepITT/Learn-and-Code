# server.py
import sys
import os
sys.path.append(os.path.dirname(os.path.abspath(__file__)))

import socket
import threading
import json
from roles.role import Role
from roles.admin import Admin
from roles.chef import Chef
from roles.employee import Employee
from database_handler import DatabaseHandler

# MySQL database connection configuration
db_config = {
    'user': 'root',
    'password': 'root',
    'host': '127.0.0.1',
    'database': 'foodrecommendation'
}

# Initialize the DatabaseHandler
db_handler = DatabaseHandler(db_config)

# Function to get user role from database
def get_user_role(username, password):
    return db_handler.get_user_role(username, password)

# Function to get instance of specific role class based on role name
def get_role_instance(role_name):
    role_classes = {
        "Admin": Admin,
        "Chef": Chef,
        "Employee": Employee
    }
    return role_classes.get(role_name, Role)(role_name, db_handler)

# Function to handle each client connection
def handle_client(client_socket):
    try:
        user_credentials = client_socket.recv(1024).decode().strip()
        user_info = json.loads(user_credentials)
        
        username = user_info['username']
        password = user_info['password']

        user = get_user_role(username, password)

        if user:
            role_name = user["RoleName"]
            role_instance = get_role_instance(role_name)
            functionalities = role_instance.get_functionalities()

            response = {
                'status': 'success',
                'role': role_name,
                'functions': {key: name for key, (name, func) in functionalities.items()}
            }

            client_socket.send(json.dumps(response).encode())

            while True:
                choice = client_socket.recv(1024).decode().strip()
                
                if choice.isdigit():
                    choice = int(choice)
                    if choice in functionalities:
                        func_name, func = functionalities[choice]
                        result = func()
                        client_socket.send(result.encode())         
                    else:
                        client_socket.send(json.dumps({"status": "failure", "message": "Invalid choice. Try again."}).encode())
                else:
                    client_socket.send(json.dumps({"status": "failure", "message": "Please enter a number."}).encode())
        else:
            response = {
                'status': 'failure',
                'message': 'Invalid credentials'
            }

            client_socket.send(json.dumps(response).encode())
    except Exception as e:
        print(f"Error: {e}")
        client_socket.send(json.dumps({"status": "error", "message": str(e)}).encode())
    finally:
        client_socket.close()

# Function to start the server and listen for incoming connections
def start_server():
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind(("0.0.0.0", 9999))
    server.listen(5)
    print("Server started on port 9999")

    while True:
        client_socket, addr = server.accept()
        print(f"Accepted connection from {addr}")
        client_handler = threading.Thread(target=handle_client, args=(client_socket,))
        client_handler.start()

if __name__ == "__main__":
    start_server()
