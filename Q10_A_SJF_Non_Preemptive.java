import java.util.*;

public class Q10_A_SJF_Non_Preemptive {
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
        // find min arrival time
        int minArrivalTime = Integer.MAX_VALUE;
        for(int arrivalTime : arrivalTimes){
            minArrivalTime = Math.min(minArrivalTime,arrivalTime);
        }

        Queue<Integer> readyQueue = new LinkedList<>();

        for(int j = 0; j < processes; j++){
            if(arrivalTimes[j] == minArrivalTime){
                readyQueue.offer(j);
            }
        }

        int time = minArrivalTime;
        int [] finishTimes = new int[processes];
        int [] turnaroundTimes = new int[processes];
        int [] waitingTimes = new int[processes];
        Set<Integer> executed = new HashSet<>();

        while (!readyQueue.isEmpty()){
            int process = findMinBurstTimeProcess(readyQueue,burstTimes,arrivalTimes,executed);
            time += burstTimes[process];
            finishTimes[process] = time;
            executed.add(process);
            for(int i = 0; i < processes; i++){
                if(!executed.contains(i) && !readyQueue.contains(i) && arrivalTimes[i] <= time){
                    readyQueue.add(i);
                }
            }
        }

        for(int i = 0; i < processes; i++){
            turnaroundTimes[i] = finishTimes[i] - arrivalTimes[i];
            waitingTimes[i] = turnaroundTimes[i] - burstTimes[i];
        }
        // Pretty Printing
        System.out.println("Process \t\t Arrival Time \t\t Burst Time \t\t Finish Time \t\t Turnaround Time \t\t Waiting Time \t\t");
        for(int i = 0; i < processes; i++){
            System.out.printf("P%d\t\t\t\t\t%d\t\t\t\t\t%d\t\t\t\t\t%d\t\t\t\t\t%d\t\t\t\t\t\t%d\t\t\t\t\t" , i,arrivalTimes[i],burstTimes[i],finishTimes[i],turnaroundTimes[i],waitingTimes[i]);
            System.out.println();
        }
    }

    private static int findMinBurstTimeProcess(Queue<Integer> readyQueue, int [] burstTimes,int [] arrivalTimes,Set<Integer> executed){
        // Find min remaining time
        int minBurstTime = Integer.MAX_VALUE;
        for (int process : readyQueue) {
            if (!executed.contains(process) && burstTimes[process] < minBurstTime) {
                minBurstTime = burstTimes[process];
            }
        }

        List<Integer> processesWithSameBurstTime = new ArrayList<>();
        for(int process : readyQueue){
            if(!executed.contains(process) && burstTimes[process] == minBurstTime){
                processesWithSameBurstTime.add(process);
            }
        }

        if(processesWithSameBurstTime.size() == 1){
            return processesWithSameBurstTime.get(0);
        }

        // if more than 1 processes has the same burst time then select the one which arrived first
        // and if arrival times are same then select first
        int minArriTime = Integer.MAX_VALUE;
        int processId = -1;
        for (int process : processesWithSameBurstTime) {
            if (!executed.contains(process) && arrivalTimes[process] < minArriTime) {
                minArriTime = arrivalTimes[process];
                processId = process;
            }
        }

        // remove selected process from the readyQueue
        readyQueue.remove(processId);
        return processId;
    }
}
/*
input: 4 1 3 2 4 1 2 4 4
output:
Process 		 Arrival Time 		 Burst Time 		 Finish Time 		 Turnaround Time 		 Waiting Time
P0					1					3					6					5						2
P1					2					4					10					8						4
P2					1					2					3					2						0
P3					4					4					14					10						6


 */