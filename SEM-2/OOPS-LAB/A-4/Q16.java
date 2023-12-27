class Book{
    String title,genre;
    int pages;
    double price;
    public Book(String t, String g, int pg,double pr ){
        this.title=t;
        this.genre=g;
        this.pages=pg;
        this.price=pr;
    }
    public void getData(){
        System.out.println("Book Title : "+title);
        System.out.println("Book Genre : "+genre);
        System.out.println("No. of Pages in Book : "+pages);
        System.out.println("Price of Book : "+price+" Rs");
    }
}
class StoryBook extends Book{
    double newPrice;
    StoryBook(String t, String g, int pg,double pr){
        super(t,g,pg,pr);
        newPrice = price+(price*0.3);
    }
    public void getData(){
        System.out.println("Book Title : "+title);
        System.out.println("Book Genre : "+genre);
        System.out.println("No. of Pages in Book : "+pages);
        System.out.println("Price of Book : "+newPrice+" Rs");
    }
}

public class Q16 {
    public static void main(String[] args) {
        Book b = new StoryBook("Steve jobs","Biography",100,200);
        b.getData();
    }
}
