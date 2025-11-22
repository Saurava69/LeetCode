import java.util.concurrent.Semaphore;
import java.util.function.IntConsumer;

class FizzBuzz {
    private int n;

    private Semaphore fizzS = new Semaphore(0);
    private Semaphore buzzS = new Semaphore(0);
    private Semaphore fizzbuzzS = new Semaphore(0);
    private Semaphore numberS = new Semaphore(1);

    private int current = 1;

    public FizzBuzz(int n) {
        this.n = n;
    }

    // printFizz.run() outputs "fizz".
    public void fizz(Runnable printFizz) throws InterruptedException {
        while (true) {
            fizzS.acquire();
            if (current > n) return;
            printFizz.run();
            current++;
            numberS.release();
        }
    }

    // printBuzz.run() outputs "buzz".
    public void buzz(Runnable printBuzz) throws InterruptedException {
        while (true) {
            buzzS.acquire();
            if (current > n) return;
            printBuzz.run();
            current++;
            numberS.release();
        }
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        while (true) {
            fizzbuzzS.acquire();
            if (current > n) return;
            printFizzBuzz.run();
            current++;
            numberS.release();
        }
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void number(IntConsumer printNumber) throws InterruptedException {
        while (true) {
            numberS.acquire();
            if (current > n) {
                // release workers once so they exit gracefully
                fizzS.release();
                buzzS.release();
                fizzbuzzS.release();
                return;
            }

            if (current % 15 == 0) {
                fizzbuzzS.release();
            } else if (current % 3 == 0) {
                fizzS.release();
            } else if (current % 5 == 0) {
                buzzS.release();
            } else {
                printNumber.accept(current);
                current++;
                numberS.release();
            }
        }
    }
}
