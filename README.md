package Core;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class DataProcessor2 {

    public String[] processPipeline(String[] inputStrings) {
        List<Double> numbers = convertToDoubles(inputStrings);
        List<Double> processed = processData(numbers);
        return convertToStringsWithoutDotZero(processed);
    }

    private List<Double> convertToDoubles(String[] strings) {
        List<Double> doubles = new ArrayList<>();
        for (String s : strings) {
            try {
                doubles.add(Double.parseDouble(s.trim()));
            } catch (NumberFormatException e) {
            }
        }
        return doubles;
    }

    private String[] convertToStringsWithoutDotZero(List<Double> doubles) {
        String[] strings = new String[doubles.size()];
        for (int i = 0; i < doubles.size(); i++) {
            double value = doubles.get(i);
            // Если число целое - выводим без .0
            if (value == (long) value) {
                strings[i] = String.valueOf((long) value);
            } else {
                strings[i] = String.valueOf(value);
            }
        }
        return strings;
    }

    public List<Double> processData(List<Double> input) {
        if (input.isEmpty()) {
            return new ArrayList<>();
        }

        double min = Collections.min(input);
        double max = Collections.max(input);

        List<Double> result = new ArrayList<>();

        for (double i = min + 1; i < max; i++) {
            if (!input.contains(i)) {
                result.add(i);
            }
        }

        return result;
    }
}
package Core;
import java.util.ArrayList;
import java.util.List;

public class DataProcessor3 {
    public static List<Integer> processData(List<Integer> input) {
        List<Integer> result = new ArrayList<>();
        for (Integer num : input) {
            if (!result.contains(num)) {
                result.add(num);
            }
        }
        return result;
    }

    public static String[] processPipeline(String[] strings) {

        List<Integer> numbers = convertToIntegers(strings);

        List<Integer> uniqueNumbers = processData(numbers);

        return convertToStrings(uniqueNumbers);
    }

    private static List<Integer> convertToIntegers(String[] strings) {
        List<Integer> result = new ArrayList<>();
        for (String str : strings) {
            try {
                result.add(Integer.parseInt(str));
            } catch (NumberFormatException e) {
            }
        }
        return result;
    }

    private static String[] convertToStrings(List<Integer> numbers) {
        String[] result = new String[numbers.size()];
        for (int i = 0; i < numbers.size(); i++) {
            result[i] = String.valueOf(numbers.get(i));
        }
        return result;
    }
}
