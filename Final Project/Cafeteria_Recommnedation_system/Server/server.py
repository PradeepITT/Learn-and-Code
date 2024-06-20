import socket
import threading
import json
from database_handler import DatabaseHandler
from login_handler import LoginHandler

class Server:
    def __init__(self, host, port, db_host, db_user, db_password, db_name):
        self.host = host
        self.port = port
        self.db_handler = DatabaseHandler(db_host, db_user, db_password, db_name)
        self.login_handler = LoginHandler(self.db_handler)
        self.server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    def start_server(self):
        self.db_handler.connect()
        self.server_socket.bind((self.host, self.port))
        self.server_socket.listen(5)
        print(f"Server started on {self.host}:{self.port}")
        while True:
            client_socket, addr = self.server_socket.accept()
            print(f"Connection from {addr}")
            client_thread = threading.Thread(target=self.handle_client, args=(client_socket,))
            client_thread.start()

    def handle_client(self, client_socket):
        try:
            data = client_socket.recv(1024).decode()
            request = json.loads(data)
            if request.get("endpoint") == "/login":
                username = request["username"]
                password = request["password"]
                user = self.login_handler.login(username, password)
                if user:
                    response = {
                        "status": "success",
                        "user": {
                            "ID": user["ID"],
                            "Name": user["Name"],
                            "RoleName": user["RoleName"]
                        }
                    }
                else:
                    response = {"status": "failure", "message": "Invalid credentials"}
                client_socket.sendall(json.dumps(response).encode())
            else:
                response = {"status": "failure", "message": "Invalid endpoint"}
                client_socket.sendall(json.dumps(response).encode())
        except Exception as e:
            print(f"Error: {e}")
        finally:
            client_socket.close()

if __name__ == "__main__":
    server = Server('localhost', 12345, 'localhost', 'root', 'root', 'foodrecommendation')
    server.start_server()
