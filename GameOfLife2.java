import java.util.*;
public class GameOfLife2 {

	public static void main(String[] args) {
		Scanner poi = new Scanner (System.in);
		int y = poi.nextInt();
		int x = poi .nextInt();
		
		int[][]arr = new int [y][x];
		
		for(int aa = 0;aa<y;aa++) {
			for(int bb = 0;bb<x;bb++) {
				arr[aa][bb] = poi.nextInt();
			}
		}
		int que = poi.nextInt();
		int box_x,box_y;
		int box_x_str,box_y_str;
		int box_x_end,box_y_end;
		int pos_x,pos_y;
		int ct = 0;
		for(int uu = 0;uu< que;uu++) {
			box_y = poi.nextInt();
			box_x = poi.nextInt();
			pos_y = poi.nextInt()-1;
			pos_x = poi.nextInt()-1;
			
			box_y = (box_y-1)/2;
			box_x = (box_x-1)/2;
			
			box_y_str = pos_y - box_y;
			box_x_str = pos_x - box_x;
			
			box_y_end = pos_y + box_y;
			box_x_end = pos_x + box_x;
			
			if(box_y_str < 0) box_y_str = 0;
			if(box_x_str < 0) box_x_str = 0;
			if(box_y_end >= y) box_y_end = y-1;
			if(box_x_end >= x) box_x_end = x-1;
			
			
			
			for(int ss = box_y_str; ss <= box_y_end; ss++) {
				for(int dd = box_x_str; dd <= box_x_end; dd++) {
					if(arr[ss][dd] == 1) ct++;
				}
			}
			
			System.out.println(ct);
			ct = 0;
		}
		

	}

}
