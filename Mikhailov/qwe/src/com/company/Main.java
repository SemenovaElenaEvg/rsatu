package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        String mainStr = in.nextLine();


        //mainStr = mainStr.replaceAll("()", "1");

        while (true) {
            int index = mainStr.indexOf("()");


            if (index == -1) {
                break;
            }

            mainStr = mainStr.replace("()", "");
        }

        if(mainStr.length() < 4){
            System.out.println(mainStr);
            System.exit(0);
        }

        Integer[] dopMas = new Integer[mainStr.length()];
        String[] mainMas = new String[mainStr.length()];


        for (int i = 0; i < mainStr.length(); i++) {
            dopMas[i] = 0;
        }

        mainMas = mainStr.split("");

        if (mainMas[0].equals("(") && mainMas[mainStr.length() - 1].equals(")")) {
            dopMas[0] = 1;
            dopMas[mainStr.length() - 1] = 1;
        }


        int i = 0;
        int startOfSub = 0;

        while (i < mainStr.length()) {
            if (mainMas[i].equals("(") && dopMas[i] == 0) {
                if (!mainMas[i + 1].equals("(") && dopMas[i + 1] == 0) {
                    startOfSub = i;
                    while ((!mainMas[i].equals(")") && dopMas[i] == 0) || (mainMas[i].equals("(") && dopMas[i] == 0)) {
                        i++;
                    }
                    for (int j = startOfSub; j < i + 1; j++) {
                        dopMas[j] = 1;
                    }

                } else {
                    i++;
                }
            } else {
                i++;
            }
        }


        String[] resMas = new String[mainStr.length()];

        for (int j = 0; j < mainStr.length(); j++) {
            resMas[j] = "-";
        }

        String str = "";
        int ind = 0;
        for (int j = 0; j < mainStr.length(); j++) {
            if (dopMas[j] == 1 || (!mainMas[j].equals("(") && !mainMas[j].equals(")") && dopMas[j] == 0)) {
                //System.out.print(mainMas[j]);
                resMas[ind] = mainMas[j];
                ind++;

            }
        }


        if (resMas[0].equals(resMas[1]) && resMas[ind - 2].equals(resMas[ind - 1])) {
            if (ind < 6) {
                resMas[0] = "-";
                resMas[ind - 1] = "-";
            }
        }


        for (int j = 0; j < mainStr.length(); j++) {
            if (!resMas[j].equals("-"))
                System.out.print(resMas[j]);
        }

        // ((abx)sd(d()))

        //((()(b)))
        // ((a)(b))
        // ((((a)((b))((((c)))))))
    }
}
