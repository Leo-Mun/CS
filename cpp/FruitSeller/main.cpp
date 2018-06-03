#include <iostream>

using namespace std;


class FruitSeller {
private :
    const int APPLE_PRICE;
    int numOfApples;
    int myMoney;

public :
{
    FruitSeller(int price, int num, int money)
        : APPLE_PRICE(price), numOfApples(num), myMoney(money) {}
    int SalesApples(int money)
    int num = money / APPLE_PRICE;
    numOfApples -= num;
    myMoney += money;
    return num;
}
    void InitMembers (int price, int num, int money) {
        APPLE_PRICE = price;
        numOfApples = num;
        myMoney = money;

    }
    void ShowSalesResult()
    {
        cout << "남은 사과 : " << numOfApples << endl;
        cout << "판매 수익 : " << myMoney << endl;
    }

};

class FruitBuyer
{
private :
    int myMoney;
    int numOfApples;
public :
    void InitMembers(int money)
    {
        myMoney = money;
        numOfApples = 0;
    }
    void BuyApples(FruitSeller &seller, int money)
    {
        numOfApples += seller.SalesApples(money);
        myMoney -= money;
    }
    void ShowBuyResult()
    {
        cout << "현재 잔액 : " << myMoney << endl;
        cout << "사과 갯수 : " << numOfApples << endl;
    }
};


int main()
{
    FruitSeller seller;
    seller.InitMembers(1000, 20, 0);
    FruitBuyer buyer;
    buyer.InitMembers(5000);
    buyer.BuyApples(seller, 2000);

    cout << "과일 판매자의 현황" << endl;
    seller.ShowSalesResult();
    cout << "과일 구매자의 현황" << endl;
    buyer.ShowBuyResult();

    return 0;
}
