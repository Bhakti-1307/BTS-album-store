#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <ctime>

using namespace std;

// BTS Album Store - Boraheland
// Console-based C++ project

struct Product {
    int id;
    string albumname;
    string category;
    int price;
};

struct Order { 
    int OrderID; 
    int id; 
    int quantity;
    string customerId;
    time_t orderDate;
};

int main () { 
    vector<int> selectedAlbums;
    vector<Product> products = {
        {701, "Dark & Wild", "Korean Studio Album", 25},
        {702, "Wings", "Korean Studio Album", 25},
        {703, "Love Yourself: Tear", "Korean Studio Album", 30},
        {704, "Map of the Soul: 7", "Korean Studio Album", 30},
        {705, "BE", "Korean Studio Album", 30},
        {706, "Wake Up", "Japanese Studio Album", 25},
        {707, "Youth", "Japanese Studio Album", 25},
        {708, "Face Yourself", "Japanese Studio Album", 25},
        {709, "Map of the Soul: 7 – The Journey", "Japanese Studio Album", 30},
        {710, "O!RUL8,2?", "Mini Album", 25},
        {711, "Skool Luv Affair", "Mini Album", 25},
        {712, "The Most Beautiful Moment in Life, Part 1", "Mini Album", 25},
        {713, "The Most Beautiful Moment in Life, Part 2", "Mini Album", 25},
        {714, "Love Yourself: Her", "Mini Album", 25},
        {715, "Map of the Soul: Persona", "Mini Album", 25},
        {716, "Skool Luv Affair Special Addition", "Special Album", 30},
        {717, "The Most Beautiful Moment in Life: Young Forever", "Special Album", 30},
        {718, "You Never Walk Alone", "Repackage Album", 25},
        {719, "Love Yourself: Answer", "Special Album", 30},
        {720, "Proof", "Anthology Album", 30},
        {721, "2025 BTS Festa: Capsule Album Vol.1", "Compilation Album", 30},
        {722, "The Best of Bangtan Sonyeondan - Korean Edition", "Compilation Album", 30},
        {723, "The Best of Bangtan Sonyeondan - Japanese Edition", "Compilation Album", 30},
        {724, "BTS the best", "Compilation Album", 30},
        {725, "2 Cool 4 Skool", "Debut Single Album", 25},
        {726, "Butter", "Digital Single Album", 25},
        {727, "Dynamite", "Digital Single Album", 25},
        {728, "Permission to Dance", "Digital Single Album", 25},
        {729, "Take Two", "Digital Single Album", 25},
        {730, "BTS World OST", "Soundtrack Album", 25},
        {731, "Permission to Dance on Stage", "Live Album", 30},
        {732, "Film Out", "Digital Japanese Single Album", 25},
        {733, "Indigo", "RM's Solo Studio Album", 25},
        {734, "Right Place Wrong Person", "RM's Solo Studio Album", 25},
        {735, "Mono", "RM's Mixtape", 25},
        {736, "RM", "RM's Mixtape", 25},
        {737, "Happy", "Jin's Solo Mini Album", 25},
        {738, "Echo", "Jin's Solo Mini Album", 25},
        {739, "The Astronaut", "Jin's Notable Single", 25},
        {740, "Super Tuna", "Jin's Notable Single", 25},
        {741, "D-DAY", "SUGA's Solo Studio Album", 25},
        {742, "Agust D", "SUGA's Mixtape", 25},
        {743, "D-2", "SUGA's Mixtape", 25},
        {744, "Agust D Tour 'D-DAY'", "SUGA's Live Album", 30},
        {745, "Jack in the Box", "J-hope's Solo Studio Album", 25},
        {746, "Hope World", "J-hope's Mixtape", 25},
        {747, "Hope on the Street Vol.1", "J-hope's Special Album", 30},
        {748, "Killin' It Girl", "J-hope's Notable Single", 25},
        {749, "Mona Lisa", "J-hope's Notable Single", 25},
        {750, "Sweet Dreams", "J-hope's Notable Single", 25},
        {751, "Face", "Jimin's Solo Studio Album", 25},
        {752, "Muse", "Jimin's Solo Studio Album", 25},
        {753, "Promise", "Jimin's Notable Single", 25},
        {754, "Closer than this", "Jimin's Notable Single", 25},
        {755, "Layover", "Taehyung's Solo Studio Album", 25},
        {756, "Fr(end)s", "Taehyung's Notable Single", 25},
        {757, "Winter Ahead", "Taehyung's Notable Single", 25},
        {758, "White Christmas", "Taehyung's Notable Single", 25},
        {759, "Golden", "Jungkook's Solo Studio Album", 25},
        {760, "Seven", "Jungkook's Notable Single", 25},
        {761, "3D", "Jungkook's Notable Single", 25},
        {762, "Never Let Go", "Jungkook's Notable Single", 25},
        {763, "Still With You", "Jungkook's Notable Single", 25}
    };

    list<Order> orderHistory;
    int nextOrderId = 1001;
    int choice;

    cout << "Anneyonghaseyo!\nWelcome to BTS Album Store: Boraheland\n\n";

    do {
        cout << "\n1. Browse all albums\n";
        cout << "2. View album details\n";
        cout << "3. Cart\n";
        cout << "4. Place Order\n";
        cout << "5. View purchase history\n";
        cout << "6. Billing summary\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            for (const auto& product : products) {
                cout << product.albumname << endl;
            }
            break;

        case 2:
            for (const auto& product : products) {
                cout << "Album: " << product.albumname
                     << " | Category: " << product.category
                     << " | ID: " << product.id << endl;
            }
            break;

        case 3: {
            int cartChoice;
            int albumId;

            do {
                cout << "\n--- CART MENU ---\n";
                cout << "1. Add album to cart\n";
                cout << "2. View cart\n";
                cout << "3. Back to main menu\n";
                cout << "Enter choice: ";
                cin >> cartChoice;

                if (cartChoice == 1) {
                    cout << "Enter Album ID: ";
                    cin >> albumId;

                    bool found = false;

                    for (const auto& product : products) {
                        if (product.id == albumId) {
                            selectedAlbums.push_back(albumId);
                            cout << "Added: " << product.albumname << endl;
                            found = true;
                            break;
                        }
                    }

                    if (found == false) {
                        cout << "Album ID not found.\n";
                    }
                }

                else if (cartChoice == 2) {
                    if (selectedAlbums.empty()) {
                        cout << "Your cart is empty.\n";
                    } else {
                        for (int id : selectedAlbums) {
                            for (const auto& product : products) {
                                if (product.id == id) {
                                    cout << "- " << product.albumname
                                         << " ($" << product.price << ")\n";
                                }
                            }
                        }
                    }
                }

            } while (cartChoice != 3);

            break;
        }

        case 4: {
            if (selectedAlbums.empty()) {
                cout << "Your cart is empty.\n";
                break;
            }

            for (int id : selectedAlbums) {
                Order newOrder;
                newOrder.OrderID = nextOrderId++;
                newOrder.id = id;
                newOrder.quantity = 1;
                newOrder.customerId = "B001";
                newOrder.orderDate = time(0);

                orderHistory.push_back(newOrder);
            }

            selectedAlbums.clear();
            cout << "Order placed successfully!\n";
            break;
        }

        case 5:
            if (orderHistory.empty()) {
                cout << "No purchase history.\n";
            } else {
                for (const auto& order : orderHistory) {
                    cout << "\nOrder ID: " << order.OrderID;
                    cout << "\nDate: " << ctime(&order.orderDate);
                }
            }
            break;

        case 6: {
            int total = 0;

            for (const auto& order : orderHistory) {
                for (const auto& product : products) {
                    if (product.id == order.id) {
                        cout << product.albumname
                             << " - $" << product.price << endl;
                        total += product.price;
                    }
                }
            }

            cout << "Total: $" << total << endl;
            break;
        }

        case 7:
            cout << "Thank you for visiting Boraheland 💜\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 7);

    return 0;
}
