import socket
import json
from userHandler.chef import Chef
from userHandler.admin import Admin
from userHandler.employee import Employee

def login(username, password):
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    request = {
        "endpoint": "/login",
        "username": username,
        "password": password
    }
    
    client_socket.connect(('localhost', 12345))
    json_data = json.dumps(request).encode()
    client_socket.sendall(json_data)
    response = client_socket.recv(1024).decode()
    data = json.loads(response)['user']
    if(data['RoleName'] == "Admin"):
        user = Admin(data['ID'], data['Name'], data['RoleName'], client_socket)
        user.user_menu()
    elif(data['RoleName'] == "Chef"):
        user = Chef(data['ID'], data['Name'], data['RoleName'], client_socket)
        user.user_menu()
    elif(data['RoleName'] == "Employee"):
        user = Employee(data['ID'], data['Name'], data['RoleName'], client_socket)
        user.user_menu()
    else:
        print("\nInvalid Creds")   

if __name__ == "__main__":
    username = input("Enter username: ")
    password = input("Enter password: ")
    response = login(username, password)
