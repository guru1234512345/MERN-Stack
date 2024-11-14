package os;

import java.util.Arrays;
import java.util.Scanner;

public class SCAN_DISK_SH {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("\n        !!! SCAN Disk Scheduling Algorithm !!! \n");

        int ntrack, nreq;

        System.out.print("Enter total number of tracks present on a Plater: ");
        ntrack = sc.nextInt();

        System.out.print("Enter total number of track requests: ");
        nreq = sc.nextInt();

        int[] arr = new int[nreq+2];
        System.out.println("Enter your track request queue: ");
        for(int i=1; i<= nreq; i++){
            arr[i] = sc.nextInt();
        }

        int rwhead;
        System.out.print("Enter initial track position of  R/W head: ");
        rwhead = sc.nextInt();

        arr[0] = rwhead; // initial position of read-write head is stored at arr[0]

        int choice;
        System.out.println("Choose the Direction of R/W head 1.smaller track 2.greater track \noption: ");
        choice = sc.nextInt();

        if(choice == 1){
            arr[nreq+1] = 0;
        }else{
            arr[nreq+1] = ntrack-1;
        }

        switch (choice){
            case 1 : small(arr, rwhead);
            break;
            case 2 : large(arr, rwhead);
            break;
            default: System.out.println("Invalid Input !!!");
        }

    }

    public static void small(int[] arr , int rwhead){
        Scanner sc = new Scanner(System.in);
        Arrays.sort(arr);

        int idx=0;
        for(int i=0; i<arr.length; i++){
            if(arr[i] == rwhead){
                idx = i;
            }
        }

        int t, st, tst = 0;
        System.out.print("Enter time taken by R/W head pointer for one track movement: ");
        t = sc.nextInt();

        System.out.println  ("\n+-------------------------------------------");
        System.out.println("|    --->             seek time   ");
        System.out.println  ("|-------------------------------------------");

        for(int i=idx; i >0; i--){
            st = arr[i]-arr[i-1];
            if(st < 0){
                st = -st;
            }
            st = st * t;
            tst = tst + st;
            System.out.println("|  "+arr[i]+" ---> "+arr[i-1]+"     :       "+st+"         ");
        }

        st = arr[idx+1] - arr[0];
        st = st * t;
        tst = tst + st;
        System.out.println("|  "+arr[0]+" ---> "+arr[idx+1]+"     :       "+st+"         ");

        for(int i=idx+1; i< arr.length-1; i++){
            st = arr[i]-arr[i+1];
            if(st < 0){
                st = -st;
            }
            st = st * t;
            tst = tst + st;
            System.out.println("|  "+arr[i]+" ---> "+arr[i+1]+"     :       "+st+"         ");
        }
        System.out.println  ("+-------------------------------------------");
        System.out.println("\nTotal seek time : "+tst);

    }

    public static void large(int[] arr , int rwhead){
        Scanner sc = new Scanner(System.in);
        Arrays.sort(arr);

        int idx=0;
        for(int i=0; i<arr.length; i++){
            if(arr[i] == rwhead){
                idx = i;
            }
        }

        int t, st, tst = 0;
        System.out.print("Enter time taken by R/W head pointer for one track movement: ");
        t = sc.nextInt();

        System.out.println  ("\n+-------------------------------------------");
        System.out.println("|    --->             seek time   ");
        System.out.println  ("|-------------------------------------------");

        for(int i=idx; i<arr.length-1; i++){
            st = arr[i]-arr[i+1];
            if(st < 0){
                st = -st;
            }
            st = st * t;
            tst = tst + st;
            System.out.println("|  "+arr[i]+" ---> "+arr[i+1]+"     :       "+st+"         ");
        }

        st = arr[arr.length-1] - arr[idx-1];
        st = st * t;
        tst = tst + st;
        System.out.println("|  "+arr[arr.length-1]+" ---> "+arr[idx-1]+"     :       "+st+"         ");

        for(int i=idx-1; i>0; i--){
            st = arr[i]-arr[i-1];
            if(st < 0){
                st = -st;
            }
            st = st * t;
            tst = tst + st;
            System.out.println("|  "+arr[i]+" ---> "+arr[i-1]+"     :       "+st+"         ");
        }
        System.out.println  ("+-------------------------------------------");
        System.out.println("\nTotal seek time : "+tst);

    }
}
