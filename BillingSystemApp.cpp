#include <iostream>
#include<fstream>
#include<string>
class Customer {
    char name[50];
    char surname[50];
    char address[50];
    char phoneNumber[50];
public:
    void getCustomerdata(std::fstream &file) {
        std::cout << "Enter customer's name: ";
        std::cin >> name;
        file << name;
        std::cout << "\nEnter customer's surname: ";
        std::cin >> surname;
        file << "\n"<<surname;
        std::cout << "\nEnter customer's address : ";
        std::cin >> address;
        file <<"\n"<< address;
        std::cout << "\nEnter customer's phoneNumber : ";
        std::cin >> phoneNumber;
        file << "\n"<<phoneNumber;
        
    }
};

class Product {
    char productType[30];
    double productPrice;
    double prouductQuantity;
public:
    void getProductData(std::fstream &file) {
        std::cout << "Enter product type :";
        std::cin >> productType;
        file << productType;
        std::cout << "\nEnter quantity purchased: ";
        std::cin >> prouductQuantity;
        file <<","<< prouductQuantity;
        std::cout << "\nEnter product price: ";
        std::cin >> productPrice;
        file <<","<< productPrice;
        
    }
    double getProductPrice() {
        return productPrice;
    }

    double getProductQuantity() {
        return prouductQuantity;
    }
};

int main(int argc,char** argv)
{
    std::fstream salesReport;
    char newCustomerService,printReport;
    double totalCost=0;
    Customer customer;
    Product product1;
    
    std::cout << "New customer service?: Y/N ";
    std::cin >> newCustomerService;

    while (newCustomerService == 'Y' || newCustomerService == 'y') {
        salesReport.open("Sales Report.csv", std::ios::out);
        if (salesReport.is_open()) {
            salesReport << " Grocery store\n";
            salesReport << " Address : xxxxxxxx\n";
            salesReport << "VAT number: xxxxxxxxxx\n";
            salesReport << "Phone number:xxxxxxxxxxx\n";
            salesReport << "***************************\n";
            salesReport << " Start of Sales Report\n\n";
            salesReport << "Customer Information:\n";

            customer.getCustomerdata(salesReport);
            std::cout << " Enter products? : Y/N ";
            char newProduct;
            std::cin >> newProduct;
           
                salesReport << "\n\n";
                salesReport << "Products"<<",";
                salesReport << "Quantity"<<",";
                salesReport << "Price"<<",";
                salesReport << "Total\n";
                while (newProduct == 'Y' || newProduct == 'y') {
                product1.getProductData(salesReport);
                salesReport << "," << product1.getProductPrice() * product1.getProductQuantity()<<"\n";
                totalCost += product1.getProductPrice() * product1.getProductQuantity();
                std::cout << " Enter more products? : Y/N ";
                std::cin >> newProduct;
            }
            salesReport <<","<<","<<"," << totalCost;
            salesReport.close();
            std::cout << " Print report ? : Y/N ";
            std::cin >> printReport;
            if (printReport == 'Y' || printReport == 'y') {
                salesReport.open("Sales Report.txt", std::ios::in);
                if (salesReport.is_open()) {
                    std::string line;
                    while (getline(salesReport, line)) {
                        std::cout << line << std::endl;
                    }
                    salesReport.close();
                }
            }




        }
        std::cout << "New customer service?: Y/N ";
        std::cin >> newCustomerService;
    }
    std::cout << " \n\nYour report is printed!";

    return 0;
}


