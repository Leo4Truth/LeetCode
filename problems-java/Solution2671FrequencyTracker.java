import java.util.*;

public class Solution2671FrequencyTracker {
    public static void main(String[] args) {

    }
}

class FrequencyTracker {

    private final Map<Integer, Integer> count;
    private final Map<Integer, Set<Integer>> freqMap;

    public FrequencyTracker() {
        count = new HashMap<>();
        freqMap = new HashMap<>();
    }

    public void add(int number) {
        if (!count.containsKey(number)) {
            count.put(number, 0);
        }
        int oldFreq = count.getOrDefault(number, 0);
        int newFreq = oldFreq + 1;
        count.put(number, newFreq);
        if (oldFreq > 0) {
            freqMap.get(oldFreq).remove(number);
        }
        if (!freqMap.containsKey(newFreq)) {
            Set<Integer> newSet = new HashSet<>();
            newSet.add(number);
            freqMap.put(newFreq, newSet);
        } else {
            freqMap.get(newFreq).add(number);
        }
    }

    public void deleteOne(int number) {
        if (count.containsKey(number) && count.get(number) > 0) {
            int oldFreq = count.get(number);
            int newFreq = oldFreq - 1;
            count.put(number, newFreq);
            freqMap.get(oldFreq).remove(number);
            if (newFreq > 0) {
                freqMap.get(newFreq).add(number);
            }
        }
    }

    public boolean hasFrequency(int frequency) {
        return freqMap.containsKey(frequency) && !freqMap.get(frequency).isEmpty();
    }
}

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker obj = new FrequencyTracker();
 * obj.add(number);
 * obj.deleteOne(number);
 * boolean param_3 = obj.hasFrequency(frequency);
 */