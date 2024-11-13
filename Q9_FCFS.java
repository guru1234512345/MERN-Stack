import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Q9_FCFS {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of processes : ");
        int processes = sc.nextInt();

        int [] arrivalTimes = new int[processes];
        int [] burstTimes = new int[processes];
        for(int i = 0; i < processes; i++){
            System.out.println("Enter arrival time for process P"+i+" : ");
            arrivalTimes[i] = sc.nextInt();
            System.out.println("Enter burst time for process P"+i+" : ");
            burstTimes[i] = sc.nextInt();
        }
        // find min arrival times
        int minArrivalTime = Integer.MAX_VALUE;
        for (int arrivalTime : arrivalTimes) {
            minArrivalTime = Math.min(minArrivalTime, arrivalTime);
        }

        Queue<Integer> readyQueue = new LinkedList<>();
            for(int idx = 0; idx < arrivalTimes.length; idx++){
                if(arrivalTimes[idx] == minArrivalTime){
                    readyQueue.add(idx);
                }
        }
        System.out.println(readyQueue);

        int [] finishTimes = new int[processes];
        int [] turnaroundTimes = new int[processes]; // finish - arrival
        int [] waitingTimes = new int[processes]; // turnaround - burst

        int index = 0;
        int finish = minArrivalTime;
        while (!readyQueue.isEmpty()){
            int process = readyQueue.poll();
            // finish time
            finish += burstTimes[process];
            finishTimes[index] = finish;
            // turnaround time
            turnaroundTimes[index] = finishTimes[process] - arrivalTimes[process];
            // waiting times
            waitingTimes[index] = turnaroundTimes[process] - burstTimes[process];
            // increment index
            index++;
        }

        // pretty printing
        System.out.println("Process \t\t Arrival Time \t\t Burst Time \t\t Finish Time \t\t Turnaround Time \t\t Waiting Time \t\t");
        for(int i = 0; i < processes; i++){
            System.out.printf("P%d\t\t\t\t\t%d\t\t\t\t\t%d\t\t\t\t\t%d\t\t\t\t\t%d\t\t\t\t\t\t%d\t\t\t\t\t" , i,arrivalTimes[i],burstTimes[i],finishTimes[i],turnaroundTimes[i],waitingTimes[i]);
            System.out.println();
        }

        /*
            How to run the program :
            -> save file as Q9_FCFS.java   (save file in Desktop)
            -> open terminal and type command cd Desktop
            -> see whether there is Q9_FCFS.java file is present (use command ls for that)
            -> if found , next command      javac Q9_FCFS.java
            -> next command     java Q9_FCFS
            -> Now your program is running , provide the input below.

            Input :

            No of Processes = 6

            Process     Arrival Time       Burst Time
            P0              0                   9
            P1              1                   3
            P2              1                   2
            P3              1                   4
            P4              2                   3
            P5              3                   2

            Output :

            Process     Arrival Time       Burst Time       Finish Time        Turnaround Time      Waiting Time
            P0              0                   9               9                   9                   0
            P1              1                   3               12                  11                  8
            P2              1                   2               14                  13                  11
            P3              1                   4               18                  17                  13
            P4              2                   3               21                  19                  16
            P5              3                   2               23                  20                  18
         */
    }
}
