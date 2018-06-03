package homeword;

import java.util.ArrayList;
import java.util.List;

public class Library {
	
	private List<Book> books;
//	private Book[] books;
	private String nameOfLibrary;
	public static String hour = "9AM to 5PM";
	
	
	
	public Library(String nameOfLibrary) {
		
		this.nameOfLibrary = nameOfLibrary;
		
		books = new ArrayList<Book>();
//		for (int initNull = 0; initNull < books.length; ++initNull) {
//			books[initNull] = null;
//		}
		
	}
	
	public void addBook(Book book) {
		
		books.add(book);
//		for (int elementChk = 0; elementChk < books.length; ++elementChk) {
//			if (books[elementChk] == null) {
//				books[elementChk] = book;
//				
//				break;
//			}
//			
//			else 
//				continue;
//			
//			
//		}
		
		return;
	}
	
	public String getName() {
		
		return this.nameOfLibrary;
	}
	
	public void printAllBooks() {
		for (int index = 0; index < books.size(); ++index){
				System.out.println(books.get(index).getTitle() + " in " + nameOfLibrary );
		}
		
		return;
	}
	
	public void printAllRentedBooks() {
		
		for (int rentBookChk = 0 ; rentBookChk < books.size(); ++rentBookChk){
			if (books.get(rentBookChk).isInPlace() == false) {
				System.out.println(books.get(rentBookChk).getTitle() + " is rented in " + getName());
			}
			
		}
		
		return;
	}
	
	public boolean rentBook(String bookName) {
		boolean rentChk = false;
		
		for (int bookChk = 0; bookChk < books.size(); ++bookChk) {
			if (books.get(bookChk).getTitle().equals(bookName)) {
				if(books.get(bookChk).isInPlace()){
					books.get(bookChk).setRent();
					rentChk = books.get(bookChk).getRent();
					System.out.println("You rented " + books.get(bookChk).getTitle());

					break;
				}
				
				else {
					books.get(bookChk).setRent();
					rentChk = books.get(bookChk).getRent();
				}
			
			}
		}
		
		return rentChk;	
			
		
	}
	
	public void handInBook(String bookName) {
		
		for (int bookChk = 0; bookChk < books.size(); ++bookChk) {
			if (books.get(bookChk).getTitle().equals(bookName)) {
				if(books.get(bookChk).isInPlace() ==  false) {
					books.get(bookChk).setHandIn();
					System.out.println("Thank you for returning " + books.get(bookChk).getTitle());

					break;
				}
		
		
	
			}
		}
	}
}