import java.util.Date;
import java.util.concurrent.atomic.AtomicLong;

public class TimeEventsStatistics {

    private AtomicLong eventsPerMinute,
            eventsPerHour, eventsPerDay;
    private long timeM, timeH, timeD, time;

    public TimeEventsStatistics() {
        eventsPerMinute = new AtomicLong(0);
        eventsPerHour = new AtomicLong(0);
        eventsPerDay = new AtomicLong(0);
        timeM = System.currentTimeMillis();
        timeH = System.currentTimeMillis();
        timeD = System.currentTimeMillis();
    }

    public void considerEvent(long time){
        if(time % (60 * 1000) == 0){
            timeM = time;
            eventsPerMinute.set(0);
        }
        if(time % (60 * 60 * 1000) == 0){
            timeH = time;
            eventsPerHour.set(0);
        }
        if(time % (24 * 60 * 60 * 1000) == 0){
            timeD = time;
            eventsPerDay.set(0);
        }
        if(time - timeM < 60 * 1000) eventsPerMinute.incrementAndGet();
        if(time - timeH < 60 * 60 * 1000) eventsPerHour.incrementAndGet();
        if(time - timeD < 24 * 60 * 60 * 1000) eventsPerDay.incrementAndGet();
    }

    public long getEventsCountPerMinute(){
        return eventsPerMinute.get();
    }

    public long getEventsCountPerHour(){
        return eventsPerHour.get();
    }

    public long getEventsCountPerDay(){
        return eventsPerDay.get();
    }
}
