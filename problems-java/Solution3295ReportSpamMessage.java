import java.util.*;

/**
 * @link https://leetcode.cn/problems/report-spam-message/
 * 
 * @level middle
 * 
 * @tag simulation
 * @tag hash set
 */
public class Solution3295ReportSpamMessage {

    public boolean reportSpam(String[] message, String[] bannedWords) {
        Map<String, Integer> wordCnt = new HashMap<>();

        for (String messageWord : message) {
            if (!wordCnt.containsKey(messageWord)) {
                wordCnt.put(messageWord, 1);
            } else {
                wordCnt.put(messageWord, wordCnt.get(messageWord) + 1);
            }
        }

        Set<String> bannedWordSet = new HashSet<>();
        int bannedWordCnt = 0;
        for (String bannedWord : bannedWords) {
            if (bannedWordSet.contains(bannedWord)) {
                continue;
            }
            bannedWordSet.add(bannedWord);
            if (wordCnt.containsKey(bannedWord)) {
                bannedWordCnt += wordCnt.get(bannedWord);
            }
            if (bannedWordCnt >= 2) {
                return true;
            }
        }

        return false;
    }


    /**
     * 
     * @param message
     * @param bannedWords
     * @return
     */
    public boolean reportSpam1(String[] message, String[] bannedWords) {
        Set<String> bannedWordSet = new HashSet<>(Arrays.asList(bannedWords));
        int bannedWordCnt = 0;
        for (String messageWord : message) {
            if (bannedWordSet.contains(messageWord)) {
                bannedWordCnt++;
            }
            if (bannedWordCnt >= 2) {
                return true;
            }
        }
        return false;
    }

}
