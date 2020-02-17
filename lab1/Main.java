import java.util.*;

public class Main {

    public static void main(final String args[]) throws InterruptedException {
        System.out.println("working so far");

        // producer/consumer methods in PC object
        PC pc = new PC();

        // create producer thread
        Thread producer = new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    pc.produce();
                }
                catch(InterruptedException e) {
                    System.out.println(e);
                }
            }
		});

        // create consumer thread
        Thread consumer = new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    pc.consume();
                }
                catch(InterruptedException e) {
                    System.out.println(e);
                }
            }
        });

        //start threads
        producer.start();
        consumer.start();

        //producer.join();
        //consumer.join();

    }
}

// object with array thats written to and read by consume/produce methods
class PC {
    //int[] buffer = new int[5];
    ArrayList<Integer> buffer = new ArrayList<Integer>(5);
    int bufferSize = 5;
    int value = 1;

    public void produce() throws InterruptedException {
        while(true) {
            //Thread.sleep(100);
            synchronized(this) {

                // while buffer is full, wait()
                while(buffer.size() == bufferSize) {
                    wait();
                }
                // if buffer is not full, add 1 to arrayList and notify threads
                System.out.println("adding " + value + " to buffer");
                buffer.add(0, value);
                System.out.print("[ ");
                for(int num:buffer) {
                    System.out.print(num + " ");
                }
                System.out.println("]");
                //Thread.sleep(1000);
                //notifyAll();
                if(buffer.size() == bufferSize) {
                    System.out.println("waiting for consumer thread");
                }
                else {
                    notifyAll();
                } 
            }
            Thread.sleep(800);
            //Thread.sleep(200);
            //continue;
        }
    }
    public void consume() throws InterruptedException {
        while(true) {
            //Thread.sleep(100);
            synchronized(this) {
                
                // while buffer is empty, wait()
                while(buffer.size() == 0) {
                    wait();
                }

                // if buffer full, remove 1 element from arrayList and notify threads
                System.out.println("removing " + value + " from buffer");
                //buffer.remove(buffer.size() - 1);
                buffer.remove(0);
                System.out.print("[ ");
                for(int num:buffer) {
                    System.out.print(num + " ");
                }
                System.out.println("]");
                //Thread.sleep(200);
                //notifyAll();
                if(buffer.size() < bufferSize) {
                    System.out.println("waiting for on producer thread");
                }
                else {
                    notifyAll();
                }
            }
            Thread.sleep(1000);
            //Thread.sleep(1000);
            //continue;
        }
    }
}
