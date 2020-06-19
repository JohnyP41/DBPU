using System;
using System.Collections.Generic;
using System.IO;

namespace Labirynt
{
    class Program
    {
        static void Main(string[] args)
        {
            int[,] tab = new int[8,8]; // labirynt
            int y = 0;
            int x = 0;
            int endX = -1;
            int endY = -1;
            using (StreamReader sr = new StreamReader("labirynt.txt")) // wszytywanie pliku
            {
                for (int i = 0; i < 8; i++)
                {
                    var line = sr.ReadLine();
                    x = 0;
                    foreach (char c in line)
                    {
                        if (c == '1')
                        {
                            tab[x, y] = 1;
                        }
                        else
                        {
                            if(x == 7 || y == 7) // nie wiadomo, czy pkt. (3,7) to zawsze koncowy pkt. , wiec szukamy dalszego od pkt (0,0)
                            {
                                endX = x;
                                endY = y;
                            }
                        }
                        if (c == '0' || c == '1') x++;
                    }
                    y++;
                }
            }

            int max = 7;//zmieniony
            x = 0; //Start position
            y = 0;

            List<Verticle> queue = new List<Verticle>();
            var current = new Verticle { X = 0, Y = 0 };
            queue.Add(current);

            int index = 0;
            while (current.X != endX && current.Y != endY)//uzywamy bfs z kolejką
            {
                if (index == queue.Count) // brak rozwiazania
                {
                    Console.WriteLine("Brak rozwiazania");
                    return;
                }
                current = queue[index];
                if (current.X < max && tab[current.X + 1, current.Y] == 0) // prawo
                {
                    queue.Add(new Verticle { X = current.X + 1, Y = current.Y });
                    tab[current.X + 1, current.Y] = 4;
                }
                if (current.Y < max && tab[current.X, current.Y + 1] == 0) // dol
                {
                    queue.Add(new Verticle { X = current.X, Y = current.Y + 1 });
                    tab[current.X, current.Y + 1] = 4;
                }
                if (current.X > 0 && tab[current.X - 1, current.Y] == 0) // lewo
                {
                    queue.Add(new Verticle { X = current.X - 1, Y = current.Y });
                    tab[current.X - 1, current.Y] = 4;
                }
                if (current.Y > 0 && tab[current.X, current.Y - 1] == 0) // gora
                {
                    queue.Add(new Verticle { X = current.X, Y = current.Y - 1 });
                    tab[current.X, current.Y - 1] = 4;
                }
                index++;
            }
            
            for(int i = 0; i < 8; i++) // wypisanie labiryntu
            {
                for(int j = 0; j < 8; j++)
                {
                    Console.Write(tab[j, i] + " ");
                }
                Console.Write("\n");
            }
            Console.ReadLine();
        }
    }

    public class Verticle
    {
        public int X { get; set; }
        public int Y { get; set; }
    }
}