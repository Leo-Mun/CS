package homeword;

public class Homework4 {
    public static void main(String[] args) {
        System.out.println("========== Test book class ==========");
        Book oopBook = new Book("Object Oriented Programming");
        System.out.println("OOP book is in a library: " + oopBook.isInPlace());
        oopBook.rent();
        System.out.println("OOP book is in a library: " + oopBook.isInPlace());
        oopBook.handIn();
        System.out.println("OOP book is in a library: " + oopBook.isInPlace());
        oopBook.handIn();
        System.out.println("OOP book is in a library: " + oopBook.isInPlace());
        oopBook.rent();
        System.out.println("OOP book is in a library: " + oopBook.isInPlace());
        oopBook.rent();

        Library sunggokLib = new Library("Sunggok Library");
        Library csLib = new Library("Computer Science Library");

        System.out.println("========== Print Library Info ==========");
        System.out.println("sunggokLib name: " + sunggokLib.getName());
        System.out.println("csLib name: " + csLib.getName());
        System.out.println("The library hour: " + Library.hour);

        sunggokLib.addBook(new Book("Oedipus the King"));
        sunggokLib.addBook(new Book("Hamlet"));
        sunggokLib.addBook(new Book("King Lear"));

        csLib.addBook(new Book("Object Oriented Programming"));
        csLib.addBook(new Book("Linear Algebra"));
        csLib.addBook(new Book("Hamlet"));

        System.out.println("========== Print all books in the library==========");
        sunggokLib.printAllBooks();
        csLib.printAllBooks();

        System.out.println("========== Renting books ==========");
        boolean rentSucceed = sunggokLib.rentBook("Hamlet");
        System.out.println("Hamlet rent from sunggok succeed : " + rentSucceed);
        rentSucceed = sunggokLib.rentBook("Hamlet");
        System.out.println("Hamlet rent from sunggok succeed : " + rentSucceed);
        rentSucceed = csLib.rentBook("Hamlet");
        System.out.println("Hamlet rent from csLib succeed : " + rentSucceed);
        rentSucceed = csLib.rentBook("Object Oriented Programming");
        System.out.println("Object Oriented Programming rent from csLib succeed : " + rentSucceed);

        System.out.println("========== Print all rented books ==========");
        sunggokLib.printAllRentedBooks();
        csLib.printAllRentedBooks();

        System.out.println("========== Returning books ==========");
        sunggokLib.handInBook("Hamlet");
        sunggokLib.handInBook("King Lear");
    }
}
