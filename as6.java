interface Teacher {
    void teach();
}
interface Researcher {
    void research();
}
class Professor implements Teacher, Researcher {
    String name;
    Professor(String pn) {
        name = pn;
    }
    public void teach(String t){
        System.out.println("Professor "+ name + " is teaching "+ t);
    }
    public void teach() {
        System.out.println("Professor " + name + " is teaching a class.");
    }
    public void research() {
        System.out.println("Professor " + name + " is doing research.");
    }
}
public class as6 {
    public static void main(String[] args) {
        Professor prof = new Professor("Dr. Smith");
        Teacher t = prof;
        t.teach("Science");
        t.teach();
        Researcher r= prof;
        r.research();
    }
}
