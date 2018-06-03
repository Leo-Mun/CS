package kr.ac.kookmin.cs.oop.inheritance.abstractclass;

public class RestaurantRunner {
    public static void main(String[] args) {
        Restaurant restaurant = new KoreanRestaurant();
        restaurant.cook("gimchi-soup");
    }
}