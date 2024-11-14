package os;

import java.util.Scanner;

public class SSTF_DISK_SH {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("\n        !!! SSTF Disk Scheduling Algorithm !!! \n");

        int ntrack, nreq;

        System.out.print("Enter total number of tracks present on a Plater: ");
        ntrack = sc.nextInt();

        System.out.print("Enter total number of track requests: ");
        nreq = sc.nextInt();

        int[] arr = new int[nreq+1];
        System.out.println("Enter your track request queue: ");
        for(int i=1; i<= nreq; i++){
            arr[i] = sc.nextInt();
        }

        int rwhead;
        System.out.print("Enter initial track position of  R/W head: ");
        rwhead = sc.nextInt();

        arr[0] = rwhead; // initial position of read-write head is stored at arr[0]

        int t, st, tst = 0;
        System.out.print("Enter time taken by R/W head pointer for one track movement: ");
        t = sc.nextInt();

        int[] arr1 = new int[nreq+1];
        arr1[0] = arr[0];
        int diff, flag=0, nearestno=99999;     // nearest track = nearestno
        for(int i=0; i<nreq; i++){
            for(int j=1; j<=nreq; j++){
                if(arr[j] >= 0){
                    diff = arr1[i] - arr[j];
                    if(diff < 0){
                        diff = -diff;
                    }
                    if(diff<nearestno){
                        nearestno = diff;
                        arr1[i+1] = arr[j];
                        flag = j;
                    }
                }
            }
            arr[flag] = -1;
            nearestno = 999999;
        }

        System.out.println  ("\n+-------------------------------------------");
        System.out.println("|    --->             seek time   ");
        System.out.println  ("|-------------------------------------------");
        for(int i=0; i < nreq; i++){
            st = arr1[i]-arr1[i+1];
            if(st < 0){
                st = -st;
            }
            st = st * t;
            tst = tst + st;

            System.out.println("|  "+arr1[i]+" ---> "+arr1[i+1]+"     :       "+st+"         ");
        }
        System.out.println  ("+-------------------------------------------");

        System.out.println("\nTotal seek time : "+tst);
    }
}