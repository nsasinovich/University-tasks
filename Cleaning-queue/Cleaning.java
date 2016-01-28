package bsu.mmf.sasinovich;
import java.util.Random;
import java.util.concurrent.TimeUnit;
 
public class Cleaning {
    public static void main(String args[]) {
        TasksQueue queue = new TasksQueue();
 
        Cleaner cleaner = new Cleaner("Anna", queue);
        new Thread(cleaner).start();
 
        cleaner = new Cleaner("Olga", queue);
        new Thread(cleaner).start();
 
        cleaner = new Cleaner("Masha", queue);
        new Thread(cleaner).start();
 
        cleaner = new Cleaner("Liza", queue);
        new Thread(cleaner).start();
 
    }
}
 
class Task {
 
    private String description;
    private long time;
 
    public Task(String description, long time) {
        this.description = description;
        this.time = time;
    }
 
    public void setDescription(String description) {
        this.description = description;
    }
 
    public String getDescription() {
        return this.description;
    }
 
    public void setTime(long time) {
        this.time = time;
    }
 
    public long getTime() {
        return this.time;
    }
 
}
 
class TasksQueue {
 
    private Random random = new Random();
 
    private String[] descriptions = new String[]{
        "wash the dishes",
        "clean the window",
        "water the flowers",
        "tuck in bed",
        "wash floors",
        "vacuum-clean",
        "relax"
    };
 
    private String getRandomDescription() {
        return descriptions[random.nextInt(descriptions.length)];
    }
 
    public synchronized Task getTask() {
        return new Task(getRandomDescription(), random.nextInt(10) + 1);
    }
 
}
 
class Cleaner implements Runnable {
 
    private TasksQueue queue;
    private String name;
 
    public Cleaner(String name, TasksQueue queue) {
        this.queue = queue;
        this.name = name;
    }
 
    @Override
    public void run() {
        while (true) {
            Task task = queue.getTask();
            process(task);
        }
    }
 
    private void process(Task task) {
        try {
            TimeUnit.SECONDS.sleep(task.getTime());
            System.out.println(String.format("%s done \"%s\" in %d min.",
                                name,
                                task.getDescription(),
                                task.getTime()));
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
 
}