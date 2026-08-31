import java.util.Scanner;

public class as4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n,m;
        System.out.println("ENTER FLOORS AND ROOMS PER FLOOR");
        n=sc.nextInt();
        m=sc.nextInt();
        boolean [][] a= new boolean[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                a[i][j]=false;
            }
        }
        while (true) {
            System.out.println("||ENTER CHOICE||");
            System.out.println("1.View Available Rooms");
            System.out.println("2.Vacate a room");
            System.out.println("3.Book a Room");
            System.out.println("4.Exit");
            int x;
            x=sc.nextInt();
            if(x==4)break;
            switch (x) {
                case 1:
                    for(int i=0;i<n;i++){
                        for(int j=0;j<m;j++){
                            if(a[i][j]){
                                System.out.print("B ");
                            }
                            else System.out.print("A ");
                        }
                        System.out.println();
                    }
                    break;
                case 2:
                    int i,j;
                    System.out.println("Enter floor number and room number");
                    i=sc.nextInt();
                    j=sc.nextInt();
                    i--;
                    j--;
                    if(a[i][j]){
                        a[i][j]=false;
                        System.out.println("Room Vacated");
                    }
                    else{
                        System.out.println("Room already vacant");
                    }
                    break;
                case 3:
                    int t,tt;
                    System.out.println("Enter floor number and room number");
                    t=sc.nextInt();
                    tt=sc.nextInt();
                    t--;
                    tt--;
                    if(a[t][tt]){
                        System.out.println("Already Booked");
                    }
                    else{
                        a[t][tt]=true;
                        System.out.println("Room Booked");
                    }
                    break;
                default:
                    System.out.println("Invalid Choice");
                    break;
            }
        }
        sc.close();
    }
}
