import java.util.concurrent.Semaphore;
import java.util.function.IntConsumer;

class FizzBuzz {
    private int n;
    private Semaphore fizzS;
    private Semaphore buzzS;
    private Semaphore fizzbuzzS;
    private Semaphore numberS;

    public FizzBuzz(int n) {
        this.n = n;
        this.fizzS = new Semaphore(0);
        this.buzzS = new Semaphore(0);
        this.fizzbuzzS = new Semaphore(0);
        this.numberS = new Semaphore(1);
    }

    public void fizz(Runnable printFizz) throws InterruptedException {
        for(int i=1;i<=n;i++){
            if(i % 3 == 0 && i % 5 != 0){
                fizzS.acquire();
                printFizz.run();
                numberS.release();
            }
        }
    }

    public void buzz(Runnable printBuzz) throws InterruptedException {
        for(int i=1;i<=n;i++){
            if(i % 5 == 0 && i % 3 != 0){
                buzzS.acquire();
                printBuzz.run();
                numberS.release();
            }
        }
    }

    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        for(int i=1;i<=n;i++){
            if(i % 15 == 0){
                fizzbuzzS.acquire();
                printFizzBuzz.run();
                numberS.release();
            }
        }
    }

    public void number(IntConsumer printNumber) throws InterruptedException {
        for(int i=1;i<=n;i++){
            numberS.acquire();
            if(i % 3 != 0 && i % 5 != 0){
                printNumber.accept(i);
                numberS.release();
            } else if(i % 3 == 0 && i % 5 != 0){
                fizzS.release();
            } else if(i % 5 == 0 && i % 3 != 0){
                buzzS.release();
            } else {
                fizzbuzzS.release();
            }
        }
    }
}
