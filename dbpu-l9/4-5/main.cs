using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
 
namespace matrix_multiplication
{
    class Program
    {
        static void Main(string[] args)
        { 
            int i, j,m=3,n=3;
            int[,] a = {{1,1,1},{2,2,2},{3,3,3}};
			int[,] b = {{1,1,1},{2,2,2},{3,3,3}};
            int[,] c = new int[m, n];
            for (i = 0; i < m; i++)
            {
                for (j = 0; j < n; j++)
                {
                    c[i, j] = 0;
                    for (int k = 0; k < 3; k++)
                    {
                        c[i, j] += a[i, k] * b[k, j];
                    }
                }
            }
            for (i = 0; i < m; i++)
            {
                for (j = 0; j < n; j++)
                {
                    Console.Write(c[i, j] + "\t");
                }
                Console.WriteLine();
            }
 
            Console.ReadKey();
        }
    }
}
