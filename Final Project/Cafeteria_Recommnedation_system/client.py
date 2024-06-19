import socket
import json

def start_client():
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect(("127.0.0.1", 9999))

    try:
        # Enter credentials
        username = input("Enter username: ")
        password = input("Enter password: ")
        credentials = json.dumps({"username": username, "password": password})
        client.send(credentials.encode())

        # Receive initial response from server
        response = client.recv(1024).decode()
        response_data = json.loads(response)
        
        if response_data['status'] == 'success':
            print(f"Login successful! Your role is {response_data['role']}.")
            print("Available functionalities:")
            for key, func_name in response_data['functions'].items():
                print(f"{key}. {func_name}")

            while True:
                choice = input("Enter the number of the functionality you want to execute (or 'exit' to quit): ")
                client.send(choice.encode())

                if choice.lower() == 'exit':
                    print("Exiting program.")
                    break

                result = client.recv(10000).decode()
                print(result)

        else:
            print(f"Login failed: {response_data['message']}")

    except Exception as e:
        print(f"Error: {e}")

    finally:
        client.close()

if __name__ == "__main__":
    start_client()
