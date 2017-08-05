package com.jee.practice;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Color {

	public static void main(String[] args) {
		int t, n, i, tc, sum, count, val;
		boolean flag;
		Scanner sc = new Scanner(System.in);
		t = sc.nextInt();
		for (tc = 1; tc <= t; tc++) {
			n = sc.nextInt();
			int[] A = new int[n];
			sum = n;
			Map<Integer, Integer> M = new HashMap<>();
			for (i = 0; i < n; i++) {
				A[i] = sc.nextInt();
				if (!M.containsKey(A[i])) {
					M.put(A[i], 1);
				} else {
					count = M.get(A[i]);
					M.put(A[i], count + 1);
				}
			}
			flag = true;
			while (sum > 0) {
				if (M.containsKey(sum)) {
					val = M.get(sum);
					M.remove(sum);
					sum -= val;
				} else {
					flag = false;
					break;
				}
			}
			if (flag) {
				if (!M.isEmpty()) {
					System.out.println("NO");
				} else {
					System.out.println("YES");
				}
			} else {
				System.out.println("NO");
			}
		}
	}
}
