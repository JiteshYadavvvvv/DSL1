import java.util.Scanner;

public class as5 {

   public static class temp {
        int[] d;
        int mi=100, ma=-100;
        double ag=0;
        public temp(Scanner sc){
            System.out.println("Give number of different temps for the day");
            int n;
            n=sc.nextInt();
            int[] d=new int[n];
            for(int i=0;i<n;i++){
                d[i]=sc.nextInt();
                ag+=d[i];
                mi=Math.min(mi,d[i]);
                ma=Math.max(ma, d[i]);
            }
            ag=ag/n;
        }
    }
    public static double average(temp[] a){
        double ave=0;
        int n=a.length;
        for(temp x: a){
            ave+=x.ag;
        }
        ave=ave/n;
        return ave;
    }
    public static int maxx(temp[] a){
        int maxx=-100;
        for(temp x: a){
            maxx=Math.max(maxx,x.ma);
        }
        return maxx;
    }
    public static int minn(temp[] a){
        int minn=100;
        for(temp x: a){
            minn=Math.max(minn,x.mi);
        }
        return minn;
    }
    public static int count(temp[] a, double ave){
        int c=0;
        for(temp x: a){
            if(x.ag==ave)c++;
        }
        return c;
    }
    public static double sav(temp ...a){
        double ave=0;
        for(temp x: a){
            ave+=x.ag;
        }
        ave=ave/a.length;
        return ave;
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n;
        System.out.println("Give number of days");
        n=sc.nextInt();
        temp[] a=new temp[n];
        for(int i=0;i<n;i++){
            System.out.println("The "+i+1+" Day");
            a[i]=new temp(sc);
        }
        while (true) {
            int x;
            System.out.println("||Enter Choice\n1.Avg temp\n2.Max and min temp\n 3. Count number of days with avg temp\n 4.Avg Temperature on Selected days\n5.Exit");
            x=sc.nextInt();
            if(x==5)break;
            switch (x) {
                case 1:
                    System.out.println(average(a));
                    break;
                case 2:
                    System.out.println("Max is "+maxx(a)+"\n Min is "+minn(a));
                    break;
                case 3:
                    System.out.println("Number of days with average temperature equal to overall average temperature is "+count(a, average(a)));
                    break;
                case 4:
                    System.out.println("Give number of Selected days and selected days");
                    int nn=sc.nextInt();
                    temp[] b=new temp[nn];
                    for(int i=0;i<nn;i++){
                        int tt;
                        tt=sc.nextInt();
                        tt--;
                        b[i]=a[tt];
                    }
                    break;
                default:
                    System.out.println("Invalid Option");
                    break;
            }
        }
        sc.close();
    }
}
