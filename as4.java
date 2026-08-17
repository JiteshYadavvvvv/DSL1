import java.util.Scanner;

public class as4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // 3 floors, 5 rooms on each floor
        int[][] rooms = new int[3][5];

        int choice;

        do {
            System.out.println("\n--- Hotel Room Booking System ---");
            System.out.println("1. View Rooms");
            System.out.println("2. Book a Room");
            System.out.println("3. Exit");
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();

            switch (choice) {

                case 1:
                    // Display room status
                    System.out.println("\nRoom Status:");
                    for (int floor = 0; floor < rooms.length; floor++) {
                        System.out.println("Floor " + (floor + 1));

                        for (int room = 0; room < rooms[floor].length; room++) {
                            if (rooms[floor][room] == 0) {
                                System.out.println("Room " + (room + 1) + " - Available");
                            } else {
                                System.out.println("Room " + (room + 1) + " - Booked");
                            }
                        }
                    }
                    break;

                case 2:
                    // Book a room
                    System.out.print("Enter floor (1-3): ");
                    int floor = sc.nextInt();

                    System.out.print("Enter room number (1-5): ");
                    int room = sc.nextInt();

                    if (floor < 1 || floor > 3 || room < 1 || room > 5) {
                        System.out.println("Invalid floor or room number.");
                    } else if (rooms[floor - 1][room - 1] == 1) {
                        System.out.println("Room is already booked.");
                    } else {
                        rooms[floor - 1][room - 1] = 1;
                        System.out.println("Room booked successfully!");
                    }
                    break;

                case 3:
                    System.out.println("Thank you! Exiting...");
                    break;

                default:
                    System.out.println("Invalid choice.");
            }

        } while (choice != 3);

        sc.close();
    }
}
