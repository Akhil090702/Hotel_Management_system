#include <iostream>
#include <vector>

class HotelRoom {
private:
    int roomNumber;
    bool isOccupied;
public:
    HotelRoom(int number) : roomNumber(number), isOccupied(false) {}

    int getRoomNumber() const {
        return roomNumber;
    }

    bool getIsOccupied() const {
        return isOccupied;
    }

    void setIsOccupied(bool occupied) {
        isOccupied = occupied;
    }
};

class Hotel {
private:
    std::vector<HotelRoom> rooms;
    std::vector<std::string> foodMenu;
    std::vector<std::string> foodOrdered;

public:
    Hotel() {
        // Initialize hotel with rooms (for demonstration, let's assume 10 rooms)
        for (int i = 1; i <= 10; ++i) {
            rooms.emplace_back(HotelRoom(i));
        }

        // Initialize food menu
        foodMenu = { "Burger", "Pizza", "Pasta", "Salad" };
    }

    void displayTotalRooms() const {
        std::cout << "Total Rooms: " << rooms.size() << "\n";
    }

    void displayAvailableRooms() const {
        std::cout << "Available Rooms:\n";
        for (const auto& room : rooms) {
            if (!room.getIsOccupied()) {
                std::cout << "Room Number: " << room.getRoomNumber() << "\n";
            }
        }
    }

    void bookRoom(int roomNumber) {
        for (auto& room : rooms) {
            if (room.getRoomNumber() == roomNumber && !room.getIsOccupied()) {
                room.setIsOccupied(true);
                std::cout << "Room " << roomNumber << " has been booked.\n";
                return;
            }
        }
        std::cout << "Room " << roomNumber << " is not available.\n";
    }

    void orderFood(int choice) {
        if (choice >= 1 && choice <= foodMenu.size()) {
            std::cout << "You have ordered: " << foodMenu[choice - 1] << "\n";
            foodOrdered.push_back(foodMenu[choice - 1]);
        } else {
            std::cout << "Invalid choice.\n";
        }
    }

    void displayFoodOrdered() const {
        std::cout << "Food items ordered:\n";
        for (const auto& food : foodOrdered) {
            std::cout << food << "\n";
        }
    }

    void displayFoodMenu() const {
        std::cout << "Food Menu:\n";
        for (size_t i = 0; i < foodMenu.size(); ++i) {
            std::cout << i + 1 << ". " << foodMenu[i] << "\n";
        }
    }
};

int main() {
    Hotel hotel;

    int choice;
    int roomChoice;
    int foodChoice;

    std::cout << "Welcome to the Hotel Management System\n";

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Display Total Rooms\n";
        std::cout << "2. Display Available Rooms\n";
        std::cout << "3. Book a Room\n";
        std::cout << "4. Order Food\n";
        std::cout << "5. Display Food Items Ordered\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                hotel.displayTotalRooms();
                break;
            case 2:
                hotel.displayAvailableRooms();
                break;
            case 3:
                std::cout << "Enter room number to book: ";
                std::cin >> roomChoice;
                hotel.bookRoom(roomChoice);
                break;
            case 4:
                hotel.displayFoodMenu();
                std::cout << "Enter food choice: ";
                std::cin >> foodChoice;
                hotel.orderFood(foodChoice);
                break;
            case 5:
                hotel.displayFoodOrdered();
                break;
            case 6:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 6);

    return 0;
}
