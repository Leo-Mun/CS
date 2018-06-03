package homework;

public class DessertCheckoutRunner {
    public static void main(String[] args) {
        DessertCheckout dessertCheckout = new DessertCheckout(5);
    	
        dessertCheckout.enterItem(new Cookie("Chocochip", 2, 1000));
        dessertCheckout.enterItem(new Cookie("Raisin Oatmeal", 3, 1500));
        dessertCheckout.enterItem(new Espresso("Americano", 1));

        System.out.println("Checking out " + dessertCheckout.getTotalNumberOfItems() + " items");
        System.out.println("Total price is " + dessertCheckout.getTotalCost());

        dessertCheckout.clearItems();

        System.out.println("============================================");
        dessertCheckout.enterItem(new Cookie("Chocochip", 1, 1000));
        dessertCheckout.enterItem(new Cookie("Raisin Oatmeal", 1, 1500));
        dessertCheckout.enterItem(new Espresso("Americano", 2));
        dessertCheckout.enterItem(new Mocha("Caffe Mocha", 1, 100, 50));
        boolean addSucceed = dessertCheckout.enterItem(new Mocha("Caffe Mocha", 2, 50, 50));
        System.out.println("add a dessert item succeed: " + addSucceed);
        addSucceed = dessertCheckout.enterItem(new Cookie("Chocochip", 2, 1000));
        System.out.println("add a dessert item succeed: " + addSucceed);

        System.out.println("Checking out " + dessertCheckout.getTotalNumberOfItems() + " items");
        System.out.println("Total price is " + dessertCheckout.getTotalCost());

    }
}
