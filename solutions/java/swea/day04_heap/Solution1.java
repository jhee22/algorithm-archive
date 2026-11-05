package swea.day04_heap;
import java.io.*; 
import java.util.*; 
public class Solution1 {
    // 힙의 값을 저장하는 배열, 크기
    static int[] heap; 
    static int size; 

    static void insert(int val){
        // 맨 뒤에 삽입 
        heap[++size] = val; 
        int curr = size; 
        
        // heap[1] = Root = 부모 X 
        while (curr > 1) {
            int parent = curr / 2; // 부모 위치 찾기 

            if (heap[parent] >= heap[curr]){
                break; 
            }

            int tmp = heap[parent]; 
            heap[parent] = heap[curr]; 
            heap[curr] = tmp;

            curr = parent; 
        }
    }

    static int remove(){
        if (size == 0) {
            return -1;
        }

        int result = heap[1]; 
        heap[1] = heap[size]; 
        size--; 

        int curr = 1; 
        while (true) {
            int left = curr * 2; 
            int right = curr * 2 + 1; 

            if (left > size) {
                break; 
            }

            int bigger = left; 
            if (right <= size && heap[right] > heap[left]) {
                bigger = right; 
            }

            if (heap[curr] >= heap[bigger]) {
                break; 
            }

            int tmp = heap[curr]; 
            heap[curr] = heap[bigger]; 
            heap[bigger] = tmp; 

            curr = bigger; 
        }
        return result; 
    
    }

    public static void main(String args[]) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
        StringBuilder sb = new StringBuilder(); 
        int T = Integer.parseInt(br.readLine());
        for (int test_case = 1; test_case <= T; test_case++) {
            // 수행해야할 연산의 수 
            int N = Integer.parseInt(br.readLine()); 
            heap = new int[N + 1]; 
            size = 0; 

            sb.append("#").append(test_case); 
            for (int i = 0; i < N; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine()); 
                 
                int cmd = Integer.parseInt(st.nextToken()); 
                // 연산 1 : val 를 최대 힙에 추가하는 연산 
                if (cmd == 1) {
                    int val = Integer.parseInt(st.nextToken()); 
                    insert(val); 
                
                // 연산 2 : 현재 최대 힙의 루트 노드의 키값을 출력, 해당 노드를 삭제
                } else {
                    sb.append(" ").append(remove());
                }

            }
            sb.append("\n"); 

            
        }

        System.out.println(sb);

    }
     

}