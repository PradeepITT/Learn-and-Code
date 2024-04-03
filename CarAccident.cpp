#include <iostream>
#include <stdexcept>

using namespace std;

class CarAccident {
public:
    static void main() {
        try {
            driveSafely();
            cout << "Both persons reached the destination and are safe." << endl;
        } catch (CarDamageException& e) {
            handleCarDamage();
        } catch (PersonInjuredException& e) {
            handlePersonInjured();
        } catch (BrakeFailureException& e) {
            handleBrakeFailure();
        } catch (...) {
            cerr << "Unknown exception occurred." << endl;
        } 
    }

private:
    static void driveSafely() {
        bool collision = false;
        bool brakeFailure = true;

        if (collision) {
            throw CarDamageException("Car damaged due to collision.");
        } else if (brakeFailure) {
            throw BrakeFailureException("Brake Failure Occurred");
        }
    }

    static void handleCarDamage() {
        cout << "Car damaged due to collision. Insurance claim process initiated." << endl;
    }

    static void handlePersonInjured() {
        cout << "Person injured due to collision. Medical assistance required." << endl;
    }

    static void handleBrakeFailure() {
        cout << "Brake failure detected. Pull over safely and engage emergency brake." << endl;
    }
};