import java.util.Scanner;

class Process {
    int pid; // Process ID
    int arrivalTime; // Arrival Time
    int burstTime; // Burst Time
    int priority; // Priority (lower value = higher priority)
    int finishTime; // Finish Time
    int turnaroundTime; // Turnaround Time
    int waitingTime; // Waiting Time
}

public class PriorityNonPreemptiveScheduling {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number of processes: ");
        int n = sc.nextInt();

        Process[] processes = new Process[n];
        for (int i = 0; i < n; i++) {
            processes[i] = new Process();
            processes[i].pid = i + 1;
            System.out.print("Enter arrival time, burst time, and priority for process " + (i + 1) + ": ");
            processes[i].arrivalTime = sc.nextInt();
            processes[i].burstTime = sc.nextInt();
            processes[i].priority = sc.nextInt();
        }

        // Sorting by Arrival Time initially for simplicity
        sortProcessesByArrivalTime(processes);

        int currentTime = 0;
        boolean[] completed = new boolean[n];
        int completedCount = 0;

        // Non-preemptive Priority Scheduling
        while (completedCount < n) {
            int highestPriorityIndex = -1;
            int highestPriority = Integer.MAX_VALUE;

            for (int i = 0; i < n; i++) {
                if (!completed[i] && processes[i].arrivalTime <= currentTime && processes[i].priority < highestPriority) {
                    highestPriority = processes[i].priority;
                    highestPriorityIndex = i;
                }
            }

            if (highestPriorityIndex == -1) {
                currentTime++;
                continue;
            }

            Process selectedProcess = processes[highestPriorityIndex];
            selectedProcess.finishTime = currentTime + selectedProcess.burstTime;
            selectedProcess.turnaroundTime = selectedProcess.finishTime - selectedProcess.arrivalTime;
            selectedProcess.waitingTime = selectedProcess.turnaroundTime - selectedProcess.burstTime;

            currentTime += selectedProcess.burstTime;
            completed[highestPriorityIndex] = true;
            completedCount++;
        }

        // Display results
        System.out.println("\nProcess\tArrival\tBurst\tPriority\tFinish\tTurnaround\tWaiting");
        for (Process process : processes) {
            System.out.println(process.pid + "\t" + process.arrivalTime + "\t" + process.burstTime + "\t" + process.priority + "\t\t" +
                    process.finishTime + "\t" + process.turnaroundTime + "\t\t" + process.waitingTime);
        }

        sc.close();
    }

    // Sort processes by arrival time for non-preemptive scheduling
    private static void sortProcessesByArrivalTime(Process[] processes) {
        for (int i = 0; i < processes.length - 1; i++) {
            for (int j = i + 1; j < processes.length; j++) {
                if (processes[i].arrivalTime > processes[j].arrivalTime) {
                    Process temp = processes[i];
                    processes[i] = processes[j];
                    processes[j] = temp;
                }
            }
        }
    }
}


/*
// Sample Input:
// Enter the number of processes: 4
// Enter arrival time, burst time, and priority for process 1: 0 8 2
// Enter arrival time, burst time, and priority for process 2: 1 4 1
// Enter arrival time, burst time, and priority for process 3: 2 9 3
// Enter arrival time, burst time, and priority for process 4: 3 5 2

// Expected Output:
// Process Arrival Burst Priority Finish Turnaround Waiting
// 1       0       8     2        8       8         0
// 2       1       4     1        12      11        7
// 3       2       9     3        26      24        15
// 4       3       5     2        17      14        9
*/
