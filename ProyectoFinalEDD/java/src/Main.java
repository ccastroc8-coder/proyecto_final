import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.TreeMap;

public class Main {

    public static void main(String[] args) {

        benchmarkHashMap();
        benchmarkTreeMap();

        System.out.println(
            "\njava_results.csv generado correctamente"
        );
    }

    public static void benchmarkHashMap() {

        try {

            FileWriter file =
                new FileWriter("java_results.csv");

            file.write(
                "language,operation,structure,records,time_ms\n"
            );

            HashMap<Integer, String> map =
                new HashMap<>();

            long startInsert = System.nanoTime();

            for(int i = 0; i < 10000; i++) {

                map.put(i, "Student" + i);
            }

            long endInsert = System.nanoTime();

            double insertTime =
                (endInsert - startInsert) / 1000000.0;

            file.write(
                "Java,insert,HashMap,10000,"
                + insertTime
                + "\n"
            );

            long startSearch = System.nanoTime();

            for(int i = 0; i < 10000; i++) {

                map.get(i);
            }

            long endSearch = System.nanoTime();

            double searchTime =
                (endSearch - startSearch) / 1000000.0;

            file.write(
                "Java,search,HashMap,10000,"
                + searchTime
                + "\n"
            );

            file.close();

        } catch(IOException e) {

            System.out.println("Error");
        }
    }

    public static void benchmarkTreeMap() {

        try {

            FileWriter file =
                new FileWriter(
                    "java_results.csv",
                    true
                );

            TreeMap<Integer, String> tree =
                new TreeMap<>();

            long startInsert = System.nanoTime();

            for(int i = 0; i < 10000; i++) {

                tree.put(i, "Student" + i);
            }

            long endInsert = System.nanoTime();

            double insertTime =
                (endInsert - startInsert) / 1000000.0;

            file.write(
                "Java,insert,TreeMap,10000,"
                + insertTime
                + "\n"
            );

            long startTraversal = System.nanoTime();

            for(Integer key : tree.keySet()) {

                tree.get(key);
            }

            long endTraversal = System.nanoTime();

            double traversalTime =
                (endTraversal - startTraversal)
                / 1000000.0;

            file.write(
                "Java,traversal,TreeMap,10000,"
                + traversalTime
                + "\n"
            );

            file.close();

        } catch(IOException e) {

            System.out.println("Error");
        }
    }
}