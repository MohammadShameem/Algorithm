// Java Program to demonstrate adjacency list 
// representation of graphs
import java.util.LinkedList;

public class GAM 
{
    static class City{
        int city;
        LinkedList<Integer> nearCities[];
        City(int city){
            this.city=city;
            
            nearCities= new LinkedList[city];
            
            for (int i= 0;i<city ;i++ ){
                
                nearCities[i]=new LinkedList<>();
            } 
            
        }
    }
        
     static   void addRoad(City city,int src,int des){
            city.nearCities[src].addFirst(des);
            city.nearCities[des].addFirst(src);
            
        }
    
      static void printGraph(City city)
    {       
        for(int v = 0; v < city.city; v++)
        {
            System.out.println("Adjacency list of cities "+ v);
            System.out.print("head");
            for(Integer pCrawl: city.nearCities[v]){
                System.out.print(" -> "+pCrawl);
            }
            System.out.println("\n");
        }
    }
    

	
	// Driver program to test above functions
	public static void main(String args[])
	{
		// create the graph given in above figure
		int V = 5;
		City city = new City(V);
		addRoad(city, 0, 1);
		addRoad(city, 0, 4);
		addRoad(city, 1, 2);
		addRoad(city, 1, 3);
		addRoad(city, 1, 4);
		addRoad(city, 2, 3);
		addRoad(city, 3, 4);
	
		// print the adjacency list representation of 
		// the above graph
		printGraph(city);
	}
}
// This code is contributed by Sumit Ghosh