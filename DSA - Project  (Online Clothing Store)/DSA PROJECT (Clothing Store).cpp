#include <iostream>
#include <string>
using namespace std;

const int MAX_RATINGS = 20;
const int MAX_CART = 10;


struct Product {
	int id;
	string name;
	float price;
	int ratings[MAX_RATINGS];
	int ratingCount;
	Product* next;
};


struct Order {
	int productIds[MAX_CART];
	int itemCount;
	float totalBill;
	Order* next;
};


Product* productHead = nullptr;
Order* orderHead = nullptr;


void addProduct(int id, string name, float price) {
	Product* newProduct = new Product{id, name, price, {}, 0, nullptr};
	if (!productHead) {
		productHead = newProduct;
	} else {
		Product* temp = productHead;
		while (temp->next) temp = temp->next;
		temp->next = newProduct;
	}
}


void showProducts() {
	Product* temp = productHead;
	cout << "\nAvailable Products:\n";
	while (temp) {
		cout << "ID: " << temp->id << ", Name: " << temp->name << ", Price: $" << temp->price << endl;
		temp = temp->next;
	}
}


void deleteProductById(int id) {
	if (!productHead) {
		cout << "No products to delete.\n";
		return;
	}

	Product* temp = productHead;
	Product* prev = nullptr;

	if (temp->id == id) {
		productHead = temp->next;
		delete temp;
		cout << "Product with ID " << id << " deleted.\n";
		return;
	}

	while (temp && temp->id != id) {
		prev = temp;
		temp = temp->next;
	}

	if (temp) {
		prev->next = temp->next;
		delete temp;
		cout << "Product with ID " << id << " deleted.\n";
	} else {
		cout << "Product with ID " << id << " not found.\n";
	}
}


void rateProduct() {
	int id, rating;
	showProducts();
	cout << "Enter Product ID to rate: ";
	cin >> id;

	Product* temp = productHead;
	while (temp && temp->id != id)
		temp = temp->next;

	if (temp) {
		cout << "Enter rating (1-5): ";
		cin >> rating;
		if (rating >= 1 && rating <= 5 && temp->ratingCount < MAX_RATINGS) {
			temp->ratings[temp->ratingCount++] = rating;
			cout << "Thank you! Rating added.\n";
		} else {
			cout << "Invalid rating or limit reached.\n";
		}
	} else {
		cout << "Product not found.\n";
	}
}


void placeOrder() {
	int pid, count = 0;
	int cart[MAX_CART];
	float total = 0;

	showProducts();
	cout << "Add product IDs to cart (0 to finish):\n";

	while (count < MAX_CART) {
		cout << "Enter product ID: ";
		cin >> pid;
		if (pid == 0) break;

		Product* temp = productHead;
		while (temp && temp->id != pid) temp = temp->next;

		if (temp) {
			cart[count++] = pid;
			total += temp->price;
			cout << temp->name << " added to cart.\n";
		} else {
			cout << "Invalid ID.\n";
		}
	}

	Order* newOrder = new Order;
	for (int i = 0; i < count; i++) newOrder->productIds[i] = cart[i];
	newOrder->itemCount = count;
	newOrder->totalBill = total;
	newOrder->next = nullptr;

	if (!orderHead) {
		orderHead = newOrder;
	} else {
		Order* temp = orderHead;
		while (temp->next) temp = temp->next;
		temp->next = newOrder;
	}

	cout << "Order placed! Total bill: $" << total << endl;
}


void viewOrders() {
	if (!orderHead) {
		cout << "No orders found.\n";
		return;
	}

	Order* tempOrder = orderHead;
	int orderNum = 1;

	while (tempOrder) {
		cout << "\nOrder #" << orderNum++ << ":\n";
		for (int i = 0; i < tempOrder->itemCount; i++) {
			Product* p = productHead;
			while (p && p->id != tempOrder->productIds[i]) p = p->next;
			if (p) cout << "- " << p->name << " ($" << p->price << ")\n";
		}
		cout << "Total Bill: $" << tempOrder->totalBill << endl;
		tempOrder = tempOrder->next;
	}
}

int main() {
	addProduct(1, "T-Shirt", 15.5);
	addProduct(2, "Jeans", 40.0);
	addProduct(3, "Jacket", 60.0);
	addProduct(4, "Sneakers", 55.0);
	addProduct(5, "Cap", 10.0);

	int choice;
	do {
		cout << "\n==== Online Clothing Shop ====\n";
		cout << "1. Show Products\n";
		cout << "2. Rate a Product\n";
		cout << "3. Place Order\n";
		cout << "4. View Order History\n";
		cout << "5. Exit\n";
		cout << "6. Delete a Product\n";
		cout << "Choose option: ";
		cin >> choice;

		switch (choice) {
			case 1:
				showProducts();
				break;
			case 2:
				rateProduct();
				break;
			case 3:
				placeOrder();
				break;
			case 4:
				viewOrders();
				break;
			case 5:
				cout << "Thank you for visiting!\n";
				break;
			case 6:
				int delId;
				cout << "Enter Product ID to delete: ";
				cin >> delId;
				deleteProductById(delId);
				break;
			default:
				cout << "Invalid choice!\n";
		}
	} while (choice != 5);

	return 0;
}

