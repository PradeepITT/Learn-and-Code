#include <iostream>
#include <stdexcept>

using namespace std;

class CarDamageException : public exception {
private:
    string message;
public:
    CarDamageException(const char* msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class BrakeFailureException : public exception {
private:
    string message;
public:
    BrakeFailureException(const char* msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class Car {
public:
    void driveSafely(bool collision, bool brakeFailure) {
        if (collision) {
            throw CarDamageException("Car damaged due to collision.");
        } else if (brakeFailure) {
            throw BrakeFailureException("Brake Failure Occurred");
        }
    }
};

class AccidentHandler {
public:
    static void handleCarDamage(const char* message) {
        cout << "Car damaged: " << message << ". Insurance claim process initiated." << endl;
    }

    static void handleBrakeFailure(const char* message) {
        cout << "Brake failure detected: " << message << ". Pull over safely and engage emergency brake." << endl;
    }

    static void cleanUpAfterAccident() {
        cout << "Clean-up operations after accident completed." << endl;
    }
};

class CarAccident {
public:
    static void main() {
        Car car;
        try {
            car.driveSafely(false, true);
            cout << "Both persons reached the destination and are safe." << endl;
        } catch (CarDamageException& e) {
            AccidentHandler::handleCarDamage(e.what());
        } catch (BrakeFailureException& e) {
            AccidentHandler::handleBrakeFailure(e.what());
        } catch (...) {
            cerr << "Unknown exception occurred." << endl;
        }
        AccidentHandler::cleanUpAfterAccident();
    }
};

int main() {
    CarAccident::main();
    return 0;
}
