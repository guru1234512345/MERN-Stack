import java.util.Scanner;

class Process {
    int pid; // Process ID
    int arrivalTime; // Arrival Time
    int burstTime; // Burst Time
    int priority; // Priority (lower value = higher priority)
    int remainingTime; // Remaining Time for execution
    int finishTime; // Finish Time
    int turnaroundTime; // Turnaround Time
    int waitingTime; // Waiting Time
}

public class PriorityPreemptiveScheduling {
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
            processes[i].remainingTime = processes[i].burstTime;
        }

        // Time variables
        int completed = 0, currentTime = 0, minPriority = Integer.MAX_VALUE;
        int shortest = -1;
        boolean found;

        // Preemptive Priority Scheduling
        while (completed != n) {
            found = false;
            for (int i = 0; i < n; i++) {
                if (processes[i].arrivalTime <= currentTime && processes[i].remainingTime > 0 &&
                        processes[i].priority < minPriority) {
                    minPriority = processes[i].priority;
                    shortest = i;
                    found = true;
                }
            }

            if (!found) {
                currentTime++;
                continue;
            }

            // Execute the selected process
            processes[shortest].remainingTime--;
            minPriority = processes[shortest].priority;

            if (processes[shortest].remainingTime == 0) {
                processes[shortest].finishTime = currentTime + 1;
                processes[shortest].turnaroundTime = processes[shortest].finishTime - processes[shortest].arrivalTime;
                processes[shortest].waitingTime = processes[shortest].turnaroundTime - processes[shortest].burstTime;
                completed++;
                minPriority = Integer.MAX_VALUE;
            }
            currentTime++;
        }

        // Display results
        System.out.println("\nProcess\tArrival\tBurst\tPriority\tFinish\tTurnaround\tWaiting");
        for (Process process : processes) {
            System.out.println(process.pid + "\t" + process.arrivalTime + "\t" + process.burstTime + "\t" + process.priority + "\t\t" +
                    process.finishTime + "\t" + process.turnaroundTime + "\t\t" + process.waitingTime);
        }

        sc.close();
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
// 1       0       8     2        18      18        10
// 2       1       4     1        5       4         0
// 3       2       9     3        29      27        18
// 4       3       5     2        13      10        5
*/
