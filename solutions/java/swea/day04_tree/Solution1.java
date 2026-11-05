package swea.day04_tree;
import java.io.*; 
import java.util.*; 

public class Solution1 {
    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
        int T = Integer.parseInt(br.readLine()); 

        for(int test_case = 1; test_case <= T; test_case++) {
			/*
                (1) 트리 정보 저장 
            */
            // 1 : V, E, 공통조상을 찾을 두 정점 
            StringTokenizer st = new StringTokenizer(br.readLine()); 
            int V = Integer.parseInt(st.nextToken()); 
            int E = Integer.parseInt(st.nextToken()); 
            int node1 = Integer.parseInt(st.nextToken()); 
            int node2 = Integer.parseInt(st.nextToken()); 

            // 2. 트리 저장 공간 만들기 
            int[] parent = new int[V + 1]; 

            // children[부모] = 자식들 
            List<Integer>[] children = new ArrayList[V + 1]; 

            for (int i = 1; i <= V; i++) {
                children[i] = new ArrayList<>(); 
            }

            // 3. 간선 만들기 
            st = new StringTokenizer(br.readLine()); 
            for (int i = 0; i  < E; i ++) {
                int p = Integer.parseInt(st.nextToken()); 
                int c = Integer.parseInt(st.nextToken()); 

                // 위로 올라가기 위한 정보 
                parent[c] = p; 

                // 아래로 내려가기 위한 정보 
                children[p].add(c); 
            }
            /*
                공통조상 찾기 
            */
            int current = node1;
        
            // 방문한 정점들을 저장 
            Set<Integer> visited = new HashSet<>(); 
            while (current != 0) {
                // 1. 현재 정점 저장
                visited.add(current); 
                current = parent[current];
            } 

             // 2. 부모로 한 칸 이동 
            current = node2; 
            int commonAnc = 0; 
            while (current != 0 ) {
                if (visited.contains(current)) {
                    commonAnc = current; 
                    break; 
                }

                    current = parent[current];
                }

            
            /*
                정점 개수 세기 
            */
            int size = 0; 
            Deque<Integer> stack = new ArrayDeque<>(); 
            stack.push(commonAnc); 

            while(!stack.isEmpty()) {
                // 현재 정점 하나 꺼내기 
                int node = stack.pop(); 

                // 정점 하나 발견
                size++; 

                // 현재 정점의 자식을 다시 stack에 넣기 
                for (int child: children[node]) {
                    stack.push(child); 
                }
            }

            System.out.print("#" + test_case + " " + commonAnc + " " + size);
            System.out.println();
		}
    
    }
}
